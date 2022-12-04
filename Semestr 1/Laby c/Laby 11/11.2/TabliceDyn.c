#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TabliceDyn.h"

int *utworzTD(int n)
{
    int  i;
    int *tabD = (int*) malloc (n *sizeof(int));
    if(tabD==NULL)
    {
        printf("Blad przydzialu pamieci\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++)
    {
        printf("wpisz liczbe tab[%d]: ", i);
        scanf("%d", tabD + i);
    }
    return tabD;
}

void wyswietlTD(int * tabD, int n)
{
    int  i;
    printf("\nZawartosc tablicy:\n");
    for (i=0; i<n; i++)
        printf ("%d\t", *(tabD+i));
    printf ("\n ");
}

void usunTD(int *tabD)
{
    free(tabD);
    tabD=0;
}
