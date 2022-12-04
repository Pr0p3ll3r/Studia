#include <QCoreApplication>
#include <iostream>
using namespace std;

template<typename T>
T getMin(T tab[], int size)
{
    T min = tab[0];
    for(int i=1;i<size;i++)
    {
        if(tab[i]<min)
            min = tab[i];
    }
    return min;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int tab1[] = {1,2,3,4,5,6,7,8,9,10};
    string tab2[] = {"jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec","dziesiec"};

    cout<<getMin(tab1, 10)<<endl;
    cout<<getMin(tab2, 10)<<endl;

    return a.exec();
}
