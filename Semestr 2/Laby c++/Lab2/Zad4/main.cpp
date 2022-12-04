#include <iostream>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
    char plec;
    bool status;
    int wiek;
public:
    Osoba(string imie, string nazwisko, char plec, int wiek)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->plec=plec;
        status=0;
        this->wiek=wiek;
    }
    string getImie()
    {
        return imie;
    }
    string getNazwisko()
    {
        return nazwisko;
    }
    char getPlec()
    {
        return plec;
    }
    bool getStatus()
    {
        return status;
    }
    int getWiek()
    {
        return wiek;
    }
    string setImie(string imie)
    {
        this->imie=imie;
    }
    string setNazwisko(string nazwisko)
    {
        this->nazwisko=nazwisko;
    }
    char setPlec(char plec)
    {
        this->plec=plec;
    }
    bool setStatus(bool status)
    {
        this->status=status;
    }
    int setWiek(int wiek)
    {
        this->wiek=wiek;
    }
    void show()
    {
        cout<<"Imie: "<<imie<<endl;
        cout<<"Nazwisko: "<<nazwisko<<endl;
        cout<<"Plec: "<<plec<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Wiek: "<<wiek<<endl;
    }
    bool ofAge()
    {
        if(age>=18)
            return true;
        else return false;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
