#include <iostream>
using namespace std;

void printAllDivisorsOfNumber(int n)
{
    for(int i = 1; i*i <= n ; i++)
    {
        if (n % i == 0)
        {
            cout<<" "<<i<<" ";
            if(i != (n/i))
            {
                cout<<" "<<n/i;
            }
        }
        
    }

}

int main()
{
    int n = 90;

    printAllDivisorsOfNumber(n);

    cout<<endl<<"Control ends\n";
    return 0;
}

// Time Complexity: O(sqrt(n)) 
// Auxiliary Space: O(1)

// logic:

// all the divisors are present in pairs.
//for example if n = 100, then the various pairs of divisors are: (1,100), (2,50), (4,25), (5,20), (10,10)

// Example: n = 100
// Let’s list all the divisor pairs:

// i	n / i	Pair
// 1	100	    (1, 100)
// 2	50	    (2, 50)
// 4	25	    (4, 25)
// 5	20	    (5, 20)
// 10	10	    (10, 10) special case

// After 10, the pairs repeat (e.g., (20, 5), (25, 4)...), so we only go up to √n to avoid duplicates.


// Divisors are always appear in pair.
// for ex: for n = 30 = (1,30), (2,15), (3,10), (5,6)
// x * y = n
// x * x <= n
// x^2 <= n
// therefore : x^2 <= n or x <= sq.root(n)
// that is one number from each pair will always be less than sq.root(n).
// like sq.root(30) = 5.47 And you can see that no one of the number of each pair is greater than 5.47
// (1,30), (2,15), (3,10), (5,6)

// Why the if(i != n/i) check?
// To avoid duplicate printing for perfect squares.
// Example: If n = 36 and i = 6, then n/i = 6.
// We only want to print 6 once, not twice.