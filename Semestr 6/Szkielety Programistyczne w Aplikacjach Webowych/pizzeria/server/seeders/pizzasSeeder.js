const { Pizza } = require('../models/pizza')

const pizzasData = [
  {
    name: 'Margherita',
    priceFor32: 28,
    priceFor42: 32,
    toppings: [],
  },
  {
    name: 'Hawajska',
    priceFor32: 32,
    priceFor42: 36,
    toppings: ['ananas', 'szynka'],
  },
  {
    name: 'Z szynką i grzybami',
    priceFor32: 32,
    priceFor42: 36,
    toppings: ['szynka', 'pieczarki'],
  },
  {
    name: 'Z salami',
    priceFor32: 30,
    priceFor42: 34,
    toppings: ['salami'],
  },
  {
    name: 'Serowa',
    priceFor32: 34,
    priceFor42: 38,
    toppings: ['ser ementaler', 'ser parmezan', 'ser kozi', 'ser mozzarella'],
  },
  {
    name: 'Wegetariańska',
    priceFor32: 38,
    priceFor42: 42,
    toppings: ['kukurydza', 'pieczarki', 'papryka', 'papryka', 'brokuły'],
  },
  {
    name: 'Mięsna',
    priceFor32: 36,
    priceFor42: 40,
    toppings: ['kiełbasa', 'salami', 'bekon', 'szynka'],
  },
  {
    name: 'Z kurczakiem',
    priceFor32: 32,
    priceFor42: 36,
    toppings: ['cebula', 'kurczak'],
  },
]

const seedPizzas = async () => {
  try {
    const count = await Pizza.countDocuments();
    if (count > 0) {
      return;
    }

    await Pizza.insertMany(pizzasData);

    console.log('Dodano pizze');
  } catch (error) {
    console.error('Błąd przy dodawaniu pizzy:', error);
  }
}

module.exports = seedPizzas
