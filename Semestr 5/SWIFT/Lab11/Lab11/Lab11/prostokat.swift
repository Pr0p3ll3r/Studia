import Foundation

class Prostokat
{
    var a: Double = 0
    var b: Double = 0
    init(a: Double, b: Double)
    {
        self.a = a
        self.b = b
    }
    func pole() -> Double
    {
        return a*b
    }
    func obwod() -> Double
    {
        return 2*a + 2*b
    }
    func wyswietl()
    {
        print("Pole: \(pole()) Obwod: \(obwod())")
    }
}