#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Napis
{
private:
    string napis;
public:
    Napis(string napis)
    {
        this->napis=napis;
    }
    ~Napis()
    {
        cout<<"Obiekt jest usuwany"<<endl;
    }
    string getNapis()
    {
        return napis;
    }
    void setNapis(string napis)
    {
        this->napis=napis;
    }
    void show()
    {
        cout<<napis<<endl;
    }
    int getSize()
    {
        return napis.length();
    }
    bool anagram(string napis2)
    {
        string napis1=napis;

        if(napis1.length() != napis2.length())
            return false;

        for(int i=0;i<napis1.length()-1;i++)
        {
            if(napis1[i] >= 'A' && napis1[i] <= 'Z')
            {
                napis1[i] += 32;
            }
            if(napis2[i] >= 'A' && napis2[i] <= 'Z')
            {
                napis2[i] += 32;
            }
        }
        for(int i=0;i<napis1.length()-1;i++)
        {
            for(int j=0;j<napis2.length()-1;j++)
            {
                if(napis1[j] > napis1[j+1])
                    swap(napis1[j], napis1[j+1]);
                if(napis2[j] > napis2[j+1])
                    swap(napis2[j], napis2[j+1]);
            }
        }
        return napis1==napis2;
    }
    void maleDuze()
    {
        int duze=0, male=0;
        for(int i=0;i<napis.length();i++)
        {
            if((int)napis[i]>=97 && (int)napis[i]<=122)
                male++;
            if((int)napis[i]>=65 && (int)napis[i]<=90)
                duze++;
        }
        cout<<"Malych liter: "<<male<<endl;
        cout<<"Duzych liter: "<<duze<<endl;
    }
    int ileSamoglosek()
    {
        int samo=0;
        for(int i=0;i<napis.length();i++)
        {
            if(napis[i] == 'a' || napis[i] == 'e' || napis[i] == 'i' || napis[i] == 'o' || napis[i] == 'u' || napis[i] == 'y')
            {
                samo++;
            }
        }
        return samo;
    }
    bool palindrom()
    {
        string napis2=napis;
        reverse(napis.begin(), napis.end());
        if(napis==napis2)
            return true;
        else
            return false;
    }
};

int main()
{
    Napis napis("kajak");
    napis.show();
    cout<<"Rozmiar napisu: "<<napis.getSize()<<endl;
    if(napis.anagram("kajak")==true)
        cout<<"Napisy sa anagramami"<<endl;
    else
        cout<<"Napisy nie sa anagramami"<<endl;
    napis.maleDuze();
    cout<<"Samoglosek: "<<napis.ileSamoglosek()<<endl;
    if(napis.palindrom())
        cout<<"Napis jest palindromem"<<endl;
    else
        cout<<"Napis nie jest palindromem"<<endl;
    return 0;
}
