#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <iostream>
using namespace std;
class Complex
{
private:
    double re;
    double im;
public:
    Complex(double re, double im);
    Complex();
    ~Complex();
    void show();
    Complex operator-(Complex *c2);
    Complex operator*(Complex *c2);
    bool operator>(Complex c1);
    friend istream & operator>>(istream & keyboard, Complex &c);
    friend Complex maxModule(Complex tab[], int n);
};


#endif // COMPLEX_H_INCLUDED
