#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(0,0);
    cin>>c1;
    Complex c2(0,0);
    cin>>c2;
    c1.show();
    c2.show();

    //operator -
    Complex *c3=new Complex(5, 11);
    Complex c4=c1-c3;
    c3->show();
    c4.show();

    //operator *
    Complex c5=c2*c3;
    c5.show();

    cout<<(c5>c4);

    Complex tab[5];
    for(int i=0;i<5;i++)
    {
        Complex(i+1, i+2);
    }
    Complex cc = maxModule(tab, 5);
    cc.show();
    return 0;
}
