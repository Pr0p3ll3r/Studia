#include <iostream>
#include "person.h"
//#include "teacher.h"
#include "student.h"
using namespace std;
int main()
{
    Student tab1[3];
    Student* tab2;
    Student* tab3[3];
    Student** tab4;

    for(int i=0; i<3; i++)
    {
        tab1[i].init("Anna","Nowak",20+i);
        tab1[i].setIndex("95391");
        tab1[i].showInfoStudent();
    }

    tab2 = new Student[3];
    for(int i=0; i<3; i++)
    {
        tab2[i].init("Ola","Adamek",20+i);
        tab2[i].setIndex("95391");
        tab2[i].showInfoStudent();
    }

    for(int i=0; i<3; i++)
    {
        tab3[i]=new Student("Kasia","Kowalska",20+i,"95391");
        tab3[i]->showInfoStudent();
    }

    tab4=new Student*[3];
    for(int i=0; i<3; i++)
    {
        tab4[i]=new Student("Pawel","Wojcik",20+i,"95391");
        tab4[i]->showInfoStudent();
    }

    for(int i=0;i<3;i++)
    {
        delete tab3[i];
    }

    for(int i=0;i<3;i++)
    {
        delete tab4[i];
    }
    delete [] tab4;

    return 0;
}
