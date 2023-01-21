import Foundation

enum Kierunek: String, CaseIterable
{
    case Informatyka
    case Mechatronika
    case Zarzadzanie
    case Matematyka
}

class Student : Osoba
{
    var numerIndeksu: String = ""
    var kierunek: Kierunek = Kierunek.Informatyka
    var rok: Int = 0
    var oceny: [Double] = []
    init(imie: String, nazwisko: String, rok_urodzenia: Int, numerIndeksu: String, kierunek: Kierunek, rok: Int, 
    oceny: [Double])
    {
        self.numerIndeksu = numerIndeksu
        self.kierunek = kierunek
        self.rok = rok
        for ocena in oceny {
            if (ocena != 2 && ocena != 3 && ocena != 3.5 && ocena != 4 && ocena != 4.5 && ocena != 5) {
                print("Bledna ocena")
                self.oceny = []
                super.init(imie: imie, nazwisko: nazwisko, rok_urodzenia: rok_urodzenia)
                return
            }
        }
        self.oceny = oceny
        super.init(imie: imie, nazwisko: nazwisko, rok_urodzenia: rok_urodzenia)
    }
    override init()
    {
        super.init()
    }
    func srednia() -> Double
    {
        var srednia = 0.0
        for ocena in oceny {
            srednia += ocena
        }
        return srednia/Double(oceny.count)
    }
    override func wyswietl()
    {
        super.wyswietl()
        print("Numer indeksu: \(numerIndeksu) Kierunek studiow: \(kierunek) Rok studiow: \(rok) Oceny: \(oceny)")
    }
}