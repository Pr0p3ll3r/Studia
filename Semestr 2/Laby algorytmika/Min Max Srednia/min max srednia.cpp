#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

void przydzielPamiec1D(int *&tab, int n)
{
    tab = new int[n];
}

void wypelnijTablice1D(int *tab, int n, int a, int b)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=rand()%(b-a+1)+a;
    }
}

void wyswietlTablice1D(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void usunTablice1D(int *&tab)
{
    delete [] tab;
    tab=nullptr;
}

bool czyPierwsza(int x)
{
    if(x<2) return false;

    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }

    return true;
}

int najmniejszy(int *tab, int n)
{
    int x=tab[0];
    for(int i=1;i<n;i++)
    {
        if(tab[i]<x)
            x=tab[i];
    }
    return x;
}

void wyswietlIleRazy(int *tab, int n)
{
    int ileRazy;
    for(int i=0;i<10;i++)
    {
        ileRazy=0;
        for(int j=0;j<n;j++)
        {
            if(tab[j]==i)
                ileRazy++;
        }
        cout<<"Cyfra "<<i<<" - "<<ileRazy<<" razy"<<endl;
    }
}


int main()
{
    srand(time(NULL));
    int n, a, b, *tab;
    cout<<"Podaj rozmiar tablicy:"<<endl;
    cin>>n;
    przydzielPamiec1D(tab, n);

    cout<<endl<<"Zad 1.2"<<endl;
    cout<<"Podaj przedzial <a,b>:"<<endl;
    cout<<"a:";
    cin>>a;
    cout<<"b:";
    cin>>b;
    wypelnijTablice1D(tab,n,a,b);
    wyswietlTablice1D(tab,n);
    int najm = najmniejszy(tab,n);
    cout<<"Element najmniejszy to "<<najm<<endl;
    if(czyPierwsza(najm))
        cout<<"Jest to liczba pierwsza"<<endl;
    else
         cout<<"Nie jest to liczba pierwsza"<<endl;

    cout<<endl<<"Zad 1.3"<<endl;
    cout<<"Podaj rozmiar tablicy:"<<endl;
    cin>>n;
    wypelnijTablice1D(tab,n,0,9);
    wyswietlTablice1D(tab,n);
    wyswietlIleRazy(tab,n);

    usunTablice1D(tab);
    return 0;
}
