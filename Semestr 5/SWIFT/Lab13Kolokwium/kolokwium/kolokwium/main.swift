//
//  main.swift
//  kolokwium
//
//  Created by student on 23/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

var kierowca1 = Kierowca(imie: "Adam", nazwisko: "Nowak", pesel: "00291411295", obywatelstwo: Obywatelstwo.polskie, zespol: Zespol.Mercedes, czasNajszybszegoOkrazenia: 100, liczbaNajlepszychPozycjiStartowych: 5, piecNajlepszychWynikow: [])

kierowca1.wyswietl()
kierowca1.dodajSezon(sezon: "2022", liczbaPunktow: 150)
kierowca1.wyswietl()

var kierowca2 = Kierowca(imie: "Adam", nazwisko: "Nowak", pesel: "01301511295", obywatelstwo: Obywatelstwo.wloskie, zespol: Zespol.Mercedes, czasNajszybszegoOkrazenia: 100, liczbaNajlepszychPozycjiStartowych: 10, piecNajlepszychWynikow: [(sezon: "2022", liczbaPunktow: 100)])
var kierowca3 = Kierowca(imie: "Janusz", nazwisko: "Nowak", pesel: "02271611295", obywatelstwo: Obywatelstwo.niemieckie, zespol: Zespol.Mercedes, czasNajszybszegoOkrazenia: 100, liczbaNajlepszychPozycjiStartowych: 15, piecNajlepszychWynikow: [(sezon: "2022", liczbaPunktow: 200)])
var kierowca4 = Kierowca(imie: "Jakub", nazwisko: "Nowak", pesel: "03241711295", obywatelstwo: Obywatelstwo.hiszpanskie, zespol: Zespol.Mercedes, czasNajszybszegoOkrazenia: 100, liczbaNajlepszychPozycjiStartowych: 20, piecNajlepszychWynikow: [(sezon: "2022", liczbaPunktow: 300)])
var kierowca5 = Kierowca(imie: "Marcin", nazwisko: "Nowak", pesel: "04221811295", obywatelstwo: Obywatelstwo.niemieckie, zespol: Zespol.Mercedes, czasNajszybszegoOkrazenia: 100, liczbaNajlepszychPozycjiStartowych: 30, piecNajlepszychWynikow: [(sezon: "2022", liczbaPunktow: 50), (sezon: "2021", liczbaPunktow: 100)])

print()
print("Kierowcy")
var kierowcy: [Kierowca] = [kierowca1, kierowca2, kierowca3, kierowca4, kierowca5]
kierowcy = kierowcy.sorted(by: { $0.liczbaNajlepszychPozycjiStartowych < $1.liczbaNajlepszychPozycjiStartowych})
for kierowca in kierowcy {
    kierowca.wyswietl()
}

print()
print("Ranking kierowcow")
var rankingKierowcow = RankingKierowcow(liczbaKierowcow: 5, kierowcy: kierowcy)
rankingKierowcow.wyswietlWszystkich()
print()
print("Kierowcy z Niemiec")
rankingKierowcow.wyswietlNiemcow()
print()
rankingKierowcow.wyswietlTrzechNajlepszych(sezony: ["2022", "2021", "2020"])
