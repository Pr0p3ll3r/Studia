#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1,y1,x2,y2;
    float d, r;
    printf("Podaj wspolrzedne punktu przez ktory przechodzi okrag: (.../...)\n");
    scanf("%f/%f", &x1, &y1);
    printf("Podaj wspolrzedne srodka okrag: (.../...)\n");
    scanf("%f/%f", &x2, &y2);
    r = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    d = 2 * M_PI * r;
    printf("Obwod okregu wynosi: %f", d);
    return 0;
}
