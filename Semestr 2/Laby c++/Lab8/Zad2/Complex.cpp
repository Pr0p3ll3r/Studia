#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

Complex::Complex(double re, double im)
{
    this->re=re;
    this->im=im;
}

Complex::Complex()
{
    re=0;
    im=0;
}

Complex::~Complex()
{}

void Complex::show()
{
    cout<<re<<" + "<<im<<" i"<<endl;
}

Complex Complex::operator-(Complex *c2)
{
    Complex cn(re-c2->re, im-c2->im);
    return cn;
}

Complex Complex::operator*(Complex *c2)
{
    Complex ln(re*c2->re, im*c2->im);
    return ln;
}

bool Complex::operator>(Complex c1)
{
    if(im>c1.im)
    {
        return true;
    }
    else
    {
        return false;
    }
}

istream & operator>>(istream & keyboard, Complex &c)
{
    keyboard>>c.re;
    keyboard>>c.im;
    return keyboard;
}

Complex maxModule(Complex tab[], int n)
{
    int x = 0;
    double z = sqrt(pow(tab[0].re, 2) + pow(tab[0].im, 2));
    for(int i=1;i<n;i++)
    {
        double temp=sqrt(pow(tab[i].re, 2) + pow(tab[i].im, 2));
        if(temp > z)
        {
            z = temp;
            x = i;
        }
    }
    return tab[x];
}
