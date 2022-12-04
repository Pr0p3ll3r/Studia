#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element
{
    int number;
    element* next;
};

void push(element* &stack, int value)
{
    element* e1 = new element;
    e1->number=value;
    e1->next=stack;
    stack=e1;
}

void pop(element* &stack)
{
    element* temp=stack;
    stack=stack->next;
    delete temp;
}

bool isEmpty(element* stack)
{
    if(stack==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int top(element* stack)
{
    return stack->number;
}

int main()
{
    srand(time(NULL));
    element* stack=nullptr;
    int wybor, x;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Czy stos jest pusty?"<<endl;
        cout<<"2: Dodanie elementu"<<endl;
        cout<<"3: Usuniecie elementu"<<endl;
        cout<<"4: Pobranie elementu"<<endl;
        cout<<"5: Usun wszystkie elementy"<<endl;
        cout<<"6: Koniec programu"<<endl;
        cin>>wybor;
        cout<<endl;
        switch(wybor)
        {
            case 1:
                if(isEmpty(stack) == true)
                {
                    cout<<"Stos jest pusty"<<endl;
                }
                else
                {
                    cout<<"Stos nie jest pusty"<<endl;
                }
                break;
            case 2:
                x = rand() % 100 + 1;
                push(stack, x);
                cout<<"Dodano liczbe "<<x<<endl;
                break;
            case 3:
                if(isEmpty(stack) == true)
                {
                    cout<<"Stos jest pusty"<<endl;
                }
                else
                {
                    pop(stack);
                    cout<<"Usunieto liczbe "<<x<<endl;
                }
                break;
            case 4:
                if(isEmpty(stack) == true)
                {
                    cout<<"Stos jest pusty"<<endl;
                }
                else
                {
                    cout<<top(stack)<<endl;
                }
                break;
            case 5:
                while(!isEmpty(stack))
                {
                    pop(stack);
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
