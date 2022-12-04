#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element
{
    int number;
    element* next;
    element* prev;
};

struct double_list
{
    element* head;
    element* tail;
    int counter;
};

bool isEmpty(double_list l)
{
    if(l.head==nullptr && l.tail==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void add_tail(double_list &l, int value)
{
    element* el = new element;
    el->number = value;
    el->next=nullptr;
    el->prev==nullptr;
    if(l.tail!=nullptr)
    {
        l.tail->next=el;
        el->prev=l.tail;
    }
    else
    {
        l.head=el;
    }
    l.tail=el;
    l.counter++;
}

void add_head(double_list &l, int value)
{
    element* el = new element;
    el->number = value;
    el->next=nullptr;
    el->prev==nullptr;
    if(l.head!=nullptr)
    {
        l.head->prev=el;
        el->next=l.head;
    }
    else
    {
        l.tail=el;
    }
    l.head=el;
    l.counter++;
}

void add_position(double_list &l, int value, int position)
{
    element* temp = l.head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    element* el = new element;
    el->number=value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;
    l.counter++;
}

void delete_tail(double_list &l)
{
    element* temp=l.tail;
    if(l.counter==1)
    {
        l.tail=nullptr;
        l.head=nullptr;
    }
    else
    {
        l.tail=l.tail->prev;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}


void delete_head(double_list &l)
{
    element* temp = l.head;
    if(l.counter==1)
    {
        l.tail=nullptr;
        l.head=nullptr;
    }
    else
    {
        l.head=l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;
}

void delete_position(double_list &l, int position)
{
    element* temp = l.head;
    int i=1;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    element* temp_us = temp->next;
    temp->next=temp_us->next;
    temp->next->prev=temp;
    delete temp_us;
    l.counter--;
}

void show(double_list &l, int mode)
{
    if(mode == 0)
    {
        element* temp = l.head;
        while(temp != nullptr)
        {
            cout<<temp->number<<" ";
            temp = temp->next;
        }
    }
    else if(mode == -1)
    {
        element* temp = l.tail;
        while(temp != nullptr)
        {
            cout<<temp->number<<" ";
            temp = temp->prev;
        }
    }
    cout<<endl;
}

int find_min(double_list &l, int& ind)
{
    element* temp = l.head;
    float minimum = temp->number;
    ind=1;
    int i=1;
    while(temp != nullptr)
    {
        if(temp->number < minimum)
        {
            minimum = temp->number;
            ind = i;
        }
        temp = temp->next;
        i++;
    }
    return minimum;
}

int main()
{
    srand(time(NULL));
    double_list l;
    l.head=nullptr;
    l.tail=nullptr;
    l.counter=0;
    int wybor, liczba, pozycja;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy lista jest pusta?"<<endl;
        cout<<"2: Dodanie elementu na koniec listy"<<endl;
        cout<<"3: Dodanie elementu na pcozatek listy"<<endl;
        cout<<"4: Dodanie elementu na pozycje o podanym numerze"<<endl;
        cout<<"5: Usuniecie elementu z konca listy"<<endl;
        cout<<"6: Usuniecie elementu z poczatku listy"<<endl;
        cout<<"7: Usuniecie elementu z podanej pozycji"<<endl;
        cout<<"8: Wyswietlenie listy od poczatku do konca"<<endl;
        cout<<"9: Wyswietlenie listy od konca do poczatku"<<endl;
        cout<<"10: Element minimalny"<<endl;
        cout<<"11: Usuniecie listy"<<endl;
        cout<<"12: Koniec programu"<<endl;
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
                add_tail(l,liczba);
                cout<<"Dodano "<<liczba<<endl;
                break;
            case 3:
                liczba = rand() % 50 + 1;
                add_head(l,liczba);
                cout<<"Dodano "<<liczba<<endl;
                break;
            case 4:
                cout<<"Podaj pozycje: ";
                cin>>pozycja;
                liczba = rand() % 50 + 1;
                add_position(l,liczba,pozycja);
                cout<<"Dodano "<<liczba<<" na pozycje "<<pozycja<<endl;
                break;
            case 5:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
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
                    cout<<"Podaj pozycje: ";
                    cin>>pozycja;
                    delete_position(l, pozycja);
                }
                break;
            case 8:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    show(l, 0);
                }
                break;
            case 9:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    show(l, -1);
                }
                break;
            case 10:
                if(isEmpty(l))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    cout<<"Najmniejsza liczba to "<<find_min(l,pozycja)<<" i znajduje sie na pozycji "<<pozycja<<endl;
                }
                break;
            case 11:
                while(!isEmpty(l))
                {
                    delete_head(l);
                }
                break;
            case 12:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
