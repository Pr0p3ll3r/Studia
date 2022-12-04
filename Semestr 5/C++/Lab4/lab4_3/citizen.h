#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>

class Citizen
{
private:
    std::string name;
    std::string surname;
    int age;
    char sex;
    std::string postal_code;
public:
    Citizen();
    Citizen(std::string _name, std::string _surname, int _age, char _sex, std::string _postal_code);
    void show();
    std::string getName() const;
    std::string getSurname() const;
    int getAge() const;
    char getSex() const;
    std::string getPostalCode() const;
};

#endif // CITIZEN_H
