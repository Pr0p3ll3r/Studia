#include <iostream>

using namespace std;

class Pociag
{
private:
    string nazwa;
    int liczbaWagonow;
    int* liczbaMiejsc;
public:
    Pociag()
    {
        liczbaWagonow = 0;
        liczbaMiejsc = new int[liczbaWagonow];
        cout<<"Konstruktor bezparametrowy"<<endl;
    }
    Pociag(string nazwa, int liczbaWagonow)
    {
        this->nazwa = nazwa;
        this->liczbaWagonow = liczbaWagonow;
        liczbaMiejsc = new int[liczbaWagonow];
        cout<<"Konstruktor parametrowy"<<endl;
    }
    ~Pociag()
    {
        delete [] liczbaMiejsc;
        cout<<"Destruktor"<<endl;
    }
    int getWagony()
    {
        return liczbaWagonow;
    }
    void setWagony(int liczba)
    {
        liczbaWagonow = liczba;
        for(int i=0;i<liczbaWagonow;i++)
        {
            liczbaMiejsc[i] = 0;
        }
    }
    void wczytaj()
    {
        for(int i=0;i<liczbaWagonow;i++)
        {
            cout<<"Podaj liczbe miejsc wagonu nr "<<i+1<<endl;
            cin>>liczbaMiejsc[i];
        }
    }
    void wyswietl()
    {
        cout<<"Nazwa: "<<nazwa<<endl;
        cout<<"Liczba wagonow: "<<liczbaWagonow<<endl;
        for(int i=0;i<liczbaWagonow;i++)
        {
            cout<<"Liczbe miejsc wagonu nr "<<i+1<<": "<<liczbaMiejsc[i]<<endl;
        }
    }
    Pociag(Pociag &p)
    {
        nazwa = p.nazwa;
        liczbaWagonow = p.liczbaWagonow;
        liczbaMiejsc = new int[liczbaWagonow];
        for(int i=0;i<liczbaWagonow;i++)
        {
            liczbaMiejsc[i] = p.liczbaMiejsc[i];
        }
        cout<<"Konstruktor kopiujacy"<<endl;
    }
};

int ileWagonow(Pociag *tab, int rozmiar)
{
    int najmniej = tab[0].getWagony();
    for(int i=1;i<rozmiar;i++)
    {
        if(tab[i].getWagony()<najmniej)
            najmniej = tab[i].getWagony();
    }
    return najmniej;
}

void wyswietlInfo(Pociag *tab, int rozmiar)
{
    for(int i=1;i<rozmiar;i++)
    {
        tab[i].wyswietl();
    }
}

class Czlowiek
{
private:
    int liczbaLat;
    string imie;
public:
    Czlowiek(int liczbaLat, string imie)
    {
        this->liczbaLat = liczbaLat;
        this->imie = imie;
        cout<<"Konstruktor parametrowy"<<endl;
    }
    virtual ~Czlowiek()
    {
        cout<<"Destruktor"<<endl;
    }
    virtual void zainteresowania() = 0;
    virtual void wyswietl()
    {
        cout<<"Nazywam sie "<<imie<<" i mam "<<liczbaLat<<" lat"<<endl;
    }
};

class Niemowlak : public Czlowiek
{
public:
    Niemowlak(int liczbaLat, string imie):Czlowiek(liczbaLat, imie)
    {

    }
    virtual void zainteresowania()
    {
        cout<<"Lezenie i jedzenie"<<endl;
    }
    virtual ~Niemowlak()
    {

    }
};

class Emeryt : public Czlowiek
{
public:
    Emeryt(int liczbaLat, string imie):Czlowiek(liczbaLat, imie)
    {

    }
    virtual void zainteresowania()
    {
        cout<<"Odpoczywanie i chodzenie do lekarza"<<endl;
    }
    virtual ~Emeryt()
    {

    }
};

int main()
{
    Pociag p("Jakub", 5);
    cout<<"Liczba wagonow: "<<p.getWagony()<<endl;
    p.setWagony(3);
    cout<<"Liczba wagonow: "<<p.getWagony()<<endl;
    p.wczytaj();
    p.wyswietl();

    Pociag p2 = p;
    p2.wyswietl();

    Pociag *tab;
    tab = new Pociag[5];
    for(int i=0; i<5; i++)
    {
        tab[i].setWagony(i+2);
    }

    cout<<"Najmniejsza liczba wagonow: "<<ileWagonow(tab, 5)<<endl;

    wyswietlInfo(tab, 5);

    delete [] tab;

    Czlowiek *tab2[6];
    for(int i=0; i<3; i++)
    {
        tab2[i] = new Niemowlak(i+1, "Jakub");
    }
    for(int i=3; i<6; i++)
    {
        tab2[i] = new Emeryt(i+60, "Janusz");
    }
    for(int i=0; i<6; i++)
    {
        tab2[i]->wyswietl();
        tab2[i]->zainteresowania();
    }

    for(int i=0; i<6; i++)
    {
        delete tab2[i];
    }

    return 0;
}
