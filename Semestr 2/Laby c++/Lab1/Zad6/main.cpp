#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void alokowaniePamieci(int *&tab, int n)
{
    tab = new int[n];
}

void wypelnienieLosowe(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=(rand()%9)+1;
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void usuwaniePamieci(int *&tab)
{
    delete [] tab;
    tab = nullptr;
}

int fun(int *tab, int n)
{
    int sumaMax = tab[0]+tab[1];
    for(int i=1;i<n-1;i++)
    {
        int suma = tab[i]+tab[i+1];
        if(suma>sumaMax)
            sumaMax=suma;
    }

    return sumaMax;
}

int main()
{
    srand(time(NULL));
    int n, *tab;
    cout<<"Podaj rozmiar tablicy: ";
    cin>>n;

    alokowaniePamieci(tab, n);
    wypelnienieLosowe(tab,n);

    cout<<"Najwieksza suma dwoch sasiednich elementow tablicy: "<<fun(tab,n);

    usuwaniePamieci(tab);
    return 0;
}
