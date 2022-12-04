#include <stdio.h>
#include <stdlib.h>

int ciag(int n);

int main()
{
    int n;
    printf("Ile liczb chcesz wczytac: ");
    scanf("%d", &n);
    if(ciag(n) == 1)
        printf("Jest to ciag rosnacy");
    else
        printf("Nie jest to ciag rosnacy");
    return 0;
}

int ciag(int n)
{
    float tab[n];
    float liczba;

    for(int i=0;i<n;i++)
    {
        printf("Podaj liczbe: \n");
        scanf("%f", &liczba);
        tab[i] = liczba;
    }

    for(int i=0;i<n-1;i++)
    {
        if(tab[i] > tab[i+1])
            return 0;
    }

    return 1;
}
