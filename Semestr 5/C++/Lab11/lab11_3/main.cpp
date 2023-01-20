#include <iostream>
#include "doublelinkedlist.h"
using namespace std;

int main()
{
    DoubleLinkedList list = DoubleLinkedList();
    list.add_front(5);
    list.add_front(7);
    list.add_back(8);
    list.show();
    list.delete_front();
    list.show();
    list.delete_back();
    list.show();
    list.delete_back();
    list.show();
    list.add_back(8);
    list.show();
    return 0;
}
