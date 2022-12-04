#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void push(stos *&w, int x);
int pop(stos *&w);
int isEmpty(stos *w);
int first(stos* w);

struct element
{
    int number;
    element* next;
};

int zad1(stos*& w, int &arg)
{
    stos* temp=w;
    int m=INT_MIN;
    int liczba=0;
    if(isEmpty(w)==1)
    {
        arg=0;
        m=0;
        return m;
    }
    arg=1;
    while(isEmpty(w) == 0)
    {
        liczba = pop(w);
        push(temp, liczba);
        if(liczba>m)
            m=liczba;
    }
    w=temp;
    return m;
}

int zad2(element* l)
{
    int x=0;
    element* temp=l;
    int i=1;
    while(temp->next != l)
    {
        if(i%2==0)
        {
             x=x+temp->number;
        }
        temp=temp->next;
        i++;
    }
    if(i<2)
        return 0;
    if(i%2==0)
        x=x+temp->number;
    return x;
}

void add_after(element*& current, int value)
{
    element* el = new element;
    el->number = value;
    if(current != nullptr)
    {
        el->next = current->next;
        current->next = el;
    }
    else
    {
        el->next = el;
        current = el;
    }
}

int main()
{
    srand(time(NULL));
    stos* w=nullptr;
    int liczba, x;
    for(int i=0;i<10;i++)
    {
        liczba = rand() % 50 + 1;
        push(w, liczba);
    }
    liczba = zad1(w,x);
    cout<<x<<endl;
    if(x==1)
    {
        cout<<"Na stosie jest co najmniej jeden element \nMaksymalny element: "<<liczba<<endl;
    }
    else
    {
        cout<<"Stos nie zawiera co najmniej jednego elementu"<<endl;
    }
    element* l=nullptr;
    for(int i=0;i<6;i++)
    {
        liczba = rand() % 50 + 1;
        add_after(l, liczba);
    }
    cout<<"Suma elementow parzystych: "<<zad2(l)<<endl;
}
