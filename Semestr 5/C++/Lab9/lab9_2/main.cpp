#include <iostream>
#include <limits>
using namespace std;

int getNumber()
{
    int number;
    do
    {
        cout<<"Podaj liczbe calkowita dodatnia"<<endl;
        try
        {
            cin>>number;
            if(cin.fail())
                throw "To nie jest liczba";
            if(number<=0)
                throw -1;
            break;
        }
        catch(char const* error)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<error<<endl;
        }
        catch(int)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"To nie jest liczba dodatnia"<<endl;
        }
    }while(1);
    return number;
}

int main()
{
    int oczko = 0, success = 0, fail = 0;
    int number;
    while(1)
    {
        try
        {
            number = getNumber();
            oczko += number;
            if(oczko > 21)
                throw 22;
            success++;
            if(oczko == 21)
            {
                cout<<"Suma = 21"<<endl;
                cout<<"Proby udane:"<<success<<endl;
                cout<<"Proby nieudane:"<<fail<<endl;
                exit(0);
            }
        }
        catch(int)
        {
            cout<<"Suma zostala przekroczona"<<endl;
            oczko -= number;
            fail++;
        }
    }
}
