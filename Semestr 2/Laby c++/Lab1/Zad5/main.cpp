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

void wypelnienieZerami(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        tab[i]=0;
    }
}

void usuwaniePamieci(int *&tab)
{
    delete [] tab;
    tab = nullptr;
}


void fun(int *tab1, int *tab2, int *tab3, int n)
{
    int j=0,k=0;
    for(int i=0;i<n;i++)
    {
        if(tab1[i]%2==0)
        {
            tab3[j]=tab1[i];
            j++;
        }
        else
        {
            tab2[k]=tab1[i];
            k++;
        }
    }

}

void wyswietlTablice(int *tab, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    srand(time(NULL));
    int n, *tab1, *tab2, *tab3;
    cout<<"Podaj rozmiar tablicy: ";
    cin>>n;

    alokowaniePamieci(tab1, n);
    alokowaniePamieci(tab2, n);
    alokowaniePamieci(tab3, n);

    wypelnienieLosowe(tab1,n);
    wypelnienieZerami(tab2,n);
    wypelnienieZerami(tab3,n);

    fun(tab1,tab2,tab3,n);

    wyswietlTablice(tab2,n);
    wyswietlTablice(tab3,n);

    usuwaniePamieci(tab1);
    usuwaniePamieci(tab2);
    usuwaniePamieci(tab3);
    return 0;
}
