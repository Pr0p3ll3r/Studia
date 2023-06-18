const mongoose = require('mongoose')
const Schema = mongoose.Schema

const toppingSchema = new Schema({
  name: { type: String, required: true, required: true }
});

const Topping = mongoose.model('Topping', toppingSchema)

module.exports = Topping
