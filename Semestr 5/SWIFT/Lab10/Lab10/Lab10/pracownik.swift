//
//  pracownik.swift
//  Lab10
//
//  Created by student on 19/12/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

enum Stanowisko
{
    case kierownik
    case programista
    case grafik
}

class Pracownik: Osoba {
    var rok_zatrudnienia: Int = 0
    var stanowisko: Stanowisko = Stanowisko.kierownik
    var zaH: Double = 0.0
    var zrealizowane_godziny: Int = 0
    var nazwa_firmy: String = ""
    
    init(imie: String, nazwisko: String, rok_urodzenia: Int, rok_zatrudnienia: Int, stanowisko: Stanowisko, zaH: Double, zrealizowane_godziny: Int, nazwa_firmy: String)
    {
        super.init(imie: imie, nazwisko: nazwisko, rok_urodzenia: rok_urodzenia)
        self.rok_zatrudnienia = rok_zatrudnienia
        self.stanowisko = stanowisko
        self.zaH = zaH
        self.zrealizowane_godziny = zrealizowane_godziny
        self.nazwa_firmy = nazwa_firmy
    }
    
    func ileLatWFirmie() -> Int
    {
        let current_year = Calendar.current.component(.year, from: Date())
        return current_year - rok_zatrudnienia
    }
    
    func pensja() -> Double
    {
        return Double(zrealizowane_godziny) * zaH
    }
    
    override func wyswietl()
    {
        print("Imie: \(imie) Nazwisko: \(nazwisko) Rok urodzenia: \(rok_urodzenia)")
        print("Rok zatrudnienia : \(rok_zatrudnienia) stanowisko: \(stanowisko) Nazwa firmy: \(nazwa_firmy)")
    }
}
