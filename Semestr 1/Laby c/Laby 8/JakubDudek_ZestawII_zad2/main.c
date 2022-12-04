#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,pozycja;
    float liczba, minimalny;

    do
    {
        printf("Podaj liczbe elementow (min 0, max 25): \n");
        scanf("%d", &p);
    }while(p < 0 || p > 25);

    if(p>0)
    {
        printf("Podaj liczbe zmiennoprzecinkowa: \n");
        scanf("%f", &liczba);
        minimalny = liczba;
        pozycja=1;

        for(int i=2;i<=p;i++)
        {
            printf("Podaj liczbe zmiennoprzecinkowa: \n");
            scanf("%f", &liczba);

            if(liczba<minimalny)
                minimalny = liczba;

            if(liczba==minimalny)
                pozycja = i;
        }

        printf("\nElement minimalny to: %f\n", minimalny);
        printf("Pozycja ostatniego wystapenia: %d", pozycja);
    }else
    printf("Brak elementow");


    return 0;
}
