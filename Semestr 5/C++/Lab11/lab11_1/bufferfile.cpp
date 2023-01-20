#include "bufferfile.h"
using namespace std;

BufferFile::BufferFile(std::string path)
{
    file = make_unique<fstream>(path, ios::out | ios::in);
    cout<<"Konstruktor klasy BufferFile"<<endl;
}

BufferFile::~BufferFile()
{
    cout<<"Destruktor klasy BufferFile"<<endl;
}

void BufferFile::add(int a)
{
    *file<<a<<endl;
}

void BufferFile::write()
{
    cout<<"Pokaz z pliku"<<endl;
    file->seekg(0);
    int num;
    while(*file >> num)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}
