const express = require('express')
const app = express()
const PORT = 3000
app.get('/', (req, res) => res.send('Prosty serwer oparty na szkielecie programistycznym Express!'))

let metoda = (req, res, next) => {
    console.log("Metoda: " + req.method)
    let sciezka = "Ścieżka: "+ req.protocol + "://" + req.get('host') + req.originalUrl
    console.log(sciezka)
    res.send("Metoda: " + req.method + "<br> " + sciezka)
    next()
}

app.use(metoda)

app.listen(PORT, () => {  
    console.log("Serwer dziala na porcie: %s", PORT)
})
