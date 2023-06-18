const mongoose = require('mongoose')
const Joi = require('joi')

const reviewSchema = new mongoose.Schema({
    rating: { type: Number, required: true, min: 1, max: 5},
    comment: { type: String },
})

const orderSchema = new mongoose.Schema({
    userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User', required: true },
    totalPrice: { type: Number, required: true },
    payment: { type: String, required: true },
    comment: { type: String, maxlength: 255 },
    items: [
        {
            pizzaId: { type: mongoose.Schema.Types.ObjectId, ref: 'Pizza', required: true },
            size: { type: String, required: true },
            quantity: { type: Number, required: true },
            price: { type: Number, required: true },
        },
    ],
    address: {
        street: { type: String, required: true },
        houseNumber: { type: String, required: true },
        apartmentNumber: { type: String },
    },
    review: reviewSchema,
}, {
    timestamps: true,
})

const Order = mongoose.model('Order', orderSchema)

const validate = (order) => {
    const itemSchema = Joi.object({
        pizzaId: Joi.string().required(),
        size: Joi.string().required(),
        quantity: Joi.number().required(),
        price: Joi.number().required(),
    })

    const addressSchema = Joi.object({
        street: Joi.string().required().label("Ulica"),
        houseNumber: Joi.string().required().label("Numer Domu"),
        apartmentNumber: Joi.string().allow(""),
    })

    const orderSchema = Joi.object({
        userId: Joi.string().required(),
        totalPrice: Joi.number().required(),
        payment: Joi.string().valid('gotówka', 'karta', 'online').default('gotówka').messages({
            'any.only': 'Wybierz metodę płatności',
          }),
        comment: Joi.string().allow(""),
        items: Joi.array().items(itemSchema).required(),
        address: addressSchema.required(),
    })

    return orderSchema.validate(order)
}

module.exports = { Order, validate }
