#include "tv.h"
using namespace std;

TV::TV()
{

}

TV::TV(std::string name, float price, int stock, float diag, std::string type):Product(name,price,stock)
{
    this->diag=diag;
    this->type=type;
}

TV::~TV()
{

}

void TV::show()
{
    cout<<"Nazwa "<<name<<" Cena "<<price<<" Na stanie: "<<stock<<" Przekatna ekranu "<<diag<<" Rodzaj: "<<type<<endl;
}

float TV::cyberMondayDiscount()
{
    if(type=="flat" && diag > 55)
    {
        return price - (price * 0.3);
    }
    else if(type=="curved")
    {
        return price - (price * 0.25);
    }
    return price;
}
