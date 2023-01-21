//
//  main.swift
//  Lab11
//
//  Created by student on 09/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

var prostokat = Prostokat(a: 4, b: 7)
prostokat.wyswietl()

var prostopadloscian = Prostopadloscian(a: 4, b: 7, c: 8)
prostopadloscian.wyswietl()

func wczytajStudenta() -> Student
{
    let student: Student = Student()
    var kierunek: String
    print("Podaj imie")
    student.imie = readLine()!
    print("Podaj nazwisko")
    student.nazwisko = readLine()!
    print("Podaj rok urodzenia")
    student.rok_urodzenia = Int(readLine()!)!
    print("Podaj numer indeksu")
    student.numerIndeksu = readLine()!
    repeat{
        print(Kierunek.allCases)
        print("Podaj kierunek")
        kierunek = readLine()!
    }while !Kierunek.allCases.contains(Kierunek(rawValue: kierunek)!)
    student.kierunek = Kierunek(rawValue: kierunek)!
    print("Podaj rok studiow")
    student.rok = Int(readLine()!)!
    print("Podaj 5 ocen (2, 3, 3.5, 4, 4.5, 5)")
    for i in 1...5{
        var ocena = 0.0
        while(ocena != 2 && ocena != 3 && ocena != 3.5 && ocena != 4 && ocena != 4.5 && ocena != 5)
        {
            print("Podaj \(i) ocene")
            ocena = Double(readLine()!)!
        }
        student.oceny.append(ocena)
    }
    return student
}

var n: Int = 0
var studenci: [Student] = []
print("Podaj liczbe studentow")
n = Int(readLine()!)!
for _ in 0..<n {
    studenci.append(wczytajStudenta())
}

func wyswietlStudentow(kierunek: Kierunek, studenci: [Student]) 
{
    for student in studenci
    {
        if(student.kierunek == kierunek) {
            student.wyswietl()
        }
    }
}

var kierunekDoWyszukania: Kierunek
print("Podaj kierunek")
kierunekDoWyszukania = Kierunek(rawValue: readLine()!)!
wyswietlStudentow(kierunek: kierunekDoWyszukania, studenci: studenci)

let formatter = DateFormatter()
formatter.dateFormat = "dd/MM/yyyy"
let dataRozpoczecia = formatter.date(from: "21/01/2023")!
let dataZakonczenia = formatter.date(from: "21/02/2023")!

var student2 = StudentNaErasmusie(imie: "Adam", nazwisko: "Nowak", rok_urodzenia: 1999, numerIndeksu: "12345", kierunek: Kierunek.Informatyka, rok: 3, oceny: [2,3,3,4,3.5], nazwaUczelni: "Politechnika Lubelska", dataRozpoczecia: dataRozpoczecia, dataZakonczenia: dataZakonczenia, kursy: [(nazwa: "Przedmiot1", ocena: 4.5), (nazwa: "Przedmiot2", ocena: 3.5), (nazwa: "Przedmiot1", ocena: 3)])

student2.wyswietl()
print("Spedzil na Erasmusie \(student2.czasSpedzony()) dni")
print("Ocena: \(student2.ocena())")


//Zadanie swiateczne
var choinka = Choinka(wysokosc: 5, rodzajDrzewa: RodzajDrzewa.iglaste, rokZasadzenia: 1900, liczbaPoziomow: 4, wysokoscPnia: 2, liczbaOzdob: 27, rodzajOzdoby: Ozdoba.bombka)

choinka.rysujOzdobionaChoinke(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)

var decorationstobuy = choinka.ozdobyDoKupienia(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)

print("Nalezy dokupic \(decorationstobuy) ozdob")
choinka.liczbaOzdob += decorationstobuy

choinka.rysujOzdobionaChoinke(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)
