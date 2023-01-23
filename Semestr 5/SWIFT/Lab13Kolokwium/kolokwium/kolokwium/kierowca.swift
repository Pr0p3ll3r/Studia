//
//  kierowca.swift
//  kolokwium
//
//  Created by student on 23/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

enum Zespol
{
    case Mercedes
    case Ferrari
    case AlfaRomeo
    case RedBull
    case McLaren
    case Williams
}

class Kierowca : Osoba
{
    var zespol: Zespol = Zespol.Mercedes
    var czasNajszybszegoOkrazenia: Int = 0
    var liczbaNajlepszychPozycjiStartowych: Int = 0
    var piecNajlepszychWynikow: [(sezon: String, liczbaPunktow: Int)] = []
    
    init(imie: String, nazwisko: String, pesel: String, obywatelstwo: Obywatelstwo, zespol: Zespol, czasNajszybszegoOkrazenia: Int, liczbaNajlepszychPozycjiStartowych: Int, piecNajlepszychWynikow: [(sezon: String, liczbaPunktow: Int)])
    {
        self.zespol = zespol
        self.czasNajszybszegoOkrazenia = czasNajszybszegoOkrazenia
        self.liczbaNajlepszychPozycjiStartowych = liczbaNajlepszychPozycjiStartowych
        self.piecNajlepszychWynikow = piecNajlepszychWynikow
        super.init(imie: imie, nazwisko: nazwisko, pesel: pesel, obywatelstwo: obywatelstwo)
    }
    
    override func wyswietl()
    {
        super.wyswietl()
        print("Zespol: \(zespol) Czas najszybszego okrazenia: \(czasNajszybszegoOkrazenia) Liczba najlepszych pozycji startowych: \(liczbaNajlepszychPozycjiStartowych) Piec najlepszych wynikow: \(piecNajlepszychWynikow)")
    }
    
    func dodajSezon(sezon: String, liczbaPunktow: Int)
    {
        if(piecNajlepszychWynikow.count == 5)
        {
            for i in 0..<piecNajlepszychWynikow.count {
                if(piecNajlepszychWynikow[i].liczbaPunktow < liczbaPunktow) {
                    piecNajlepszychWynikow[i].sezon = sezon
                    piecNajlepszychWynikow[i].liczbaPunktow = liczbaPunktow
                    break;
                }
            }
            print("Wszystkie wyniki w tabeli sa lepsze niz podany")
        }
        else
        {
            piecNajlepszychWynikow.append((sezon: sezon, liczbaPunktow: liczbaPunktow))
        }
        piecNajlepszychWynikow = piecNajlepszychWynikow.sorted(by: { $0.liczbaPunktow < $1.liczbaPunktow})
    }
}
