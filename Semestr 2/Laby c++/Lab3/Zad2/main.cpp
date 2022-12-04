#include <iostream>

using namespace std;

class Miasto
{
private:
    string nazwa;
    int* kod_pocztowy;
    int rozmiar;
    float przychody;
    float wydatki;
    int wyksztalcenieWyzsze;
    int liczbaKobiet;
    int liczbaMezczyzn;
    int powierzchniaMiasta;
public:
    Miasto(string nazwa, int rozmiar, float przychody, float wydatki, int wyksztalcenieWyzsze, int liczbaKobiet, int liczbaMezczyzn, int powierzchniaMiasta)
    {
        this->nazwa = nazwa;
        this->rozmiar = rozmiar;
        this->kod_pocztowy = new int[rozmiar];
        this->przychody = przychody;
        this->wydatki = wydatki;
        this->wyksztalcenieWyzsze = wyksztalcenieWyzsze;
        this->liczbaKobiet = liczbaKobiet;
        this->liczbaMezczyzn = liczbaMezczyzn;
        this->powierzchniaMiasta = powierzchniaMiasta;
        for(int i=0;i<rozmiar;i++)
        {
            cout<<i+1<<" liczba kodu pocztowego"<<endl;
            cin>>kod_pocztowy[i];
        }
    }
    Miasto(string nazwa)
    {
        this->nazwa = nazwa;
        rozmiar = 1;
        przychody = 0;
        wydatki = 0;
        wyksztalcenieWyzsze = 0;
        liczbaKobiet = 0;
        liczbaMezczyzn = 0;
        powierzchniaMiasta = 0;
        kod_pocztowy = new int[rozmiar];
        kod_pocztowy[0] = 0;
    }
    Miasto(Miasto &m)
    {
        nazwa = m.nazwa;
        rozmiar = m.rozmiar;
        kod_pocztowy = new int[rozmiar];
        for(int i=0;i<rozmiar;i++)
        {
            kod_pocztowy[i]=m.kod_pocztowy[i];
        }
        przychody = m.przychody;
        wydatki = m.wydatki;
        wyksztalcenieWyzsze = m.wyksztalcenieWyzsze;
        liczbaKobiet = m.liczbaKobiet;
        liczbaMezczyzn = m.liczbaMezczyzn;
        powierzchniaMiasta = m.powierzchniaMiasta;
    }
    Miasto()
    {
        nazwa = "";
        rozmiar = 1;
        przychody = 0;
        wydatki = 0;
        wyksztalcenieWyzsze = 0;
        liczbaKobiet = 0;
        liczbaMezczyzn = 0;
        powierzchniaMiasta = 0;
        kod_pocztowy = new int[rozmiar];
        for(int i=0;i<rozmiar;i++)
        {
            kod_pocztowy[i]=0;
        }
    }
    ~Miasto()
    {
        delete [] kod_pocztowy;
    }
    void setNazwa(string nazwa)
    {
        this->nazwa = nazwa;
    }
    void setKod(int* kod)
    {
        kod_pocztowy = kod;
    }
    void setRozmiar(int rozmiar)
    {
        this->rozmiar = rozmiar;
    }
    void setPrzychody(float przychody)
    {
        this->przychody = przychody;
    }
    void setWydatki(float wydatki)
    {
        this->wydatki= wydatki;
    }
    void setWyksztalcenie(int wyksztalcenieWyzsze)
    {
        this->wyksztalcenieWyzsze = wyksztalcenieWyzsze;
    }
    void setLiczbaKobiet(int liczba)
    {
        liczbaKobiet = liczba;
    }
    void setLiczbaMezczyzn(int liczba)
    {
        liczbaMezczyzn = liczba;
    }
    void setPowierzchnia(int powierzchniaMiasta)
    {
        this->powierzchniaMiasta = powierzchniaMiasta;
    }

    string getNazwa()
    {
        return nazwa;
    }
    int* getKod()
    {
        return kod_pocztowy;
    }
    int getRozmiar()
    {
        return rozmiar;
    }
    int getPrzychody()
    {
        return przychody;
    }
    int getWydatki()
    {
        return wydatki;
    }
    int getWyksztalcenie()
    {
        return wyksztalcenieWyzsze;
    }
    int getLiczbaKobiet()
    {
        return liczbaKobiet;
    }
    int getLiczbaMezczyzn()
    {
        return liczbaMezczyzn;
    }
    int getPowierzchnia()
    {
        return powierzchniaMiasta;
    }

    void wyswietl()
    {
        cout<<"Nazwa miasta: "<<nazwa<<endl;
        cout<<"Kod pocztowy: ";
        for(int i=0;i<rozmiar;i++)
        {
            cout<<kod_pocztowy[i];
        }
        cout<<endl;
        cout<<"Powierzchnia miasta: "<<powierzchniaMiasta<<endl;
        cout<<"Przychody: "<<przychody<<" "<<"Wydatki: "<<wydatki<<endl;
        cout<<"Liczba osob z wyksztalceniem wyzszym: "<<wyksztalcenieWyzsze<<endl;
        cout<<"Liczba kobiet: "<<liczbaKobiet<<" "<<"Liczba mezczyzn: "<<liczbaMezczyzn<<endl;
    }

    void dodajOsobe()
    {
        char c;
        while(c!='K' || c!='M')
        {
            cout<<"Dodawanie osoby (K/M)"<<endl;
            cin>>c;
        }
        if(c=='K')
        {
            liczbaKobiet++;
        }
        else if(c=='M')
        {
            liczbaMezczyzn++;
        }

        while(c!='T' || c!='N')
        {
            cout<<"Czy ta osoba ma wyksztalcenie wyzsze?(T/N)"<<endl;
            cin>>c;
        }
        if(c=='T')
            wyksztalcenieWyzsze++;
    }
    float bilans()
    {
        return przychody-wydatki;
    }
    float zaludnienie()
    {
        return (float)(liczbaKobiet+liczbaMezczyzn)/powierzchniaMiasta;
    }
    float procentWyzsze()
    {
        return (float)wyksztalcenieWyzsze/(liczbaKobiet+liczbaMezczyzn);
    }
};

Miasto najPowierzchnia(Miasto miasta[], int n)
{
    Miasto m(" ");
    for(int i=0;i<n;i++)
    {
        if(miasta[i].getPowierzchnia()>m.getPowierzchnia())
            m.setPowierzchnia(miasta[i].getPowierzchnia());
    }
    return m;
}

void wyswietlAll(Miasto miasta[], int n)
{
    for(int i=0;i<n;i++)
    {
        miasta[i].wyswietl();
    }
}

void przeniesKobiete(Miasto &m1, Miasto &m2)
{
    if(m1.getLiczbaKobiet()==0)
        cout<<"W miescie nie ma ¿adnej kobiety"<<endl;
    else
    {
        m1.setLiczbaKobiet(m1.getLiczbaKobiet()-1);
        m2.setLiczbaKobiet(m2.getLiczbaKobiet()+1);
    }
}

void bilans(Miasto *m1, Miasto *m2)
{
    if (m1->bilans() > m2->bilans())
    {
        cout<<"Bilans miasta "<<m1->getNazwa()<<" jest wiekszy!"<<endl;
    }
    else if (m1->bilans() > m2->bilans())
    {
        cout<<"Bilans miasta "<< m2->getNazwa()<<" jest wiekszy!"<<endl;
    }
    else if (m1->bilans() == m2->bilans())
    {
        cout<<"Bilansy sa rowne!"<<endl;
    }
}

int main()
{
    Miasto m1("Lublin", 5, 2000, 1000, 5, 10, 15, 100);
    Miasto m2("Warszawa", 4, 233, 900, 2, 5, 7, 80);
    Miasto miasta[4];
    miasta[0] = Miasto("Lublin");
    miasta[1] = Miasto("Szczecin");
    miasta[2] = Miasto("Bydgoszcz");
    miasta[3] = Miasto("Wroclaw");
    m1.wyswietl();
    m2.wyswietl();
    przeniesKobiete(m1,m2);
    m1.wyswietl();
    m2.wyswietl();
    Miasto* m3=&m1;
    Miasto* m4=&m2;
    bilans(m3,m4);
    Miasto m5(m1);
    m5.wyswietl();
    wyswietlAll(miasta, 4);
    return 0;
}
