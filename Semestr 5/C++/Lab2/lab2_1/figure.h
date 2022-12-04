#ifndef FIGURE_H
#define FIGURE_H


class Figure
{
private:
    float area;
    float perimeter;
public:
    Figure();
    virtual ~Figure();
    float getArea();
    void setArea(float area1);
    float getPerimeter();
    void setPerimeter(float perimeter1);
    virtual void calculateArea()=0;
    virtual void show();
    virtual void calculatePerimeter()=0;
};

#endif // FIGURE_H
