//
//  main.swift
//  Lab11
//
//  Created by student on 09/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation

var choinka = Choinka(wysokosc: 5, rodzajDrzewa: RodzajDrzewa.iglaste, rokZasadzenia: 1900, liczbaPoziomow: 4, wysokoscPnia: 2, liczbaOzdob: 27, rodzajOzdoby: Ozdoba.bombka)

choinka.rysujOzdobionaChoinke(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)

var decorationstobuy = choinka.ozdobyDoKupienia(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)

print("Nalezy dokupic \(decorationstobuy) ozdob")
choinka.liczbaOzdob += decorationstobuy

choinka.rysujOzdobionaChoinke(layercount: choinka.wysokosc, levelcount: choinka.liczbaPoziomow)
