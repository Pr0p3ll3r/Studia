#include <QCoreApplication>
#include <QMap>
#include <QPair>
#include <iostream>
#include <cctype>
using namespace std;

void addCountry(QMap<string,int> &map, string name, int amount)
{
    map.insert(name, amount);
}

void show(QMap<string,int> map)
{
    for(auto it=map.begin();it!=map.end();it++)
    {
        cout<<it.key()<<" Liczba ludnosci "<<it.value()<<endl;
    }
}

void showNames(QMap<string,int> map)
{
    for(auto it=map.begin();it!=map.end();it++)
    {
        cout<<it.key()<<endl;
    }
}

void showRange(QMap<string,int> map, string name1, string name2)
{
    auto from = map.lowerBound(name1);
    auto to = map.upperBound(name2);
    cout <<"Przedzial od "<<name1<<" do "<<name2<<endl;
    for (auto it=from; it != to; it++)
         cout<<it.key()<<" Liczba ludnosci "<<it.value()<<endl;
}

void deleteCountry(QMap<string,int> &map, string name)
{
    auto it = map.find(name);
    map.erase(it);
}

bool moreThan(QPair<string, int> x1, QPair<string, int> x2)
{
    return x1.second>x2.second;
}

bool lessThan(QPair<string, int> x1, QPair<string, int> x2)
{
    return x1.second<x2.second;
}

void sortMap(QMap<string,int> map, int type)
{
    QVector<QPair<string, int>> vec;
    for(auto it=map.begin();it!=map.end();it++)
    {
        vec.append(qMakePair(it.key(), it.value()));
    }
    if(type == 0)
    {
        sort(vec.begin(), vec.end(), moreThan);
    }
    else if(type == 1)
    {
        sort(vec.begin(), vec.end(), lessThan);
    }
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        cout<<it->first<<" Liczba ludnosci "<<it->second<<endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<string,int> map;
    addCountry(map, "Polska", 38000000);
    addCountry(map, "Niemcy", 83000000);
    addCountry(map, "Francja", 67500000);
    addCountry(map, "Szwecja", 10500000);
    show(map);
    showNames(map);
    showRange(map, "Niemcy", "Polska");
    cout<<"Po usunieciu Francji"<<endl;
    deleteCountry(map, "Francja");
    show(map);
    cout<<"Po sortowaniu malejaco"<<endl;
    sortMap(map, 0);
    cout<<"Po sortowaniu rosnaco"<<endl;
    sortMap(map, 1);
    return a.exec();
}
