// Test Bisection Method.For this equation 4*(e^(-x))sinx-1.
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define EP 0.001
//#define D 
#define e 2.71828183
double fun( double x) { return ((4*(pow(e,-x))*(sin(x)))-1);}

void Bisection (double a, double b)
{
double error, c;
int i=0;
if((fun(a)*fun(b))>=0){cout<<"\n Have not assumed between a & b."<<endl;return;}
c=a;
while((b-a)>=EP)
{
c=(a+b)/2;
error=(c-a)/c;
cout<<" X"<<++i<<"\t"<<c;
cout.setf(ios::right);
cout<<setw(16)<<"\t error: "<<error*100<<endl;
if(fun(c)==0)break;
if((fun(a)*fun(c))<0)b=c;
else a=c;
}
cout<<"\n The value of root is: "<<c<<endl;
}

int main()
{
double a=0.0,  b= 0.5;
cout<<fun(a)<<" & "<<fun(b)<<endl;
Bisection(a,b);
return 0;
}