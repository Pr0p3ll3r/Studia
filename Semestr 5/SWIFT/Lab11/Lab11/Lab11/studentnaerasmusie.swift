import Foundation

class StudentNaErasmusie : Student
{
    var nazwaUczelni: String = ""
    var dataRozpoczecia: Date
    var dataZakonczenia: Date
    var kursy: [(nazwa: String, ocena: Float)] = []
    init(imie: String, nazwisko: String, rok_urodzenia: Int, numerIndeksu: String, kierunek: Kierunek, rok: Int, 
    oceny: [Double], nazwaUczelni: String, dataRozpoczecia: Date, dataZakonczenia: Date, kursy: [(nazwa: String, ocena: Float)])
    {
        self.nazwaUczelni = nazwaUczelni
        self.dataRozpoczecia = dataRozpoczecia
        self.dataZakonczenia = dataZakonczenia
        self.kursy = kursy
        super.init(imie: imie, nazwisko: nazwisko, rok_urodzenia: rok_urodzenia, numerIndeksu: numerIndeksu, kierunek: kierunek, rok: rok, oceny: oceny)
    }
    override func wyswietl()
    {
        super.wyswietl()
        print("Nazwa uczelni: \(nazwaUczelni) Data rozpoczecia: \(dataRozpoczecia) Data zakonczenia: \(dataZakonczenia) Kursy: \(kursy)")
    }
    func czasSpedzony() -> Int
    {
       let diffComponents = Calendar.current.dateComponents([.day], from: dataRozpoczecia, to: dataZakonczenia)
        return diffComponents.day!
    }
    func ocena() -> String
    {
        var ocena: Float = 0
        for kurs in kursy
        {
            ocena += kurs.ocena
        }
        ocena /= (Float)(kursy.count)
        switch(ocena)
        {
            case 4.6...5.0:
                return "bardzo dobra"
            case 3.6...4.5:
                return "dobra"
            case 3.0...3.5:
                return "dostateczna"
            default:
                return "niedostateczna"
        }
    }
}