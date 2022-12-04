//
//  main.swift
//  lab5
//
//  Created by student on 07/11/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation

//Zadanie 1
var licz : Int
var x1 : Int = 1
var x2 : Int = 1
var x3 : Int
print("Podaj liczbe")
licz = Int(readLine()!)!
if(x1 < licz)
{
    print("Elementy ciagu")
    print(x1)
    print(x2)
    x3 = x1 + x2
    while x3 < licz
    {
        print(x3)
        x1 = x2
        x2 = x3
        x3 = x1 + x2
    }
}

//Zadanie 2
var liczba : Int
var podzielna : Bool = false
print("Podaj liczbe")
liczba = Int(readLine()!)!
if(liczba < 2)
{
     print("Nie jest to liczba pierwsza")
}
else
{
    for i in 2...
    {
        if(i*i>liczba){
            break;
        }
        if(liczba%i==0)
        {
            print("Nie jest to liczba pierwsza")
            podzielna = true;
            break;
        }
    }
    if(!podzielna)
    {
        print("Jest to liczba pierwsza")
    }
}

//Zadanie 3
var liczba1 : String
var srednia : Double = 1
print("Podaj liczbe")
liczba1 = readLine()!
if(liczba1.count >= 3)
{
    for char in liczba1
    {
        srednia *= Double(String(char))!
    }
    srednia = pow(srednia, Double(1/Double(liczba1.count)))
    print("Srednia geometryczna: \(srednia)")
}

//Zadanie 4
var ciag : String
print("Podaj wyraz")
ciag = readLine()!
for char in ciag
{
    
}
