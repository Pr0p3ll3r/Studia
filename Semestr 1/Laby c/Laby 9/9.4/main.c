#include <stdio.h>
#include <stdlib.h>

int iloczyn(int, int *);

int main()
{
    int x, czy, ilocz;
    do{
        printf("Podaj liczbe elementow ciagu: \n");
        scanf("%d", &x);
    } while(x<=1);

    czy = iloczyn(x, &ilocz);

    if(czy != 0)
        printf("Iloczyn liczb wynosi %d", ilocz);
    else
        printf("Brak liczb spelniajacych zalozenie");
    return 0;
}


int iloczyn(int n, int *il)
{
    int i, a;
    int ile = 0;
    *il = 1;

    for(i = 0; i < n; i++)
    {
        printf("Podaj liczbe calkowita: \n");
        scanf("%d", &a);
        if (a >=1 && a <= 100)
        {
            *il*=a;
            ile++;
        }
    }
    return ile;
}
