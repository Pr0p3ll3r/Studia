#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>

class Warehouse
{
private:
    std::string name;
    int amount;
public:
    Warehouse(std::string name, int amount);
    ~Warehouse();
    void show();
    const std::string &getName() const;
    void setName(const std::string &newName);
    int getAmount() const;
    void setAmount(int newAmount);
};

#endif // WAREHOUSE_H
