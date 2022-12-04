#include <stdio.h>
#include <stdlib.h>

void fun();

int main()
{
    fun();
    return 0;
}

void fun()
{
    float x, max;
    printf("Podawaj liczbe(ostatnia -1): \n");
    scanf("%f", &max);
    while(x != -1)
    {
        scanf("%f", &x);
        if(x > max)
            max = x;
    }
    printf("Najwieksza: %f\n", max);
}
