// we will solve this GCD problem using Euclidean Algorithm


// The GCD of two integers is the largest number that divides both of them without leaving a remainder.
// GCD(12, 18)

// Divisors of 12 = 1, 2, 3, 4, 6, 12  
// Divisors of 18 = 1, 2, 3, 6, 9, 18

// Common divisors = 1, 2, 3, 6  
// Greatest = 6

// So, GCD(12, 18) = 6


#include <iostream>
using namespace std;

int gcd(int a , int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a= a-b;
        }
        else
        {
            b = b- a;
        }
    }
    return a;     
}
int main()
{
    cout<<gcd(15,10);
    cout<<"\n Control ends\n";
    return 0;
}

// Time Complexity:
// Worst Case: O(max(a, b))