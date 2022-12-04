#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <map>

class Dictionary
{
private:
    std::map<std::string,std::string> words;
public:
    Dictionary();
    void addWord(std::string word,std::string translation);
    void deleteWord(std::string word);
    void show();
    void showTranslation(std::string word);
    void sort();
};

#endif // DICTIONARY_H
