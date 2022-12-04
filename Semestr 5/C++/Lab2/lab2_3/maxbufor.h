#ifndef MAXBUFOR_H
#define MAXBUFOR_H

#include "bufor.h"

class MaxBufor : public Bufor
{
public:
    MaxBufor();
    MaxBufor(int size1);
    ~MaxBufor();
    virtual double calculate() override;
    virtual void add(int value) override;
};

#endif // MAXBUFOR_H
