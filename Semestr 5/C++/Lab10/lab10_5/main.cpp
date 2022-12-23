#include <tuple>
#include <iostream>
#include <fstream>
#include <variant>
#include <vector>
#include <set>
using namespace std;

void addName(vector<tuple<string, int>> &vec, string name)
{
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        if(get<0>(*it) == name)
        {
            get<1>(*it)++;
            return;
        }
    }
    vec.push_back(make_tuple(name, 1));
}

void addDomain(set<string> &set, string email)
{
    int at = email.find('@');
    string domain = email.substr(at + 1, email.length() - 1);
    set.insert(domain);
}

int main()
{
    set<string> domains;
    vector<string> phoneNumbers;
    vector<string> lastNames;
    vector<tuple<string, int>> vecNames;
    ifstream plik;
    plik.open("dane.txt", ios::in);
    if(plik.is_open())
    {
        string linia;
        while(!plik.eof())
        {
            getline(plik,linia,';');
            if(linia.empty())
                 continue;
            addName(vecNames, linia);

            getline(plik,linia,';');
            lastNames.push_back(linia);

            getline(plik,linia,';');
            getline(plik,linia,';');
            phoneNumbers.push_back(linia);

            getline(plik,linia,'\n');
            addDomain(domains, linia);
        }
        plik.close();
    }
    cout<<"Nazwiska laczone"<<endl;
    for(auto it=lastNames.begin();it!=lastNames.end();it++)
    {
        auto ind = it->find('-');
        if(ind != variant_npos)
        {
            cout<<*it<<endl;
        }
    }
    cout<<endl<<"Statystyka imion (imie + liczba wystapien)"<<endl;
    for(auto it=vecNames.begin();it!=vecNames.end();it++)
    {
        cout<<get<0>(*it)<<"->"<<get<1>(*it)<<endl;
    }
    cout<<endl<<"Nazwy unikatowych domen"<<endl;
    for(auto it=domains.begin();it!=domains.end();it++)
    {
        cout<<*it<<endl;
    }
    cout<<endl<<"Numery telefonow, ktore koncza sie liczba parzysta"<<endl;
    for(auto it=phoneNumbers.begin();it!=phoneNumbers.end();it++)
    {
        char lastNumber = it->at(it->length()-1);
        if((int)(lastNumber - '0') % 2 == 0)
            cout<<*it<<endl;
    }
    return 0;
}
