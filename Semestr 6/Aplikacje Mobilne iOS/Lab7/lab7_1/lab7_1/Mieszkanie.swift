//
//  Mieszkanie.swift
//  lab7_1
//
//  Created by student on 18/04/2023.
//  Copyright © 2023 PL. All rights reserved.
//

import Foundation
import UIKit

struct Mieszkanie {
    var nazwa: String
    var powierzchnia: Double
    var liczbaPokoi: Int
    var czyDwupoziomowy: Bool
    var obraz: UIImage
    
    init(nazwa: String, powierzchnia: Double, liczbaPokoi: Int, czyDwupoziomowy: Bool, obraz: UIImage) {
        self.nazwa = nazwa
        self.powierzchnia = powierzchnia
        self.liczbaPokoi = liczbaPokoi
        self.czyDwupoziomowy = czyDwupoziomowy
        self.obraz = obraz
    }
}
