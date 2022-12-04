#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template<typename T>
class Array
{
private:
    T* tab;
    int size;
    int index;
public:
    Array(int size)
    {
        this->size=size;
        tab = new T[size];
        index = 0;
    }
    Array()
    {
        size=10;
        tab = new T[size];
        index=0;
    }
    ~Array()
    {
        delete [] tab;
    }
    void sort()
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<size-i-1;j++)
            {
                if(tab[j]>tab[j+1])
                    std::swap(tab[j], tab[j+1]);
            }
        }
    }
    T getMax()
    {
        T max = tab[0];
        for(int i=1;i<size;i++)
        {
            if(tab[i]>max)
                max=tab[i];
        }
        return max;
    }
    void show()
    {
        for(int i=0;i<size;i++)
        {
            std::cout<<tab[i]<<" ";
        }
        std::cout<<std::endl;
    }
    void add(T value)
    {
        tab[index]=value;
        index++;
    }
    T getElem(int i)
    {
        return tab[i];
    }
};

template<>
class Array<std::string>
{
private:
    std::string* tab;
    int size;
    int index;
public:
    Array(int size)
    {
        this->size=size;
        tab = new std::string[size];
        index = 0;
    }
    Array()
    {
        size=10;
        tab = new std::string[size];
        index=0;
    }
    ~Array()
    {
        delete [] tab;
    }
    void sort()
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<size-i-1;j++)
            {
                if(tab[j].size()>tab[j+1].size())
                    std::swap(tab[j], tab[j+1]);
            }
        }
    }
    std::string getMax()
    {
        std::string word = tab[0];
        for(int i=1;i<size;i++)
        {
            if(tab[i].size()>word.size())
                word=tab[i];
        }
        return word;
    }
    void show()
    {
        for(int i=0;i<size;i++)
        {
            std::cout<<tab[i]<<" ";
        }
        std::cout<<std::endl;
    }
    void add(std::string value)
    {
        tab[index]=value;
        index++;
    }
    std::string getElem(int i)
    {
        return tab[i];
    }
};

#endif // ARRAY_H
