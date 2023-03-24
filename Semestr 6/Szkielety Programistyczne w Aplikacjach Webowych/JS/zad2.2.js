const listaZadan = [
    {
      id: 1,
      tekst: "Zrobienie zakupów",
      zrealizowano: true
    },
    {
      id: 2,
      tekst: "Przegląd techniczny samochodu",
      zrealizowano: false
    },
    {
      id: 3,
      tekst: "Wizyta u dentysty",
      zrealizowano: false
    },
]
      
listaZadan.forEach(zadanie => console.log(`Tekst: ${zadanie.tekst}`))
      
console.log(listaZadan.map(zadanie => zadanie.tekst))
    
console.log(listaZadan.filter(zadanie => zadanie.zrealizowano == true)
.map(zadanie => zadanie.tekst)) 