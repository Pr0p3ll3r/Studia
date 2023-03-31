const http = require("http")
const hostname = "localhost"
const port = 3000
const server = http.createServer((req, res) => {
    res.statusCode = 200
    res.setHeader("Content-Type", "text/html")
    res.end("Aplikacja w Node <br> To jest odpowiedz HTML <br>1. <br>2. <br>3.")
})
server.listen(port, hostname, () => {
console.log(`Server running at http://${hostname}:${port}/`)
})