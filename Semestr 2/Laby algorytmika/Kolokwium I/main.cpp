/*
Zadanie 2
Pobieramy od u¿ytkownika dane o k samochodach.
S¹ to: rok produkcji, marka oraz cena(liczba ca³kowita dodatnia).

a.Posortowaæ samochody na te o cenie nie wy¿szej ni¿ 20000, a nastêpnie pozosta³e.
b.Wyznaczyæ, ile samochodów o cenie nie wy¿szej ni¿ 20000 jest marki o podanej przez u¿ytkownika nazwie.
c.Uporz¹dkowaæ malej¹co algorytmem sortowania przez wybieranie wed³ug rocznika samochody o cenie powy¿ej 20000.
d.Wyznaczyæ trzy (ró¿ne)liczby oznaczaj¹ce roczniki najdro¿szych samochodów.

*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct samochod
{
    int rok_produkcji;
    string marka;
    int cena;
};

void wczytajSamochody(samochod*& tab, int& n)
{
    string sciezka,linia,pomoc;
    ifstream plik;
    char sredniki;
    sciezka="samochody.csv";
    plik.open(sciezka);
    plik >> n;
    tab = new samochod[n];
    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<n; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, pomoc, ';');
        tab[i].rok_produkcji=atoi(pomoc.c_str());
        getline(ss, tab[i].marka, ';');
        getline(ss, pomoc);
        tab[i].cena=atoi(pomoc.c_str());
    }
    plik.close();
    cout<<"Dane wczytane"<<endl;
}

void wyswietlTablice(samochod* tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i].rok_produkcji<<" "<<tab[i].marka<<" "<<tab[i].cena<<endl;
    }
}

int podzial_2_czesci(samochod*& tab, int n, int granica)
{
    int i=0, j=n-1;
    while(i<j)
    {
        while(tab[i].cena<=granica && i<j)
            i++;
        while(tab[j].cena>granica && i<j)
            j--;
        if(i<j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if(tab[i].cena<=granica)
        return i+1;
    else
        return i;
}

int wyszukiwanieLiniowe(samochod* tab, int n, string marka)
{
    int i=n, ile=0;
    while(i>=0)
    {
        if(tab[i].marka==marka)
        {
            ile++;
        }
        i--;
    }
    return ile;
}

void sortowaniePrzezWybor(samochod*& tab, int n, int p)
{
    int i=n-1;
    while(i>p)
    {
        int ind=p;
        int j=p+1;
        while(j<=i)
        {
            if(tab[j].rok_produkcji<tab[ind].rok_produkcji)
            {
                ind=j;
            }
            j++;
        }
        swap(tab[i], tab[ind]);
        i--;
    }
}

void roczniki(samochod *tab, int n, int p,int &r1, int &r2, int &r3)
{
    int m = INT_MIN;
    int i1= INT_MIN, i2= INT_MIN, i3= INT_MIN;
    for (int i = p; i < n; i++)
    {
        if(tab[i].cena > m)
            m = tab[i].cena;
    }

    for(int i = p; i < n; i++)
    {
        if (tab[i].cena == m)
        {
            if (tab[i].rok_produkcji > i1)
            {
                i3 = i2;
                i2 = i1;
                i1 = tab[i].rok_produkcji;
            }
            else if (tab[i].rok_produkcji > i2)
            {
                i3 = i2;
                i2 = tab[i].rok_produkcji;
            }
            else if (tab[i].rok_produkcji > i3)
            {
                i3 = i;
            }
        }
    }

    r1 = i1;
    r2 = i2;
    r3 = i3;
}

int main()
{
    int k;
    samochod* tab;
    wczytajSamochody(tab, k);
    wyswietlTablice(tab, k);
    cout<<endl<<"Po podziale na 2 czesci"<<endl;
    int p = podzial_2_czesci(tab, k, 20000);
    wyswietlTablice(tab, k);

    string marka;
    cout<<endl<<"Podaj marke: "<<endl;
    cin>>marka;
    cout<<"Jest "<<wyszukiwanieLiniowe(tab, p-1, marka)<<" samochodow marki "<<marka<<" o cenie nie wyzszej niz 20000"<<endl;

    cout<<endl<<"Po sortowaniu przez wybieranie"<<endl;
    sortowaniePrzezWybor(tab, k, p);
    wyswietlTablice(tab, k);

    int r1, r2 , r3;
    roczniki(tab, k, p, r1, r2, r3);

    cout<<endl<<"3 roczniki najdrozszych samochodow: "<<endl;
    cout<<r1<<endl<<r2<<endl<<r3<<endl;

    delete [] tab;
    tab=nullptr;
    return 0;
}

/*
samochody.csv
10;;
2015;BMW;25230
2001;Volkswagen;3400
2002;Audi;10000
2009;Citroen;19999
1999;BMW;3000
2007;Mazda;2135
2018;Kia;60000
2010;BMW;20001
2009;BMW;20000
1998;Citroen;3500
*/
