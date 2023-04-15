const express = require('express')
const app = express()
const PORT = 3000
app.get('/', (req, res) => res.send('Prosty serwer oparty na szkielecie programistycznym Express!'))
app.listen(PORT, () => {  
    console.log("Serwer dziala na porcie: %s", PORT)
})
app.get("/abort", (req, res) => res.send('Autor strony: Jan Kowalski'))