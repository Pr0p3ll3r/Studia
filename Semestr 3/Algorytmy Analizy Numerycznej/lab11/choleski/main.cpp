#include <iostream>
#include <cmath>

using namespace std;

const int n=3;

double* licz(int L[][n], double* b)
{
    double* x = new double[n];
    for(int i=0;i<n;i++)
    {
        double pomoc=0;
        for(int j=0;j<i;j++)
        {
            pomoc+=L[i][j]*x[j];
        }
        pomoc-=b[i];
        pomoc*=-1;
        x[i]=pomoc/L[i][i];
    }
    return x;
}

double* liczOdw(int L[][n], double* b)
{
    double* x = new double[n];
    for(int i=n-1;i>=0;i--)
    {
        double pomoc=0;
        for(int j=i+1;j<n;j++)
        {
            pomoc+=L[j][i]*x[j];
        }
        pomoc-=b[i];
        pomoc*=-1;
        x[i]=pomoc/L[i][i];
    }
    return x;
}

void choleski(int matrix[][n], double* b)
{
	int L[n][n];

	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
            L[i][j]=0;

	for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
			int sum = 0;
			if(j==i)
			{
				for (int k=0;k<j;k++)
					sum += pow(L[j][k], 2);
				L[j][j] = sqrt(matrix[j][j]-sum);
			}
			else
			{
				for(int k=0;k<j;k++)
					sum += (L[i][k]*L[j][k]);
				L[i][j] = (matrix[i][j]-sum)/L[j][j];
			}
		}
	}

	for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
			cout<<L[i][j]<<"\t";
		cout<<endl;
	}

    double* y = new double[n];
	y=licz(L,b);

	double* x = new double[n];
	x=liczOdw(L,y);
/*
    for (int i=0;i<n;i++)
    {
        cout<<y[i]<<" ";
	}
	cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
	}*/
}

int main()
{
	int matrix[n][n] = { { 4, -2, -4 },
						{ -2, 2, 1 },
						{ -4, 1, 6 } };
    double* b = new double[n];
    b[0]= -2;
    b[1]= 1;
    b[2]= 3;
    choleski(matrix, b);
	return 0;
}
