const express = require('express');
const router = express.Router();
const PizzaController = require('../controllers/PizzaController');

router.get('/', PizzaController.getPizzas);
router.post('/', PizzaController.addPizza);
router.delete('/', PizzaController.deletePizza);

module.exports = router;
