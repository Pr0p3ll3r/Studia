#include <iostream>
#include <stdlib.h>

using namespace std;

void bubbleSort(float x[], float y[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (x[j] < x[j+1])
            {
                swap(x[j], x[j+1]);
                swap(y[j], y[j+1]);
            }
        }
    }
}

float newton(int n, float punkt, float x[], float y[])
{
    int i=0, j=1;
    while(j<=n)
    {
        i=n;
        while(i>=j)
        {
            y[i] = (y[i] - y[i-1])/(x[i]-x[i-j]);
            i--;
        }
        j++;
    }
    float wynik=y[0];
    float iloraz=1;
    for(int k=1;k<=n;k++)
    {
        iloraz=(punkt-x[k-1]) * iloraz;
        cout<<"Iloraz "<<iloraz<<endl;
        wynik=wynik + y[k]*iloraz;
        cout<<"Wynik "<<wynik<<endl;
    }
    return wynik;
}

int main()
{
    int n=4;
    float wynik=0, punkt=-3;
    float x[n+1] = {-4,-2,0,1,3};
    float y[n+1] ={-1,-7,-21,-1,573};
    wynik = newton(n, punkt, x, y);
    cout<<"Wynik: "<<wynik<<endl;
    /*bubbleSort(x, y, n);
    for(int i=0;i<n;i++)
    {
        if(x[i]==x[i+1])
        {
            cout<<"Wezly nie sa rozne"<<endl;
            exit(0);
        }
    }
    if(punkt >= x[0] && punkt <= x[n+1])
    {
        cout<<"Wynik: "<<wynik<<endl;
    }
    else
    {
        cout<<"Punkt nie nalezy do dziedziny"<<endl;
    }*/
    return 0;
}
