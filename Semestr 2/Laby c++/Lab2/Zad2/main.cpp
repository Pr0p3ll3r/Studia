#include <iostream>

using namespace std;

class BankAccount
{
private:
    string first_name;
    string last_name;
    string account_number;
    float saldo;
public:
    BankAccount()
    {
        cout<<"Konstruktor bez parametrowy"<<endl;
    }
    void init(string first_name, string last_name, string account_number)
    {
        this->first_name=first_name;
        this->last_name=last_name;
        this->account_number=account_number;
        saldo=0;
    }
    void add(float kwota)
    {
        saldo+=kwota;
    }
    void withdraw(float kwota)
    {
        saldo-=kwota;
    }
    float getSaldo()
    {
        return saldo;
    }
    void show()
    {
        cout<<"Imie: "<<first_name<<endl;
        cout<<"Nazwisko: "<<last_name<<endl;
        cout<<"Saldo konta: "<<saldo<<endl;
    }
    void setFirst(string first_name)
    {
        this->first_name=first_name;
    }
    void setLast(string last_name)
    {
        this->last_name=last_name;
    }
};

void changeOwner(BankAccount &a1)
{
    string first,last;
    cout<<"Podaj imie nowego wlasciciela: "<<endl;
    cin>>first;
    a1.setFirst(first);
    cout<<"Podaj nazwisko nowego wlasciela: "<<endl;
    cin>>last;
    a1.setLast(last);
}

int main()
{
    string imie,nazwisko,nrkonta;

    //tablica statyczna dynamicznych obiektów

    /*
    BankAccount *tab1[3];
    for(int i=0;i<3;i++)
    {
        tab1[i] = new BankAccount();
    }
    for(int i=0;i<3;i++)
    {
        cout<<"Podaj imie: "; cin>>imie;
        cout<<"Podaj nazwisko: "; cin>>nazwisko;
        cout<<"Podaj nrkonta: "; cin>>nrkonta;
        tab1[i]->init(imie,nazwisko,nrkonta);
    }
    for(int i=0;i<3;i++)
    {
        tab1[i]->show();
    }
    for(int i=0;i<3;i++)
    {
        delete tab1[i];
    }
*/

    //tablica statyczna statycznych obiektów

    /*
    BankAccount tab2[3] = {BankAccount()};
    for(int i=0;i<3;i++)
    {
        cout<<"Podaj imie: "; cin>>imie;
        cout<<"Podaj nazwisko: "; cin>>nazwisko;
        cout<<"Podaj nrkonta: "; cin>>nrkonta;
        tab2[i].init(imie,nazwisko,nrkonta);
    }
    for(int i=0;i<3;i++)
    {
        tab2[i].show();
    }
    */

    //tablica dynamiczna dynamicznych obiektów

    /*
    BankAccount **tab3;
    tab3 = new BankAccount*[3];
    for(int i=0;i<3;i++)
    {
        tab3[i] = new BankAccount();
    }
    for(int i=0;i<3;i++)
    {
        cout<<"Podaj imie: "; cin>>imie;
        cout<<"Podaj nazwisko: "; cin>>nazwisko;
        cout<<"Podaj nrkonta: "; cin>>nrkonta;
        tab3[i]->init(imie,nazwisko,nrkonta);
    }
    for(int i=0;i<3;i++)
    {
        tab3[i]->show();
    }
    for(int i=0;i<3;i++)
    {
        delete tab3[i];
    }
    delete [] tab3;
    */

    //dynamiczna tablica statycznych obiektów
    BankAccount *tab4;
    tab4=new BankAccount[3];
    for(int i=0;i<3;i++)
    {
        cout<<"Podaj imie: "; cin>>imie;
        cout<<"Podaj nazwisko: "; cin>>nazwisko;
        cout<<"Podaj nrkonta: "; cin>>nrkonta;
        tab4[i].init(imie,nazwisko,nrkonta);
    }
    for(int i=0;i<3;i++)
    {
        tab4[i].show();
    }
    delete [] tab4;
    return 0;
}
