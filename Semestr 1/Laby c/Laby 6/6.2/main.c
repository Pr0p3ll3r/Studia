#include <stdio.h>
#include <stdlib.h>

void sredniaWhile(int n);
void sredniaDoWhile(int n);

int main()
{
    int n;
    printf("Podaj liczbe elementow: \n");
    scanf("%d", &n);
    if(n >= 2)
    {
        sredniaWhile(n);
        sredniaDoWhile(n);
    }
    else
        printf("Nalezy podac przynajmniej 2 liczby");
    return 0;
}

void sredniaWhile(int n)
{
    int i = 1, a, s = 0;

    while(i <= n)
    {
        printf("Podaj liczbe calkowita: ");
        scanf("%d", &a);
        s += a;
        i++;
    }
    printf("Srednia wynosi: %f\n", (float)s/n);
}

void sredniaDoWhile(int n)
{
    int i = 1, a, s = 0;

    do
    {
        printf("Podaj liczbe calkowita: ");
        scanf("%d", &a);
        s += a;
        i++;
    }while(i <= n);
    printf("Srednia wynosi: %f", (float)s/n);
}
