#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct element
{
    char character;
    element* next;
};

struct queue
{
    element* head;
    element* tail;
};

void push(queue &q, char value)
{
    element* el = new element;
    el->character=value;
    el->next=nullptr;
    if(q.tail!=nullptr)
    {
        q.tail->next=el;
    }
    else
    {
        q.head=el;
    }
    q.tail=el;
}

void pop(queue &q)
{
    element* temp=q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head==nullptr)
    {
        q.tail=nullptr;
    }
}

bool isEmpty(queue q)
{
    if(q.head==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char first(queue q)
{
    return q.head->character;
}

void addFromFile(queue &q, string path)
{
    char c;
    ifstream plik;
    plik.open(path);
    while(plik.get(c))
    {
        if((int)c >= 65 && (int)c <= 90)
            push(q, c);
    }
    plik.close();
    cout<<"Wczytano znaki z pliku"<<endl;
}

void show(queue q)
{
    queue q1;
    q1.head=nullptr;
    q1.tail=nullptr;
    while(!isEmpty(q))
    {
        cout<<first(q)<<" ";
        push(q1, first(q));
        pop(q);
    }
    cout<<endl;
}

int main()
{
    srand(time(NULL));
    queue q;
    q.head=nullptr;
    q.tail=nullptr;
    int wybor;
    char c;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy kolejka jest pusta?"<<endl;
        cout<<"2: Dodanie elementu"<<endl;
        cout<<"3: Usuniecie elementu"<<endl;
        cout<<"4: Pobranie elementu"<<endl;
        cout<<"5: Usun wszystkie elementy"<<endl;
        cout<<"6: Wczytanie z pliku"<<endl;
        cout<<"7: Wyswietl kolejke"<<endl;
        cout<<"8: Koniec programu"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
            case 1:
                if(isEmpty(q))
                {
                    cout<<"Kolejka jest pusta"<<endl;
                }
                else
                {
                    cout<<"Kolejka nie jest pusta"<<endl;
                }
                break;
            case 2:
                c = rand() % (126 + 1 - 33) + 33;
                push(q, c);
                cout<<"Dodano znak "<<c<<endl;
                break;
            case 3:
                if(isEmpty(q))
                {
                    cout<<"Kolejka jest pusta"<<endl;
                }
                else
                {
                    cout<<"Usunieto znak "<<first(q)<<endl;
                    pop(q);
                }
                break;
            case 4:
                if(isEmpty(q))
                {
                    cout<<"Kolejka jest pusta"<<endl;
                }
                else
                {
                    cout<<first(q)<<endl;
                }
                break;
            case 5:
                while(!isEmpty(q))
                {
                    cout<<"Usunieto znak "<<first(q)<<endl;
                    pop(q);
                }
                break;
            case 6:
                addFromFile(q, "znaki2.txt");
                break;
            case 7:
                if(isEmpty(q))
                {
                    cout<<"Kolejka jest pusta"<<endl;
                }
                else
                {
                    show(q);
                }
                break;
            case 8:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
