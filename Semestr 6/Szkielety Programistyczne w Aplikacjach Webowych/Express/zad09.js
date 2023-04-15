const express = require('express')
const app = express()
const PORT = 3000
app.get('/', (req, res) => res.send('Prosty serwer oparty na szkielecie programistycznym Express!'))
app.listen(PORT, () => {  
    console.log("Serwer dziala na porcie: %s", PORT)
})
app.get("/name/:imie1&:imie2", (req, res) => {
    res.setHeader('content-type', 'text/html');
    res.status(200).send("<h1> Cześć " + req.params.imie1 + " i " + req.params.imie2 + "</h1>") 
});
app.use((req, res) => {
    console.log('Obsługa bledu 404.')
    res.status(404)
    res.send('404 - Nie znaleziono<br>')
})