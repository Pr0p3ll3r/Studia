//
//  main.swift
//  Lab2
//
//  Created by student on 10/10/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

//Zadanie 1
let rokAktualny = 2022
var rok: Int
var lata: Int

print("Podaj rok urodzenia")
rok = Int(readLine()!)!

lata = rokAktualny - rok
print("Masz \(lata) lat")

//Zadanie 2
let pi: Double = 3.14
var r: Double
var pole: Double
var obwod: Double

print("Podaj promien kola")
r = Double(readLine()!)!
pole = pi * r * r
obwod = 2 * pi * r

print(String(format: "Pole wynosi %.2f", pole), String(format: "a obwod %.2f", obwod))

//Zadanie 3
var aSz: Double
var poleSz: Double
var objetosc: Double

print("Podaj bok szescianu")
aSz = Double(readLine()!)!
poleSz = 6 * aSz * aSz
objetosc = pow(aSz,3)

print(String(format: "Pole wynosi %.2f", poleSz), String(format: "a objetosc %.2f", objetosc))

//Zadanie 4
var a,b,z,s,cena,ileMetrow,jakaCena: Double

print("Podaj szerokosc pokoju")
a = Double(readLine()!)!
print("Podaj dlugosc pokoju")
b = Double(readLine()!)!
print("Podaj dlugosc korytarza")
z = Double(readLine()!)!
print("Podaj szerokosc drzwi")
s = Double(readLine()!)!
print("Podaj cene listwy za metr biezacy")
cena = Double(readLine()!)!

ileMetrow = 2 * a + 4 * b + 2 * z - 2 * s
jakaCena = ileMetrow * cena

print("Potrzeba \(ileMetrow) metrow biezacych listwy, a cena listwy wynosi \(jakaCena)")


//Zadanie 5
var srednia: Double
var w,x,y: Int
w = Int.random(in: 1...9)
x = Int.random(in: 1...9)
y = Int.random(in: 1...9)
srednia = Double(w+x+y)/3.0

print("Wylosowanie liczby to \(w) \(x) \(y), srednia wynosi \(srednia)")


//Zadanie 6
var sredniaWaz: Double
var o1, o2, o3, w1, w2, w3: Int
print("Podaj 1 ocene")
o1 = Int(readLine()!)!
print("Podaj wage 1 oceny")
w1 = Int(readLine()!)!
print("Podaj 2 ocene")
o2 = Int(readLine()!)!
print("Podaj wage 2 oceny")
w2 = Int(readLine()!)!
print("Podaj 3 ocene")
o3 = Int(readLine()!)!
print("Podaj wage 3 oceny")
w3 = Int(readLine()!)!
sredniaWaz = Double(o1*w1 + o2*w2 + o3*w3)/Double(w1+w2+w3)

print("Srednia wazona wynosi \(sredniaWaz)")
