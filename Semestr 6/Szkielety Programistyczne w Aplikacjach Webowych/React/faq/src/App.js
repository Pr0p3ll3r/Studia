import { Provider } from "react-redux"
import { configureStore } from '@reduxjs/toolkit'
import rootReducer from "./reducers"
import Faq from "./components/Faq"
import "./App.css"

const store = configureStore({ reducer: rootReducer })
const App = () => {
  return (
    <Provider store={store}>
      <Faq />
    </Provider>
  )
}

export default App