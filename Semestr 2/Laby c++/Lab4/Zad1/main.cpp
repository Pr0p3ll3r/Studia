#include <iostream>

using namespace std;
class Samochod
{
private:
    string marka;
    string model;
    int rok_produkcji;
public:
    Samochod(string marka1, string model1, int rok_produkcji1) //konstruktor
    {
        marka=marka1;
        model=model1;
        rok_produkcji=rok_produkcji1;
    }
    Samochod() //konstruktor bez parametrowy, uzywany przy tworzeniu tablicy samochodow w klasie Osoba
    {
    }
    ~Samochod() //destruktor
    {
    }

    void show()
    {
        cout<<"Marka: "<<marka<<" model: "<<model<<" rok_produkcji: "<<rok_produkcji<<endl;
    }
};
class Osoba
{
private:
    string imie;
    string nazwisko;
    int wiek;
    Samochod *tab; //obiekt klasy Samochod jako pole w klasie Osoba, osoba moze posiadac kilka samochodow
    int ile_max;  //aby ulatwic zadanie, zakladamy, ze kazda osoba ma okreslona liczbe samochodow ktore moze posiadac
    int ile_obecnie; //ile samochodow obecnie posiada osoba
public:
    Osoba(string imie1, string nazwisko1, int wiek1, int ile_max1)
    {
        imie=imie1;
        nazwisko=nazwisko1;
        wiek=wiek1;
        ile_max=ile_max1;
        tab=new Samochod[ile_max]; // zaalokowanie pamieci, stworzenie tablicy samochodow
        ile_obecnie=0;
    }
    ~Osoba()
    {
        delete [] tab; //zwolnienie pamieci
    }
    Osoba(Osoba &os) //kostruktor kopiujacy w celu wykonania poprawnego kopiowania dwoch obiektow
    {
        imie=os.imie;
        nazwisko=os.nazwisko;
        wiek=os.wiek;
        ile_obecnie=os.ile_obecnie;
        ile_max=os.ile_max;
        tab=new Samochod[ile_max];
        for(int i=0; i<ile_obecnie; i++)
        {
            tab[i]=os.tab[i];
        }

    }
    void show()
    {
        cout<<"Imie: "<<imie<<" nazwisko: "<<nazwisko<<" wiek: "<<wiek<<endl;
        cout<<"Samochody"<<endl;
        for(int i=0; i<ile_obecnie; i++) //wyswietlenie informacji o posiadanych samochodach
        {
            tab[i].show();  //tab[i] jest obiektem klasy Samochod, za pomoca metody show z klasy Samochod wyswietlamy informacje o i tym samochodzie
        }
    }
    void dodajSamochod(Samochod s) //dodawanie samochodu, metoda przyjmuje jako parametr obiekt klasy Samochod
    {
        if(ile_obecnie<ile_max) //sprawdzenie czy jest miejsce na dodanie kolejnego samochodu
        {
            tab[ile_obecnie]=s; // tab[ile_obecnie] jest obiektem klasy Samochod, s tez jest obiektem klasy samochod
            ile_obecnie++;      //zwiekszenie liczby obecnie posiadanych samochodow
        }
        else
        {
            cout<<"Nie mozna dodac kolejnego samochodu"<<endl;
        }
    }
    void usunOstatniSamochod() //"prowizoryczne" usuwanie ostatniego samochodu
    {
        ile_obecnie--;  //zmiejszenie liczby samochodow o 1
    }
};

int main()
{
    Osoba os1("Alicja","Nowak",22,4); //stworzenie obiektu klasy Osoba
    os1.show();
    Samochod s1("Opel","Astra",2006);  //stworzenie obiektu klasy Samochod
    os1.dodajSamochod(s1);  //dodanie osobie os1 samochodu s
    os1.show();
    Samochod s2("Skoda","Fabia", 2019); //stworzenie kolejnego obiektu klasy Samochod
    os1.dodajSamochod(s2); //dodanie kolejnego samochodu
    os1.show();
    Samochod s3("Volvo","S40", 1999);
    os1.dodajSamochod(s3);
    os1.show();
    Samochod s4("Skoda","Octavia", 2006);
    os1.dodajSamochod(s4);
    os1.show();
    Samochod s5("Peugeot","208", 2010); //stworzenie piatego samochodu
    os1.dodajSamochod(s5); //proba dodania piatego samochodu, przy ustalonej maxymalnej liczbie samochodow 4
    os1.show();
    os1.usunOstatniSamochod(); //"usuniecie" ostatniego samochodu
    os1.show();

    Osoba os2(os1); //kopiowanie obiektu (wywolanie konsruktora kopiujacego)
    os2.show();

    return 0;
}
