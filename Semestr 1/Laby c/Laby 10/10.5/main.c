#include <stdio.h>
#include <stdlib.h>

void wczytajTablice(int N, float tab[][N]);
void wyswietlTablice(int N, float tab[][N]);
void iloczyn(int N, float tab[][N]);
void suma(int N, float tab[][N]);

int main()
{
    int N;

    do{
        printf("Podaj liczbe wierszy: ");
        scanf("%d",&N);
    }while(N <= 0);

    float tab[N][N];

    wczytajTablice(N,tab);
    wyswietlTablice(N,tab);
    iloczyn(N,tab);
    suma(N,tab);
    return 0;
}

void wczytajTablice(int N, float tab[N][N])
{
    for(int i = 0;i<N;i++)
    {
        for(int j =0;j<N;j++)
        {
            printf("tab[%d][%d] = ", i, j);
            scanf("%f", &tab[i][j]);
        }
    }
}

void wyswietlTablice(int N, float tab[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%f  ", tab[i][j]);
        }
        printf("\n");
    }
}

void iloczyn(int N, float tab[N][N])
{
    float iloczyn = 1;

    for(int i=0;i<N;i++)
    {
        iloczyn *= tab[i][i];
    }

    printf("Iloczyn elementow na glownej przekatnej wynosi %f\n", iloczyn);
}

void suma(int N, float tab[N][N])
{
    float suma = 0;

    for(int i=0;i<N;i++)
    {
        suma += tab[i][i];
    }

    printf("Suma elementow na glownej przekatnej wynosi %f\n", suma);
}
