#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losuj(int lelem, int tab[]);
float srednia(int lelem, int tab[]);
int min(int lelem, int tab[]);
int ileRazy2(int lelem, int x, int tab[]);

int main()
{
    int n, x;
    int tab3[10] = {1,1,1,2,3,3,5,5,6,7};
    int tab4[] = {1,2,3,4,5,6,7,6,4,5};
    do{
        printf("Podaj liczbe elementow: ");
        scanf("%d",&n);
    }while(n <= 0);
    int tab5[n];
    losuj(n,tab5);

    printf("\nPodaj liczbe: ");
    scanf("%d", &x);

    //tab3
    printf("\nTAB3: Srednia elementow wynosi %f", srednia(n,tab3));
    printf("\nTAB3: Najmniejsza wartosc to %d", min(n,tab3));
    printf("\nTAB3: Podana liczba to %d, wystapila %d razy", x, ileRazy2(n,x,tab3));

    //tab4
    printf("\nTAB4: Srednia elementow wynosi %f", srednia(n,tab4));
    printf("\nTAB4: Najmniejsza wartosc to %d", min(n,tab4));
    printf("\nTAB4: Podana liczba to %d, wystapila %d razy", x, ileRazy2(n,x,tab4));

    //tab5
    printf("\nTAB5: Srednia elementow wynosi %f", srednia(n,tab5));
    printf("\nTAB5: Najmniejsza wartosc to %d", min(n,tab5));
    printf("\nTAB5: Podana liczba to %d, wystapila %d razy", x, ileRazy2(n,x,tab5));
    return 0;
}

void losuj(int lelem, int tab[])
{
    srand(time(NULL));
    for(int i = 0;i<lelem;i++)
    {
        int temp = rand() % 10;
        *(tab + i) = temp;
        printf("tab[%d] = %d\n", i, temp);
    }
}

float srednia(int lelem, int tab[])
{
    int suma = 0;
    for(int i=0;i<lelem;i++)
    {
        suma += *(tab + i);
    }
    return suma/(float)lelem;
}

int min(int lelem, int tab[])
{
    int min = *tab;
    for(int i=1;i<lelem;i++)
    {
        if(*(tab + i) < min)
            min = *(tab + i);
    }
    return min;
}

int ileRazy2(int lelem, int x, int tab[])
{
    int ile=0;
    for(int i=0;i<lelem;i++)
    {
        if(*(tab + i) == x)
            ile++;
    }
    return ile;
}
