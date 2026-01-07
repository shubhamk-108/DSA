#include <iostream>
#include <limits.h>
using namespace std;


double myPow(double x, int n) 
{
    long long N = n;  // Convert to long long to avoid overflow

    if (N < 0) 
    {            
        x = 1 / x;    // Invert the base
        N = -N;       // Make power positive
    }

    double result = 1.0;
    while (N > 0) 
    {
        if (N % 2 == 1)
            result *= x;
        x *= x;
        N /= 2;
    }

    return result;
}
int main() {
    
    double x = 2, n = -2;

	cout<<myPow(x, n);
    cout<<endl<<"control ends";
}