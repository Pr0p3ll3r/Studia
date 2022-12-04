#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b;
    float sredniaaryt, sredniageo;
    printf("Podaj dwie liczby calkowite: (.../...)\n");
    scanf("%d/%d", &a, &b);
    sredniaaryt = (a+b)/2;
    sredniageo = sqrt(a*b);
    printf("Srednia arytmetyczna wynosi: %1.2f\n", sredniaaryt);
    printf("Srednia geometryczna wynosi: %1.2f", sredniageo);
    return 0;
}
