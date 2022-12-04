#include <stdio.h>
#include <stdlib.h>

int *utworzTD(int n);
void wyswietlTD(int * tabD, int n);
void usunTD(int *tabD);

int main(int argc, char *argv[])
{
    int ile;
    int *tab1;
    printf("Podaj liczbę elementów tablicy ");
    scanf("%d",&ile);
    tab1=utworzTD(ile);
    printf("tablica dyn:\n");
    wyswietlTD(tab1, ile);
    usunTD(tab1);
    return 0;
}
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
    printf ("\nZawartosc tablicy:\n");
    for (i=0; i<n; i++)
        printf ("%d\t", *(tabD+i));
    printf ("\n ");
}

void usunTD(int *tabD)
{
    free(tabD);
    tabD=0;
}
