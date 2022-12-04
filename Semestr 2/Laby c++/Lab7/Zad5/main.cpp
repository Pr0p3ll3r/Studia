#include <iostream>

using namespace std;

class CMatrix
{
private:
    int rowNumber;
    int columnNumber;
    int** matrix;
public:
    CMatrix()
    {

    }
    CMatrix(int rowNumber, int columnNumber)
    {
        this->rowNumber = rowNumber;
        this->columnNumber = columnNumber;
        matrix = new int*[rowNumber];
        for(int i=0;i<rowNumber;i++)
        {
            matrix[i] = new matrix[columnNumber];
        }
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                tab[i][j]=0;
            }
        }
    }
    void init()
    {
        matrix = new int*[rowNumber];
        for(int i=0;i<rowNumber;i++)
        {
            matrix[i] = new matrix[columnNumber];
        }
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                tab[i][j]=0;
            }
        }
    }
    virtual ~CMatrix()
    {
        for(int i=0;i<rowNumber;i++)
        {
            delete matrix[i];
        }
        delete [] matrix;
    }
    virtual void readData()
    {
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                printf("Podaj liczbe tab[%d][%d]=", i, j);
                cin>>tab[i][j];
            }
        }
    }
    virtual void show()
    {
        for(int i=0;i<rowNumber;i++)
        {
            for(int j=0;j<columnNumber;j++)
            {
                cout<<tab[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    virtual double determinant()=0;
    void setRow(int x)
    {
        rowNumber = x;
    }
    void setColumn(int x)
    {
        columnNumber = x;
    }
    int getMatrix(int x, int y)
    {
        return matrix[x][y];
    }
    int getRow()
    {
        return rowNumber;
    }
    int getColumn()
    {
        return columnNumber;
    }
};

class CTriangularMatrix: public CMatrix
{
public:
    CTriangularMatrix(int n):CMatrix(n, n)
    {

    }
    double determinant()
    {
        double x = 1;
        for(int i=0;i<rowNumber;i++)
        {
            x *= getMatrix(i, i);
        }
        return x;
    }
    void readData()
    {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
