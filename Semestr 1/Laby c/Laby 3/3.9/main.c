#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double kat;
    printf("Podaj kat: (w stopniach)\n");
    scanf("%lf", &kat);
    kat = kat * M_PI / 180;
    printf("Sinus: %f\n Cosinus: %f\n Tangens: %f\n Cotangens: %f", sin(kat), cos(kat), tan(kat), cos(kat)/sin(kat));
    return 0;
}
