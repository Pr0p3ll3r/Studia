//
//  main.swift
//  lab4
//
//  Created by student on 24/10/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

print("Podaj rok")
guard let rok = Int(readLine()!) else {
    fatalError("Nie jest to liczba calkowita")
}

if(rok <= 0){
    print("Wprowadzono niepoprawny rok")
}else{
    if(rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0) {
        print("Rok \(rok) jest przestepny")
    }else{
        print("Rok \(rok) nie jest przestepny")
    }
    
    if(rok % 100 == 0) {
        print("Rok \(rok) - wiek \(rok/100)")
    }else{
        print("Rok \(rok) - wiek \(rok/100 + 1)")
    }
}

print("Podaj srednia")
guard let srednia = Float(readLine()!) else {
    fatalError("Nie jest to liczba zmiennoprzecinkowa")
}

switch (srednia){
    case 4.5...5: print("Stypendium wynosi 200")
    case 4..<4.5: print("Stypendium wynosi 150")
    case 3..<4: print("Stypendium wynosi 100")
    case 2..<3: print("Stypendium wynosi 0")
    default: print("Wprowadzono niepoprawna srednia")
}

print("Podaj 1 liczbe")
guard let x = Int(readLine()!) else {
    fatalError("Nie jest to liczba calkowita")
}

print("Podaj 2 liczbe")
guard let y = Int(readLine()!) else {
    fatalError("Nie jest to liczba calkowita")
}

print("""
        1-dodawanie
        2-odejmowanie
        3-mnozenie
        4-dzielenie
        """)

print("Wybierz opcje ")
guard let wybor = Int(readLine()!) else {
    fatalError("Nie jest to liczba calkowita")
}


switch (wybor)
{
    case 1: print("Wynik \(x+y)")
    case 2: print("Wynik \(x-y)")
    case 3: print("Wynik \(x*y)")
    case 4: if y == 0 {
                print("Dzielenie przez 0!")
            }else{
                print("Wynik \(Float(x)/Float(y))")
            }
    default: print("Bledna opcja")
}

print("Podaj kod pocztowy")
let kod = readLine()!

switch(kod)
{
case kod where kod.hasPrefix("20-") || kod.hasPrefix("21-") || kod.hasPrefix("22-") || kod.hasPrefix("23-") || kod.hasPrefix("24-") || kod.hasPrefix("09-"):
        print("Podano kod pocztowy wojewodztwa lubelskiego")
    default: print("Bledny kod pocztowy")
}

print("Podaj znak")
let znak = readLine()!

switch(znak)
{
case "a", "A", "i" , "I", "e", "E", "o", "O", "u", "U", "y", "Y": print("Podane samogloske")
case "b", "B", "c", "C", "d", "D", "f", "F", "g", "G", "h", "H", "j", "J", "k", "K", "l", "L", "m", "M", "n", "N", "p", "P", "q", "Q", "r", "R", "s", "S", "t", "T", "v", "V", "w", "W", "x", "X", "z", "Z": print("Podano spolgloske")
case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9": print("Podano liczbe")
    default: print("Inny znak")
}

print("Podaj pesel")
let pesel = readLine()!
let przedostatnia = pesel[pesel.index(pesel.startIndex, offsetBy: 9)]
switch(przedostatnia)
{
    case "0","2","4","6","8": print("Kobieta")
    case "1","3","5","7","9": print("Mezczyzna")
    default: print("")
}
