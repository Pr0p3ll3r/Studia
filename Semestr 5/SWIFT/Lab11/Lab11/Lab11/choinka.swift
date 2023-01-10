//
//  choinka.swift
//  Lab11
//
//  Created by student on 09/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

class Choinka : Drzewo
{
    var liczbaPoziomow: Int = 0
    var wysokoscPnia: Int = 0
    var liczbaOzdob: Int = 0
    var rodzajOzdoby: Ozdoba = Ozdoba.bombka
    
    init(wysokosc: Int, rodzajDrzewa: RodzajDrzewa, rokZasadzenia: Int, liczbaPoziomow: Int, wysokoscPnia: Int, liczbaOzdob: Int, rodzajOzdoby: Ozdoba)
    {
        super.init(wysokosc: wysokosc, rodzajDrzewa: rodzajDrzewa, rokZasadzenia: rokZasadzenia)
        self.liczbaPoziomow = liczbaPoziomow
        self.wysokoscPnia = wysokoscPnia
        self.liczbaOzdob = liczbaOzdob
        self.rodzajOzdoby = rodzajOzdoby
    }
    
    override func wyswietl()
    {
        print("Rodzaj drzewa: \(rodzajDrzewa.rawValue) Wysokosc: \(wysokosc) Rok zasadzenia: \(rokZasadzenia) Liczba poziomow: \(liczbaPoziomow) Wysokosc pnia: \(wysokoscPnia) Liczba ozdob: \(liczbaOzdob) Rodzaj ozdoby: \(rodzajOzdoby)")
    }
    
    func rysujChoinke(layercount:Int, levelcount:Int)
    {
        let length = layercount * levelcount
        var starcount = 1
        var spacecount = length
        for _ in 1...layercount {
            for _ in 1...levelcount {
                    for _ in 1...spacecount{
                        print(" ",terminator: "")
                    }
                    for _ in 1...starcount {
                        print("*",terminator: "")
                    }
                    print()
                    starcount += 2
                    spacecount -= 1
            }
            starcount = starcount - 2
            spacecount = spacecount + 1
            if levelcount <= 3 {
                starcount -= 2
                spacecount += 1
            } else {
                starcount -= 4
                spacecount += 2
            }
        }
        spacecount = length;
        for _ in 1...wysokoscPnia {
            for _ in 1...spacecount-1 {
                print(" ",terminator: "")
            }
            for _ in 1...3 {
                print("#",terminator: "")
            }
            print()
        }
    }
    
    func rysujOzdobionaChoinke(layercount:Int, levelcount:Int)
    {
        let length = layercount * levelcount
        var starcount = 1
        var spacecount = length
        var decorationcount = liczbaOzdob
        for _ in 1...layercount {
            for _ in 1...levelcount {
                    for _ in 1...spacecount{
                        print(" ",terminator: "")
                    }
                    for i in 1...starcount {
                        if decorationcount == 0 {
                            print("*",terminator: "")
                        }else if i % 2 != 0 {
                            print("*",terminator: "")
                        } else if (decorationcount > 0){
                            print("o",terminator: "")
                            decorationcount -= 1;
                        }
                    }
                    print()
                    starcount += 2
                    spacecount -= 1
            }
            starcount = starcount - 2
            spacecount = spacecount + 1
            if levelcount <= 3 {
                starcount -= 2
                spacecount += 1
            } else {
                starcount -= 4
                spacecount += 2
            }
        }
        spacecount = length;
        for _ in 1...wysokoscPnia {
            for _ in 1...spacecount-1 {
                print(" ",terminator: "")
            }
            for _ in 1...3 {
                print("#",terminator: "")
            }
            print()
        }
    }
    
    func ozdobyDoKupienia(layercount:Int, levelcount:Int) -> Int
    {
        var starcount = 1
        var decorationcount = liczbaOzdob
        var decorationtobuy = 0
        for _ in 1...layercount {
            for _ in 1...levelcount {
                    for i in 1...starcount {
                        if decorationcount == 0 {
                            decorationtobuy += 1
                        }else if i % 2 == 0 {
                            decorationcount -= 1;
                        }
                    }
                    starcount += 2
            }
            starcount = starcount - 2
            if levelcount <= 3 {
                starcount -= 2
            } else {
                starcount -= 4
            }
        }
        return decorationtobuy
    }
}
