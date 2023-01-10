//
//  drzewo.swift
//  Lab11
//
//  Created by student on 09/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

enum Ozdoba : String, CaseIterable
{
    case bombka = "bombka"
    case cukierek = "cukierek"
    case pierniczek = "pierniczek"
    case zabawka = "zabawka"
}

enum RodzajDrzewa : String, CaseIterable
{
    case lisciaste = "lisciaste"
    case iglaste = "iglaste"
}

class Drzewo
{
    var wysokosc: Int = 0
    var rodzajDrzewa: RodzajDrzewa = RodzajDrzewa.iglaste
    var rokZasadzenia: Int = 0
    init(wysokosc: Int, rodzajDrzewa: RodzajDrzewa, rokZasadzenia: Int)
    {
        self.wysokosc = wysokosc;
        switch(rodzajDrzewa)
        {
            case .iglaste:
                self.rodzajDrzewa = .iglaste
                break
            case .lisciaste:
                self.rodzajDrzewa = .lisciaste
                break
        }
        self.rokZasadzenia = rokZasadzenia;
    }
    func wyswietl()
    {
        print("Rodzaj drzewa: \(rodzajDrzewa.rawValue) Wysokosc: \(wysokosc) Rok zasadzenia: \(rokZasadzenia)")
    }
}
