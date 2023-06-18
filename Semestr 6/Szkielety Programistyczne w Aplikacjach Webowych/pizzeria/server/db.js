const mongoose = require("mongoose")
const seedPizzas = require('./seeders/pizzasSeeder')
const seedToppings = require('./seeders/toppingsSeeder')

module.exports = () => {
    const connectionParams = {
        useNewUrlParser: true,
        useUnifiedTopology: true,
    }
    try {
        mongoose.connect(process.env.DB, connectionParams)
        console.log("Connected to database successfully")

        seedPizzas()
        seedToppings()
    } catch (error) {
        console.log(error);
        console.log("Could not connect database!")
    }
}