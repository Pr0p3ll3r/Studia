#ifndef CINT27_H_INCLUDED
#define CINT27_H_INCLUDED
#include <iostream>
using namespace std;
class CInt27
{
private:
    int x;
public:
    CInt27(int x);
    CInt27 operator*(CInt27 *c);
    CInt27 operator+(CInt27 *c);
    CInt27 operator*=(int x);
    CInt27 operator++();
    friend ostream & CInt27 operator<<(ostream screen, CInt27 *c);
};

#endif // CINT27_H_INCLUDED
