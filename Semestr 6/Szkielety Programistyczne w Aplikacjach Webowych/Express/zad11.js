const express = require('express')
const path = require('path')
const app = express()
const PORT = 3000

const { check, validationResult } = require('express-validator')

app.use(express.urlencoded({ extended: false }));

app.get("/form", (req, res) => {
    res.sendFile(path.join(__dirname, "form3.html"))
})

const initials = name => {
    const names = name.split(' ')
    const firstNameInitial = names[0].charAt(0).toUpperCase()
    const lastNameInitial = names[names.length - 1].charAt(0).toUpperCase()
    return `${firstNameInitial+lastNameInitial}`
}

app.post("/form", [
    check('surname').isAlpha('pl-PL', {ignore: ' -'}).withMessage('Błędne nazwisko (3-25 znaków, tylko litery)').stripLow().trim().bail().isLength({ min: 3, max: 25 }).customSanitizer(surname => {
        return initials(surname)
    }),
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
    res.send("Użytkownik: " + surname + "<br>Email: " + email + "<br>Wiek: " + age)
})

app.listen(PORT, () => console.log(`Serwer działa na porcie ${PORT}`))