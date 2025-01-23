// Newton backward interpolation.
#include <iostream>
#include<iomanip>
using namespace std;

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
int main()
{

    int n,i,j;
    cout<<" Enter Term: ";
    cin>>n;
    float x[n],y[n][n],value;
    cout<<"\n Enter your X and Y values: \n";
    for(i=0; i<n; i++)
    {
        cout<<"X["<<i+1<<"] : ";
        cin>>x[i];
        cout<<"Y["<<i+1<<"]  : ";
        cin>>y[i][0];
    }
// Calculating the backward difference table
    for ( i = 1; i < n; i++) {
        for ( j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }
// Displaying the backward difference table
    cout<<"\n Backward Difference Table \n"<<endl;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
// Value to interpolate at
    cout<<"\n Enter your X value: ";
    cin>>value;
// Initializing u and sum
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);
    for ( i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
              fact(i);
    }
    cout << "\n Your X value " << value << "and Y value is "<< sum << endl;
    return 0;
}