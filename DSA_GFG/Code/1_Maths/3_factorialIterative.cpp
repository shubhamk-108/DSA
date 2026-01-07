#include <iostream>
using namespace std;

int findFactorial(int n)
{
    if (n == 0 || n == 1 ){return 1;}
    if (n< 0){return -1;}

    int factorial = 1;
    for(int i = 2; i <= n; i++)
    {
        factorial *= i;
    
    }
    
    return factorial;
}

int main()
{
    int n = 5;
    cout<<"Factorial of " << n << " is "<< findFactorial(n);
    cout<<"\ncontrol ends";
    
    return 0;
}

// This iterative solution has
// Time complexity : big O(n) because we need to traverse all loop exactly at every iteration
// space complexity : big O(1)

// This recursive solution has
// Time complexity : omega(n) 
// Space complexity : big O(n) 