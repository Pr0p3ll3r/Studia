const express = require('express')
const app = express()
const PORT = 3000
const routes = require('./api/routes')

const autoryzacja = require('./middleware/autoryzacja')
const metoda = require('./middleware/metoda')

app.use(routes)

app.listen(PORT, () => {  
    console.log("Serwer dziala na porcie: %s", PORT)
})