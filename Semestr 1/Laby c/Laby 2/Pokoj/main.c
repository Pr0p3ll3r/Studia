#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b,c,y,p;
    int lp;
    printf("Podaj wymiary pokoju: szer, dl i wysokosc\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    printf("Podaj na ile m^2 wystarcza 1 litr puszki\n");
    scanf("%f", &y);
    if(a>0&&b>0&&c>0&&y>0)
    {
        p = a*b+2*a*c+2*b*c-0.9-1.6;
        lp = ceil(p/y);
        printf("Potrzeba %d puszek farby na pomalowanie pokoju", lp);
    }
    else
    {
        printf("Bledne dane");
    }
    return 0;
}
