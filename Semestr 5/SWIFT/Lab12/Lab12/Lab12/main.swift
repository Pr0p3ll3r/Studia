//
//  main.swift
//  Lab12
//
//  Created by student on 16/01/2023.
//  Copyright © 2023 student. All rights reserved.
//

import Foundation
//Zadanie 1
protocol LiczbaZespolona
{
    var re: Double {get}
    var im: Double {get}
}

class OperacjeNaLiczbachZespolonych: LiczbaZespolona
{
    var re: Double = 0.0
    var im: Double = 0.0
    init(re: Double, im: Double){
        self.re = re;
        self.im = im;
    }
    func dodaj(liczba: OperacjeNaLiczbachZespolonych)
    {
        re += liczba.re;
        im += liczba.im;
    }
    func odejmij(liczba: OperacjeNaLiczbachZespolonych)
    {
        re -= liczba.re;
        im -= liczba.im;
    }
    func wyswietl()
    {
        if(im < 0) {
            print("Liczba zespolona: \(re)-\(im)i")
        }
        else if(im > 0) {
            print("Liczba zespolona: \(re)+\(im)i")
        }
        else {
            print("Liczba zespolona: \(re)")
        }
    }
}

var operacja1 = OperacjeNaLiczbachZespolonych(re: 12, im: 5)
var operacja2 = OperacjeNaLiczbachZespolonych(re: 7, im: 9)
operacja1.dodaj(liczba: operacja2)
operacja1.wyswietl()

//Zadanie 2
protocol LiczbaLosowa
{
    func generujLiczbe() -> Int
}

class Liczby : LiczbaLosowa
{
    var liczba1: Int = 0
    var liczba2: Int = 0
    func generujLiczbe() -> Int
    {
        return Int.random(in: 0...10)
    }
    func wyswietl()
    {
        print("Liczba 1: \(liczba1)")
        print("Liczba 2: \(liczba2)")
    }
    func pow(liczba: inout Int, parametr: Int)
    {
        if(parametr == 0){
            liczba = 1
        }
        else{
            let mnoznik = liczba
            for _ in 1..<parametr {
                liczba *= mnoznik
            }
        }
    }
}

var liczba = Liczby()
liczba.liczba1 = liczba.generujLiczbe()
liczba.liczba2 = liczba.generujLiczbe()
liczba.wyswietl()
liczba.pow(liczba: &liczba.liczba1, parametr: 2)
liczba.wyswietl()

//Zadanie 3
enum Walidacja: Error
{
    case dzieleniePrzez0
    case pierwiastekZLiczbyNiedodatniej
}

func waliduj(liczba: Int) throws {
    guard liczba != 0 else {
        throw Walidacja.dzieleniePrzez0
    }
    guard liczba > 0 else {
        throw Walidacja.pierwiastekZLiczbyNiedodatniej
    }
}

var liczba1: Int = 10
var liczba2: Int = 2

do
{
    try waliduj(liczba: liczba2)
    print("\(liczba1)/\(liczba2) = \(liczba1/liczba2)")
} catch Walidacja.dzieleniePrzez0 {
    print("Dzielenie przez 0!")
}

var liczba3: Double = -5.0

do
{
    try waliduj(liczba: Int(liczba3))
    let wynik = sqrt(liczba3)
    print("\(wynik)")
} catch Walidacja.pierwiastekZLiczbyNiedodatniej {
    print("Pierwiastek z liczby niedodatniej")
}

//Zadanie 4
enum WalidacjaBankomatu : Error
{
    case niewystarczajaceSrodkiNaKoncie
    case brakKwotyWBankomacie
    case przekroczenieDziennegoLimitu
    case brakNominalow
    case inny
}

func walidujBankomat(konto: Double, limit: Int, kwota: Int, kwotaWBankomacie: Int, nominaly: [(nominal: Int, ilosc: Int)]) throws {
    guard kwota % 10 == 0 else {
        throw WalidacjaBankomatu.inny
    }
    guard kwota <= Int(konto) else {
        throw WalidacjaBankomatu.niewystarczajaceSrodkiNaKoncie
    }
    guard kwota <= kwotaWBankomacie else {
        throw WalidacjaBankomatu.brakKwotyWBankomacie
    }
    guard kwota <= limit else {
        throw WalidacjaBankomatu.przekroczenieDziennegoLimitu
    }
    var potrzebnaKwota = kwota
    var nominalyTemp = nominaly
    while(potrzebnaKwota != 0)
    {
        for i in 0..<nominalyTemp.count {
            if(nominalyTemp[i].nominal <= potrzebnaKwota && nominalyTemp[i].ilosc > 0){
                potrzebnaKwota -= nominalyTemp[i].nominal
                nominalyTemp[i].ilosc -= 1
                break
            }
        }
    }
    guard potrzebnaKwota == 0 else {
        throw WalidacjaBankomatu.brakNominalow
    }
}

let kwotaWBankomacie: Int = 5000
let nominaly: [(nominal: Int, ilosc: Int)] = [(500, 0), (200, 2), (100, 1), (50, 5), (20, 2), (10, 1)]

var kwota: Int
print("Podaj kwote do wyplaty")
kwota = Int(readLine()!)!
do
{
    try walidujBankomat(konto: 1000, limit: 100, kwota: kwota, kwotaWBankomacie: kwotaWBankomacie, nominaly: nominaly)
    print("Operacja wykonana poprawnie")
} catch WalidacjaBankomatu.niewystarczajaceSrodkiNaKoncie {
    print("Niewystarczajace srodki na koncie")
} catch WalidacjaBankomatu.brakKwotyWBankomacie {
    print("Brak kwoty w bankomacie")
} catch WalidacjaBankomatu.przekroczenieDziennegoLimitu {
    print("Przekroczenie kwoty dziennego limitu")
} catch WalidacjaBankomatu.brakNominalow {
    print("Brak nominalow")
} catch WalidacjaBankomatu.inny {
    print("Bledna kwota")
}
