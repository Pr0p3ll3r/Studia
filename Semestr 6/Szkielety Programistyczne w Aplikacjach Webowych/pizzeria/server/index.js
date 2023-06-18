require('dotenv').config()
const express = require('express')
const app = express()
const cors = require('cors')
const userRoutes = require("./routes/users")
const pizzasRoutes = require('./routes/pizzas')
const ordersRoutes = require('./routes/orders')

// middleware
app.use(express.json())
app.use(cors())
const port = process.env.PORT || 8080

app.listen(port, () => console.log(`Nasłuchiwanie na porcie ${port}`))

const connection = require('./db')
connection()

// routes
app.use("/api/user", userRoutes)
app.use('/api/pizza', pizzasRoutes)
app.use("/api/order", ordersRoutes)