#include <iostream>
#include <string>

using namespace std;

void wczytajDane(string &tekst, string &wzorzec)
{
    cout<<"Podaj tekst"<<endl;
    getchar();
    getline(cin, tekst);
    cout<<"Podaj wzorzec"<<endl;
    getline(cin, wzorzec);
}

void naiwny(string tekst, string wzorzec, int dlt, int dlw)
{
    int i=0;
    cout<<"Indeks wystapien: "<<endl;
    while(i<=dlt-dlw)
    {
        int j=0;
        while(j<dlw && wzorzec[j]==tekst[i+j])
        {
            j+=1;
        }
        if(j==dlw)
        {
            cout<<i<<" ";
        }
        i+=1;
    }
    cout<<endl;
}

void zbudujTabliceDopasowan(string wzorzec, int dlw, int p[])
{
    p[0]=0;
    p[1]=0;
    int t=0, i=1;
    while(i<dlw)
    {
        while(t>0 && wzorzec[t]!=wzorzec[i])
            t=p[t];
        if(wzorzec[t]==wzorzec[i])
        {
            t+=1;
        }
        p[i+1]=t;
        i+=1;
    }
}

void kmp(string tekst, string wzorzec, int dlt, int dlw, int p[])
{
    int i=0, j=0;
    cout<<"Indeks wystapien: "<<endl;
    while(i<dlt-dlw+1)
    {
        while(wzorzec[j]==tekst[i+j]&&j<dlw)
        {
            j+=1;
        }
        if(j==dlw)
        {
            cout<<i<<" ";
        }
        i=i+max(1,j-p[j]);
        j=p[j];
    }
    cout<<endl;
}

void tablicaPrzesuniec(string wzorzec, int dlw, int p[], char pocz, char kon)
{
    int n_pocz=(int)pocz;
    int n_kon=(int)kon;
    int i=0;
    while(i<=n_kon-n_pocz)
    {
        p[i]=-1;
        i+=1;
    }
    i=0;
    while(i<dlw)
    {
        p[wzorzec[i]-n_pocz]=i;
        i+=1;
    }
}

void bm(string wzorzec, string tekst, int dlw, int dlt, int p[], char pocz)
{
    int n_pocz=(int)pocz;
    int i=0;
    cout<<"Indeks wystapien: "<<endl;
    while(i<=dlt-dlw)
    {
        int j=dlw-1;
        while(j>-1&&wzorzec[j]==tekst[i+j])
        {
            j-=1;
        }
        if(j==-1)
        {
            cout<<i<<" ";
            i+=1;
        }
        else i=i+max(1, j-p[tekst[i+j]-n_pocz]);
    }
    cout<<endl;
}

int main()
{
    int wybor;
    string tekst, wzorzec;
    int dlt, dlw;
    int *p;
    for(;;)
    {
        cout<<"MENU"<<endl;
        cout<<"1: Zad5.1"<<endl;
        cout<<"2: Zad5.2"<<endl;
        cout<<"3: Zad5.3"<<endl;
        cout<<"4: Zad5.4"<<endl;
        cout<<"5: Koniec programu"<<endl;
        cin>>wybor;

        switch(wybor)
        {
            case 1:
                wczytajDane(tekst, wzorzec);
                cout<<"Dane wczytane"<<endl;
                dlt=tekst.length();
                dlw=wzorzec.length();
                break;
            case 2:
                naiwny(tekst, wzorzec, dlt, dlw);
                break;
            case 3:
                p = new int[dlw+1];
                zbudujTabliceDopasowan(wzorzec, dlw, p);
                kmp(tekst, wzorzec, dlt, dlw, p);
                break;
            case 4:
                p = new int[34];
                tablicaPrzesuniec(wzorzec, dlw, p, 'a', 'z');
                bm(wzorzec, tekst, dlw, dlt , p, 'a');
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Niepoprawny wybor"<<endl;
        }
    }
}
