import './Card.css'
/*
import { Card1 } from "./Card1"
import { Card2 } from "./Card2"
import { Card3 } from "./Card3"
import { Card4 } from "./Card4"
*/
import { Card } from "./Card"

function App() {
    return (
     <div>
      <h1>Słynni informatycy</h1>
      <Card fullname = "Alan Turing" 
      imageSource = "https://mdz.cs.pollub.pl/ai/alan_turing.jpg" 
      date = "1912 - 1954" professions = "Matematyk" country = "Anglia"/>
      <Card fullname = "Niklaus Wirth" 
      imageSource = "https://mdz.cs.pollub.pl/ai/nicolas_wirth.jpg" 
      date = "1934 - ?" professions = "Elektronik i informatyk" country = "Szwajcaria"/>
      <Card fullname = "Dennis Ritchie" 
      imageSource = "https://mdz.cs.pollub.pl/ai/dennis_ritchie.jpg" 
      date = "1941 - 2011" professions = "Matematyk, fizyk, informatyk" country = "USA"/>
      <Card fullname = "Bjarne Stroustrup" 
      imageSource = "https://mdz.cs.pollub.pl/ai/bjarne_stroustrup.jpg" 
      date = "1950 - ?" professions = "Informatyk" country = "Dania"/>
     </div>
    )
}

export default App