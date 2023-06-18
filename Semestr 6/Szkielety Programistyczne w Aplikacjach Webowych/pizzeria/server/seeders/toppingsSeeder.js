const Topping = require('../models/topping')

const toppingsData = [
  {
    name: 'ananas',
  },
  {
    name: 'szynka',
  },
  {
    name: 'boczek',
  },
  {
    name: 'cebula',
  },
  {
    name: 'bekon',
  },
  {
    name: 'kiełbasa',
  },
  {
    name: 'krewetki',
  },
  {
    name: 'kukurydza',
  },
  {
    name: 'kurczak',
  },
  {
    name: 'oliwki',
  },
  {
    name: 'papryka',
  },
  {
    name: 'brokuły',
  },
  {
    name: 'chilli',
  },
  {
    name: 'pieczarki',
  },
  {
    name: 'fasola',
  },
  {
    name: 'pomidor',
  },
  {
    name: 'salami',
  },
  {
    name: 'ser ementaler',
  },
  {
    name: 'ser parmezan',
  },
  {
    name: 'ser kozi',
  },
  {
    name: 'szpinak',
  },
  {
    name: 'ser mozzarella',
  },
]

const seedToppings = async () => {
  try {
    const count = await Topping.countDocuments();
    if (count > 0) {
      return;
    }

    await Topping.insertMany(toppingsData)

    console.log('Dodano dodatki do pizzy')
  } catch (error) {
    console.error('Error przy dodawaniu dodatków do pizzy:', error)
  }
};

module.exports = seedToppings
