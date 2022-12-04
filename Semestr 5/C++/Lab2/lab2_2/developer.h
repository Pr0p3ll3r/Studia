#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"

class Developer : public Employee
{
public:
    Developer();
    ~Developer();
    Developer(std::string surname1, int age1, int experience1, float salary1);
    virtual float calculateBonus(int value) override;
};

#endif // DEVELOPER_H
