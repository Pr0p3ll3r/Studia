#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "warehouse.h"
#include <vector>
#include <memory>

class Shop
{
private:
    std::string name;
    std::vector<std::shared_ptr<Warehouse>> warehouses;
public:
    Shop(std::string name);
    ~Shop();
    void add(std::shared_ptr<Warehouse> w);
    void sell(std::string name, int amount);
    void showName();
    void showWarehouses();
};

#endif // SHOP_H
