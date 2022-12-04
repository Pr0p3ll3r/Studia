#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element
{
    int number;
    element* next;
};

bool isEmpty(element*& current)
{
    if(current==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
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

void add_before(element*& current, int value)
{
    element* el = new element;
    el->number = value;
    if(current != nullptr)
    {
        el->next=current;
        element* temp=current;
        while(temp->next != current)
        {
            temp = temp->next;
        }
        temp->next=el;
    }
    else
    {
        el->next = el;
        current = el;
    }
}

void delete_after(element*& current)
{
    element* temp=current->next;
    if(current->next==current)
    {
        current=nullptr;
    }
    else
    {
        current->next=current->next->next;
    }
    delete temp;
}


void delete_before(element*& current)
{
    element* temp = current->next;
    if(current->next == current)
    {
        current = nullptr;
    }
    else
    {
        element* bef_temp=temp;
        while(bef_temp->next->next != current)
        {
            bef_temp = bef_temp->next;
        }
        temp=bef_temp->next;
        bef_temp->next=current;
    }
    delete temp;
}

void delete_current(element*& current)
{
    element* temp = current;
    if(current->next == current)
    {
        current = nullptr;
    }
    else
    {
        element* last=current;
        while(last->next != current)
        {
            last = last->next;
        }
        last->next=current->next;
        current = current->next;
    }
    delete temp;
}

void show(element*& current)
{
    element* temp=current;
    while(temp->next!=current)
    {
        cout<<temp->number<<" ";
        temp=temp->next;
    }
    cout<<temp->number<<" ";
    cout<<endl;
}

int main()
{
    srand(time(NULL));
    element* e = nullptr;
    int wybor, liczba;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy lista jest pusta?"<<endl;
        cout<<"2: Dodanie elementu za element biezacy"<<endl;
        cout<<"3: Dodanie elementu przed element biezacy"<<endl;
        cout<<"4: Usuniecie elementu stojacego za elementem biezacym"<<endl;
        cout<<"5: Usuniecie elementu stojacego przed elementem biezacym"<<endl;
        cout<<"6: Usuniecie elementu biezacego"<<endl;
        cout<<"7: Wyswietlenie listy"<<endl;
        cout<<"8: Usuniecie listy"<<endl;
        cout<<"9: Koniec programu"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
            case 1:
                if(isEmpty(e))
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
                add_after(e, liczba);
                cout<<"Dodano "<<liczba<<endl;
                break;
            case 3:
                liczba = rand() % 50 + 1;
                add_before(e, liczba);
                cout<<"Dodano "<<liczba<<endl;
                break;
            case 4:
                if(isEmpty(e))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    delete_after(e);
                }
                break;
            case 5:
                if(isEmpty(e))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    delete_before(e);
                }
                break;
            case 6:
                if(isEmpty(e))
                {
                    cout<<"Lista jest pusta"<<endl;
                }
                else
                {
                    delete_current(e);
                }
                break;
            case 7:
                if(e!=nullptr)
                {
                   show(e);
                }
                break;
            case 8:
                while(!isEmpty(e))
                {
                    delete_after(e);
                }
                delete e;
                break;
            case 9:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
