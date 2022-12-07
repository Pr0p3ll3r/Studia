#include "product.h"

const std::string &Product::getName() const
{
    return name;
}

float Product::getPrice() const
{
    return price;
}

int Product::getStock() const
{
    return stock;
}

Product::Product()
{

}

Product::Product(std::string name, float price, int stock)
{
    this->name=name;
    this->price=price;
    this->stock=stock;
}

Product::~Product()
{

}
