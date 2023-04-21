const express = require('express')
const users = require('./users')
const router = express.Router()

router.get('/', (req, res) => res.send('Prosty serwer oparty na szkielecie programistycznym Express!'))

router.get('/api/users', (req,res) => {
    res.json(users)
})

router.get('/api/users/:id', (req, res) => {
    const found = users.some(user => user.id === parseInt(req.params.id))
    if(found){
        res.json(users.filter(user => user.id === parseInt(req.params.id)))
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie został odnaleziony`})}
})

router.post('/api/users', (req, res) => {
    const newUser = {
        id: users.length + 1,
        name: req.body.name,
        email: req.body.email,
        status: "aktywny"
    }
    if(!newUser.name || !newUser.email){
        console.log('name:', req.body.name, 'email:', req.body.email); 
        return res.status(400).json({msg: 'Wprowadź poprawne imię i nazwisko oraz email!'})
    }
    users.push(newUser)
    res.json(users)
})

router.patch('/api/users/:id', (req, res) => {
    const found = users.some(user => user.id === parseInt(req.params.id))
    if(found){
        const updUser = req.body
        users.forEach(user => {
            if(user.id === parseInt(req.params.id)) {
                user.name = updUser.name ? updUser.name : user.name
                user.email = updUser.email ? updUser.email : user.email
                res.json({msg: 'Dane użytkownika zaktualizowane', user})
            }
        })
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie istnieje!`})
    }
})

router.delete('/api/users/:id', (req, res) => {
    const found = users.findIndex(user => user.id === parseInt(req.params.id))
    if(found != -1){
        users.splice(found, 1);
        res.json({ msg: `Użytkownik o id ${req.params.id} usunięty`, users });
    } else {
        res.status(400).json({msg: `Użytkownik o id ${req.params.id} nie istnieje!`})
    }
})

router.use((req, res) => {
    console.log('Obsługa bledu 404.')
    res.status(404)
    res.send('404 - Nie znaleziono<br>')
})

module.exports = router