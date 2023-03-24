const firmy = [
    {nazwa:"Abasco", kategoria:"IT", poczatek:1999, koniec:2010},
    {nazwa:"Redis", kategoria:"IT", poczatek:1993, koniec:1998},
    {nazwa:"Komp", kategoria:"IT", poczatek:2003, koniec:2018},
    {nazwa:"Bosco", kategoria:"Technologie", poczatek:2011, koniec: 2014},
    {nazwa:"CCA", kategoria:"IT", poczatek:1991, koniec:1995},
    {nazwa:"Autosan", kategoria:"Auto", poczatek:2009, koniec: 2018},
    {nazwa:"Broke", kategoria:"Finanse", poczatek:1990, koniec: 1992},
    {nazwa:"Funds", kategoria:"Finanse", poczatek:2000, koniec: 2021}
]
  
let firmyzit = firmy.filter(firma => firma.kategoria == "IT")
let firmyzlat90 = firmy.filter(firma => firma.poczatek >= 1990 && firma.koniec <= 1999)
let firmydluzejniz10lat = firmy.filter(firma => firma.koniec - firma.poczatek > 10)

console.log("Firmy z IT")
firmyzit.forEach(firma => {console.log(firma)})

console.log("Firmy z lat 90")
firmyzlat90.forEach(firma => {console.log(firma)})

console.log("Firmy na rynku dłużej niż 10 lat")
firmydluzejniz10lat.forEach(firma => {console.log(firma)})
