const { Order, validate } = require('../models/order')
const jwt = require('jsonwebtoken');

const OrderController = {
  addOrder: async (req, res) => {
    try {
      //console.log(req.body)
      const { error } = validate(req.body)
      if (error)
        return res.status(400).send({ message: error.details[0].message })

      await new Order({ ...req.body }).save()
      res.status(201).send({ message: "Zamówienie zostało złożone pomyślnie" })
    } catch (error) {
      console.log(error)
      res.status(500).send({ message: "Błąd serwera" })
    }
  },

  getAllOrders: async (req, res) => {
    try {
      const token = req.headers.authorization.split(' ')[1]
      const decodedToken = jwt.verify(token, process.env.JWTPRIVATEKEY)
      //console.log(decodedToken)
      const orders = await Order.find({ userId: decodedToken._id }).populate('items.pizzaId')
      //console.log(orders)
      res.status(200).json(orders)
    } catch (error) {
      res.status(500).json({ error: 'Wystąpił błąd podczas pobierania zamówień.' })
    }
  },

  addReview: async (req, res) => {
    try {
      const { orderId, rating, comment } = req.body;

      const order = await Order.findById(orderId)
      order.review = { rating, comment }
      await order.save()

      res.status(200).json({ message: 'Opinia została dodana.' })
    } catch (error) {
      res.status(500).json({ error: 'Wystąpił błąd podczas dodawania opinii.' })
    }
  }
}

module.exports = OrderController
