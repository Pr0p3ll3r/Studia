#ifndef MEANBUFOR_H
#define MEANBUFOR_H

#include "bufor.h"

class MeanBufor : public Bufor
{
public:
    MeanBufor();
    MeanBufor(int size1);
    ~MeanBufor();
    virtual double calculate() override;
};

#endif // MEANBUFOR_H
