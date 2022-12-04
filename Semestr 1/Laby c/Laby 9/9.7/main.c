#include <stdio.h>
#include <stdlib.h>

int najwieksze(int, int *);

int main()
{
    int n, naj, naj2;
    do{
        printf("Podaj liczbe elementow: \n");
        scanf("%d", &n);
    } while(n<2);
    naj = najwieksze(n, &naj2);
    printf("Pierwsza najwieksza: %d, Druga najwieksza: %d", naj, naj2);
    return 0;
}

int najwieksze(int n, int *x)
{
    int liczba, najwieksza;
    printf("Podaj liczbe calkowita: \n");
    scanf("%d", &liczba);
    najwieksza = liczba;
    *x = 0;

    for(int i = 1; i < n; i++)
    {
        printf("Podaj liczbe calkowita: \n");
        scanf("%d", &liczba);
        if (liczba > najwieksza)
        {
            *x = najwieksza;
            najwieksza = liczba;
        }
        else if(liczba > *x) *x = liczba;
    }
    return najwieksza;
}
