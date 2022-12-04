#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void wczytajStudentow(student*& tab, int &liczbaStudentow)
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

void wyswietlStudentow(student *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }
    cout<<endl;
}

void usunTabliceStudentow(student *&tab)
{
    delete [] tab;
}

void tworzenie_kopca(student *&tab, int n, int tryb)
{
    int j, k;
    student x;
    int i=1;
    while(i<n)
    {
        j = i;
        k = (int)(j-1)/2;
        x = tab[i];
        if(tryb == 0)
        {
            while (j > 0 && tab[k].punkty > x.punkty)
            {
                tab[j] = tab[k];
                j = k;
                k = (int)(j-1)/2;
            }
            tab[j] = x;
            i++;
        }
        else if(tryb == 1)
        {
            while (j > 0 && tab[k].punkty < x.punkty)
            {
                tab[j] = tab[k];
                j = k;
                k = (int)j/2;
            }
            tab[j] = x;
            i++;
        }
    }
}

void rozbieranie_kopca(student *&tab, int n, int tryb)
{
    int j,m,k;
    int i=n-1;
    if(tryb==0)
    {
        while(i>0)
        {
            swap(tab[0], tab[i]);
            j = 0;
            k = 1;
            while (k < i)
            {
                if ((k+1) < i && tab[k+1].punkty < tab[k].punkty)
                    m = k + 1;
                else
                    m = k;

                if (tab[m].punkty >= tab[j].punkty)
                    break;

                swap(tab[j], tab[m]);
                j = m;
                k = 2*j;
            }
            i--;
        }
    }
    else if(tryb==1)
    {
        while(i>0)
        {
            swap(tab[0], tab[i]);
            j = 0;
            k = 1;
            while (k < i)
            {
                if ((k+1) < i && tab[k+1].punkty > tab[k].punkty)
                    m = k + 1;
                else
                    m = k;

                if (tab[m].punkty <= tab[j].punkty)
                    break;

                swap(tab[j], tab[m]);
                j = m;
                k = 2*j;
            }
            i--;
        }
    }
}

int main()
{
    int n, tryb;
    student *tab = nullptr;
    wczytajStudentow(tab, n);
    wyswietlStudentow(tab, n);

    cout<<endl<<"Wybierz tryb sortowania: (0-malejaco, 1-rosnaco)"<<endl;
    cin>>tryb;

    tworzenie_kopca(tab, n, tryb);
    rozbieranie_kopca(tab, n, tryb);
    wyswietlStudentow(tab, n);

    usunTabliceStudentow(tab);
    return 0;
}
