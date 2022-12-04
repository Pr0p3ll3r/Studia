#include <iostream>
#include <stack>
using namespace std;
class Element
{
private:
    int size;
    int *arr;
    int pos;
public:
    Element(int s)
    {
        size=s;
        arr=new int[size];
        pos=0;
    }
    Element(const Element &e)
    {
        size=e.size;
        arr=new int[size];
        pos=e.pos;
        for(int i=0;i<size;i++){
          arr[i]=e.arr[i];
        }
    }
    ~Element()
    {
        delete [] arr;
    }
    void add(int num)
    {
        arr[pos]=num;
        pos++;
    }
    void show()
    {
        for(int i=0; i<pos; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main()
{
    //stack - stos
    //stos, ktorego elementami sa obikety klasy Element
    stack<Element> st1;
    Element el1(5);
    Element el2(5);
    st1.push(el1); //dodanie elemntu do stosu
    for(int i=0; i<5; i++)
    {                       //st1.top() to element znajdujacy sie na wierzcholku stosu
        st1.top().add(i+1); //dostep do elementu ktory znajduje sie na wierzcholku stosu
    }

    for(int i=0; i<5; i++)
    {
        el2.add(i+100);
    }
    st1.push(el2);

    while(!st1.empty()) //sprawdzenie czy stos jest pusty
    {
        st1.top().show();
        st1.pop(); //usuniecie elementu z wierzcholka stosu
    }


    return 0;
}
