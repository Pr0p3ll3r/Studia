#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student
{
private:
    std::string firstName;
    std::string lastName;
    char sex;
    int mark;
    std::string email;
public:
    Student();
    Student(std::string firstName, std::string lastName, char sex, int mark, std::string email = "");
    const std::string &getFirstName() const;
    void setFirstName(const std::string &newFirstName);
    const std::string &getLastName() const;
    void setLastName(const std::string &newLastName);
    char getSex() const;
    void setSex(char newSex);
    int getMark() const;
    void setMark(int newMark);
    const std::string &getEmail() const;
    void setEmail(const std::string &newEmail);
};

#endif // STUDENT_H
