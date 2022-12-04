#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element
{
    int number;
    element* next;
};

struct single_list
{
    element* head;
    element* tail;
    int counter;
};

void add_tail(single_list &l, int value)
{
    element* el=new element;
    el->number=value;
    el->next=nullptr;
    if(l.tail!=nullptr)
    {
        l.tail->next=el;
    }
    else
    {
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(single_list &l, int value)
{
    element* el=new element;
    el->number=value;
    el->next=l.head;
    l.head=el;
    if(l.tail==nullptr)
    {
        l.tail=el;
    }
    l.counter++;
}

void add_position(single_list &l, int value, int position)
{
    element* el=new element;
    el->number=value;
    element* temp=l.head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    el->next=temp->next;
    temp->next=el;
    l.counter++;
}

void delete_tail(single_list &l)
{
    element* temp=l.tail;
    if(l.counter==1)
    {
        l.tail=nullptr;
        l.head=nullptr;
    }
    else
    {
        element* bef_temp=l.head;
        int i=1;
        while(i<l.counter-1)
        {
            bef_temp=bef_temp->next;
            i++;
        }
        l.tail=bef_temp;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_head(single_list &l)
{
    element* temp=l.head;
    l.head=l.head->next;
    if(l.counter==1)
    {
        l.tail=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(single_list &l, int position)
{
    element* prev = l.head;
    int i=1;
    while(i<position-1)
    {
        prev=prev->next;
        i++;
    }
    element* temp=prev->next;
    prev->next=temp->next;
    delete temp;
    l.counter--;
}

void show(single_list l)
{
    int i=1;
    element* temp=l.head;
    while(i<=l.counter)
    {
        cout<<temp->number<<" ";
        temp=temp->next;
        i++;
    }
    cout<<endl;
}

bool isEmpty(single_list l)
{
    if(l.counter==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double average(single_list l)
{
    double ave=0;
    int i=1;
    element* temp=l.head;
    while(i<=l.counter)
    {
        ave+=temp->number;
        temp=temp->next;
        i++;
    }
    return (ave/l.counter);
}

int maximum(single_list l)
{
    int m=INT_MIN;
    int i=1;
    element* temp=l.head;
    while(i<=l.counter)
    {
        if(temp->number>m)
            m=temp->number;
        temp=temp->next;
        i++;
    }
    return m;
}

int main()
{
    srand(time(NULL));
    single_list l;
    l.head=nullptr;
    l.tail=nullptr;
    l.counter=0;
    int wybor, liczba, position;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy lista jest pusta?"<<endl;
        cout<<"2: Dodanie elementu na koniec listy"<<endl;
        cout<<"3: Dodanie elementu na poczatek listy"<<endl;
        cout<<"4: Dodanie elementu na okreslona pozycje"<<endl;
        cout<<"5: Usuniecie elementu z konca listy"<<endl;
        cout<<"6: Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7: Usuniecie elementu z okreslonej pozycji"<<endl;
        cout<<"8: Pobranie pierwszego elementu"<<endl;
        cout<<"9: Pobranie ostatniego elementu"<<endl;
        cout<<"10: Srednia arytmetyczna"<<endl;
        cout<<"11: Element maksymalny"<<endl;
        cout<<"12: Wyswietlenie listy"<<endl;
        cout<<"13: Usuniecie listy"<<endl;
        cout<<"14: Koniec programu"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
            case 1:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Lista nie jest pusta"<<endl;
                }
                break;
            case 2:
                liczba = rand() % 50 + 1;
                add_tail(l, liczba);
                cout<<"Dodano "<<liczba<<" na koniec listy"<<endl;
                break;
            case 3:
                liczba = rand() % 50 + 1;
                add_head(l, liczba);
                cout<<"Dodano "<<liczba<<" na poczatek listy"<<endl;
                break;
            case 4:
                liczba = rand() % 50 + 1;
                cout<<"Na jaka pozycje chcesz dodac element?"<<endl;
                cin>>position;
                add_position(l, liczba, position);
                cout<<"Dodano "<<liczba<<" na pozycje "<<position<<endl;
                break;
            case 5:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Usunieto liczbe z konca listy"<<endl;
                    delete_tail(l);
                }
                break;
            case 6:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Usunieto liczbe z poczatku listy"<<endl;
                    delete_head(l);
                }
                break;
            case 7:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Z jakiej pozycji chcesz usunac element?"<<endl;
                    cin>>position;
                    cout<<"Usunieto liczbe z pozycji "<<position<<endl;
                    delete_position(l, position);
                }
                break;
            case 8:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<l.head->number<<endl;
                }
                break;
            case 9:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<l.tail->number<<endl;
                }
                break;
            case 10:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                     cout<<"Srednia wynosi: "<<average(l)<<endl;
                }
                break;
            case 11:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Maksymalny element: "<<maximum(l)<<endl;
                }
                break;
            case 12:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    show(l);
                }
                break;
            case 13:
                while(!isEmpty(l))
                {
                    delete_head(l);
                }
                break;
            case 14:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
