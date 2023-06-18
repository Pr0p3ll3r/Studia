import React from 'react'
import { useState, useEffect, useContext } from 'react'
import { CartContext } from '../CartContext'
import axios from "axios"
import { useNavigate } from "react-router-dom"

const Cart = () => {
  const [cart, setCart] = useState([])
  const [data, setData] = useState({
    street: '',
    houseNumber: '',
    apartmentNumber: '',
    comment: '',
    payment: '',
  })
  const { cartTotal, setCartTotal } = useContext(CartContext);
  const [error, setError] = useState("")
  const navigate = useNavigate()
  const [user, setUser] = useState(null)
  const [formData, setFormData] = useState({
    name: '',
    email: '',
    phoneNumber: '',
  })

  useEffect(() => {
    fetchCart()
    fetchUser()

    // eslint-disable-next-line
  }, [])

  const fetchUser = async () => {
    try {
      const token = localStorage.getItem('token')
      const response = await axios.get('http://localhost:8080/api/user', {
        headers: {
          Authorization: `Bearer ${token}`,
        },
      })
    
      const userData = response.data.user

      setUser(userData)
      setFormData({
        name: userData.name,
        email: userData.email,
        phoneNumber: userData.phoneNumber,
      })
    } catch (error) {
      console.error('Błąd podczas pobierania użytkownika:', error)
    }
  }

  // pobierz koszyk
  const fetchCart = () => {
    const cartData = localStorage.getItem('cart')
    if (cartData) {
      setCart(JSON.parse(cartData))
    }
    if(!cart) {
      navigate('/menu')
    }
  } 

  // zmiana ilości w koszyku
  const handleQuantityChange = (e, pizzaId, size, quantity) => {
    e.preventDefault()
    if (quantity === 0) {
      handleRemoveItem(e, pizzaId, size)
      return
    }
    const updatedCart = cart.map((item) => {
      if (item.id === pizzaId && item.size === size) {
        return { ...item, quantity }
      }
      return item
    })
    setCart(updatedCart)
    localStorage.setItem('cart', JSON.stringify(updatedCart))

    // zapisz w sesji
    const updatedTotal = updatedCart.reduce((total, item) => total + item.price * item.quantity, 0);
    setCartTotal(updatedTotal)
  }

  // usuwanie z koszyka
  const handleRemoveItem = (e, pizzaId, size) => {
    e.preventDefault()
    const updatedCart = cart.filter((item) => item.id !== pizzaId || item.size !== size)
    setCart(updatedCart)
    localStorage.setItem('cart', JSON.stringify(updatedCart))

    // zapisz w sesji
    const updatedTotal = updatedCart.reduce((total, item) => total + item.price * item.quantity, 0)
    setCartTotal(updatedTotal)

    if(updatedCart.length === 0) {
      navigate("/menu")
    }
  } 

  // wyślij zamówienie
  const handleOrderSubmit = async (e) => {
    e.preventDefault();

    const order = {
      userId: user._id,
      totalPrice: cartTotal,
      payment: data.payment,
      comment: data.comment,
      items: cart.map((item) => ({
        pizzaId: item.id,
        size: item.size,
        quantity: item.quantity,
        price: item.price,
      })),
      address: {
        street: data.street,
        houseNumber: data.houseNumber,
        apartmentNumber: data.apartmentNumber,
      },
    }

    try {
      const url = "http://localhost:8080/api/order"
      const { data: res } = await axios.post(url, order)
      navigate("/order-confirmation")
      console.log(res.message)

      setCart([]);
      localStorage.removeItem('cart');
      setCartTotal(0);
    } catch (error) {
      if (
        error.response &&
        error.response.status >= 400 &&
        error.response.status <= 500
      ) {
        setError(error.response.data.message)
      }
    }
  }

  const handleChange = ({ currentTarget: input }) => {
    setData({ ...data, [input.name]: input.value })
  }

  return (
    <div>
      <section className="page-section cta">
        <div className="container">
          <div className="row">
            <div className="mx-auto space-y-6">
              <div className="cta-inner bg-faded text-center rounded">
                <h2 className="section-heading mb-5">
                  <span className="section-heading-lower fw-bold">Koszyk</span>
                </h2>
                <div className="table-responsive">
                  <table id="koszyk" className="table table-primary">
                  <tbody>
                    <tr>
                      <td className="col-md-1 fw-bold">Ilość</td>
                      <td className="col-md-3 fw-bold">Nazwa</td>
                      <td className="col-md-2 fw-bold">Wielkość</td>
                      <td className="col-md-2 fw-bold">Zmień ilość</td>
                      <td className="col-md-2 fw-bold">Cena</td>
                      <td className="col-md-1 fw-bold">Usuń</td>
                    </tr>
                    {cart.map((item) => (
                      <tr key={item.id}>
                        <td className="col-md-1">{item.quantity}x</td>
                        <td className="col-md-3">{item.name}</td>
                        <td className="col-md-2">{item.size}cm</td>
                        <td className="col-md-2">
                          <form
                            className="form-check form-check-inline"
                            onSubmit={(e) => handleQuantityChange(e, item.id, item.size, item.quantity + 1)}
                          >
                            <button className="btn btn-primary bi-plus"></button>
                          </form>
                          <form
                            className="form-check form-check-inline"
                            onSubmit={(e) => handleQuantityChange(e, item.id, item.size, item.quantity - 1)}
                          >
                            <button className="btn btn-primary bi-dash"></button>
                          </form>
                        </td>
                        <td className="col-md-2">{item.price}zł</td>
                        <td className="col-md-2">
                          <form onSubmit={(e) => handleRemoveItem(e, item.id, item.size)}>
                            <button className="btn btn-primary bi-trash"></button>
                          </form>
                        </td>
                      </tr>
                    ))}
                    <tr>
                      <td colSpan="6" className="text-center">
                        <h4>
                          <span className="section-heading-lower fw-bold">
                            Razem do zapłaty: {cartTotal} zł
                          </span>
                        </h4>
                      </td>
                    </tr>
                    </tbody>
                  </table>
                </div>
              </div>
              <div className="cta-inner bg-faded text-center rounded">
                <h2 className="section-heading mb-5">
                  <span className="section-heading-lower fw-bold">Dane kontaktowe</span>
                </h2>
                <form onSubmit={handleOrderSubmit}>
                  <div className="table-responsive">
                    <table className="table table-primary">
                    <tbody>
                      <tr>
                        <td>
                          <input
                            type="text"
                            placeholder="Imię"
                            name="name"
                            value={formData.name}
                            disabled
                            className="block mt-1 w-full form-control"
                          />
                        </td>
                        <td>
                          <input
                            type="email"
                            placeholder="Email"
                            name="email"
                            value={formData.email}
                            disabled
                            className="block mt-1 w-full form-control"
                          />
                        </td>
                        <td>
                          <input
                            type="text"
                            placeholder="Numer telefonu"
                            name="phoneNumber"
                            value={formData.phoneNumber}
                            disabled
                            className="block mt-1 w-full form-control"
                          />
                        </td>
                      </tr>
                      <tr>
                        <td>
                          <input
                            type="text"
                            placeholder="Ulica"
                            name="street"
                            onChange={handleChange}
                            value={data.street}
                            pattern="[A-Za-z ]+"
                            maxLength="255"
                            required
                            autoComplete="address-line1"
                            title="Ulica może zawierać tylko litery"
                            className="mt-1 block w-full form-control"
                          />
                        </td>
                        <td>
                          <input
                            type="text"
                            placeholder="Numer domu"
                            name="houseNumber"
                            onChange={handleChange}
                            value={data.houseNumber}
                            pattern="[A-Za-z0-9]+"
                            maxLength="5"
                            required
                            autoComplete="address-line1"
                            title="Numer może zawierać tylko litery i cyfry. Max 5 znaków"
                            className="mt-1 block w-full form-control"
                          />
                        </td>
                        <td>
                          <input
                            type="text"
                            placeholder="Numer mieszkania"
                            name="apartmentNumber"
                            onChange={handleChange}
                            value={data.apartmentNumber}
                            pattern="[A-Za-z0-9]+"
                            maxLength="5"
                            autoComplete="address-line2"
                            title="Numer może zawierać tylko litery i cyfry. Max 5 znaków"
                            className="mt-1 block w-full form-control"
                          />
                        </td>
                      </tr>
                      <tr>
                        <td colSpan="3">
                          <textarea
                            placeholder="Komentarz"
                            className="form-control block w-full"
                            name="comment"
                            maxLength="255"
                            title="Komentarz może zawierać 255 znaków"
                            onChange={handleChange}
                          ></textarea>
                        </td>
                      </tr>
                      <tr className="text-center">
                        <td colSpan="3">
                          <h4 className='bg-transparent'>
                            <b>Jak chcesz zapłacić?</b>
                          </h4>
                          <label className='bg-transparent'>
                            <input
                              className="form-check-input"
                              type="radio"
                              id="gotowka"
                              value="gotówka"
                              name="payment"
                              onChange={handleChange}
                              title="Wybierz metodę płatności"
                            />
                            Gotówka</label>
                          <br />
                          <label htmlFor="karta" className='bg-transparent '>
                            <input
                              className="form-check-input"
                              type="radio"
                              id="karta"
                              value="karta"
                              name="payment"
                              onChange={handleChange}
                            />
                            Karta płatnicza</label>
                          <br />
                          <label htmlFor="online" className='bg-transparent '>
                            <input
                              className="form-check-input"
                              type="radio"
                              id="online"
                              value="online"
                              name="payment"
                              onChange={handleChange}
                            />
                            Płatność online</label>
                          <br />
                          <br />
                          <label className='bg-transparent '>
                            <input
                              className="form-check-input"
                              type="checkbox"
                              id="rules"
                              name="rules"
                              required
                            />
                            *Akceptuję regulamin</label>
                        </td>
                      </tr>
                      </tbody>
                    </table>
                  </div>
                  <button className="px-4 py-2 btn btn-primary">Zamawiam</button>   
                  {error && <div
                    className="mt-2 p-lg-0 text-sm text-danger space-y-1">{error}</div>}
                </form>
              </div>
            </div>
          </div>
        </div>
      </section>
    </div>
  )
}

export default Cart
