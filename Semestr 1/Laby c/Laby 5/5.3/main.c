#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float z1(float alfa, int t);
float z2(float alfa, int t);

int main()
{
    int t;
    float alfa;
    printf("Podaj t: ");
    scanf("%d", &t);
    printf("Podaj alfa: ");
    scanf("%f", &alfa);
    alfa *= M_PI / 180;
    printf("(If)Wartosc wynosi: %f\n", z1(alfa, t));
    printf("(Switch)Wartosc wynosi: %f", z2(alfa, t));
    return 0;
}

float z1(float a, int t)
{
    float w;
    if(t == 8)
    {
        w = 1 - sin(a);
    }
    else if(t >= 0 && t<= 3)
    {
        w = 1/2 * (1+cos(a));
    }
    else if(t == 4 || t == 6 || t == 7)
    {
        w = sqrt(pow(a, 2) + 1);
    }
    else
    {
        printf("Bledny parametr t\n");
        w = 0;
    }
    return w;
}

float z2(float a, int t)
{
    float w;
    switch(t)
        {
        case 0:
        case 1:
        case 2:
        case 3:
             w = 1/2 * (1+cos(a));
            break;
        case 4:
        case 6:
        case 7:
            w = sqrt(pow(a, 2) + 1);
            break;
        case 8:
            w = 1 - sin(a);
            break;
        default:
            printf("Bledny parametr t\n");
            w = 0;
            break;
        }
        return w;
}
