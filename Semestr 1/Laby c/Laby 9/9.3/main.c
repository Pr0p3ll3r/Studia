#include <stdio.h>
#include <stdlib.h>

void przypisz(int *x, int *y);

int main()
{
    int x,y;
    printf("Podaj 2 liczby calkowite: ");
    scanf("%d %d", &x, &y);
    przypisz(&x, &y);
    printf("Pierwsza liczba: %d\n", x);
    printf("Druga liczba: %d", y);
    return 0;
}

void przypisz(int *x, int *y)
{
    int suma = *x + *y;
    int roznica = *x - *y;
    *x = suma;
    *y = roznica;
}
