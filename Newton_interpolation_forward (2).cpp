// Newton Interpolation forward. Book example 3.4.
#include<iostream>
#include<iomanip>
using namespace std;
float del_cal(float del, int n)
{
    float temp=del;
    int i;
    for(i=1; i<n; i++)
        temp=temp*(del-i);
    return temp;
}

int fac(int n)
{
    int i,f=1;
    for(i=2; i<=n; i++)
        f*=i;
    return f;
}

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

cout<<" \n Forward difference table"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<setw(4)<<x[i]<<'\t';
        for(j=0; j<n-i; j++)
            cout<<setw(4)<<y[i][j]<<'\t';
        cout<<endl;
    }

cout<<"\nEnter your X value: ";
cin>>value;
float sum=y[0][0],del;
del=(value-x[0])/(x[1]-x[0]);
for(i=1; i<n; i++)
{   sum=sum+(del_cal(del,i)*y[0][i])/fac(i);
}

cout<<" Your y value is: "<<sum<<endl;
}