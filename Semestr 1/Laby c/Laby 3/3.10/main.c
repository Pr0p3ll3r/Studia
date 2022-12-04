#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,tmp;
    int s,d,j;
    printf("Podaj 1 liczbe trzycyfrowa:\n");
    scanf("%d", &a);
    printf("Podaj 2 liczbe trzycyfrowa:\n");
    scanf("%d", &b);
    tmp = a;
    a = b;
    b = tmp;
    printf("1 liczbe trzycyfrowa: %d\n", a);
    printf("2 liczbe trzycyfrowa: %d\n", b);
    printf("\nLiczby odwrotne: \n", b);
    s = a/100;
    d = (a/10)%10;
    j = a%10;
    printf("1 liczbe trzycyfrowa: %d%d%d\n", j,d,s);
    s = b/100;
    d = (b/10)%10;
    j = b%10;
    printf("2 liczbe trzycyfrowa: %d%d%d\n", j,d,s);
    return 0;
}
