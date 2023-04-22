//
//  Dom.swift
//  lab7_2
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import Foundation

struct Dom: Hashable {
    var nazwa: String
    var powierzchnia: Double
    var liczbaPokoi: Int
    var wielkoscDzialki: Double
    var liczbaPieter: Int
    var obraz: String
    
    init(nazwa: String, powierzchnia: Double, liczbaPokoi: Int, wielkoscDzialki: Double, liczbaPieter: Int, obraz: String) {
        self.nazwa = nazwa
        self.powierzchnia = powierzchnia
        self.liczbaPokoi = liczbaPokoi
        self.wielkoscDzialki = wielkoscDzialki
        self.liczbaPieter = liczbaPieter
        self.obraz = obraz
    }
}
