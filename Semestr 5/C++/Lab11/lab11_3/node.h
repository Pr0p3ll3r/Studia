#ifndef NODE_H
#define NODE_H
#include <memory>
#include <iostream>

class Node {
private:
    int value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
public:
    Node(int value);
    ~Node();
    int getValue() const;
    void setValue(int newValue);
    const std::shared_ptr<Node> &getNext() const;
    void setNext(const std::shared_ptr<Node> &newNext);
    const std::weak_ptr<Node> &getPrev() const;
    void setPrev(const std::weak_ptr<Node> &newPrev);
};
#endif // NODE_H
