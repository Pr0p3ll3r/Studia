#include <stdio.h>
#include <stdlib.h>

void wczytajTablice(int lelem, int tab[]);
void wyswietlTablice(int lelem, int tab[]);
void kopiujTablicowa(int lelem, int tab[], int tab2[]);
void kopiujWskaznikowa(int lelem, int tab[], int tab2[]);

int main()
{
    int n;
    do{
        printf("Podaj liczbe elementow: ");
        scanf("%d",&n);
    }while(n <= 0);
    int tab1[n];
    int tab2[n];
    int tab3[n];
    wczytajTablice(n,tab1);
    wyswietlTablice(n,tab1);
    kopiujTablicowa(n,tab1,tab2);
    kopiujTablicowa(n,tab1,tab3);
    wyswietlTablice(n,tab2);
    wyswietlTablice(n,tab3);
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
    printf("\n");
}

void kopiujTablicowa(int lelem, int tab[], int tab2[])
{
    for(int i=0;i<lelem;i++)
    {
        tab2[i] = tab[i];
    }
}

void kopiujWskaznikowa(int lelem, int tab[], int tab2[])
{
    for(int i=0;i<lelem;i++)
    {
        *(tab2 + i) = *(tab + i);
    }
}
