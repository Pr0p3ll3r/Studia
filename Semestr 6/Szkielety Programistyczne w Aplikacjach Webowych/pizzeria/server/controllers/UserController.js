const { User, validate } = require("../models/user")
const bcrypt = require("bcrypt")
const jwt = require('jsonwebtoken');
const Joi = require("joi")

const UserController = {
    register: async (req, res) => {
        try {
            const { error } = validate(req.body)
            //console.log(req.body);
            if (error)
                return res.status(400).send({ message: error.details[0].message })

            const user = await User.findOne({ email: req.body.email })
            if (user)
                return res.status(409).send({ message: "Podany adres email już istnieje!" })

            const salt = await bcrypt.genSalt(Number(process.env.SALT))
            const hashPassword = await bcrypt.hash(req.body.password, salt)
            await new User({ ...req.body, password: hashPassword }).save()
            res.status(201).send({ message: "Dodano użytkownika" })
        } catch (error) {
            console.log(error)
            res.status(500).send({ message: "Błąd serwera" })
        }
    },

    login: async (req, res) => {
        try {
            const { error } = validateLogin(req.body);
            if (error)
                return res.status(400).send({ message: error.details[0].message })
            const user = await User.findOne({ email: req.body.email })
            if (!user)
                return res.status(401).send({ message: "Niepoprawny email lub hasło" })
            const validPassword = await bcrypt.compare(
                req.body.password,
                user.password
            )
            if (!validPassword)
                return res.status(401).send({ message: "Niepoprawny email lub hasło" })
            const token = user.generateAuthToken();
            res.status(200).send({ data: token, message: "Zalogowano pomyślnie" })
        } catch (error) {
            res.status(500).send({ message: "Błąd serwera" })
        }
    },

    getUser: async (req, res) => {
        const token = req.headers.authorization.split(' ')[1];
        try {
            const decodedToken = jwt.verify(token, process.env.JWTPRIVATEKEY);

            const user = await User.findById(decodedToken._id);
            if (!user) {
                return res.status(404).send({ message: 'Użytkownik nie został znaleziony' });
            }

            res.status(200).send({ user, message: "Pobrano użytkownika" })
        } catch (error) {
            console.error(error)
            res.status(401).send({ message: 'Błąd serwera' })
        }
    },

    deleteUser: async (req, res) => {
        const token = req.headers.authorization.split(' ')[1];
        try {
            const decodedToken = jwt.verify(token, process.env.JWTPRIVATEKEY);

            const user = await User.findById(decodedToken._id);
            const validPassword = await bcrypt.compare(
                req.body.password,
                user.password
            )

            if (!validPassword)
                return res.status(401).send({ message: "Niepoprawne hasło" })

            await User.deleteOne(user)
            return res.status(200).json({ message: 'Konto zostało usunięte' })
        } catch (error) {
            console.error(error)
            res.status(401).send({ message: 'Błąd serwera' })
        }
    },

    changePassword: async (req, res) => {
        console.log(req.body)
        try {
            const user = await User.findById(req.body.userId);
            const validPassword = await bcrypt.compare(
                req.body.currentPassword,
                user.password
            )

            if (!validPassword)
                return res.status(401).send({ message: "Niepoprawne hasło" })

            const salt = await bcrypt.genSalt(Number(process.env.SALT))
            const hashedPassword = await bcrypt.hash(req.body.newPassword, salt)

            user.password = hashedPassword
            await user.save()
            return res.status(200).json({ message: 'Hasło zostało zmienione' })
        } catch (error) {
            console.error(error)
            res.status(401).send({ message: 'Błąd serwera' })
        }
    },

    changeInfo: async (req, res) => {
        try {
            const user = await User.findById(req.body.userId);

            const info = {
                name: req.body.name,
                email: req.body.email,
                phoneNumber: req.body.phoneNumber,
            }

            const { error } = validateInfo(info)
            //console.log(info);
            if (error)
                return res.status(400).send({ message: error.details[0].message })

            if (user.email !== info.email) {
                const existingUser = await User.findOne({ email: info.email })
                if (existingUser)
                    return res.status(409).send({ message: "Podany adres email już istnieje!" })
            }

            user.name = info.name
            user.email = info.email
            user.phoneNumber = info.phoneNumber
            await user.save()
            return res.status(200).json({ message: 'Zaktualizowano informacje o profilu' })
        } catch (error) {
            console.error(error)
            res.status(401).send({ message: 'Błąd serwera' })
        }
    }
}

const validateLogin = (data) => {
    const schema = Joi.object({
        email: Joi.string().email().required().label("Email"),
        password: Joi.string().required().label("Password"),
    })
    return schema.validate(data)
}

const validateInfo = (data) => {
    const schema = Joi.object({
        name: Joi.string().regex(/^[A-Za-z]+$/).required().label("Imię"),
        email: Joi.string().email().required().label("Email"),
        phoneNumber: Joi.string().length(9).regex(/^\d+$/).required().label("Numer Telefonu"),
    })
    return schema.validate(data)
}

module.exports = UserController