// Check Previous file for what is lcm. And what ip and op for lcm should be

#include <iostream>
#include <limits.h>
using namespace std;

 bool checkPrimeNum(int n)
{
    if  (n == 1){return false;}

	for(int i = 2; i*i <= n ; i++)
    {
        if((n % i) ==0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    
    	cout<<checkPrimeNum(59);
    	cout<<"\n Control Ends \n";
    	return 0;
}

// Time complexity: O(sqrt(n))
// Auxiliary space: O(1)

// Logic 
//  for (int i = 2; i*i <= n; i++)
// You're looping from 2 to √n instead of 2 to n-1.
// This is mathematically valid because:
// If n is divisible by any number other than 1 and itself, then at least one of its factors must be ≤ √n.
// Example:
// Suppose n = 36
// Factor pair: (2, 18), (3, 12), (4, 9), (6, 6)
// Notice: All lower factors (2, 3, 4, 6) ≤ √36 = 6
// So if no number ≤ √n divides n, it must be prime.
// This optimization reduces time complexity from O(n) to O(√n).


// Divisors are always appear in pair.
// for ex: for n = 30 = (1,30), (2,15), (3,10), (5,6)
// x * y = n
// x * x <= n
// x^2 <= n
// therefore : x^2 <= n or x <= sq.root(n)
// that is one number from each pair will always be less than sq.root(n).
// like sq.root(30) = 5.47 And you can see that no one of the number of each pair is greater than 5.47
// (1,30), (2,15), (3,10), (5,6)

// 