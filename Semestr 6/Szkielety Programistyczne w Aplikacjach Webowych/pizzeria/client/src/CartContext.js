import React, { createContext, useState } from 'react'

export const CartContext = createContext()

export const CartProvider = ({ children }) => {
  const [cartTotal, setCartTotal] = useState(0)

  return (
    <CartContext.Provider value={{ cartTotal, setCartTotal }}>
      {children}
    </CartContext.Provider>
  )
}
