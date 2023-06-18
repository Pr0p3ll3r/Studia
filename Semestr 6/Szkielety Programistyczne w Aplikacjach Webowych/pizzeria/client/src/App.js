import React from 'react'
import { Route, Routes, Navigate } from 'react-router-dom'
import Main from './pages/Main'
import Register from './pages/Register'
import Login from './pages/Login'
import Menu from './pages/Menu'
import Contact from './pages/Contact'
import Cart from './pages/Cart'
import Profile from './pages/Profile'
import Orders from './pages/Orders'
import OrderConfirmation from './pages/OrderConfirmation'
import Error404 from './pages/Error404'
import { CartProvider } from './CartContext'
import Header from './components/Header'
import Navigation from './components/Navigation'
import Footer from './components/Footer'
import ProfileEdit from './pages/ProfileEdit'

function App() {
  const user = localStorage.getItem('token')

  return (
    <CartProvider>
      <Header />
      <Navigation />

      <Routes>
        <Route path="/" element={<Main />} />
        <Route path="/menu" element={<Menu />} />
        <Route path="/contact" element={<Contact />} />
        <Route path="/error404" element={<Error404 />} />
        <Route path="*" element={<Navigate to="/error404" replace />} />
        {user ? (
          <>
            <Route path="/register" element={<Navigate replace to="/profile" />} />
            <Route path="/login" element={<Navigate replace to="/profile" />} />
            <Route path="/profile" element={<Profile />} />
            <Route path="/cart" element={<Cart />} />
            <Route path="/orders" element={<Orders />} />
            <Route path="/order-confirmation" element={<OrderConfirmation />} />
            <Route path="/profile/edit" element={<ProfileEdit />} />
          </>
        ) : (
          <>
            <Route path="/register" element={<Register />} />
            <Route path="/login" element={<Login />} />
            <Route path="/profile" element={<Navigate replace to="/login" />} />
            <Route path="/cart" element={<Navigate replace to="/login" />} /> 
            <Route path="/orders" element={<Navigate replace to="/login" />} />
            <Route path="/order-confirmation" element={<Navigate replace to="/login" />} />
            <Route path="/profile/edit" element={<Navigate replace to="/login" />} />   
          </>
        )}
      </Routes>

      <Footer />
    </CartProvider>
  )
}

export default App
