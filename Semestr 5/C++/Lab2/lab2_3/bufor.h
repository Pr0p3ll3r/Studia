#ifndef BUFOR_H
#define BUFOR_H


class Bufor
{
private:
    int* tab;
    int size;
    int index;
public:
    Bufor();
    Bufor(int size1);
    virtual ~Bufor();
    virtual void add(int value);
    virtual double calculate()=0;
    int getIndex() const;
    int getSize() const;
    int getTab(int i) const;
    int getFirst() const;
    void setFirst(int value);
    void setTab(int pos, int value);
    void show();
};

#endif // BUFOR_H
