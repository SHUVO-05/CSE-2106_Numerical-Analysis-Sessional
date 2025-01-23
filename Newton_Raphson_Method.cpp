//Newton Raphson Method Implimentation for Book example 2.15.
#include<iostream>
#include<iomanip>
#define EP 0.001
using namespace std;
 
// Bisection Method. The function is ((x*x*x)- (2*x) - 5).
double func(double x)
{
    return x*x*x - 2*x - 5;
}
 
// Derivative of the above function which is (3*x^x - 2)
double dFunc(double x)
{
    return 3*x*x - 2;
}
// Function to find the root
void newtonRaphson(double x)
{
    double h = func(x) / dFunc(x);
    while (abs(h) >= EP)
    {
        h = func(x)/dFunc(x);
        // x(i+1) = x(i) - f(x) / f'(x)  
        x = x - h;
    }
    cout << "The value of the root is : " << x<<endl;
}
int main()
{
    double Xo = 2;
    newtonRaphson(Xo);
    return 0;
}