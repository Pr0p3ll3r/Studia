#include "product.h"

const std::string &Product::getName() const
{
    return name;
}

int Product::getAmount() const
{
    return amount;
}

Product::Product(std::string name, int amount)
{
    this->name = name;
    this->amount = amount;
}
