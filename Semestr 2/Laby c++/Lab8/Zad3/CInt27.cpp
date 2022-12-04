#include <iostream>
#include "CInt27.h"
using namespace std;

CInt27::CInt27(int x)
{
    this->x=x;
}

CInt27 CInt27::operator*(CInt27 *c)
{
    CInt27 cn(x*c->x);
    return cn;
}

CInt27 CInt27::operator+(CInt27 *c)
{
    CInt27 cn(x+c->x);
    return cn;
}

CInt27 CInt27::operator*=(int x)
{
    CInt27 cn(c.x*x);
    return cn;
}

CInt27 CInt27::operator++()
{
    x++;
    return this;
}

ostream & CInt27 operator<<(ostream screen, CInt27 *c)
{
    screen<<c->x;
    return screen;
}
