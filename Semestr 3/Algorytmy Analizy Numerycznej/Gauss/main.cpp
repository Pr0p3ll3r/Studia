#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void wczytaj(string nazwaPliku, double**& A, double*& b, unsigned &matrix_size){
    ifstream source_file(nazwaPliku);
    if (!source_file.is_open())
    {
        cout <<"The file has not been open!"<<endl;
        exit(0);
    }
    source_file >> matrix_size;

    A = new double*[matrix_size];
    A[0] = new double[matrix_size*matrix_size];
    for(unsigned i = 1; i< matrix_size; i++)
        A[i] = A[i-1] + matrix_size;

    b = new double[matrix_size];

    char semicolumn;
    for (unsigned i = 0; i < matrix_size+1; i++)
        source_file >> semicolumn;

    for (unsigned i = 0; i < matrix_size; i++)
    {
        for (unsigned j = 0; j < matrix_size; j++)
        {
            source_file >> A[i][j];
            source_file >> semicolumn;
        }
        source_file >> semicolumn;
        source_file >> b[i];
    }
    source_file.close();
}

void wyswietl(double** A, double* b, unsigned matrix_size){
    for(int i=0;i<matrix_size;i++)
    {
        for(int j=0;j<matrix_size;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<b[i];
        cout<<endl;
    }
}

void liczWiersze(double**& A, double*& b, unsigned matrix_size, int i){
    double p=0;
    for(int j=i;j<matrix_size;j++)
    {
        p=A[j][i-1]/A[i-1][i-1];
        A[j][i-1]=0;
        b[j]-=p*b[i-1];
        for(int k=i;k<matrix_size;k++)
        {
            A[j][k]-=p*A[i-1][k];
        }
    }
}

double* liczX(double** A, double* b, unsigned matrix_size){
    double* x;
    x = new double[matrix_size];
    for(int i=matrix_size-1;i>=0;i--)
    {
        double pomoc=0;
        for(int j=i+1;j<matrix_size;j++)
        {
            pomoc+=A[i][j]*x[j];
        }
        pomoc-=b[i];
        pomoc*=-1;
        x[i]=pomoc/A[i][i];
    }
    return x;
}

void sprawdzH(double*& x, unsigned matrix_size, int* h){
    for(int i=0;i<matrix_size;i++)
    {
        if(h[i]!=i)
        {
            int m;
            for(int j=0;j<matrix_size;j++)
            {
                if(h[j]==i)
                {
                    m=j;
                    break;
                }
            }
            swap(x[i],x[m]);
            swap(h[i],h[m]);
        }
    }
}

void wyswietlX(double* x, unsigned matrix_size){
    for(int i=0;i<matrix_size;i++)
    {
        cout<<"x"<<i+1<<"="<<x[i]<<endl;
    }
    cout<<endl;
}

void zamien(double**& A, double*& b, unsigned matrix_size, int wiersz, int*& h){
    //wyswietl(A,b,matrix_size);
    double maxA=INT_MIN;
    int k,w;
    //znalezienie maksymalnego elementu co do wartosci bezwzglednej
    for(int i=wiersz;i<matrix_size;i++)
    {
        for(int j=wiersz;j<matrix_size;j++)
        {
            if(abs(A[i][j])>maxA)
            {
                maxA=abs(A[i][j]);
                w=i;
                k=j;
            }
        }
    }
    //zamiana wierszy i kolumn
    if(w!=wiersz){
        swap(b[w],b[wiersz]);
        for(int i=wiersz;i<matrix_size;i++)
        {
            swap(A[wiersz][i],A[w][i]);
        }

    }
    if(k!=wiersz){
        for(int i=wiersz;i<matrix_size;i++)
        {
            swap(A[i][wiersz],A[i][k]);
        }
        swap(h[wiersz],h[k]);
    }
}

void zamienW(double**& A, double*& b, unsigned matrix_size, int wiersz){
    double maxA=INT_MIN;
    int w;
    //znalezienie maksymalnego elementu co do wartosci bezwzglednej w kolumnie
    for(int i=wiersz;i<matrix_size;i++)
    {
        if(abs(A[i][wiersz])>maxA)
        {
            maxA=abs(A[i][wiersz]);
            w=i;
        }
    }
    //zamiana wiersza
    if(w!=wiersz)
    {
        swap(b[w],b[wiersz]);
        for(int i=wiersz;i<matrix_size;i++)
        {
            swap(A[wiersz][i],A[w][i]);
        }
    }
}

void zamienK(double**& A, double*& b, unsigned matrix_size, int kolumna, int*& h){
    double maxA=INT_MIN;
    int k;
    //znalezienie maksymalnego elementu co do wartosci bezwzglednej w wierszu
    for(int i=kolumna;i<matrix_size;i++)
    {
        if(abs(A[kolumna][i])>maxA)
        {
            maxA=abs(A[kolumna][i]);
            k=i;
        }
    }
    //zamiana kolumny
    if(k!=kolumna)
    {
        for(int i=kolumna;i<matrix_size;i++)
        {
            swap(A[i][kolumna],A[i][k]);
        }
        swap(h[kolumna],h[k]);
    }
}

int zadanie1(string nazwaPliku){
    double** A;
    double* b;
    unsigned matrix_size;
    wczytaj(nazwaPliku, A, b, matrix_size);
    for(int i=1;i<matrix_size;i++)
    {
        if(A[i-1][i-1]==0)
        {
            cout<<"Element referencyjny jest rowny 0!"<<endl;
            return -1;
        }
        liczWiersze(A,b,matrix_size,i);
    }
    wyswietl(A,b,matrix_size);
    double* x;
    x = liczX(A,b,matrix_size);
    wyswietlX(x, matrix_size);
}

void zadanie2(string nazwaPliku){
    double** A;
    double* b;
    unsigned matrix_size;
    wczytaj(nazwaPliku, A, b, matrix_size);
    int* h=new int[matrix_size];
    for(int i=0;i<matrix_size;i++)
    {
        h[i]=i;
    }
    for(int i=0;i<matrix_size;i++)
    {
        zamienK(A,b,matrix_size,i,h);
        liczWiersze(A,b,matrix_size,i+1);
    }
    double* x;
    x = liczX(A,b,matrix_size);
    sprawdzH(x,matrix_size,h);
    wyswietlX(x, matrix_size);
}

void zadanie3(string nazwaPliku){
    double** A;
    double* b;
    unsigned matrix_size;
    wczytaj(nazwaPliku, A, b, matrix_size);
    for(int i=0;i<matrix_size;i++)
    {
        zamienW(A,b,matrix_size,i);
        liczWiersze(A,b,matrix_size,i+1);
    }
    //wyswietl(A,b,matrix_size);
    double* x;
    x = liczX(A,b,matrix_size);
    wyswietlX(x, matrix_size);
}

void zadanie4(string nazwaPliku){
    double** A;
    double* b;
    unsigned matrix_size;
    wczytaj(nazwaPliku, A, b, matrix_size);
    int* h=new int[matrix_size];
    for(int i=0;i<matrix_size;i++)
    {
        h[i]=i;
    }
    for(int i=0;i<matrix_size;i++)
    {
        zamien(A,b,matrix_size,i,h);
        liczWiersze(A,b,matrix_size,i+1);
    }
    //wyswietl(A,b,matrix_size);
    double* x;
    x = liczX(A,b,matrix_size);
    sprawdzH(x,matrix_size,h);
    wyswietlX(x, matrix_size);
}

int main()
{
    zadanie1("plik1.csv");
    //zadanie2("plik4.csv");
    //zadanie3("plik4.csv");
    //zadanie4("plik4.csv");
    return 0;
}
