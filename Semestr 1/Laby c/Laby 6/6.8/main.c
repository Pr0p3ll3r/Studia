#include <stdio.h>
#include <stdlib.h>

void fun(float wplata, float procent);

int main()
{
    float wplata, oprocentowanie;
    printf("Podaj kwote wplaty oraz oprocentowanie roczne: \n");
    scanf("%f %f", &wplata, &oprocentowanie);
    fun(wplata, oprocentowanie);
    return 0;
}

void fun(float wplata, float procent)
{
    int lat=0;
    float x = wplata*2;
    while(wplata < x)
    {
        int temp = wplata * procent * 0.01;
        wplata += temp;
        //printf("%f\n", wplata);
        lat++;
    }

    printf("Kwota bedzie podwojona po uplywie %d lat\nKwota bedzie wynosila %f", lat, wplata);
}
