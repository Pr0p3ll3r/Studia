#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>

class Buffer
{
public:
    Buffer();
    virtual ~Buffer();
    virtual void add(int a) = 0;
    virtual void write() = 0;
};

#endif // BUFFER_H
