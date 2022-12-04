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

float neville(int n, float punkt, float x[], float y[])
{
    float p[n+1];
    int k=0,j=0;
    while(k<n+1)
    {
        p[k]=y[k];
        j=k-1;
        while(j>=0)
        {
            p[j]=p[j+1]+(p[j+1]-p[j])*(punkt-x[k])/(x[k]-x[j]);
            j--;
        }
        k++;
    }
    return p[0];
}

int main()
{
    int n=3;
    float wynik=0, punkt=1;
    float x[n+1] = {-3,-1,0,2}, y[n+1] = {-17,9,17,23};
    /*cout<<"Podaj punkt: ";
    cin>>punkt;
    for(int i=0;i<n+1;i++)
    {
        cout<<"Podaj punkt x"<<i<<": ";
        cin>>x[i];
        cout<<"Podaj wartosc w punkcie x"<<i<<": ";
        cin>>y[i];
    }*/
    wynik = neville(n, punkt, x, y);
    bubbleSort(x, y, n);
    for(int i=0;i<n;i++)
    {
        if(x[i]==x[i+1])
        {
            cout<<"Wezly nie sa rozne"<<endl;
            exit(0);
        }
    }
    if(punkt >= x[0] && punkt <= x[n])
    {
        cout<<"Wynik: "<<wynik<<endl;
    }
    else
    {
        cout<<"Punkt nie nalezy do dziedziny"<<endl;
    }
    return 0;
}
