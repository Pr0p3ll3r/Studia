#include "node.h"

int Node::getValue() const
{
    return value;
}

void Node::setValue(int newValue)
{
    value = newValue;
}

const std::shared_ptr<Node> &Node::getNext() const
{
    return next;
}

void Node::setNext(const std::shared_ptr<Node> &newNext)
{
    next = newNext;
}

const std::weak_ptr<Node> &Node::getPrev() const
{
    return prev;
}

void Node::setPrev(const std::weak_ptr<Node> &newPrev)
{
    prev = newPrev;
}

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
}

Node::~Node()
{
    std::cout<<"Destruktor klasy Node"<<std::endl;
}
