#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "node.h"

class DoubleLinkedList
{
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
public:
    DoubleLinkedList();
    void add_front(int value);
    void add_back(int value);
    void delete_front();
    void delete_back();
    bool isEmpty();
    void show();
};

#endif // DOUBLELINKEDLIST_H
