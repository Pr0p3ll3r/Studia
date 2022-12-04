#include <iostream>
#include <cmath>

using namespace std;

class CPayment
{
private:
    int cash_balance;
public:
    CPayment()
    {
        cash_balance=0;
        cout<<"Konstruktor bezparametrowy CPayment"<<endl;
    }
    virtual ~CPayment()
    {
        cout<<"Destruktor CPayment"<<endl;
    }
    virtual void deposit()=0;
    virtual void withdraw()=0;
    virtual void show_cash_balance()
    {
        cout<<"Cash balance: "<<cash_balance<<endl;
    }
    void addBalance(int value)
    {
        cash_balance+=value;
    }
    void removeBalance(int value)
    {
        cash_balance-=value;
    }
};

class CInternetPayment:public CPayment
{
public:
    CInternetPayment():CPayment()
    {
        cout<<"Konstruktor bezparametrowy CInternetPayment"<<endl;
    }
    ~CInternetPayment()
    {
        cout<<"Destruktor CInternetPayment"<<endl;
    }
    void virtual deposit()
    {
        int x;
        cout<<"Podaj kwote: ";
        cin>>x;
        if(x>0) addBalance(x);
    }
    void virtual withdraw()
    {
        string login, haslo;
        int kwota;
        cout<<"Podaj login: "<<endl;
        cin>>login;
        cout<<"Podaj haslo: "<<endl;
        cin>>haslo;
        if(login=="Kubus" && haslo=="Puchatek")
        {
            cout<<"Podaj kwote: "<<endl;
            cin>>kwota;
            if(kwota>0) removeBalance(kwota);
        }
        else cout<<"Nieprawid³owy login lub haslo"<<endl;
    }
};

class CRandomPayment:public CPayment
{
public:
    CRandomPayment():CPayment()
    {
        cout<<"Konstruktor bezparametrowy CRandomPayment"<<endl;
    }
    virtual ~CRandomPayment()
    {
         cout<<"Destruktor CRandomPayment"<<endl;
    }
    virtual void deposit()
    {
        int a = rand();
        cout<<"Wylosowano kwote: "<<a<<endl;
    }
};

int main()
{
    CPayment *a = new CRandomPayment();
    a->deposit();
    return 0;
}
