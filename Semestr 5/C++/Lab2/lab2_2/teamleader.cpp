#include "teamleader.h"
using namespace std;

TeamLeader::TeamLeader()
{

}

TeamLeader::~TeamLeader()
{

}

TeamLeader::TeamLeader(std::string surname1, int age1, int experience1, float salary1):Employee(surname1, age1, experience1, salary1)
{

}

float TeamLeader::calculateBonus(int value)
{
    return value*(1+getSalary()+getExperience());
}

void TeamLeader::show()
{
    Employee::show();
    cout<<"Jestem Team Leader z "<<getExperience()<<" letnim doswiadczeniem"<<endl;
}
