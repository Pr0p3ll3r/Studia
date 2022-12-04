#ifndef EVEN_H
#define EVEN_H
class Even
{
private:
    int divider;
public:
    Even(int divider);
    bool operator( )(int x);
};
#endif // EVEN_H
