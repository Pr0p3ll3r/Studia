#include <stdio.h>
#include <stdlib.h>

void wczytajTablice(int lelem, int tab[]);
void wyswietlTablice(int lelem, int tab[]);
int sumaElementow(int lelem, int tab[]);
int max(int lelem, int tab[]);
int ileRazy(int lelem, int x, int tab[]);

int main()
{
    int n, x;
    do{
        printf("Podaj liczbe elementow: ");
        scanf("%d",&n);
    }while(n <= 0);
    int t[n];

    wczytajTablice(n,t);
    wyswietlTablice(n,t);
    printf("\nSuma elementow wynosi %d", sumaElementow(n,t));
    printf("\nNajwieksza wartosc to %d", max(n,t));
    printf("\nPodaj liczbe: ");
    scanf("%d", &x);
    printf("Podana liczba to %d, wystapila %d razy", x, ileRazy(n,x,t));
    return 0;
}

void wczytajTablice(int lelem, int tab[])
{
    for(int i = 0;i<lelem;i++)
    {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

}

void wyswietlTablice(int lelem, int tab[])
{
    for(int i = 0;i<lelem;i++)
        printf("%d  ", tab[i]);
}

int sumaElementow(int lelem, int tab[])
{
    int suma = 0;
    for(int i=0;i<lelem;i++)
    {
        suma += tab[i];
    }
    return suma;
}

int max(int lelem, int tab[])
{
    int max = 0;
    for(int i=0;i<lelem;i++)
    {
        if(tab[i] > max)
            max = tab[i];
    }
    return max;
}

int ileRazy(int lelem, int x, int tab[])
{
    int ile=0;
    for(int i=0;i<lelem;i++)
    {
        if(tab[i] == x)
            ile++;
    }
    return ile;
}
