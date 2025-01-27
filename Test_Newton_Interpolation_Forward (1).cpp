//Newton_Interpolation_Forward.
#include<iostream>
#include<iomanip>
using namespace std;


double p_cal(double pf, int n)
{
    double temp=pf;
    for(int i=1; i<n; i++)
        temp*=(pf-i);
    return temp;
}

int fac(int m)
{
    if(m==0)return 1;
    return m*fac(m-1);
}

int main()
{
    int i, j, m;
    cout<<"\n Enter number of terms: ";
    cin>>m;
    double x[m],y[m][m],x_value;
    cout<<"\n Enter X & Y values. "<<endl;
    for(i=0; i<m; i++)
    {
        cout<<" X["<<i<<"] : ";
        cin>>x[i];
        cout<<" Y["<<i<<"] : ";
        cin>>y[i][0];
    }

//Forward Calculation.
    for(i=1; i<m; i++)
        for(j=0; j<m-i; j++)
            y[j][i]=y[j+1][i-1]-y[j][i-1];

// Forward Difference Table.
cout<<"\n Forward Difference Table."<<endl;
    for(i=0; i<m; i++)
    {   cout<<setw(4)<<x[i]<<'\t';
        for(j=0; j<m-i; j++)
            cout<<y[i][j]<<'\t';
        cout<<endl;
    }

    cout<<"\n Enter X terms: ";
    cin>>x_value;
    double sum=y[0][0], p;
    p=(x_value-x[0])/(x[1]-x[0]);
    
 //   double ans=1/(x[1]-x[0])
    
    for(i=1; i<m; i++)
        sum+=(p_cal(p,i)*y[0][i])/fac(i);

    cout<<"For X term"<<x_value<<" Y value is "<<sum<<endl;
    return 0;
}






