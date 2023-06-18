import React from 'react'
import { useState, useEffect, useContext } from "react"
import axios from "axios"
import { CartContext } from '../CartContext'
import { useNavigate } from "react-router-dom"

const Menu = () => {
  const [pizzas, setPizzas] = useState([])
  const { cartTotal, setCartTotal } = useContext(CartContext)
  const navigate = useNavigate()

  useEffect(() => {
    fetchMenuList()
  }, [])

  const fetchMenuList = async () => {
    try {
      const response = await axios.get('http://localhost:8080/api/pizza')
      setPizzas(response.data)
    } catch (error) {
      console.error('Błąd podczas pobierania danych pizz:', error)
    }
  }

  const handleAddToCart = (e) => {
    e.preventDefault()

    const user = localStorage.getItem("token")
    if(!user) {
      navigate('/login')
      return
    }
    
    const pizzaId = e.target.id.value
    const size = e.target.size.value

    const cartData = JSON.parse(localStorage.getItem('cart')) || []
    const existingPizza = cartData.find((pizza) => pizza.id === pizzaId && pizza.size === size)

    if (existingPizza) {
      existingPizza.quantity += 1
    } else {
      const pizza = pizzas.find((pizza) => pizza._id === pizzaId)
      const pizzaData = {
        id: pizzaId,
        size,
        quantity: 1,
        name: pizza.name,
        price: size === '32' ? pizza.priceFor32 : pizza.priceFor42,
      }
      cartData.push(pizzaData)
    }

    localStorage.setItem('cart', JSON.stringify(cartData))
    const pizzaData = cartData.find((pizza) => pizza.id === pizzaId && pizza.size === size)
    setCartTotal((prevTotal) => prevTotal + pizzaData.price)

    // Zapisz wartość cartTotal do localStorage
    localStorage.setItem('cartTotal', cartTotal)
  }

  return (
    <div>
      <section className="py-5">
        <div className="container px-4 px-lg-5 mt-5">
          <div className="row gx-4 gx-lg-5 row-cols-2 row-cols-md-3 row-cols-xl-4 justify-content-center">
            {pizzas.map((pizza) => (
              <form onSubmit={handleAddToCart} key={pizza._id}>
                <div className="col mb-5">
                  {/* Pizza image */}
                  <img className="card-img-top" src={`./images/pizza/${pizza.name}.png`} alt={`Pizza ${pizza.name}`} />
                  {/* Pizza details */}
                  <div className="card-body p-4">
                    <div className="text-center text-white">
                      {/* Pizza name */}
                      <h5 className="fw-bolder">{pizza.name}</h5>
                      {/* Pizza toppings */}
                      <p>
                        sos, ser, przyprawy, {' '}
                        {pizza.toppings.join(', ')}
                      </p>
                    </div>
                  </div>
                  <select name="size" className="form-select btn btn-primary text-center mb-4">
                    <option value="32">32cm - {pizza.priceFor32}zł</option>
                    <option value="42">42cm - {pizza.priceFor42}zł</option>
                  </select>
                  <br />
                  <input type="hidden" value={pizza._id} name="id" />
                  <div className="text-center">
                    <button type="submit" className="btn btn-primary">
                      Dodaj do koszyka
                    </button>
                  </div>
                </div>
              </form>
            ))}
          </div>
        </div>
      </section>
    </div>
  )
}

export default Menu
