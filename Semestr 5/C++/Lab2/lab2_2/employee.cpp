#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee(std::string surname1, int age1, int experience1, float salary1)
{
    surname=surname1;
    age=age1;
    experience=experience1;
    salary=salary1;
}

Employee::Employee()
{

}

Employee::~Employee()
{

}

void Employee::show()
{
    cout<<"Nazwisko: "<<surname<<" Wiek: "<<age<<" Doswiadczenie: "<<experience<<" Wyplata: "<<salary<<endl;
}

int Employee::ageEmployment()
{
    return age-experience;
}

string Employee::getSurname()
{
    return surname;
}

int Employee::getAge()
{
    return age;
}

int Employee::getExperience()
{
    return experience;
}

float Employee::getSalary()
{
    return salary;
}
