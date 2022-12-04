#include <QCoreApplication>
#include <iostream>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <string>
#include <iostream>
#include <boost/mpl/int.hpp>
#include <map>
#include <boost/type_index.hpp>

using namespace std;

map<string, int> mapa;

class Check
{
public:
    template <typename T>
    void operator()(T t)
    {
        for(auto it=mapa.begin(); it!=mapa.end();it++)
        {
            if(it->first == boost::typeindex::type_id<T>().pretty_name())
            {
                it->second++;
            }
        }
    }
};

int main()
{   
    boost::fusion::vector<int, char, bool, double> vec{10, 'c', true, 3.14};
    auto vec1 = push_back(vec, 100);
    mapa.insert(make_pair("int", 0));
    mapa.insert(make_pair("double", 0));
    mapa.insert(make_pair("float", 0));
    mapa.insert(make_pair("bool", 0));
    mapa.insert(make_pair("char", 0));
    for_each(vec1, Check());
    for(auto it=mapa.begin(); it!=mapa.end();it++)
    {
        cout<<it->first<<"->"<<it->second<<endl;
    }
    return 0;
}
