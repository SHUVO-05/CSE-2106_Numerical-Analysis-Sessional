// Bisection Method for Non- algebraic function.
// Find the positive root, between 0 and 1, of the equation F(x)= (x*pow(e,x)-1) to a tolerance of 0.05%.
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define EP 0.0005
#define e 2.71828183

double func(double x)
{
    return ((x*(pow(e,x)))-1);
}

void bisection(double a, double b)
{
    double err;
    int i=0;
    if((func(a)*func(b))>=0)
    {
        cout<<" You have not assumed right a & b"<<endl;
        return;
    }
    double c= a;

    while ((b-a)>=EP)
    {
        c= (a+b)/2;
        err=(c-a)/c;
        cout<<" X"<<++i<<'\t'<<c;
        cout.setf(ios::right);
        cout<<setw(16)<<"\terror : "<<err*100<<endl;
        if(func(c)==0.0)break;
        else if((func(c)*func(a))<0)b=c;
        else a=c;
    }
    cout<<"\n The value of root is: "<<c<<endl;
}


int main()
{

    double a=0.0,b=1.0;
   // cout<<" Enter Your A & B value; ";
    //cin>>a>>b;
    bisection(a,b);
    return 0;
}
