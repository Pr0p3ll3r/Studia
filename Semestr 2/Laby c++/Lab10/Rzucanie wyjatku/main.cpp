#include <iostream>
#include <math.h>
using namespace std;
double sqrt_function(int a)
{
    if(a<0)
    {
        throw -1.0; //rzucenie wyjatku typ rzucanego wyjatku nie jest powiazany z typem zwracanym
    }
    else
    {
        return sqrt(a);
    }
}
char upperCase(char character)
{
    int code=(int) character;
    if((code>=(int)'a' )&& (code<=(int) 'z'))
    {
        return (char)(code-32); //z malej litery do duzej
    }
    else
    {
        throw false;  //rzucenie wyjatku
    }
}
int main()
{
    try //sekcja zglaszania wyjatkow
    {
        //double result=sqrt_function(-5);
        char character=upperCase('w');
        //cout<<"Wynik to: "<<result<<endl;
        cout<<"Wynik to: "<<character<<endl;

    }
    catch(double w1) //lapanie wyjatkow, okreslenei typu wyjatku
    {
        //jesli jakis wyjatek zostanie zlapany, program przechodzi za sekcje catch'ow
        cout<<"Zplapany wyjatek double "<<w1<<endl;
    }
    catch(bool line)
    {
        cout<<"Zlapany wyjatek bool "<<line<<endl;
    }
    catch(...)  //jesli nie zostal zlapany nigdzie wyjzej wyjatek to zawsze wykona sie blok ...
    {
        cout<<"Brak zdefiniowanego wyjatku"<<endl;

    }
    return 0;
}
