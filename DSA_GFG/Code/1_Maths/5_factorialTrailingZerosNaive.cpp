// Count trailing zeros in factorial
// if 5 factorial = 120 then trailing zero count is 1

// This naive solution is very bad as for even a slightly bigger number like 20 the factorial would be very big
// and the data type like int will not store such big number so we will face overflow problem.
// So this is not efficient solution

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

int findTrailingZeroes(int n)
{
    int fact = findFactorial(n);

    int count = 0;

    while(fact % 10==0)
    {
        count++;
        fact = fact /10;
    }
    return count;

}

int main()
{
    int n = 5;
    cout<<"Trailing zeroes in factorial of  " << n << " is/are "<< findTrailingZeroes(n);
    cout<<"\ncontrol ends";
    
    return 0;
}

// This solution has
// Time complexity : theta(n)
// Space complexity :
