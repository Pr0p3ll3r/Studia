//
//  main.swift
//  lab8
//
//  Created by student on 28/11/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation
/*
//Zadanie 1
let osoba = (imie:"Anna",nazwisko:"Nowak", rok:2000)
let osoba2 =  (imie:"Michal",nazwisko:"Nowak", rok:2001)

if(2022 - osoba.rok > 2022 - osoba2.rok){
    print("\(osoba.imie) jest starsza")
}
else if(2022 - osoba.rok < 2022 - osoba2.rok){
    print("\(osoba.imie) jest starsza")
}
else{
    print("Sa w tym samym wieku")
}


//Zadanie 2
enum Oceny : Double, CaseIterable{
    case oc2 = 2
    case oc3 = 3.0
    case oc35 = 3.5
    case oc4 = 4.0
    case oc45 = 4.5
    case oc5 = 5.0
}

var stud1 = (nazwisko:"", oc1: Oceny.oc2, oc2: Oceny.oc2, oc3: Oceny.oc2)
var stud2 = (nazwisko:"", oc1: Oceny.oc2, oc2: Oceny.oc2, oc3: Oceny.oc2)
var stud3 = (nazwisko:"", oc1: Oceny.oc2, oc2: Oceny.oc2, oc3: Oceny.oc2)

print("Dane studenta 1")
print("Podaj nazwisko")
var nazwisko = readLine()!
stud1.nazwisko = nazwisko
var ocena : Double
for i in 0..<3
{
    repeat{
        print("Podaj ocene")
        ocena = Double(readLine()!)!
    }
        while !Oceny.allCases.contains(Oceny(rawValue: ocena)!)
        switch i{
            case 0: stud1.oc1 = Oceny(rawValue: ocena)!
            case 1: stud1.oc2 = Oceny(rawValue: ocena)!
            default: stud1.oc3 = Oceny(rawValue: ocena)!
    }
}

print("Dane studenta 2")
print("Podaj nazwisko")
nazwisko = readLine()!
stud2.nazwisko = nazwisko
for i in 0..<3
{
    repeat{
        print("Podaj ocene")
        ocena = Double(readLine()!)!
    }
        while !Oceny.allCases.contains(Oceny(rawValue: ocena)!)
        switch i{
            case 0: stud2.oc1 = Oceny(rawValue: ocena)!
            case 1: stud2.oc2 = Oceny(rawValue: ocena)!
            default: stud2.oc3 = Oceny(rawValue: ocena)!
    }
}

print("Dane studenta 3")
print("Podaj nazwisko")
nazwisko = readLine()!
stud3.nazwisko = nazwisko
for i in 0..<3
{
    repeat{
        print("Podaj ocene")
        ocena = Double(readLine()!)!
    }
        while !Oceny.allCases.contains(Oceny(rawValue: ocena)!)
        switch i{
            case 0: stud3.oc1 = Oceny(rawValue: ocena)!
            case 1: stud3.oc2 = Oceny(rawValue: ocena)!
            default: stud3.oc3 = Oceny(rawValue: ocena)!
    }
}

var sr: [((nazwisko: String, oc1: Oceny, oc2: Oceny, oc3: Oceny),Double)] = []
var s: Double
s = (stud1.oc1.rawValue + stud1.oc2.rawValue + stud1.oc3.rawValue) / 3
sr.append((stud1,s))

s = (stud2.oc1.rawValue + stud2.oc2.rawValue + stud2.oc3.rawValue) / 3
sr.append((stud2,s))

s = (stud3.oc1.rawValue + stud3.oc2.rawValue + stud3.oc3.rawValue) / 3
sr.append((stud3,s))

let srSort = sr.sorted(by: {$0.1 > $1.1})
print(srSort)
*/
/*
enum Standard: Int, CaseIterable{
    case wysoki = 1
    case sredni = 2
    case niski = 3
}

var mieszkania: [(n: String, st:Standard)] = [("M1", .wysoki), ("M2", .sredni), ("M3", .niski), ("M4", .wysoki)]

let mieszSort = mieszkania.sorted(by: {$0.st.rawValue < $1.st.rawValue})
print(mieszSort)
*/
//Zadanie 3

var mieszkania: [((lokalizacja: String, powierzchnia:Double, cenaZaMetr:Double),cena: Double)] = []
print("Podaj liczbe mieszkan")
let liczbaMieszkan = Int(readLine()!)!
var loka: String
var powie: Double
var cena: Double
for _ in 0..<liczbaMieszkan
{
    print("Podaj lokalizacje mieszkania")
    loka = readLine()!
    print("Podaj powierzchnie mieszkania")
    powie = Double(readLine()!)!
    print("Podaj cene za metr")
    cena = Double(readLine()!)!
    mieszkania.append(((loka, powie, cena), powie * cena))
}

let mieszkaniaSorted = mieszkania.sorted(by: {$0.cena > $1.cena})
print(mieszkaniaSorted.first)
print(mieszkaniaSorted.last)
