#include <stdio.h>
#include <stdlib.h>

void sprawdz(float x, float y);

int main()
{
    float x, y;
    printf("Podaj wspolrzedne punktu: (.../...)\n");
    scanf("%f/%f", &x, &y);
    sprawdz(x, y);
    return 0;
}

void sprawdz(float x, float y)
{
    if((x >= -1 && x <= 1) && (y >= -1 && y <= 1))
    {
        printf("Punkt nalezy do obszaru");
    }
    else
    {
        printf("Punkt nie nalezy do obszaru");
    }

}
