#ifndef BUFFERARR_H
#define BUFFERARR_H

#include "buffer.h"

class BufferArr : public Buffer
{
private:
    int n;
    int *tab;
    int current;
public:
    BufferArr(int n);
    ~BufferArr();
    virtual void add(int a) override;
    virtual void write() override;
};

#endif // BUFFERARR_H
