#include <stdio.h>
#include <stdlib.h>

void wczytajTablice(int lelem, float tab[]);
int zdali(int lelem, float tab[]);

int main()
{
    int n;
    do{
        printf("Podaj ilosc studentow: ");
        scanf("%d",&n);
    }while(n <= 0);
    float tab1[n];
    wczytajTablice(n,tab1);
    if(zdali(n, tab1) == 0)
    {
        printf("Nie wszyscy studenci zdali");
    }
    else
    {
        printf("Wszyscy studenci zdali");
    }
    return 0;
}

void wczytajTablice(int lelem, float tab[])
{
    for(int i = 0;i<lelem;i++)
    {
        printf("Ocena ucznia %d = ", i+1);
        scanf("%f", &tab[i]);
    }
}

int zdali(int lelem, float tab[])
{
    for(int i = 0;i<lelem;i++)
    {
        if(tab[i] < 3)
            return 0;
    }
    return 1;
}
