import { Link } from "react-router-dom"
import React, { useEffect, useState, useContext } from "react"
import { CartContext } from '../CartContext'

const Navigation = () => {
  const [hasCart, setHasCart] = useState(false)
  const { cartTotal, setCartTotal } = useContext(CartContext)

  useEffect(() => {
    setHasCart(cartTotal > 0)
    
    // Obliczanie wartości cartTotal po odświeżeniu strony
    const cartData = JSON.parse(localStorage.getItem('cart')) || []
    const calculatedTotal = cartData.reduce((total, pizza) => total + pizza.price * pizza.quantity, 0)
    setCartTotal(calculatedTotal)

    window.addEventListener('scroll', handleScroll)
    return () => {
      window.removeEventListener('scroll', handleScroll)
    }
  }, [setCartTotal, cartTotal])

  const handleScroll = () => {
    const nav = document.getElementById('mainNav')
    if (window.scrollY > 1) {
      nav.style.position = 'sticky'
      nav.style.top = '-1px'
    } else {
      nav.style.position = 'static'
      nav.style.top = '-50px'
    }
  }

  return (
    <div id="mainNav">
      <nav className="navbar navbar-expand-lg navbar-dark py-lg-4" >
        <div className="container">
          <a className="navbar-brand text-uppercase fw-bold d-lg-none" href="/">
            Pop Pizza
          </a>
          <button
            className="navbar-toggler"
            type="button"
            data-bs-toggle="collapse"
            data-bs-target="#navbarSupportedContent"
            aria-controls="navbarSupportedContent"
            aria-expanded="false"
            aria-label="Toggle navigation"
          >
            <span className="navbar-toggler-icon" />
          </button>
          <div className="collapse navbar-collapse" id="navbarSupportedContent">
            <ul className="navbar-nav mx-auto">
              <li className="nav-item px-lg-4">
                <Link to="/" className="nav-link text-uppercase">
                  Strona główna
                </Link>
              </li>
              <li className="nav-item px-lg-4">
                <Link to="/menu" className="nav-link text-uppercase">
                  Menu
                </Link>
              </li>
              <li className="nav-item px-lg-4">
                <Link to="/contact" className="nav-link text-uppercase">
                  Kontakt
                </Link>
              </li>
              <li className="nav-item px-lg-4">
                <Link to="/login" className="nav-link text-uppercase">
                  Konto
                </Link>
              </li>
              <li className="nav-item px-lg-4">
                {hasCart ? (
                  <Link to="/cart" className="btn btn-outline-light">
                    <b className="bi-cart-fill me-1 text-white marg" />
                    <span className="badge bg-dark text-white ms-1 rounded-pill">
                      {cartTotal} zł
                    </span>
                  </Link>
                ) : (
                  <Link to="/cart" className="btn btn-outline-light disabled">
                    <b className="bi-cart-fill me-1 text-white marg" />
                    <span className="badge bg-dark text-white ms-1 rounded-pill">
                      {cartTotal} zł
                    </span>
                  </Link>
                )}
              </li>
            </ul>
          </div>
        </div>
      </nav>
      </div>
  )
}

export default Navigation
