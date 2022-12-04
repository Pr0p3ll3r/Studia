#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14

void fun(int x)
{
    cout<<"Wartosc funkcji wynosi "<<((abs(pow(x,3)) - 3 + x)/(sqrt(pow(x,2) + 6 * PI)))<<endl;
}

int main()
{
    int x;
    cout<<"Podaj parametr x: ";
    cin>>x;
    fun(x);
    return 0;
}
