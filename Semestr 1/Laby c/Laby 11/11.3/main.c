#include <stdio.h>
#include <stdlib.h>
#include "TabliceDyn2.h"

int main()
{
    int**tab2D;
    int i,j,n,m;
    printf("\ntablica 2D\n");
    printf("Podaj liczbê wierszy tablicy ");
    scanf("%d",&n);
    printf("Podaj liczbê kolumn tablicy ");
    scanf("%d",&m);
    tab2D = utworzT2D(n,m);
    wyswietlT2D(tab2D,n,m);
    usunTD(tab2D);
}
