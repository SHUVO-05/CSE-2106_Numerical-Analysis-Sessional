//Forward difference
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"\     Enter your terms Number: ";
    cin>>n;
    double x[n],y[n][n];
    for(i=0; i<n; i++)
    {
        cout<<"X["<<i<<"] ";
        cin>>x[i];
        cout<<"Y["<<i<<"] ";
        cin>>y[i][0];
    }

// calculation forward difference.
    for(i=1; i<n; i++)
        for(j=0; j<n-i; j++)
            y[j][i]=y[j+1][i-1]-y[j][i-1];

    cout<<"\n Forward difference table.\n"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<setw(4)<<x[i]<<'\t';
        for(j=0; j<n-i; j++)
            cout<<setw(4)<<y[i][j]<<'\t';
        cout<<endl;
    }
}