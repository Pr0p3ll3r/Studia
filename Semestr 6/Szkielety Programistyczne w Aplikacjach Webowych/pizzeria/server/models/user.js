const mongoose = require("mongoose")
const jwt = require("jsonwebtoken")
const Joi = require("joi")
const passwordComplexity = require("joi-password-complexity")

const userSchema = new mongoose.Schema({
    name: { type: String, required: true },
    email: { type: String, unique: true, required: true },
    phoneNumber: { type: String, required: true },
    password: { type: String, required: true },
}, {
    timestamps: true
});
userSchema.methods.generateAuthToken = function () {
    const token = jwt.sign({ _id: this._id }, process.env.JWTPRIVATEKEY, {
        expiresIn: "7d",
    })
    return token
}
const User = mongoose.model("User", userSchema)

const validate = (data) => {
    const schema = Joi.object({
        name: Joi.string().regex(/^[A-Za-z]+$/).required().label("Imię"),
        email: Joi.string().email().required().label("Email"),
        phoneNumber: Joi.string().length(9).regex(/^\d+$/).required().label("Numer Telefonu"),
        password: passwordComplexity().required().label("Hasło"),
        confirmPassword: Joi.string().valid(Joi.ref("password")).required().label("Powtórz hasło"),
    })
    return schema.validate(data)
}

module.exports = { User, validate }