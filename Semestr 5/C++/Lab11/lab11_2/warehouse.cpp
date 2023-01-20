#include "warehouse.h"
using namespace std;

Warehouse::Warehouse(std::string name, int amount)
{
    this->name = name;
    this->amount = amount;
}

Warehouse::~Warehouse()
{
    cout<<"Destruktor klasy Warehouse"<<endl;
}

const std::string &Warehouse::getName() const
{
    return name;
}

void Warehouse::setName(const std::string &newName)
{
    name = newName;
}

int Warehouse::getAmount() const
{
    return amount;
}

void Warehouse::setAmount(int newAmount)
{
    amount = newAmount;
}

void Warehouse::show()
{
    cout<<name<<" "<<amount<<endl;
}
