#include "doublelinkedlist.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

void DoubleLinkedList::add_front(int value)
{
    shared_ptr<Node> node = make_shared<Node>(value);
    if(head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        head->setPrev(node);
        node->setNext(head);
        head = node;
    }
}

void DoubleLinkedList::add_back(int value)
{
    shared_ptr<Node> node = make_shared<Node>(value);
    if(tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
}

void DoubleLinkedList::delete_front()
{
    if(head == nullptr)
        return;

    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->getNext();
    }
}

void DoubleLinkedList::delete_back()
{
    if(tail == nullptr)
        return;

    if(head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->getPrev().lock();
        tail->setNext(nullptr);
    }
}

bool DoubleLinkedList::isEmpty()
{
    if(head == nullptr)
        return true;
    return false;
}

void DoubleLinkedList::show()
{
    if(isEmpty())
    {
        cout<<"Pusta"<<endl;;
        return;
    }

    shared_ptr<Node> tempNode = head;
    while(tempNode)
    {
        cout<<tempNode->getValue()<<" ";
        tempNode = tempNode->getNext();
    }
    cout<<endl;
}
