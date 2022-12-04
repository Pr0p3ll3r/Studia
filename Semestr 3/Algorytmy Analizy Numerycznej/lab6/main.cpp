#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

float suma(int n, float x[])
{
    float suma = 0;
    for(int i=0;i<=n;i++)
    {
        suma += x[i];
    }
    return suma;
}

float sumaKwadratow(int n, float x[])
{
    float suma = 0;
    for(int i=0;i<=n;i++)
    {
        suma += pow(x[i],2);
    }
    return suma;
}

float sumaIloczynow(int n, float x[], float f[])
{
    float suma = 0;
    for(int i=0;i<=n;i++)
    {
        suma += x[i]*f[i];
    }
    return suma;
}

void aproksymacja1(int n, float x[], float f[], float punkt, float &a0, float &a1)
{
    float cz1,cz2,cz3,cz4,cz5,cz6,w,w0,w1;
    cz1 = n+1;
    cz2 = suma(n, x);
    cz3 = suma(n, f);
    cz4 = suma(n, x);
    cz5 = sumaKwadratow(n, x);
    cz6 = sumaIloczynow(n, x, f);
    w = cz1*cz5 - cz2*cz4;
    w0 = cz3*cz5 - cz2*cz6;
    w1 = cz1*cz6 - cz3*cz4;
    a0 = w0/w;
    a1 = w1/w;
}

float aproksymacja2(int n, float x[], float f[], float punkt)
{
    float a0,a1;
    for(int i=0;i<=n;i++)
    {
        x[i] = 1/x[i];
    }
    aproksymacja1(n,x,f,punkt,a0,a1);
    cout<<"g(x)="<<a0<<" + "<<a1<<"/x"<<endl;
    float wynik = (float)a1/punkt + a0;
    return wynik;
}

float aproksymacja3(int n, float x[], float f[], float punkt)
{
    float a0,a1;
    for(int i=0;i<=n;i++)
    {
        f[i] = log(f[i]);
    }
    aproksymacja1(n,x,f,punkt,a0,a1);
    cout<<"g(x)="<<"e^"<<a0<<"*((e)^"<<a1<<")^"<<punkt<<")"<<endl;
    a0 = pow(2.7, a0);
    a1 = pow(2.7, a1);
    float wynik = (float)a1*pow(a0,punkt);
    return wynik;
}

int main()
{
    int n=4;
    //float x[n+1] = {1,3,4,6,8}, f[n+1] = {-4,-8,-10,-14,-18};
    //float x[n+1] = {1,(float)1/3,(float)1/5,(float)1/6,(float)1/7}, f[n+1] = {4,8,12,14,16};
    float x[n+1] = {1,2,3,5,7}, f[n+1] = {1,20.08,403.42,162754.79,65659969.13};
    float wynik, punkt, a0, a1;
    punkt = 5;
    //punkt = (float)1/3;
    float minx = INT_MAX;
    float maxx = INT_MIN;
    for(int i=0; i<=n; i++)
    {
        if(x[i]>maxx) maxx=x[i];
        if(x[i]<minx) minx=x[i];
    }
    for(int i=0;i<n;i++)
    {
        if(x[i]==x[i+1])
        {
            cout<<"Wezly nie sa rozne"<<endl;
            exit(0);
        }
    }
    if(punkt >= minx && punkt <= maxx)
    {
        //aproksymacja1(n,x,f,punkt,a0,a1);
        //cout<<"g(x)="<<a0<<" + "<<a1<<"x"<<endl;
        //wynik = a0+a1*punkt;

        //wynik = aproksymacja2(n,x,f,punkt);

        wynik = aproksymacja3(n,x,f,punkt);
        cout<<"Wynik: "<<wynik<<endl;
    }
    else
    {
        cout<<"Punkt nie nalezy do dziedziny"<<endl;
    }
    return 0;
}
