#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

template <typename T>
class Student
{
private:
    std::string name;
    int mark;
public:
    Student(int mark, std::string name)
    {
        this->mark = mark;
        this->name = name;
    }
    Student()
    {

    }
    void show()
    {
        std::cout<<"imie "<<name<<" ocena "<<mark<<std::endl;
    }
    void showMark()
    {
        std::cout<<mark<<std::endl;
    }
};

template<>
void Student<int>::showMark()
{
    std::cout<<"Twoja ocena to: "<<mark<<std::endl;
}

template<>
class Student<std::string>
{
private:
    std::string name;
    int mark;
public:
    Student(int mark, std::string name)
    {
        this->mark = mark;
        this->name = name;
    }
    Student()
    {

    }
    void show()
    {
        std::cout<<"imie: "<<name<<" ocena "<<mark<<std::endl;
    }
    int showMark()
    {
        std::string word[6] = {"jedynka","dowjka","trojka","czworka","piatka","szostka"};
        std::cout<<"Twoja ocena to: "<<word[mark-1]<<std::endl;
        return mark;
    }
};
#endif // STUDENT_H
