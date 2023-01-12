#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <QDir>
using namespace std;

class Error
{
public:
    virtual void error()=0;
    virtual~Error() {};
};

class FileError: public Error
{
public:
    void error()
    {
        cout<<"Plik nie istnieje"<<endl;
    }
};

int main()
{
    char c;
    ifstream plik;
    try
    {     
         plik.open("kod.txt");
         if(plik.fail())
             throw new FileError();
         while(plik.get(c))
         {
            if(c == '/' && plik.peek() == '/')
            {
                 plik.clear();
                 plik.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
            }
            else
                cout<<c;
         }
    }
    catch(Error *error)
    {
        error->error();
    }
    plik.close();
    return 0;
}
