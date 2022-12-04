#ifndef COMPARE_H
#define COMPARE_H
#include "student.h"

class Compare
{
public:
    bool operator( ) (Student &s1, Student &s2);
};
#endif // COMPARE_H_INCLUDED
