const express = require('express')
const path = require('path')
const app = express()
const PORT = 3000

app.use(express.urlencoded({ extended: false }));

app.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "form2.html"))
})
/*
app.post("/result", (req, res) => {
    let username = req.body.username
    let password = req.body.password
    if(username === "" || password === "")
        res.send("Uzupełnij dane!")
    else
        res.send("Użytkownik: " + username + "<br>Hasło: " + password)
})
*/
app.post("/result", (req, res) => {
    let fullname = req.body.fullname
    let languages = req.body.languages
    let languagesList = "<ul>"
    if(languages){
        if (!Array.isArray(languages)) {
            languages = [languages]
        }
        languages.forEach(language => {
            languagesList +=`<li>${language}</li>`
        });        
    }
    languagesList += "</ul>"
    if(fullname === "")
        res.send("Uzupełnij dane!")
    else {
        res.send("Użytkownik: " + fullname + "<br>Znajomość języków: " + languagesList)
    }     
})
app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))