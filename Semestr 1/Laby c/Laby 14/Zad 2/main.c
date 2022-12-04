#include <stdio.h>
#include <stdlib.h>

struct Zawodnik{
    char nazwisko[25];
    float wysokosc;
};

struct Zawodnik *utworzTab(int k);
void wyswietlTab(struct Zawodnik *tab, int k);
void usunTab(int *tabD);

int main()
{
    int k = 0;
    float min = 0;
    struct Zawodnik *tab;
    while(k<=0)
    {
        printf("Podaj liczbe zawodnikow ");
        scanf("%d",&k);
    }

    tab=utworzTab(k);
    wyswietlTab(tab, k);

    min = tab[0].wysokosc;
    for(int i=1;i<k;i++)
    {
        if(tab[i].wysokosc<min)
            min = tab[i].wysokosc;
    }
    printf("Najnizszy skok:\n");
    for(int j=0;j<k;j++)
    {
        if(tab[j].wysokosc==min)
        {
            printf ("%s\t%0.2f\n", tab[j].nazwisko, tab[j].wysokosc);
        }
    }

    usunTab(tab);
    return 0;
}

struct Zawodnik *utworzTab(int k)
{
    struct Zawodnik *tab = (struct Zawodnik*) malloc (k*sizeof(struct Zawodnik));
    if(tab==NULL)
    {
        printf("Blad przydzialu pamieci\n");
        exit(EXIT_FAILURE);
    }
    for (int i=0; i<k; i++)
    {
        printf("Zawodnik %d\n", i+1);
        printf("Nazwisko: ");
        scanf("%s", &(tab[i].nazwisko));
        printf("Wysokosc skoku: ");
        scanf("%f", &(tab[i].wysokosc));
    }
    return tab;
}

void wyswietlTab(struct Zawodnik *tab, int n)
{
    printf ("\nZawodnicy:\n");
    for (int i=0; i<n; i++)
    {
        printf ("%s\t%0.2f\n", tab[i].nazwisko, tab[i].wysokosc);
    }
}

void usunTab(int *tabD)
{
    free(tabD);
    tabD=0;
}
