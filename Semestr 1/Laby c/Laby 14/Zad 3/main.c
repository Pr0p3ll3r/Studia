#include <stdio.h>
#include <stdlib.h>

void wczytajTab(int n,int m, int tab[][m]);
void wyswietlTab(int n,int m,int tab[][m]);
void iloczyn(int n,int m,int tab[][m]);

int main()
{
    int lw,lk;
    printf("Podaj liczbe wierszy tablicy ");
    scanf("%d",&lw);
    printf("Podaj liczbe kolumn tablicy ");
    scanf("%d",&lk);
    int tab[lw][lk];
    wczytajTab(lw,lk,tab);
    wyswietlTab(lw,lk,tab);
    iloczyn(lw,lk,tab);
    return 0;
}

void wczytajTab(int n,int m,int tab[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("tab[%d][%d]= ", i,j);
            scanf("%d", &(tab[i][j]));
        }
    }
}

void wyswietlTab(int n,int m,int tab[][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
     }
}

void iloczyn(int n,int m,int tab[][m])
{
    int wynik = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            wynik *= tab[i][j];
        }
     }
     printf("Iloczyn wszystkich elementow wynosi: %d", wynik);
}
