//
//  main.swift
//  lab6
//
//  Created by student on 14/11/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

//Zadanie 1
var tab: [Int] = Array(repeating: 1, count: 12)
    for i in tab {
    print(i)
}

//Zadanie 2
var liczba: Int
var tab2: [Int] = []
for i in 0..<10 {
    tab2.append(Int.random(in: 1...100))
    print(tab2[i])
}

print("Podaj liczbe")
liczba = Int(readLine()!)!
tab2.insert(liczba, at: 0)
for i in tab2 {
    print(i)
}

tab2.insert(liczba, at: Int.random(in: 0..<tab.count))
for i in tab2 {
    print(i)
}

//Zadanie 3
var tab3: [Int] = []
var wielkosc: Int
print("Podaj wielkosc")
wielkosc = Int(readLine()!)!
if(wielkosc > 0) {
    for _ in 1...wielkosc
    {
        print("Podaj liczbe")
        tab3.append(Int(readLine()!)!)
    }
}
for i in tab3{
    if(tab3.first == 1){
        print("Pierwszy element tablicy")
    }
    if(tab3.last == wielkosc){
        print("Ostatni element tablicy")
    }
}

//Zadanie 4
print("Podaj wielkosc")
var tab4: [Int] = []
var tab5: [Int] = []
wielkosc = Int(readLine()!)!
if(wielkosc > 0) {
    for _ in 0..<wielkosc {
        tab4.append(Int.random(in: 1...20))
        tab5.append(Int.random(in: 1...20))
    }
}
tab4.sort()
tab5.sort()
var takieSame : Bool = true;
for i in 0..<wielkosc {
    if(tab4[i] != tab5[i]){
        takieSame = false;
        break;
    }
}
if(takieSame){
    print("Tablice zawieraja identyczne elementy")
}
else{
    print("Tablice nie zawieraja identycznych elementow")
}

//Zadanie 5
let mac: [[Int]] = [[10, 20, 30], [40, 50, 60]]
for i in 0 ..< mac.count {
    for j in 0 ..< mac[i].count{
        print("\(mac[i][j])", terminator:" ")
    }
    print()
}

//Zadanie 6
print("Podaj liczbe wierszy")
let wie = Int(readLine()!)!
print("Podaj liczbe kolumn")
let kol = Int(readLine()!)!
var mac2: [[Float]] = [[]]
for i in 0 ..< wie{
    for _ in 0 ..< kol{
        mac2[i].append(Float.random(in: -100...100))
    }
    
}
for i in 0 ..< mac2.count {
    for j in 0 ..< mac2[i].count{
        print("\(mac[i][j])", terminator:" ")
    }
    print()
}
