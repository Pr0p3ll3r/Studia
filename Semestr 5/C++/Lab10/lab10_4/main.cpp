#include <regex>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    regex regPatternFirstName("[A-Za-z]+");
    regex regPatternLastName("[A-Za-z-]+");
    regex regPatternAge("[0-9]{1,2}");
    regex regPatternPhoneNumber("[1-9][0-9]{8}");
    regex regPatternEmail("[^0-9_.-][A-Za-z0-9_.-]+@[A-Za-z0-9]+\\.[A-Za-z0-9]+");
    string firstName, lastName, age, phoneNumber, email;
    cout<<"Podaj imie"<<endl;
    cin>>firstName;
    cout<<"Podaj nazwisko"<<endl;
    cin>>lastName;
    cout<<"Podaj wiek"<<endl;
    cin>>age;
    cout<<"Podaj numer telefonu"<<endl;
    cin>>phoneNumber;
    cout<<"Podaj email"<<endl;
    cin>>email;
    bool good = true;
    if (!regex_match(firstName, regPatternFirstName))
    {
        good = false;
        cout<<"Imie nieprawidlowe"<<endl;
    }
    if (!regex_match(lastName, regPatternLastName))
    {
        good = false;
        cout<<"Nazwisko nieprawidlowe"<<endl;
    }
    if (!regex_match(age, regPatternAge))
    {
        good = false;
        cout<<"Wiek nieprawidlowy"<<endl;
    }
    if (!regex_match(phoneNumber, regPatternPhoneNumber))
    {
        good = false;
        cout<<"Numer telefonu nieprawidlowy"<<endl;
    }
    if (!regex_match(email, regPatternEmail))
    {
        good = false;
        cout<<"Email nieprawidlowy"<<endl;
    }
    if(good)
    {
        cout<<"Dane prawidlowe"<<endl;
        ofstream plik;
        plik.open("dane.txt", ios::app);
        if(plik.is_open())
        {
            cout<<"Zapisano do pliku"<<endl;
            plik<<firstName<<";"<<lastName<<";"<<age<<";"<<phoneNumber<<";"<<email<<endl;
            plik.close();
        }
    }
    return 0;
}
