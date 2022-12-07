#include "fridge.h"
using namespace std;

Fridge::Fridge()
{

}

Fridge::Fridge(std::string name, float price, int stock, float height, bool no_frost):Product(name,price,stock)
{
    this->height=height;
    this->no_frost=no_frost;
}

Fridge::~Fridge()
{

}

void Fridge::show()
{
    cout<<"Nazwa "<<name<<" Cena "<<price<<" Na stanie: "<<stock<<" Wysokosc "<<height<<" NoFrost?: "<<no_frost<<endl;
}

float Fridge::cyberMondayDiscount()
{
    if(no_frost)
    {
        return price - (price * 0.15);
    }
    else
    {
        return price - (price * 0.05);
    }
}
