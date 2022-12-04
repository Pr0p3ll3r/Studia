#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int make_hash(char s, int off, int p, int exp)
{
    int n_hash=((int)s-off)*pow(p, exp);
    return n_hash;
}

int update_hash(int h, char s_prev, char s_next, int off, int p, int exp)
{
    int u_hash=h-((int)s_prev-off)*pow(p, exp);
    u_hash*=p;
    u_hash+=((int)s_next-off);
    return u_hash;
}

void kr(string pattern, string text, int lenP, int lenT, int p, int off)
{
    int hashP=0, hashT=0, i=0;
    bool found=false;
    while(i<lenP)
    {
        hashP += make_hash(pattern[i], off, p, lenP-i-1);
        hashT += make_hash(text[i], off, p, lenP-i-1);
        i++;
    }
    i=lenP;
    int j=0;
    while(i<=lenT)
    {
        if(hashP==hashT)
        {
            int k=0;
            while(k<lenP && pattern[k]==text[j+k])
            {
                k++;
            }
            if(k==lenP)
            {
                cout<<j<<" ";
                found=true;
            }
        }
        if(i<lenT)
        {
            hashT=update_hash(hashT, text[j], text[i], off, p, lenP-1);
        }
        i++;
        j++;
    }
    if(found==false)
        cout<<"-1";
}

int main()
{
    string tekst, wzorzec;
    string sciezka;
    ifstream plik;
    sciezka="tekst.txt";
    plik.open(sciezka);
    plik >> wzorzec;
    int dw=wzorzec.length();
    int i=2;
    int dt;
    while(plik>>tekst)
    {
        dt=tekst.length();
        cout<<"Linijka "<<i<<": ";
        kr(wzorzec, tekst, dw, dt, 10, 65);
        cout<<endl;
        i++;
    }
    plik.close();
    return 0;
}
