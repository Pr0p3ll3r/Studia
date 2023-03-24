function sumator(...liczby) {
    let wynik = 0
    for(let liczba of liczby) {	
      wynik += liczba
    }
    return `Suma liczb: ${liczby} wynosi ${wynik}`
  }  
  
console.log(sumator(1,2,3,4,5));