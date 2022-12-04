#include <stdio.h>
#include <stdlib.h>

void stypendium(float x, float y, float z);

int main()
{
    float x, y, z;
    printf("Podaj trzy oceny: \n");
    scanf("%f %f %f", &x, &y, &z);
    stypendium(x,y,z);
    return 0;
}

void stypendium(float x, float y, float z)
{
    float srednia;
    if(x >= 3 && y >= 3 && z >= 3)
    {
        srednia = (x + y + z) / 3;
        if(srednia > 4)
           printf("Przyznano stypendium o wartosci 500 zl");
        else
           printf("Przyznano stypendium o wartosci 300 zl");
    }
    else
    {
        printf("Nie przyznano stypendium");
    }
}
