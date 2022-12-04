#include <iostream>
#include <windows.h> //system("cls")
using namespace std;
void linia(){cout<<"------------------------------------------------------------------------------------------------------------------------------";}

int zmiana(long long &a, long long &b, long long q)
{
        long long k=b;
        b=a-q*k;
        a=k;
        return 0;
}

int main(int argc, char** argv)
{
    linia();
    cout<<endl<<"Wprowadzenie danych:"<<endl;
    linia();

    long long m,n;
    cout<<endl<<"NWD(m,n)"<<endl<<"M:";
    cin>>m;
    cout<<"N:";
    cin>>n;

    system("cls");
    linia();
    cout<<endl<<"Tabelka zmiennych w petli:"<<endl;
    linia();
    cout<<endl<<"\tl\t"<<"\tq\t"<<"\td\t"<<"\tdd\t"<<"\ts\t"<<"\tss\t"<<"\tt\t"<<"\ttt\t"<<endl;

    long long d,dd;
    d=m;
    dd=n;

    long long k,q;
    long long l=0;

    long long s,ss,t,tt;

    s=1;ss=0;
    t=0;tt=1;


    cout<<"\t"<<l<<"\t";
    cout<<"\t"<<"-"<<"\t";
    cout<<"\t"<<d<<"\t";
    cout<<"\t"<<dd<<"\t";
    cout<<"\t"<<s<<"\t";
    cout<<"\t"<<ss<<"\t";
    cout<<"\t"<<t<<"\t";
    cout<<"\t"<<tt<<"\t";

    while (dd>0)
    {
        l++;//l
        cout<<endl<<"\t"<<l<<"\t";
        q=d/dd;//q
        cout<<"\t"<<q<<"\t";
        zmiana(d,dd,q);//d,dd
        cout<<"\t"<<d<<"\t";
        cout<<"\t"<<dd<<"\t";
        zmiana(s,ss,q);//s,ss
        cout<<"\t"<<s<<"\t";
        cout<<"\t"<<ss<<"\t";
        zmiana(t,tt,q);//t,tt
        cout<<"\t"<<t<<"\t";
        cout<<"\t"<<tt<<"\t";
    }

    cout<<endl;

    linia();
    cout<<endl<<"Wyniki:"<<endl;
    linia();

    cout<<endl<<"NWD("<<m<<","<<n<<")= "<<d<<endl;
    cout<<d<<"=("<<s<<")*"<<m<<"+("<<t<<")*"<<n<<endl<<endl;
    cout<<"Liczby odwrotne:"<<endl;
    cout<<"do liczby: ("<<m<<") jest odwrotna: ("<<s<<") (mod "<<n<<")"<<endl;
    cout<<"do liczby: ("<<n<<") jest odwrotna: ("<<t<<") (mod "<<m<<")"<<endl<<endl;
    cout<<"Liczba obrotow= "<<l<<endl;

    return 0;
}
