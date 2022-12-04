#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <time.h>

using namespace std;

class Buffer
{
public:
    Buffer()
    {
        cout<<"Konstruktor Buffer"<<endl;
    }
    virtual ~Buffer()
    {
        cout<<"Destruktor Buffer"<<endl;
    }
    virtual void add(int a)=0;
    virtual void write()=0;

};

class BufferArr : public Buffer
{
private:
    int* tab;
    int n;
    int liczbaElementow;
public:
    BufferArr()
    {
        n = 100;
        liczbaElementow = 0;
        tab = new int[n];
        cout<<"Konstruktor klasy BufferArr"<<endl;
    }
    BufferArr(int n)
    {
        this->n=n;
        liczbaElementow = 0;
        tab = new int[n];
        cout<<"Konstruktor klasy BufferArr"<<endl;
    }
    virtual ~BufferArr()
    {
        delete [] tab;
        cout<<"Destruktor klasy BufferArr"<<endl;
    }
    int getSize()
    {
        return n;
    }
    void setSize(int n)
    {
        this->n=n;
        tab = new int[n];
    }
    int getTab(int x)
    {
        return tab[x];
    }
    void add(int a)
    {
        if(n>liczbaElementow)
        {
            tab[liczbaElementow]=a;
            liczbaElementow++;
        }
        else
        {
            cout<<"Tablica jest pelna"<<endl;
        }
    }
    void write()
    {
        int i=0;
        for(i=0;i<liczbaElementow;i++)
        {
            cout<<tab[i]<<endl;
        }
        cout<<"Zostalo wyswietlone "<<i+1<<" elementow"<<endl;
    }
};

class BufferFile : public Buffer
{
private:
    ifstream odczyt;
    ofstream zapis;
public:
    BufferFile()
    {
        zapis.open("liczby.txt", ios::in);
        cout<<"Konstruktor klasy BufferFile"<<endl;
    }
    BufferFile(string sciezka)
    {
        zapis.open(sciezka, ios::in);
        cout<<"Konstruktor klasy BufferFile"<<endl;
    }
    virtual ~BufferFile()
    {
        zapis.close();
        cout<<"Destruktor klasy BufferFile"<<endl;
    }
    void add(int a)
    {
        zapis<<a<<',';
    }
    void write()
    {
        odczyt.open("liczby.txt");
        ios_base::fmtflags parzysta=ios::showpos|ios::left;
        ios_base::fmtflags nieparzysta=ios::showpos|ios::right;
        int liczba;
        char przecinek;
        int i=0;
        int j=0;
        while(odczyt>>liczba && odczyt>>przecinek)
        {
            if(i%4==0)
            {
                j++;
                cout<<endl;
            }
            if(j%2==0)
            {
                cout.flags(parzysta);
                cout<<setfill('|')<<setw(6)<<liczba;
            }
            else
            {
                cout.flags(nieparzysta);
                cout<<setw(6)<<setfill('|')<<liczba;
            }
            i++;
        }
        odczyt.close();
    }
};

int main()
{
    srand(time(NULL));
    Buffer* tab[6];
    Buffer* b = new BufferFile();
    for(int j=0;j<10;j++)
    {
        int x=rand() % 100;
        b->add(x);
    }
    delete b;
    Buffer* b1 = new BufferFile();
    b1->write();
    return 0;
}
