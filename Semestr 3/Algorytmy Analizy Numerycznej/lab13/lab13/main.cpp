#include <iostream>
#include <cmath>

using namespace std;

double fun(double x)
{
    return (pow(x,3) - 71);
}

double fun2(double x)
{
    return (3*pow(x,2));
}

double bisekcja(double a, double b, double eps)
{
    double s=0;
    while(true)
    {
        s=(a+b)/2;
        if(abs(fun(s))<=eps)
        {
             return s;
        }
        else
        {
            if(fun(a)*fun(s)<0)
                b=s;
            else
                a=s;
        }
    }
}

double newton(double x0, double eps)
{
    double x=0;
    while(true)
    {
        x=x0-(fun(x0)/fun2(x0));
        if(abs(fun(x))<=eps)
            return x;
        else
            x0=x;
    }
}

int main()
{
    double a=3;
    double b=5;
    double eps=0.1;
    double x0=4;
    cout<<"Bisekcja: "<<bisekcja(a,b,eps)<<endl;
    cout<<"Newton: "<<newton(x0,eps)<<endl;
}
