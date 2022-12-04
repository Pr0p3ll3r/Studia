//
//  main.swift
//  FirstCommandLine
//
//  Created by student on 03/10/2022.
//  Copyright © 2022 PL. All rights reserved.
//

import Foundation

var suma: Int
var srednia: Float
suma = 0
for _ in 1...3  {
    let liczba = Int.random(in: 1..<100)
    suma+=liczba
    print("Wygenerowana liczba: ", liczba)
}
srednia = (Float)(suma)/3
print("Suma wynosi: ", suma)
print("Srednia wynosi ", srednia)


print(String(format: "Srednia: %.5f", srednia))
