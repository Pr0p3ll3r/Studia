#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void alokowaniePamieci(int **&tab, int N, int M)
{
    tab = new int* [N];

    for(int i=0;i<N;i++)
        tab[i] = new int[M];

}

void wypelnienieLosowe(int **tab, int N, int M)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
             tab[i][j]=(rand()%9)+1;
             cout<<tab[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<endl;
}

void usuwaniePamieci(int **&tab, int N)
{
    for(int i=0;i<N;i++)
        delete [] tab[i];

    delete [] tab;
    tab = nullptr;
}

int fun(int **tab, int N, int M)
{
    int sumaMin=0, uczenMin=0;
    for(int i=0;i<N;i++)
        sumaMin += tab[i][0];
    int suma = 0;
    for(int j=1;j<M;j++)
    {
        suma = 0;
        for(int k=0;k<N;k++)
            suma+=tab[j][k];
        if(suma<sumaMin)
        {
            sumaMin=suma;
            uczenMin=j;
        }
    }

    int przedmiot=tab[0][uczenMin];
    for(int l=1;l<N;l++)
    {
        if(tab[l][uczenMin]>przedmiot)
            przedmiot = tab[l][uczenMin];
    }

    return przedmiot;
}

int main()
{
    srand(time(NULL));
    int N, M, **tab;
    cout<<"Podaj rozmiar tablicy: "<<endl;
    cout<<"Liczba wierszy: ";
    cin>>N;
    cout<<"Liczba kolumn: ";
    cin>>M;

    alokowaniePamieci(tab, N, M);
    wypelnienieLosowe(tab, N, M);

    cout<<fun(tab, N, M);

    usuwaniePamieci(tab, N);
    return 0;
}
