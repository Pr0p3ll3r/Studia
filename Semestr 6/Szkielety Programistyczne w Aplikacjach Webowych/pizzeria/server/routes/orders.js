const express = require('express')
const router = express.Router()
const OrderController = require('../controllers/OrderController')

router.post('/', OrderController.addOrder)
router.get('/', OrderController.getAllOrders)
router.post('/review', OrderController.addReview)

module.exports = router
