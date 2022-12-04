#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lat, miesiecy, x;
    printf("Podaj liczbe lat i miesiecy: (.../...)\n");
    scanf("%d/%d", &lat, &miesiecy);
    printf("Podaj liczbe miesiecy, ktora chcesz dodac: \n");
    scanf("%d", &x);

    miesiecy += x;
    while(miesiecy>11)
    {
        lat++;
        miesiecy-=12;
    }

    printf("Twoj wiek w przyszlosci: %d lat %d miesiecy", lat, miesiecy);
    return 0;
}
