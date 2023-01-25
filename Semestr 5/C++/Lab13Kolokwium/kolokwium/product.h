#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
private:
    std::string name;
    int amount;
public:
    Product(std::string name, int amount);
    const std::string &getName() const;
    int getAmount() const;
};
#endif // PRODUCT_H
