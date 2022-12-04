#include <iostream>
#include <cmath>

using namespace std;

void trapezy(int m, float a, float b)
{
    float wynik=0,x=0,f=0,h=0;
    int i=0;
    h=(b-a)/m;
    while(i<=m)
    {
        x=a+i*h;
        f=pow(sin(x),2)+2;
        //f=exp(x)*2*pow(x,3);
        if(i==0 || i==m)
            wynik += (float)1/2 * f;
        else
            wynik += f;
        i++;
    }
    wynik *= h;
    cout<<"Wzor trapezow: "<<wynik<<endl;
}

void simpson(int m, float a, float b)
{
    float wynik=0,x=0,f=0,h=0;
    int i=0;
    h=(b-a)/m;
    while(i<=m)
    {
        x=a+i*h;
        f=exp(x);
        //f=exp(x)*2*pow(x,3);
        if(i==0 || i==m)
            wynik += f;
        else if(i%2==0)
            wynik += (2 * f);
        else
            wynik += (4 * f);
        i++;
    }
    wynik *= (float)(h/3);
    cout<<"Wzor Simpsona: "<<wynik<<endl;
}

void hermit()
{
    int n=4;
    float wynik=0;
    int i=0;
    float x4=2.020183,x3=0.958572,x2=0,x1=(-1)*x3,x0=(-1)*-x4;
    float H4=0.019953,H3=0.393619,H2=0.945309,H1=H3,H0=H4;
    wynik+=H4*cos(x4);
    wynik+=H3*cos(x3);
    wynik+=H2*cos(x2);
    wynik+=H1*cos(x1);
    wynik+=H0*cos(x0);
    cout<<"Kwadratura Gauss'a Hermit'a: "<<wynik<<endl;
}

int main()
{
    int m=6;
    //float a=0,b=2*M_PI;
    //float a=0,b=2;
    float a=0,b=12;
    trapezy(m,a,b);
    simpson(m,a,b);
    hermit();
    return 0;
}
