//
//  osoba.swift
//  kolokwium
//
//  Created by student on 23/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

enum Obywatelstwo
{
    case hiszpanskie
    case niemieckie
    case polskie
    case wloskie
}

class Osoba
{
    var imie: String = ""
    var nazwisko: String = ""
    var pesel: String = ""
    var obywatelstwo: Obywatelstwo = Obywatelstwo.polskie
    
    init(imie: String, nazwisko: String, pesel: String, obywatelstwo: Obywatelstwo)
    {
        self.imie = imie
        self.nazwisko = nazwisko
        self.pesel = pesel
        self.obywatelstwo = obywatelstwo
    }
    
    func wiek(data: Date) -> Int
    {
        let year = pesel[pesel.index(pesel.startIndex, offsetBy: 0)...pesel.index(pesel.startIndex, offsetBy: 1)]
        let month = pesel[pesel.index(pesel.startIndex, offsetBy: 2)...pesel.index(pesel.startIndex, offsetBy: 3)]
        let day = pesel[pesel.index(pesel.startIndex, offsetBy: 4)...pesel.index(pesel.startIndex, offsetBy: 5)]
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy/MM/dd"
        let birthDate = formatter.date(from: "20\(year)/\(Int(month)! - 20)/\(day)")
        return Calendar.current.dateComponents([.year], from: birthDate!, to: data).year!
    }
    
    func wyswietl()
    {
        print("Imie: \(imie) Nazwisko: \(nazwisko) Pesel: \(pesel) Obywatelstwo: \(obywatelstwo)")
    }
}
