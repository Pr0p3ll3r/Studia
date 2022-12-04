#include "developer.h"

Developer::Developer()
{

}

Developer::~Developer()
{

}

Developer::Developer(std::string surname1, int age1, int experience1, float salary1):Employee(surname1, age1, experience1, salary1)
{

}

float Developer::calculateBonus(int value)
{
    return value+0.2*value*(getSalary()+getExperience());
}
