#ifndef TV_H
#define TV_H

#include "product.h"

class TV : public Product
{
private:
    float diag;
    std::string type;
public:
    TV();
    TV(std::string name, float price, int stock, float diag, std::string curved);
    ~TV();
    virtual void show() override;
    virtual float cyberMondayDiscount() override;
};

#endif // TV_H
