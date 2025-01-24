//Gaussian Elimination Implimentation. For 3 Unknown Values.
#include<iostream>
#include<iomanip>
using namespace std;
#define N 3

void swap_row(double mat[N][N+1], int i, int j)
{
    for (int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

int fElim(double mat[N][N+1])
{
    for (int k=0; k<N; k++)
    {
        int i_max = k;
        int v_max = mat[i_max][k];

        for (int i = k+1; i < N; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i;
        if (!mat[k][i_max])
            return k;
        if (i_max != k)
            swap_row(mat, k, i_max);
        for (int i=k+1; i<N; i++)
        {
            double f = mat[i][k]/mat[k][k];
            for (int j=k+1; j<=N; j++)
                mat[i][j] -= mat[k][j]*f;
            mat[i][k] = 0;
        }
    }

    return -1;
}
void bSub(double mat[N][N+1])
{
    double x[N];
    for (int i = N-1; i >= 0; i--)
    {
        x[i] = mat[i][N];
        for (int j=i+1; j<N; j++)
        {
            x[i] -= mat[i][j]*x[j];
        }
        x[i] = x[i]/mat[i][i];
    }

    cout<<"\n Your X,Y,Z value is : "<<endl;
    for (int i=0; i<N; i++)
        cout<<x[i]<<'\t';

}

void gaussEli(double mat[N][N+1])
{
    fElim(mat);
    bSub(mat);
}

int main()
{
    int i,j;
    double mat[N][N+1];
    cout<<"\n\t Enter your x,y,z coficient "<<endl;
    for(i=0; i<N; i++)
        for(j=0; j<=N; j++)
            cin>>mat[i][j];
    gaussEli(mat);
    return 0;
}