const poniedzialek = [
    {
    'nazwa': 'Przygotowania do zajęć z AI',
    'czas': 180
    },
    {
    'nazwa': 'Realizacja projektu z AI',
    'czas': 120
    }
]
const wtorek = [
    {
    'nazwa': 'Rozbudowa swojego bloga',
    'czas': 240
    },
    {
    'nazwa': 'Administrowanie serwisem szkoly',
    'czas': 180
    },
    {
    'nazwa': 'Sluchanie koncertu online',
    'czas': 240
    }
]
  
let kwota = wtorek.reduce((arr, dzien) => arr.concat(dzien), poniedzialek)
  .map(zadanie => zadanie.czas / 60)
  .filter(czas => czas > 2)
  .map(czas => czas * 35)
  .reduce((acc, curr) => { return [+(acc) + +(curr)]; })
  .map(kwota => `${parseFloat(kwota).toFixed(2)} PLN`)
  .reduce(kwota => {return kwota})
console.log(kwota)
  