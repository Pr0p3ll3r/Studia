const http = require('http')
const url = require('url')

http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'})
    let q = url.parse(req.url, true).query
    var p = ((+q.a) + (+q.b) + (+q.c) / 2)
    res.end("Pole powierzchni wynosi: " + p)
}).listen(3000)