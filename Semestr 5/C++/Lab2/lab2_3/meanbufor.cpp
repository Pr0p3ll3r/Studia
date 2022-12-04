#include "meanbufor.h"

MeanBufor::MeanBufor()
{

}

MeanBufor::MeanBufor(int size1):Bufor(size1)
{

}

MeanBufor::~MeanBufor()
{

}

double MeanBufor::calculate()
{
    double mean = 0;
    int size = getSize();
    for(int i=0;i<size;i++)
    {
        mean+=getTab(i);
    }
    mean/=size;
    return mean;
}
