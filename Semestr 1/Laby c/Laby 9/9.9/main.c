#include <stdio.h>
#include <stdlib.h>

int wyznaczniki(float, float, float, float, float, float, float *, float *);

int main()
{
    float a1, b1, c1, a2, b2, c2, x, y;
    printf("Podaj parametry A, B, C pierwszego rownania liniowego: (Ax+By=C)\n");
    scanf("%f %f %f", &a1, &b1, &c1);
    printf("Podaj parametry A, B, C drugiego rownania liniowego: (Ax+By=C)\n");
    scanf("%f %f %f", &a2, &b2, &c2);

    int wynik = wyznaczniki(a1,b1,c1,a2,b2,c2,&x,&y);

    if(wynik == -1)
        printf("Uklad sprzeczny: Brak rozwiazan");
    else if(wynik == 0)
        printf("Uklad nieoznaczony: Nieskonczenie wiele rozwiazan");
    else
        printf("Uklad ma rozwiazanie: x = %f y = %f", x, y);

    return 0;
}

int wyznaczniki(float a1, float b1, float c1, float a2, float b2, float c2, float *x, float *y)
{
    float W, Wx, Wy;
    W = a1*b2 - a2*b1;
    Wx = c1*b2 - c2*b1;
    Wy = a1*c2 - a2*c1;
    if(W == 0 && Wx == 0 && Wy == 0) return 0;
    else if(W == 0 && (Wx != 0 || Wy != 0)) return -1;
    else if(W != 0)
    {
        *x = Wx/W;
        *y = Wy/W;
        return 1;
    }
}
