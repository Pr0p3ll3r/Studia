const express = require('express')
const path = require('path')
const app = express()
const hbs = require('hbs')
/*
app.set('view engine', 'hbs')
app.set('views', path.join(__dirname, 'views'))
*/
app.get('/about', (req, res) => {
    res.render('about', {name: 'Jan'})
})

app.listen(3000, () => console.log('Serwer działa!'))

const { check, validationResult } = require('express-validator')

app.use(express.urlencoded({ extended: false }));

app.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "form3.html"))
})

const reactEngine = require ('express-react-views')
app.set('view engine', 'jsx')
app.engine('jsx', reactEngine.createEngine())

app.post("/form", [
    check('surname').isAlpha('pl-PL', {ignore: ' -'}).withMessage('Błędne nazwisko (3-25 znaków, tylko litery)').stripLow().trim().bail().isLength({ min: 3, max: 25 }),
    check('email').isEmail().withMessage('Błędny adres email').trim().stripLow().bail().normalizeEmail(),
    check('age').isNumeric().withMessage('Błędny wiek (0-110)').trim().stripLow().bail().isInt({ min: 0, max: 110 })
    ], (req, res) => {
    const errors = validationResult(req)
    if (!errors.isEmpty()) {
    return res.status(422).json({ errors: errors.array() })
    }
    const surname = req.body.surname
    const email = req.body.email
    const age = req.body.age
    res.render('info', {name: surname, email: email, age: age})
})