import './App.css';
import React, { useState } from "react"
import Header from "./components/Header"
import MainArea from "./components/MainArea"
import Sidebar from "./components/Sidebar"
import Footer from './components/Footer'
import colorName from 'color-name'

function App() {
  const [fontSize, setFontSize] = useState(18)
  const [color, setColor] = useState("green")
  const [fontSizeButton, setfontSizeButton] = useState(18)
  const [fontColorButton, setfontColorButton] = useState("green")
  const [counter, setCounter] = useState(0)

  const handleIncrement = () => {
    setCounter(licznik => licznik + 1)
  }

  const handleFontSizeChange = (e) => {
    setfontSizeButton(e.target.value)
  }

  const handleColorChange = (e) => {
    setfontColorButton(e.target.value)
  }

  const handleButtonClick = () => {
    const isValidFontSize = !isNaN(fontSizeButton) && parseInt(fontSizeButton) > 0
    const isValidColorName = colorName[fontColorButton.toLowerCase()] !== undefined
    if (isValidFontSize && isValidColorName) {
      setFontSize(fontSizeButton)
      setColor(fontColorButton)
    }
  }

  const handleButtonClickFooter = () => {
    setFontSize(30)
    setfontSizeButton(30)
  }

  return (
    <div className="grid-parent">
      <Header fontSize={fontSize} color={color} counter={counter} />
      <Sidebar
        fontSizeButton={fontSizeButton}
        fontColorButton={fontColorButton}
        handleFontSizeChange={handleFontSizeChange}
        handleColorChange={handleColorChange}
        handleButtonClick={handleButtonClick}
      />
      <MainArea fontSize={fontSize} color={color} />
      <Footer
        handleButtonClickFooter={handleButtonClickFooter}
        handleIncrement={handleIncrement}
      />
    </div>
  )
}

export default App