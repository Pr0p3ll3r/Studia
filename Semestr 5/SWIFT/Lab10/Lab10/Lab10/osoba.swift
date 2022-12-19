//
//  osoba.swift
//  Lab10
//
//  Created by student on 19/12/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

class Osoba {
    var imie: String = ""
    var nazwisko: String = ""
    var rok_urodzenia: Int = 0
    
    init(imie: String, nazwisko: String, rok_urodzenia: Int)
    {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rok_urodzenia = rok_urodzenia
    }
    
    func wiek() -> Int {
        let current_year = Calendar.current.component(.year, from: Date())
        return current_year - rok_urodzenia
    }
    
    func wyswietl()
    {
        print("Imie: \(imie) Nazwisko: \(nazwisko) Rok urodzenia: \(rok_urodzenia)")
    }
}
