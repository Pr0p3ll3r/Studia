//
//  rankingkierowcow.swift
//  kolokwium
//
//  Created by student on 23/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

class RankingKierowcow
{
    var liczbaKierowcow: Int = 0
    var kierowcy: [Kierowca] = []
    
    init(liczbaKierowcow: Int, kierowcy: [Kierowca])
    {
        self.liczbaKierowcow = liczbaKierowcow
        self.kierowcy = kierowcy
    }
    
    func wyswietlWszystkich()
    {
        for kierowca in kierowcy {
            kierowca.wyswietl()
        }
    }
    
    func wyswietlNiemcow()
    {
        for kierowca in kierowcy {
            if(kierowca.obywatelstwo == Obywatelstwo.niemieckie) {
                kierowca.wyswietl()
            }
        }
    }
    
    func wyswietlTrzechNajlepszych(sezony: [String])
    {
        for sezon in sezony {
            var kierowcySezon: [(kierowca: Kierowca, liczbaPunktow: Int)] = []
            for kierowca in kierowcy {
                for wynik in kierowca.piecNajlepszychWynikow {
                    if (wynik.sezon == sezon){
                        kierowcySezon.append((kierowca, wynik.liczbaPunktow))
                    }
                }
            }
            kierowcySezon = kierowcySezon.sorted(by: { $0.liczbaPunktow > $1.liczbaPunktow })
            if(kierowcySezon.count == 0) {
                print("Nie ma danych o kierowcach w sezonie \(sezon)")
            }
            else if(kierowcySezon.count < 3) {
                print(sezon)
                for k in kierowcySezon {
                    k.kierowca.wyswietl()
                }
            }
            else {
                print(sezon)
                for i in 0..<3 {
                    kierowcySezon[i].kierowca.wyswietl()
                }
            }
            print()
        }
    }
}
