//Backward Differences.
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{

    int n,i,j;
    cout<<" Enter Term: ";
    cin>>n;
    float x[n],y[n][n],value;
    cout<<"\n Enter your X and Y values: \n\n";
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
    cout<<setw(4)<<x[i]<<'\t';
        for ( j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
   return 0;
}