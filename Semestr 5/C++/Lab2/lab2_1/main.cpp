#include <QCoreApplication>
#include <figure.h>
#include <square.h>
#include <circle.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Figure* f1 = new Square(5);
    Figure* f2 = new Circle(3);

    f1->calculateArea();
    f1->calculatePerimeter();
    f1->show();

    f2->calculateArea();
    f2->calculatePerimeter();
    f2->show();

    delete f1;
    delete f2;

    Figure* f3;
    Square s1(4);
    f3=&s1;
    f3->calculateArea();
    f3->show();

    Figure* tab[3];
    tab[0] = new Square(4);
    tab[1] = new Square(2);
    tab[2] = new Circle(5);
    for(int i=0;i<3;i++)
    {
        tab[i]->calculateArea();
        delete tab[i];
    }

    return a.exec();
}
