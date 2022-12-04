#include <iostream>

using namespace std;

class Error
{
public:
    virtual void error()=0;
    virtual ~Error() {};
};

class BufferArrError : public Error
{
private:
    string description;
public:
    BufferArrError(string description)
    {
        this->description=description;
    }
    void error()
    {
        cout<<description<<endl;
    }
};

class BufferArr
{
private:
    int* tab;
    int n;
    int first;
public:
    BufferArr()
    {
        cout<<"Konstruktor klasy BufferArr"<<endl;
    }
    BufferArr(int n)
    {
        if(n<=0)
        {
            throw BufferArrError("Nieprawidlowy rozmiar tablicy");
        }
        else
        {
            this->n=n;
            tab = new int[n];
            first=0;
            cout<<"Konstruktor klasy BufferArr"<<endl;
        }
    }
    ~BufferArr()
    {
        delete [] tab;
        cout<<"Destruktor klasy BufferArr"<<endl;
    }
    void add(int elem)
    {
        if(first>n)
        {
            throw BufferArrError("Tablica jest pelna");
        }
        else
        {
            tab[first]=elem;
            first++;
        }
    }
    void write()
    {
        if(first==0)
        {
            throw BufferArrError("Tablica jest pusta");
        }
        else
        {
            int i=0;
            for(i=0;i<first;i++)
            {
                cout<<tab[i]<<" ";
            }
            cout<<endl<<"Zostalo wyswietlone "<<i<<" elementow"<<endl;
        }
    }
    int getElement(int index)
    {
        if(index<0)
        {
            throw BufferArrError("Index mniejszy od zera");
        }
        else if(index>first && index<n)
        {
            throw BufferArrError("Index wiekszy od aktualnego rozmiaru tablicy");
        }
        else if(index>=n)
        {
            throw BufferArrError("Index wiekszy od rozmiaru tablicy");
        }
        else
        {
            return tab[index];
        }
    }
    void setElement(int elem, int index)
    {
        if(index<0)
        {
            throw BufferArrError("Index mniejszy od zera");
        }
        else if(index>first && index<n)
        {
            throw BufferArrError("Index wiekszy od aktualnego rozmiaru tablicy");
        }
        else if(index>=n)
        {
            throw BufferArrError("Index wiekszy od rozmiaru tablicy");
        }
        else
        {
            tab[index]=elem;
        }
    }
    void reduct()
    {
        if(first==0)
        {
            throw BufferArrError("Tablica jest pusta");
        }
        else
        {
            first--;
        }
    }
    BufferArr* divide()
    {
        BufferArr* b = new BufferArr(n);
        for(int i=0;i<first;i++)
        {
            if(tab[i+1]==0)
            {
                throw BufferArrError("Dzielenie przez zero");
            }
            else
            {
                b->add((tab[i]/tab[i+1]));
            }
        }
        return b;
    }
};

int main()
{
    BufferArr b(5);
    try
    {
        BufferArr b1(0);
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.write();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.add(10);
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.add(10);
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.write();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        int elem = b.getElement(1);
        cout<<elem<<endl;
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.setElement(5, 1);
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    BufferArr* b2 = nullptr;
    try
    {
        b2 = b.divide();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.reduct();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.reduct();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b.reduct();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    try
    {
        b2->write();
    }
    catch(BufferArrError e)
    {
        e.error();
    }

    return 0;
}
