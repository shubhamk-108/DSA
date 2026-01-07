#include <iostream>
#include <limits.h>
#include<vector>
using namespace std;


 void sievePrintPrimeNumbers(int n)
{
    if(n <= 1)
		return;

	vector<bool> markPrime(n+1, true);
    
    for (int i = 2; i*i <= n; i ++)
    {
        if(markPrime[i])
        {
            for (int j = i*i; j <=n ; j = j + i)
            {
                markPrime[j] = false;
            }
        }
    }

    for(int i = 2; i<=n; i++)
    {
        if (markPrime[i])
        {   
            cout<<" "<<i<<" ";
        }
        
    }
}
int main() {
    
    	int n = 18;

		sievePrintPrimeNumbers(n);
}

// Time Complexity: O(n*log(log(n)))
// Auxiliary Space: O(n)

// Logic : 

// We create a boolean array markPrime[0...n] and set all values to true (assume all numbers are prime initially).
// 	for(int i=2; i*i <= n; i++)
// for this loop we have already discussed why loop is like this in previous programs

// for (int j = i*i; j <=n ; j = j + i)
// we are makeing multiples of i like multiples of 2,3,4,5 ,etc as false because they are not prime numbers
// If i is still marked as prime, mark all multiples of i (like 2×i, 3×i, ...) as not prime.
// These are guaranteed to be composite because they’re multiples of i.

// we can even use j = j*2 but j = i * i is even more optimised. It filters duplicate marking of multiples

// for(int i = 2; i<=n; i++)
// we are printing remaining true values which are prime numbers

// dry run

//  Example: n = 18

// for j = i * 2
// Initial: isPrime[2..18] = true
// i = 2: mark 4, 6, 8, 10, 12, 14, 16, 18 as false
// i = 3: mark 6, 9, 12, 15, 18 as false (some already false)
// i = 4: already marked as false, skip
// Loop ends at i = 4 because i*i > 18

// now if we take j = i*i
// for i = 2, j will be 4. And j = j+ i which is 4,6,8,10, etc will be marked as false not prime.
// for i = 3, j will be 9. And j = j+ i which is 9,12,15,18, etc will be marked as false not prime.
// for i = 5, j will be 25. And j = j+ i which is 30, 35, 40, 45 etc will be marked as false not prime.

