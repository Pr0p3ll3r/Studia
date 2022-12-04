#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    private:
        std::string name;
        std::string surname;
        int age;
    public:
        Person(std::string name1, std::string surname1, int age1);
        Person();
        void setAge(int age1);
        std::string getSurname() const;
        bool is_18();
        void showInfoPerson();
        void init(std::string name1, std::string surname1, int age1);
};

#endif // PERSON_H
