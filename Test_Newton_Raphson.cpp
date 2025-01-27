// Implementation of Newton Raphson Method. For equation x*sinx+cosx=0.
#include<iostream>
#include<cmath>
using namespace std;
#define EP 0.001
double fun(double x) {
    return ( (x*sin(x))+cos(x));
}
double dfun(double x) {
    return (x*cos(x));
}

void N_R(double x)
{

    double h = fun(x)/dfun(x);
    int i=0;
    cout<<"\nn\t Xn\t F(Xn)\t Xn+1\n"<<endl;
    while(abs(h)>=EP)
    {
        h=fun(x)/dfun(x);
        cout<<++i<<"\t"<<x<<"\t "<<fun(x)<<"\t"<<x<<endl;
        x=x-h;

    }
    cout<<"\n The value of rooot is : "<<x<<endl;
}
int main()
{
    double xo=3.1415;
    N_R(xo);
    //cout<<fun(xo);
    return 0;    //cout<<fun(3.1416)<<endl;
}