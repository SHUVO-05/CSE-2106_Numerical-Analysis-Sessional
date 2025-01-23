//Forward Differences.
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,i,j;
    cout<<" Enter Term: ";
    cin>>n;
    float x[n],y[n][n],value;
    cout<<" Enter your X and Y values: \n";
    for(i=0; i<n; i++)
    {
        cout<<"X["<<i+1<<"] : ";
        cin>>x[i];
        cout<<"Y["<<i+1<<"]  : ";
        cin>>y[i][0];
    }

// calculating forward Difference.
    for(i=1; i<n; i++)
        for(j=0; j<n-i; j++)
            y[j][i]=y[j+1][i-1]-y[j][i-1];


//Forward difference table;

cout<<" \n Forward difference table \n"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<setw(4)<<x[i]<<'\t';
        for(j=0; j<n-i; j++)
            cout<<setw(4)<<y[i][j]<<'\t';
        cout<<endl;
    }
}