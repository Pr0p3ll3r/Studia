#include <iostream>

using namespace std;

class CStudent
{
private:
    int id;
    string name;
public:
    CStudent(int id, string name);
    void setId(int id);
    int getId();
    void show();
};

CStudent::CStudent(int id, string name)
{
    this->id=id;
    this->name=name;
}

int CStudent::getId()
{
    return id;
}

void CStudent::setId(int id)
{
    this->id=id;
}

void CStudent::show()
{
    cout<<"Imie: "<<name<<" ID: "<<id<<endl;
}

class CNumber
{
private:
    static int number;
public:
    static int next()
    {
        number++;
        return number;
    }
};
int CNumber::number=0;

int main()
{
    CStudent* tab[30];
    for(int i=0;i<30;i++)
    {
        string imie;
        cout<<"Podaj imie studenta "<<i+1<<": "<<endl;
        cin>>imie;
        tab[i] = new CStudent(CNumber::next(), imie);
    }
    for(int i=0;i<30;i++)
    {
        tab[i]->show();
    }
    for(int i=0;i<30;i++)
    {
        delete tab[i];
    }
    return 0;
}
