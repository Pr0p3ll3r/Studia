#include "citizen.h"
#include <iostream>
using namespace std;

Citizen::Citizen()
{

}

Citizen::Citizen(std::string _name, std::string _surname, int _age, char _sex, std::string _postal_code)
{
    name = _name;
    surname = _surname;
    age = _age;
    sex = _sex;
    postal_code = _postal_code;
}

void Citizen::show()
{
    cout<<name<<" "<<surname<<" "<<age<<" "<<sex<<" "<<postal_code<<endl;
}

std::string Citizen::getName() const
{
    return name;
}

std::string Citizen::getSurname() const
{
    return surname;
}

int Citizen::getAge() const
{
    return age;
}

char Citizen::getSex() const
{
    return sex;
}

std::string Citizen::getPostalCode() const
{
    return postal_code;
}
