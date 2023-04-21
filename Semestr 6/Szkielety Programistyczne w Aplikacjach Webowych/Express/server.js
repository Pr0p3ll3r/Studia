const express = require('express')
const app = express()
const PORT = 3000
const path = require('path')
const getDate = require('./server-files/getDate')

app.listen(PORT, () => {
    console.log(getDate() + " === Serwer zostaje uruchomiony na porcie " + PORT)
})

app.get("/form", (req, res) => {
    console.log(getDate() + " --- Klient wysłał zapytanie o plik form2.html")
    res.sendFile(path.join(__dirname, "form2.html"))
})

app.get('/strona1', function(req, res) {
  res.sendFile(path.join(__dirname, 'strona1.html'));
});

app.get('/strona2', function(req, res) {
  res.sendFile(path.join(__dirname, 'strona2.html'));
});

app.get('/strona3', function(req, res) {
  res.sendFile(path.join(__dirname, 'strona3.html'));
});

app.get('/strona4', function(req, res) {
  res.sendFile(path.join(__dirname, 'strona4.html'));
});

app.get('/strona5', function(req, res) {
  res.sendFile(path.join(__dirname, 'strona5.html'));
});

app.get('/convert', (req, res) => {
    const toRad = req.query.toRad;
    const value = req.query.value;
    const result = toRad === 'true' ? value * (Math.PI / 180) : value * (180 / Math.PI);
    if(toRad === 'true')
        res.send(`${value} stopni to ${result} radianów.`);
    else
        res.send(`${value} radianów to ${result} stopni.`);
});

app.use((req, res, next) => {
    const bg = req.query.bg;
    if (bg) {
      res.setHeader('Content-Type', 'text/html');
      res.write('<style>body { background-color: ' + bg + '; }</style>');
    }
    next();
  });
  
app.get('/', (req, res) => {
    res.send('Prosty serwer oparty na szkielecie programistycznym Express!')
});