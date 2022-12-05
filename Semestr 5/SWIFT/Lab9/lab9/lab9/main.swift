//
//  main.swift
//  lab9
//
//  Created by student on 05/12/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation
/*
//Zadanie 1
struct liczbaZespolona{
    var rec: Double;
    var uro: Double;
}

var liczbaZespolona1 = liczbaZespolona(rec: 0,uro: 0)
var liczbaZespolona2 = liczbaZespolona(rec: 0,uro: 0)
print("Pierwsza liczba urojona")
print("Podaj czesc rzeczywista")
liczbaZespolona1.rec = Double(readLine()!)!
print("Podaj czesc urojona")
liczbaZespolona1.uro = Double(readLine()!)!
print("Druga liczba urojona")
print("Podaj czesc rzeczywista")
liczbaZespolona2.rec = Double(readLine()!)!
print("Podaj czesc urojona")
liczbaZespolona2.uro = Double(readLine()!)!
var wybor = -1
var wynik = liczbaZespolona(rec: 0,uro: 0)
while(wybor != 0)
{
    wybor = -1
    print("MENU")
    print("0-wyjdz")
    print("1-dodaj")
    print("2-odejmij")
    print("3-pomnoz")
    wybor = Int(readLine()!)!
    switch(wybor)
    {
    case 1:
        wynik.rec = liczbaZespolona1.rec + liczbaZespolona2.rec
        wynik.uro = liczbaZespolona1.uro + liczbaZespolona2.uro
        break;
    case 2:
        wynik.rec = liczbaZespolona1.rec - liczbaZespolona2.rec
        wynik.uro = liczbaZespolona1.uro - liczbaZespolona2.uro
        break;
    case 3:
        wynik.rec = liczbaZespolona1.rec * liczbaZespolona2.rec
        wynik.uro = liczbaZespolona1.uro * liczbaZespolona2.uro
        break;
    default:
        break;
    }
    print("Wynik \(wynik.rec)+\(wynik.uro)")
}
*/
/*
//Zadanie 2
struct rzutOszczepem{
    var id: Int
    var p1: Double
    var p2: Double
    var p3: Double
}

var zawodnicy: [(rzutOszczepem, srednia: Double)] = []

for i in 1...4
{
    var zawodnik = rzutOszczepem(id: 0, p1: 0, p2: 0, p3: 0)
    print("Zawodnik \(i)")
    print("Podaj id")
    zawodnik.id = Int(readLine()!)!
    print("Podaj rzut 1")
    zawodnik.p1 = Double(readLine()!)!
    print("Podaj rzut 2")
    zawodnik.p2 = Double(readLine()!)!
    print("Podaj rzut 3")
    zawodnik.p3 = Double(readLine()!)!
    zawodnicy.append((zawodnik, (zawodnik.p1+zawodnik.p2+zawodnik.p3)/3.0))
}

var sorted = zawodnicy.sorted(by: {$0.srednia > $1.srednia})
print("\(sorted.first?.0.id): \(sorted.first?.0.p1),\(sorted.first?.0.p2),\(sorted.first?.0.p3) Srednia \(sorted.first?.srednia)")
sorted.removeLast()
*/
/*
//Zadanie 3
var samochody: Set = ["A3", "A4", "X3", "Polo", "Golf", "Cooper"]

for i in samochody{
    print(i)
}

print("Podaj model samochodu do usuniecia")
let doUsuniecia = readLine()!
if let samochodDoUsuniecia = samochody.remove(doUsuniecia){
    print("Usunieto \(samochodDoUsuniecia)")
    for i in samochody{
        print(i)
    }
}
else{
     print("Element nie istnieje")
}
*/
/*
//Zadanie 4
var student: [String: String] = [:]
for i in 1...5
{
    print("Dane studenta \(i)")
    print("Podaj identyfikator")
    let identyfikator = readLine()!
    print("Podaj nazwisko")
    let nazwisko = readLine()!
    student[identyfikator] = nazwisko
}

for (id, nazwisko) in student{
    print("ID: \(id) Nazwisko: \(nazwisko)")
}

print("Podaj identyfikator studenta do znalezienia")
let doZnalezienia = readLine()!
if student[doZnalezienia] != nil {
    print(student[doZnalezienia] as Any)
} else {
    print("Element nie istnieje")
}

print("Podaj identyfikator studenta do usuniecia")
let doUsuniecia = readLine()!
if let usunietyElem = student.removeValue(forKey: doUsuniecia) {
    print("Usunięto \(usunietyElem)")
    for (id, nazwisko) in student{
        print("ID: \(id) Nazwisko: \(nazwisko)")
    }
} else {
    print("Element nie istnieje")
}
*/
//Zadanie 5
struct loty{
    var wylot: [Int:String]
    var przylot: [Int:String]
    var czas: Double
}

var tabLoty: [loty] = []
print("Podaj ilosc lotow")
guard let n = Int(readLine()!) else {
    fatalError("To nie jest liczba calkowita")
}
if(n > 0){
    for _ in 1...n{
        var lot = loty(wylot: [:], przylot: [:], czas: 0)
        print("Wylot")
        print("Podaj numer lotniska")
        guard let wNumer = Int(readLine()!) else{
            fatalError("To nie jest liczba calkowita")
        }
        print("Podaj nazwe lotniska")
        let wNazwa = readLine()
        lot.wylot[wNumer] = wNazwa
        print("Przylot")
        print("Podaj numer lotniska")
        guard let pNumer = Int(readLine()!) else{
            fatalError("To nie jest liczba calkowita")
        }
        print("Podaj nazwe lotniska")
        let pNazwa = readLine()
        lot.przylot[pNumer] = pNazwa
        print("Podaj czas podrozy w minutach")
        guard let czas = Double(readLine()!) else{
            fatalError("To nie jest liczba zmiennoprzecinkowa")
        }
        lot.czas = czas
        tabLoty.append(lot)
    }
    var srednia: Double = 0
    for i in tabLoty{
        print(i)
        srednia += i.czas
    }
    print("Loty trwajace dluzej niz srednia")
    srednia /= Double(tabLoty.count)
    for i in tabLoty{
        if(i.czas > srednia){
            print(i)
        }
    }
    for (index, lot) in tabLoty.enumerated().reversed() {
        if(lot.czas < srednia){
            tabLoty.remove(at: index)
        }
    }
    print("Loty po usuniecie krotszych niz srednia")
    for i in tabLoty{
        print(i)
    }
}
