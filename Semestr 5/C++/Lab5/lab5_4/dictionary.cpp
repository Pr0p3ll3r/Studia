#include "dictionary.h"
#include <vector>
#include <algorithm>
using namespace std;

Dictionary::Dictionary()
{

}

void Dictionary::addWord(std::string word, std::string translation)
{
    if(words.count(word))
    {
        cout<<"Slowo jest juz w slowniku"<<endl;
    }
    else
    {
        words.insert(make_pair(word,translation));
    }
}

void Dictionary::deleteWord(std::string word)
{
    if(words.count(word))
    {
        words.erase(words.find(word));
    }
    else
    {
        cout<<"Brak tego slowa w slowniku"<<endl;
    }
}

void Dictionary::show()
{
    for(auto it=words.begin();it!=words.end();it++)
    {
        cout<<it->first<<"-"<<it->second<<endl;
    }
}

void Dictionary::showTranslation(std::string word)
{
    if(words.count(word))
    {
        cout<<"Podane slowo "<<word<<"-"<<words.find(word)->second<<endl;
    }
    else
    {
        cout<<"Brak tego slowa w slowniku"<<endl;
    }
}

void Dictionary::sort()
{
    vector<pair<string,string>> vec;
    for(auto it=words.begin();it!=words.end();it++)
    {
        vec.push_back(make_pair(it->first, it->second));
    }
    std::sort(vec.begin(),vec.end());
    words.clear();
    for(auto it=vec.begin();it!=vec.end();it++)
    {
        words.insert(make_pair(it->first,it->second));
    }
}
