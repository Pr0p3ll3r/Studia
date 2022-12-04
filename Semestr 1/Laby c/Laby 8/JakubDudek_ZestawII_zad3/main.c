#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float liczba, temp;
    int x;
    do
    {
        printf("Podaj liczbe elementow (min 0, max 20): \n");
        scanf("%d", &n);
    }while(n < 0 || n > 20);

    if(n>0)
    {
        printf("Podaj liczbe zmiennoprzecinkowa: \n");
        scanf("%f", &liczba);
        temp = liczba;

        for(int i=1;i<n;i++)
        {
            printf("Podaj liczbe zmiennoprzecinkowa: \n");
            scanf("%f", &liczba);
            if(liczba>=temp)
            {
                printf("Nie jest to ciag scisle malejacy");
                x==0;
                break;
            }
        }
        if(x==1)
            printf("Jest to ciag scisle malejacy");

    }
    else
        printf("Brak elementow");


    return 0;
}
