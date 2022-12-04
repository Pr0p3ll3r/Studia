#ifndef TEAMLEADER_H
#define TEAMLEADER_H

#include "employee.h"

class TeamLeader : public Employee
{
public:
    TeamLeader();
    ~TeamLeader();
    TeamLeader(std::string surname1, int age1, int experience1, float salary1);
    virtual float calculateBonus(int value) override;
    virtual void show() override;
};

#endif // TEAMLEADER_H
