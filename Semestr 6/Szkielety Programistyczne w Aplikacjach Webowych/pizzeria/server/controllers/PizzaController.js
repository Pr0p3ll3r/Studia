const { Pizza, validate } = require('../models/pizza')
const Topping = require('../models/topping')

const PizzaController = {
    getPizzas: async (req, res) => {
        try {
            const pizzas = await Pizza.find()
            res.json(pizzas)
        } catch (error) {
            console.error('Błąd podczas pobierania danych pizz:', error)
            res.status(500).json({ error: 'Błąd serwera' })
        }
    },

    addPizza: async (req, res) => {
        try {
            //console.log(req.body)
            const { error } = validate(req.body)
            if (error)
                return res.status(400).send({ message: error.details[0].message })

            const pizza = await Pizza.findOne({ name: req.body.name })
            if (pizza)
                return res.status(409).send({ message: "Podana pizza już istnieje!" })

            const newPizza = await new Pizza({ ...req.body }).save()
            res.status(201).json({ message: "Dodano pizze", newPizza })
        } catch (error) {
            console.error('Błąd podczas dodawania pizzy:', error)
            res.status(500).json({ error: 'Błąd serwera' })
        }
    },

    deletePizza: async (req, res) => {
        try {
            const { pizzaId } = req.body
            const deletedPizza = await Pizza.findByIdAndDelete(pizzaId)
            if (!deletedPizza) {
                return res.status(404).json({ error: 'Pizza nie znaleziona' })
            }

            res.json({ message: 'Pizza została usunięta', deletedPizza })
        } catch (error) {
            console.error('Błąd podczas usuwania pizzy:', error)
            res.status(500).json({ error: 'Błąd serwera' })
        }
    },
}

module.exports = PizzaController
