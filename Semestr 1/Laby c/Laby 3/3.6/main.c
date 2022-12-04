#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, k;
    printf("Podaj ilosc mil: ");
    scanf("%d", &m);
    if(m>0) printf("Ilosc km: %1.3f\n", m*0.625);
    else printf("blad\n");
    printf("Podaj ilosc kilometrow: ");
    scanf("%d", &k);
    if(k>0) printf("Ilosc mil: %1.3f", k*1.6);
    else printf("blad");
    return 0;
}
