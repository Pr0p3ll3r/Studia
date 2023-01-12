#include <limits>
#include <vector>
#include "student.h"
#include <iomanip>
#include <regex>
#include <fstream>
using namespace std;

void show(vector<Student> &students)
{
    for(auto it=students.begin();it!=students.end();it++)
    {
        cout<<setfill('_')<<setw(20)<<left<<it->getFirstName();
        cout<<setfill('_')<<setw(20)<<left<<it->getLastName();
        cout<<setfill('_')<<setw(20)<<left<<it->getSex();
        cout<<setfill('_')<<setw(20)<<left<<it->getMark();
        cout<<setfill('_')<<it->getEmail()<<endl;
    }
}

void addStudent(vector<Student> &students)
{
    regex regPatternName("[A-Z][a-z]+");
    regex regPatternEmail("[^0-9_.-][A-Za-z0-9_.-]+@[A-Za-z0-9]+\\.[A-Za-z0-9]+");
    string first, last, email;
    char sex;
    int mark;
    try
    {
        cout<<"Podaj imie"<<endl;
        cin>>first;
        if(!regex_match(first, regPatternName))
            throw "Imie musi zaczynac sie duza litera i moze zawierac tylko litery alfabetu lacinskiego";
        cout<<"Podaj nazwisko"<<endl;
        cin>>last;
        if(!regex_match(last, regPatternName))
            throw "Nazwisko musi zaczynac sie duza litera i moze zawierac tylko litery alfabetu lacinskiego";
        cout<<"Podaj plec"<<endl;
        cin>>sex;
        if(sex != 'K' && sex != 'M')
            throw "Plec: K lub M";
        cout<<"Podaj ocene"<<endl;
        cin>>mark;
        if(mark != 2 && mark != 3 && mark != 4 && mark != 5)
            throw "Oceny: 2, 3, 4, 5";
        cout<<"Chcesz podac email? (y/n)"<<endl;
        char wybor = '\0';
        cin>>wybor;
        if(wybor == 'y')
        {
            cout<<"Podaj email"<<endl;
            cin>>email;
            if(!regex_match(email, regPatternEmail))
                throw "Email music byc w postaci 'simple@example.com'";
            students.push_back(Student(first, last, sex, mark, email));
        }
        else
        {
            students.push_back(Student(first, last, sex, mark));
        }
        cout<<"Zapisano nowa osobe"<<endl;
    }
    catch (const char* error)
    {
        cerr<<error<<endl;
    }
}

void showStudent(vector<Student> &students)
{
    string lastName;
    cout<<"Podaj nazwisko"<<endl;
    cin>>lastName;
    for(auto it=students.begin();it!=students.end();it++)
    {
        if(it->getLastName() == lastName)
        {
            cout<<setfill('_')<<setw(20)<<left<<it->getFirstName();
            cout<<setfill('_')<<setw(20)<<left<<it->getLastName();
            cout<<setfill('_')<<setw(20)<<left<<it->getSex();
            cout<<setfill('_')<<setw(20)<<left<<it->getMark();
            cout<<setfill('_')<<it->getEmail()<<endl;
        }
    }
}

void makeFiles(vector<Student> &students)
{
    ofstream k, m;
    k.open("k.csv");
    m.open("m.csv");
    k<<"imie"<<';'<<"nazwisko"<<";"<<"plec(KM)"<<';'<<"ocena"<<';'<<"email"<<endl;
    m<<"imie"<<';'<<"nazwisko"<<";"<<"plec(KM)"<<';'<<"ocena"<<';'<<"email"<<endl;
    for(auto it=students.begin();it!=students.end();it++)
    {
        if(it->getSex() == 'K')
        {
            k<<it->getFirstName()<<';'<<it->getLastName()<<";"<<it->getSex()<<';'<<it->getMark()<<';'<<it->getEmail()<<endl;
        }
        else
        {
            m<<it->getFirstName()<<';'<<it->getLastName()<<";"<<it->getSex()<<';'<<it->getMark()<<';'<<it->getEmail()<<endl;
        }
    }
    k.close();
    m.close();
}

void showFirstX(vector<Student> &students)
{
    int x;
    cout<<"Podaj ilosc osob"<<endl;
    cin>>x;
    try
    {
        if(cin.fail())
            throw "To nie liczba";
        if(students.size() < x){
            throw "Nie ma takiej ilosci studentow";
        }
        for(auto it=students.begin();it!=students.end();it++)
        {
            if(x==0)
                break;
            cout<<setfill('_')<<setw(20)<<left<<it->getFirstName();
            cout<<setfill('_')<<setw(20)<<left<<it->getLastName();
            cout<<setfill('_')<<setw(20)<<left<<it->getSex();
            cout<<setfill('_')<<setw(20)<<left<<it->getMark();
            cout<<setfill('_')<<it->getEmail()<<endl;
            x--;
        }
    }
    catch (const char* error)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<error<<endl;
    }
}

int main()
{
    vector<Student> students;
    string path, linia;
    int wybor;
    ifstream file;
    ofstream save;
    try
    {
        cout<<"Podaj sciezke do pliku"<<endl;
        cin>>path;
        file.open(path);
        if(file.fail())
            throw "Plik nie istnieje";
        getline(file, linia);
        while(!file.eof())
        {
            getline(file, linia, ';');
            if(linia.empty())
                break;
            Student s = Student();
            s.setFirstName(linia);

            getline(file, linia, ';');
            s.setLastName(linia);

            getline(file, linia, ';');
            s.setSex(linia[0]);

            getline(file, linia, ';');
            s.setMark(linia[0] - '0');

            getline(file, linia);
            s.setEmail(linia);

            students.push_back(s);
        }
        file.close();
        while(1)
        {
            cout<<"***MENU***"<<endl;
            cout<<"1-Wyswietl ksiazke"<<endl;
            cout<<"2-Zapisz nowa osobe"<<endl;
            cout<<"3-Wyswietl osoby o podanym nazwisku"<<endl;
            cout<<"4-Stworz pliki dzielac ksiazke na plcie"<<endl;
            cout<<"5-Wyswietl X pierwszych osob"<<endl;
            cout<<"6-Posortuj wzgledem oceny rosnaco"<<endl;
            cout<<"7-Wyjdz"<<endl;
            cin>>wybor;
            switch(wybor)
            {
                case 1:
                    show(students);
                    break;
                case 2:
                    addStudent(students);
                    break;
                case 3:
                    showStudent(students);
                    break;
                case 4:
                    makeFiles(students);
                    break;
                case 5:
                    showFirstX(students);
                    break;
                case 6:
                    sort(students.begin(), students.end(), [](Student s1, Student s2){return s1.getMark() < s2.getMark();});
                    break;
                case 7:
                    save.open(path);
                    if(save.is_open())
                    {
                        save<<"imie"<<';'<<"nazwisko"<<";"<<"plec(KM)"<<';'<<"ocena"<<';'<<"email"<<endl;
                        for(auto it=students.begin();it!=students.end();it++)
                        {
                            save<<it->getFirstName()<<';'<<it->getLastName()<<";"<<it->getSex()<<';'<<it->getMark()<<';'<<it->getEmail()<<endl;
                        }
                    }
                    save.close();
                    exit(0);
            }
        }
    }
    catch(const char* error)
    {
        cerr<<error<<endl;
    }
}
