#include <stdio.h>
#include <stdlib.h>

int main()
{
    char znak;
    printf("Podaj znak: ");
    scanf("%c", &znak);
    printf("Podales znak: %c, Kod ASCII: %d\n", znak, znak);
    printf("Nastepny znak: %c, Kod ASCII: %d\n", znak+1, znak+1);
    printf("Podaj mala liter: ");
    scanf(" %c", &znak);
    znak = znak - 32;
    printf("Po zamianie na duza litere: %c", znak);
    return 0;
}
