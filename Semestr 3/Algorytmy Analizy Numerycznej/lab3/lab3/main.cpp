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

float lagrange(int n, float punkt, float x[], float y[])
{
    float wynik=0, l=1;

    for(int i=0;i<n+1;i++)
    {
        l=1;
        for(int j=0;j<n+1;j++)
        {
            if(i==j) continue;

            l *= (punkt-x[j])/(x[i]-x[j]);
        }
        wynik += l*y[i];
    }
    return wynik;
}

int main()
{
    int n;
    float wynik=0, punkt;
    cout<<"Podaj stopien wielomianu: ";
    cin>>n;
    float x[n+1], y[n+1];
    cout<<"Podaj punkt: ";
    cin>>punkt;
    for(int i=0;i<n+1;i++)
    {
        cout<<"Podaj punkt x"<<i<<": ";
        cin>>x[i];
        cout<<"Podaj wartosc w punkcie x"<<i<<": ";
        cin>>y[i];
    }
    wynik = lagrange(n, punkt, x, y);
    bubbleSort(x, y, n);
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
    }
    return 0;
}
