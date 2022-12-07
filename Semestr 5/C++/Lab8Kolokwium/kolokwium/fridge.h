#ifndef FRIDGE_H
#define FRIDGE_H

#include "product.h"

class Fridge : public Product
{
private:
    float height;
    bool no_frost;
public:
    Fridge();
    Fridge(std::string name, float price, int stock, float height, bool no_frost);
    ~Fridge();
    virtual void show() override;
    virtual float cyberMondayDiscount() override;
};

#endif // FRIDGE_H
