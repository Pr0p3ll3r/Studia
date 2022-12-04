#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void alokowaniePamieci(int *&tab, int n)
{
    tab = new int[n];
}

void wypelnienie(int *tab, int n)
{

    int x = 1 + rand()%(n-2);
    for(int i=0;i<n;i++)
    {
        if(i!=x)
            tab[i]=(rand()%9)+1;
        else
            tab[i]=0;
        cout<<tab[i];
    }
    cout<<endl;
}

void usuwaniePamieci(int *&tab)
{
    delete [] tab;
    tab = nullptr;
}

void fun(int *tab, int n)
{
    int suma1=0, suma2=0, i=0;
    float srednia1=0, srednia2=0;
    while(tab[i]!=0)
    {
        suma1+=tab[i];
        i++;
    }
    srednia1=(float)suma1/i;

    for(int j=i+1;j<n;j++)
    {
        suma2+=tab[j];
    }
    srednia2=(float)suma2/(n-i-1);

    cout<<"Srednia arytmetyczna liczb przed komorka z 0 wynosi "<<srednia1<<endl;
    cout<<"Srednia arytmetyczna liczb po komorce z 0 wynosi "<<srednia2<<endl;
}

int main()
{
    srand(time(NULL));
    int n, *tab;
    cout<<"Podaj rozmiar tablicy: ";
    cin>>n;
    alokowaniePamieci(tab, n);
    wypelnienie(tab,n);
    fun(tab, n);
    usuwaniePamieci(tab);
    return 0;
}
