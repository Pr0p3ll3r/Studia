#include "shop.h"
using namespace std;

Shop::Shop(std::string name)
{
    this->name = name;
}

Shop::~Shop()
{
    cout<<"Destruktor klasy Shop"<<endl;
}

void Shop::add(shared_ptr<Warehouse> w)
{
    warehouses.push_back(w);
}

void Shop::sell(std::string name, int amount)
{
    for(auto it=warehouses.begin();it!=warehouses.end();it++)
    {
        if(it->get()->getName() == name)
        {
            if(it->get()->getAmount() >= amount)
            {
                it->get()->setAmount(it->get()->getAmount() - amount);
                cout<<"Sprzedano "<<it->get()->getName()<<endl;
            }
            else
            {
                cout<<"Za malo sztuk danego artykulu"<<endl;
            }
            return;
        }
    }
    cout<<"Nie ma takiego artykulu"<<endl;
}

void Shop::showName()
{
    cout<<name<<endl;
}

void Shop::showWarehouses()
{
    for(auto it=warehouses.begin();it!=warehouses.end();it++)
    {
        it->get()->show();
    }
}
