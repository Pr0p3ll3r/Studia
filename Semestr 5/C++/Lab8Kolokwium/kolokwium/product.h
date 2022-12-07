#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
protected:
    std::string name;
    float price;
    int stock;
public:
    Product();
    Product(std::string name, float price, int stock);
    virtual ~Product();
    const std::string &getName() const;
    float getPrice() const;
    int getStock() const;
    virtual void show()=0;
    virtual float cyberMondayDiscount()=0;
};

#endif // PRODUCT_H
