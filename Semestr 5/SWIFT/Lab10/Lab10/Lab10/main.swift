//
//  main.swift
//  Lab10
//
//  Created by student on 12/12/2022.
//  Copyright © 2022 student. All rights reserved.
//

import Foundation
/*
//Zadanie 1
func Losuj() -> (Int, Int, Int)
{
    var liczby = (x1: 0, x2: 0, x3: 0)
    liczby.x1 = Int.random(in: 1...250)
    liczby.x2 = Int.random(in: 1...250)
    liczby.x3 = Int.random(in: 1...250)
    return liczby
}

func Max(x: Int, y: Int, z : Int) -> (Int)
{
    if(x>y && x>z){
        return x
    }else if(y>x && y>z){
        return y
    }else{
        return z
    }
}

func Min(x: Int, y: Int, z: Int) -> (Int)
{
    if(x<y && x<z){
        return x
    }else if(y<x && y<z){
        return y
    }else{
        return z
    }
}

func MinMax(x: Int, y: Int, z: Int) -> (Int, Int)
{
    var liczby = (x1: 0, x2: 0)
    liczby.x1 = Min(x: x,y: y,z: z)
    liczby.x2 = Max(x: x,y: y,z: z)
    return liczby
}

print(Min(x: 1,y: 2,z: 3))
print(Max(x: 1,y: 2,z: 3))
print(MinMax(x: 1,y: 2,z: 3))

//Zadanie 2
func Dodaj(x: Double, y: Double) -> Double
{
    return x+y
}

func Odejmij(x: Double, y: Double) -> Double
{
    return x-y
}

func Pomnoz(x: Double, y: Double) -> Double
{
    return x*y
}

func Podziel(x: Double, y: Double) -> Double
{
    if(y==0){
        print("Dzielenie przez 0!")
        return 0
    }
    return x/y
}

func Spierwiastkuj(x: Double) -> Double
{
    return sqrt(x)
}

var wybor = "-1"
while(wybor != "6")
{
    print("***MENU***")
    print("1 - dodawanie")
    print("2 - odejmowanie")
    print("3 - mnożenie")
    print("4 - dzielenie")
    print("5 - pierwiastkowanie")
    print("6 - wyjdz")
    wybor = readLine()!
    switch(wybor)
    {
    case "1":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Dodaj(x: liczba1, y: liczba2))
        break;
    case "2":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Odejmij(x: liczba1, y: liczba2))
        break;
    case "3":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Pomnoz(x: liczba1, y: liczba2))
        break;
    case "4":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Podziel(x: liczba1, y: liczba2))
        break;
    case "5":
        print("Podaj liczbe")
        let liczba = Double(readLine()!)!
        print(Spierwiastkuj(x: liczba))
        break;
    default:
        break
    }
}
*/
//Zadanie 3
func WczytajWspolrzedne() -> (Double, Double)
{
    var wspolrzedne = (x: 0.0, y: 0.0)
    print("Podaj wspolrzedna x")
    wspolrzedne.x = Double(readLine()!)!
    print("Podaj wspolrzedna y")
    wspolrzedne.y = Double(readLine()!)!
    return (wspolrzedne.x, wspolrzedne.y)
}

func Odleglosc(p1: (x: Double, y: Double), p2: (x: Double, y: Double)) -> (Double, Double)
{
    return (p1.x - p2.x, p1.y - p2.y)
}

func Cwiartka(p1: (x: Double, y: Double)) -> Int
{
    if(p1.x > 0 && p1.y > 0){
        return 1
    }else if(p1.x < 0 && p1.y > 0){
        return 2
    }else if(p1.x < 0 && p1.y < 0){
        return 3
    }else{
        return 4
    }
    
}

func Kwadrat(p1: (x: Double, y: Double), squareVertex: Double) -> String {
  let distance = sqrt(Double(p1.x * p1.x + p1.y * p1.y))
  if distance < Double(squareVertex) / 2.0 {
    return "Punkt lezy wewnatrz kwadratu"
  } else if distance == Double(squareVertex) / 2.0 {
    return "Punkt lezy na obwodzie kwadratu"
  } else {
    return "Punkt lezy poza obwodem kwadratu"
  }
}

var p1 = WczytajWspolrzedne()
var p2 = WczytajWspolrzedne()
print(p1)
print(p2)
print("Odleglosc: \(Odleglosc(p1: (p1.0, p1.1), p2: (p2.0, p2.1)))")
print("Punkt p1 jest w cwiartce: \(Cwiartka(p1: (p1.0, p1.1)))")
print(Kwadrat(p1: (p1.0, p1.1), squareVertex: 5))