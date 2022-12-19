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
        break
    case "2":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Odejmij(x: liczba1, y: liczba2))
        break
    case "3":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Pomnoz(x: liczba1, y: liczba2))
        break
    case "4":
        print("Podaj 1 liczbe")
        let liczba1 = Double(readLine()!)!
        print("Podaj 2 liczbe")
        let liczba2 = Double(readLine()!)!
        print(Podziel(x: liczba1, y: liczba2))
        break
    case "5":
        print("Podaj liczbe")
        let liczba = Double(readLine()!)!
        print(Spierwiastkuj(x: liczba))
        break
    default:
        break
    }
}
*/
/*
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

func SprawdzPunkt(point: (x: Int, y: Int), wspolrzednaKwadratu: Int)
{
    let topRightCorner = (x: wspolrzednaKwadratu, y: wspolrzednaKwadratu)
    let topLeftCorner = (x: -wspolrzednaKwadratu, y: wspolrzednaKwadratu)
    let bottomRightCorner = (x: wspolrzednaKwadratu, y: -wspolrzednaKwadratu)
    let bottomLeftCorner = (x: -wspolrzednaKwadratu, y: -wspolrzednaKwadratu)

    if point.x > topLeftCorner.x && point.x < topRightCorner.x && point.y > bottomLeftCorner.y && point.y < topLeftCorner.y {
        print("Punkt jest w srodku kwadratu")
    } else if point.x == topLeftCorner.x || point.x == topRightCorner.x || point.y == bottomLeftCorner.y || point.y == topLeftCorner.y {
        print("Punkt jest na obwodzie kwadratu")
    } else {
       print("Punkt jest poza kwadratem")
    }
}

var p1 = WczytajWspolrzedne()
var p2 = WczytajWspolrzedne()
print(p1)
print(p2)
print("Odleglosc: \(Odleglosc(p1: (p1.0, p1.1), p2: (p2.0, p2.1)))")
print("Punkt p1 jest w cwiartce: \(Cwiartka(p1: (p1.0, p1.1)))")
SprawdzPunkt(point: (x: 1, y: 1), squareVertex: 2)
*/
//Zadanie 4
/*
func WczytajTablice(n: Int) -> [Int]
{
    var tab: [Int] = []
    for _ in 0..<n {
        print("Podaj liczbe")
        let liczba = Int(readLine()!)!
        tab.append(liczba)
    }
    return tab
}

func WyswietlTablice(tab: [Int])
{
    for i in tab {
        print(i)
    }
}

func MinTab(tab: [Int]) -> (Int, Int)
{
    var min = Int.max
    var index = -1
    for i in 0..<tab.count {
        if  (tab[i] < min){
            min = tab[i]
            index = i
        }
    }
    return (min, index)
}

func MaxTab(tab: [Int]) -> (Int, Int)
{
    var max = Int.min
    var index = -1
    for i in 0..<tab.count {
        if (tab[i] > max){
            max = tab[i]
            index = i
        }
    }
    return (max, index)
}

func Zamien(tab: inout [Int])
{
    let min: (wartosc: Int, index: Int) = MinTab(tab: tab)
    let max: (wartosc: Int, index: Int) = MaxTab(tab: tab)
    tab.swapAt(min.index, max.index)
}

func Srednia(tab: [Int]) -> (Double)
{
    var srednia: Double = 0
    for i in tab {
        srednia += Double(i)
    }
    return srednia/Double(tab.count)
}

print("Podaj liczbe elementow tablicy")
var n = Int(readLine()!)!
var tab = WczytajTablice(n: n)
WyswietlTablice(tab: tab)
var min: (wartosc: Int, index: Int)
var max: (wartosc: Int, index: Int)
var srednia = Srednia(tab: tab)
min = MinTab(tab: tab)
max = MaxTab(tab: tab)
print("Max \(max.wartosc) na indexie \(max.index)")
print("Min \(min.wartosc) na indexie \(min.index)")
print("Srednia \(srednia)")
Zamien(tab: &tab)
print("Po zamianie miejscami")
WyswietlTablice(tab: tab)
*/
/* Data difference
let formatter = DateFormatter()
formatter.dateFormat = "yyyy/MM/DD"
let data1 = formatter.date(from: "2022/12/19")
let data2 = formatter.date(from: "2022/11/01")
let dif = Calendar.current.dateComponents([.year, .month, .day], from: data1!, to: data2!)
print(dif)
*/
//Zadanie 5
var o1 = Osoba(imie: "Adam", nazwisko: "Nowak", rok_urodzenia: 2000)
var o2 = Osoba(imie: "Ola", nazwisko: "Nowak", rok_urodzenia: 2001)
o1.wyswietl()
o2.wyswietl()
if(o1.wiek() > o2.wiek()){
    print("\(o1.imie) jest starszy")
    print("\(o2.imie) jest mlodsza")
}else if(o2.wiek() > o1.wiek()){
    print("\(o2.imie) jest starsza")
    print("\(o1.imie) jest mlodszy")
}else{
    print("Sa w tym samym wieku")
}

//Zadanie 6
var prac1 = Pracownik(imie: "Adam", nazwisko: "Nowak", rok_urodzenia: 2000, rok_zatrudnienia: 2020, stanowisko: Stanowisko.programista, zaH: 25, zrealizowane_godziny: 100, nazwa_firmy: "Kox")
prac1.wyswietl()
print(prac1.ileLatWFirmie())
print(prac1.pensja())
