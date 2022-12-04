#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void wczytajStudentow(student*& tab, int& liczbaStudentow)
{
    string sciezka,linia,pomoc;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();
    cout<<"Dane wczytane"<<endl;
}

void usunTabliceStudentow(student*& tab)
{
    delete [] tab;
    tab=nullptr;
}

void sortowanieQuickSort(student* tab, int lewy, int prawy)
{
    int srodek = (int)(lewy+prawy)/2;
    student piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    int granica = lewy;
    int i = lewy;
    while(i<prawy)
    {
        if(tab[i].punkty<piwot.punkty)
        {
            swap(tab[granica],tab[i]);
            granica+=1;
        }
        i+=1;
    }
    tab[prawy]=tab[granica];
    tab[granica]=piwot;
    if(lewy<granica-1) sortowanieQuickSort(tab, lewy, granica-1);
    if(granica+1<prawy) sortowanieQuickSort(tab, granica+1, prawy);
}

void wyszukiwanieLiniowe(student* tab, int n, int wartosc)
{
    int i=0;
    bool znaleziono = false;
    while(i<n)
    {
        if(tab[i].punkty==wartosc)
        {
            cout<<tab[i].imie<<" "<<tab[i].nazwisko<<endl;
            znaleziono = true;
        }
        i++;
    }
    if(znaleziono==false)
    {
        cout<<"Zaden ze studentow nie posiada podanej liczby punktow"<<endl;
    }
}

void wyszukiwanieBisekcyjne(student* tab, int n, int wartosc)
{
    ofstream zapis;
    string sciezkaDoZapisu="wyniki.csv";
    zapis.open(sciezkaDoZapisu);
    int lewy=0;
    int prawy=n-1;
    bool znaleziono = false;
    while(lewy<=prawy && znaleziono == false)
    {
        int srodek = (int)(lewy+prawy)/2;
        if(tab[srodek].punkty==wartosc)
        {
            cout<<tab[srodek].imie<<" "<<tab[srodek].nazwisko<<endl;
            zapis<<tab[srodek].imie<<";"<<tab[srodek].nazwisko<<endl;
            znaleziono = true;

            int i = srodek+1;
            while(i<n && tab[i].punkty==wartosc)
            {
                cout<<tab[i].imie<<" "<<tab[i].nazwisko<<endl;
                zapis<<tab[i].imie<<";"<<tab[i].nazwisko<<endl;
                i++;
            }

            i = srodek-1;
            while(i>=0 && tab[i].punkty==wartosc)
            {
                cout<<tab[i].imie<<" "<<tab[i].nazwisko<<endl;
                zapis<<tab[i].imie<<";"<<tab[i].nazwisko<<endl;
                i--;
            }
        }
        else
        {
            if(wartosc<tab[srodek].punkty)
            {
                prawy=srodek-1;
            }
            else
            {
                lewy=srodek+1;
            }
        }
    }
    if(znaleziono==false)
    {
        cout<<"Zaden ze studentow nie posiada podanej liczby punktow"<<endl;
        zapis<<"Zaden ze studentow nie posiada podanej liczby punktow"<<endl;
    }
    zapis.close();
}

int main()
{
    int wybor, liczbaStudentow, p, srodek;
    student* tab;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Zad7.1"<<endl;
        cout<<"2: Zad7.2"<<endl;
        cout<<"3: Zad7.3"<<endl;
        cout<<"4: Koniec programu"<<endl;
        cin>>wybor;

        switch(wybor)
        {
            case 1:
                wczytajStudentow(tab, liczbaStudentow);
                break;
            case 2:
                cout<<"Podaj liczbe punktow"<<endl;
                cin>>p;
                wyszukiwanieLiniowe(tab, liczbaStudentow, p);
                break;
            case 3:
                cout<<"Podaj liczbe punktow"<<endl;
                cin>>p;
                sortowanieQuickSort(tab, 0, liczbaStudentow-1);
                wyszukiwanieBisekcyjne(tab, liczbaStudentow, p);
                break;
            case 4:
                usunTabliceStudentow(tab);
                exit(0);
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
