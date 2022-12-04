#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

class Employee
{
private:
    std::string surname;
    int age;
    int experience;
    float salary;
public:
    Employee(std::string surname1, int age1, int experience1, float salary1);
    Employee();
    virtual ~Employee();
    virtual void show();
    virtual float calculateBonus(int value)=0;
    int ageEmployment();
    std::string getSurname();
    int getAge();
    int getExperience();
    float getSalary();
};

#endif // EMPLOYEE_H
