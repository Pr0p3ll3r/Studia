#include "student.h"

const std::string &Student::getFirstName() const
{
    return firstName;
}

void Student::setFirstName(const std::string &newFirstName)
{
    firstName = newFirstName;
}

const std::string &Student::getLastName() const
{
    return lastName;
}

void Student::setLastName(const std::string &newLastName)
{
    lastName = newLastName;
}

char Student::getSex() const
{
    return sex;
}

void Student::setSex(char newSex)
{
    sex = newSex;
}

int Student::getMark() const
{
    return mark;
}

void Student::setMark(int newMark)
{
    mark = newMark;
}

const std::string &Student::getEmail() const
{
    return email;
}

void Student::setEmail(const std::string &newEmail)
{
    email = newEmail;
}

Student::Student()
{

}

Student::Student(std::string firstName, std::string lastName, char sex, int mark, std::string email)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->sex = sex;
    this->mark = mark;
    this->email = email;
}
