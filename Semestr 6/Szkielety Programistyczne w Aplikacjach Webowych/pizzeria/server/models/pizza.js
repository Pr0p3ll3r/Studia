const mongoose = require('mongoose')
const Schema = mongoose.Schema
const Joi = require("joi")

const pizzaSchema = new Schema({
  name: { type: String, required: true, unique: true },
  priceFor32: { type: Number, required: true },
  priceFor42: { type: Number, required: true },
  toppings: [String]
})

const validate = (data) => {
  const schema = Joi.object({
    name: Joi.string().required(),
    priceFor32: Joi.number().required(),
    priceFor42: Joi.number().required(),
    toppings: Joi.array().items(Joi.string())
  })
  return schema.validate(data)
}

const Pizza = mongoose.model('Pizza', pizzaSchema)

module.exports = { Pizza, validate }
