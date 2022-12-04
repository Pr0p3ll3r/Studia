#include <iostream>

using namespace std;

class CSet
{
private:
    int tab[100];
    int index;
public:
    CSet()
    {
        index = 0;
        cout<<"Konstruktor bezparametrowy CSet"<<endl;
    }
    virtual ~CSet()
    {
        cout<<"Destruktor CSet"<<endl;
    }
    virtual void add(int value)
    {
        tab[index] = value;
        index++;
    }
    virtual double calculate() = 0;
    int getIndex()
    {
        return index;
    }
    int getTab(int i)
    {
        return tab[i];
    }
    void setTab(int value)
    {
        tab[index] = value;
        index++;
    }
};

class CSetMean : public CSet
{
public:
    CSetMean():CSet()
    {
        cout<<"Konstruktor bezparametrowy CSetMean"<<endl;
    }
    virtual ~CSetMean()
    {
        cout<<"Destruktor CSetMean"<<endl;
    }
    virtual double calculate()
    {
        double a=0;
        for(int i=0;i<getIndex();i++)
        {
            a+=getTab(i);
        }
        return a/getIndex();
    }
};

class CSetMax : public CSet
{
public:
    CSetMax():CSet()
    {
        cout<<"Konstruktor bezparametrowy CSetMax"<<endl;
    }
    virtual ~CSetMax()
    {
        cout<<"Destruktor CSetMax"<<endl;
    }
    virtual double calculate()
    {
        int m=getTab(0);
        for(int i=1;i<getIndex();i++)
        {
            if(getTab(i)>m)
                m=getTab(i);
        }
        return m;
    }
    virtual void add(int value)
    {
        if(getIndex() == 100)
        {
            cout<<"Brak miejsca w tablicy"<<endl;
        }
        else
        {
            setTab(value);
        }
    }
};

int main()
{
    CSet* tab[4];
    for(int i=0;i<2;i++)
    {
        tab[i]=new CSetMean();
    }
    for(int i=2;i<4;i++)
    {
        tab[i]=new CSetMax();
    }
    for(int i=0;i<4;i++)
    {
        tab[i]->add(i);
        tab[i]->add(i+1);
        tab[i]->add(i+2);
        tab[i]->add(i+3);
        tab[i]->add(i+4);
    }
    for(int i=0;i<2;i++)
    {
        cout<<"Srednia: "<<tab[i]->calculate()<<endl;
    }
    for(int i=2;i<4;i++)
    {
        cout<<"Max: "<<tab[i]->calculate()<<endl;
    }
    return 0;
}
