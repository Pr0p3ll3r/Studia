let isAuthorized = (req, res, next) => {
    if (req.body.password == "secretpaswd")
        res.send("Dostęp przyznany")
    else
        res.status(401).send("Dostęp zabroniony")
    next()
}

module.exports = isAuthorized