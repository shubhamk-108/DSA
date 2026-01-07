#include <iostream>
using namespace std;

int findFactorial(int n)
{
    if (n == 0 || n == 1 ){return 1;}
    if (n< 0){return -1;}

    
    return n * findFactorial(n - 1);
;
}

int main()
{
    int n = 5;
    cout<<"Factorial of " << n << " is "<< findFactorial(n);
    cout<<"\ncontrol ends";
    
    return 0;
}

// This recursive solution has
// Time complexity : theta(n) or O(n)
// Space complexity : big O(n) 

// we use theta when we know exact time complexity