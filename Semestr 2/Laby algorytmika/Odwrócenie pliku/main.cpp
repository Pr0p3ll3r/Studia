#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct element
{
    char character;
    element* next;
};

void push(element* &stack, char value)
{
    element* e1 = new element;
    e1->character=value;
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

char top(element* stack)
{
    return stack->character;
}

int main()
{
    element* stack=nullptr;

    string sciezka;
    char c;
    ifstream plik;
    sciezka="znaki1.txt";
    plik.open(sciezka);
    while(plik.get(c))
    {
        push(stack, c);
    }
    plik.close();
    cout<<"Wczytano"<<endl;

    ofstream zapis;
    string sciezkaDoZapisu="wyniki.txt";
    zapis.open(sciezkaDoZapisu);
    while(!isEmpty(stack))
    {
        zapis<<top(stack);
        pop(stack);
    }
    zapis.close();
    cout<<"Zapisano"<<endl;
    return 0;
}
