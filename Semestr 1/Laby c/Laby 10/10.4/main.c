#include <stdio.h>
#include <stdlib.h>

void wczytajTablice(int N, int M, float tab[][M]);
void wyswietlTablice(int N, int M, float tab[][M]);
void suma_srednia(int N, int M, float tab[][M]);

int main()
{
    int N, M, wybor;
    float tab[N][M];
    do
    {
        printf("0: KONIEC PROGRAMU\n");
        printf("1: WCZYTAJ TABLICE\n");
        printf("2: WYSWIETL TABLICE\n");
        printf("3: SUMA I SREDNIA ELEMENTOW TABLICY\n");
        scanf("%d", &wybor);
        switch(wybor)
        {
            case 1:
                 do{
                    printf("Podaj liczbe wierszy: ");
                    scanf("%d",&N);
                 }while(N <= 0);

                do{
                    printf("Podaj liczbe kolumn: ");
                    scanf("%d",&M);
                }while(M <= 0);
                wczytajTablice(N,M,tab);
                break;
            case 2:
                wyswietlTablice(N,M,tab);
                break;
            case 3:
                suma_srednia(N,M,tab);
                break;
        }
    }while(wybor!=0);
    return 0;
}

void wczytajTablice(int N, int M, float tab[][M])
{
    for(int i = 0;i<N;i++)
    {
        for(int j =0;j<M;j++)
        {
            printf("tab[%d][%d] = ", i, j);
            scanf("%f", &tab[i][j]);
        }
    }
}

void wyswietlTablice(int N, int M, float tab[][M])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%f  ", tab[i][j]);
        }
        printf("\n");
    }
}

void suma_srednia(int N, int M, float tab[][M])
{
    float suma = 0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            suma += tab[i][j];
        }
    }

    printf("Suma wynosi %f\nSrednia wynosi %f\n", suma, suma/(N*M));
}
