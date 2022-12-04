#include <iostream>
#include <math.h>

using namespace std;
class Error //stworzenie klasy po ktorej beda dziedziczyly klasy reprezentujace poszczegolne wyjatki
{
public:
    virtual void error()=0;  //czysto wirtualna metoda, zaimplementowana w klasach potomnych
    virtual~Error() {};
};
class SquareRootError: public Error
{
public:
    void error()
    {
        cout<<"Pierwiastek z liczby ujemnej"<<endl;
    }
};

double sqrt_function1(int a)
{
    if(a<0)
    {
        throw SquareRootError(); //rzucenie obiektu klasy SquareRoot
    }
    else
    {
        return sqrt(a);
    }
}
double sqrt_function2(int a)
{
    if(a<0)
    {
        throw new SquareRootError(); //rzucenie wskaznika na obiekt klasy SquareRootError
    }
    else
    {
        return sqrt(a);
    }
}
int main()
{
    //I wersja
    try
    {
        double result=sqrt_function1(-5);

        cout<<"Wynik to: "<<result<<endl;

    }
    catch(SquareRootError p) //wyjatek obiekt typu SquareRootError
    {
        p.error();
    }
//II wersja
    try
    {
        double result=sqrt_function2(-5);

        cout<<"Wynik to: "<<result<<endl;


    }
    catch(Error *b) //wyjatek wskaznik na obiekt klasy Error --> polimorfizm
    {
        b->error();
        delete b; //przy rzucaniu wyjatku pojawil sie operator new wiec trzeba uzyc delete
    }

//III wersja
    try
    {
        double result=sqrt_function1(-5);

        cout<<"Wynik to: "<<result<<endl;

    }
    catch(Error &b) //polimorfizm
    {
        b.error();
    }
    return 0;


};
