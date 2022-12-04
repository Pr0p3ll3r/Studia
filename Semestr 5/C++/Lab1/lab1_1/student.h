#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person
{
private:
    std::string index;
public:
    Student();
    Student(std::string name1, std::string surname1, int age1, std::string index1);
    void setIndex(std::string newIndex);
    std::string getIndex() const;
    void showInfoStudent();
};

#endif // STUDENT_H
