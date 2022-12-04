#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ile, n, m;
    int *tab1D;
    int **tab2D;
    printf("Tablica 1D\n");
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d",&ile);
    tab1D=utworzTablice(ile);
    wyswietlTablice(tab1D, ile);
    usunTablice(tab1D);
    printf("Tablica 2D\n");
    printf("Podaj liczbe wierszy tablicy: ");
    scanf("%d",&n);
    printf("Podaj liczbe kolumn tablicy: ");
    scanf("%d",&m);
    tab2D=utworzTablice2D(n,m);
    wyswietlTablice2D(tab2D,n,m);
    usunTablice(tab2D);
    return 0;
}
