import Foundation

class Prostopadloscian : Prostokat
{
    var c: Double = 0
    init(a: Double, b: Double, c: Double)
    {
        super.init(a: a, b: b)
        self.c = c
    }
    override func pole() -> Double
    {
        return 2*a*b + 2*a*c + 2*b*c
    }
    func sumaKrawedzi() -> Double
    {
        return 4*a+4*b+4*c
    }
    func objetosc() -> Double
    {
        return a*b*c
    }
    override func wyswietl()
    {
        print("Pole: \(pole()) Suma krawedzi: \(sumaKrawedzi()) Objetosc: \(objetosc())")
    }
}