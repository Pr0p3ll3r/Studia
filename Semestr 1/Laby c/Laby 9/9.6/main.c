#include <stdio.h>
#include <stdlib.h>

int fun(int n, int *ile);

int main()
{
    int n, ileDod, ileZer;
    do{
        printf("Podaj liczbe elementow: \n");
        scanf("%d", &n);
    } while(n<1);

    ileZer = fun(n, &ileDod);
    printf("Liczb dodatnich: %d, Zer: %d", ileDod, ileZer);
    return 0;
}

int fun(int n, int *ile)
{
    int liczba;
    int ileZer = 0;
    *ile = 0;

    for(int i = 0; i < n; i++)
    {
        printf("Podaj liczbe calkowita: \n");
        scanf("%d", &liczba);
        if (liczba > 0) *ile += 1;
        if (liczba == 0) ileZer++;
    }
    return ileZer;
}
