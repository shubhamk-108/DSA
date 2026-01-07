#include <iostream>
#include <limits.h>
using namespace std;

 bool isPrime(int n)
{
	if(n==1)
		return false;

	if(n==2 || n==3)
		return true;

	if(n%2==0 || n%3==0)
		return false;

	for(int i=5; i*i<=n; i=i+6)
	{
		if(n % i == 0 || n % (i + 2) == 0)
			return false; 
	}

	return true;
}

int main() {
    
    	int n = 29;
    	
    	cout<< (isPrime(n) ? "true" : "false");
    	
    	return 0;
}

// Time Complexity:
// O(√n) but faster than the basic O(√n) due to:
// Skipping multiples of 2 & 3

// Space Complexity:
// O(1) (no extra space used)



// Logic 

//  Eliminate multiples of 2 and 3
// if (n % 2 == 0 || n % 3 == 0) return false;
// Any even number >2 is not prime.
// Any number divisible by 3 >3 is not prime.
// This filters out ~50% of non-prime numbers early.

// If we take i = 5. Then we will check for i = 5 and i = 7. 
// Then we increment i by 6 and i become 11. Then between when i was 5 and now when i is 11, All
// the numbers in between are checked by 2 and 3. For example 6,8,9. 6 and 9 was checked by 3 and 8 was checked by 2.
// So this  (n % 2 == 0 || n % 3 == 0) filters many iterations that is why we need to increment i by 6.

//  we are incrementing by 6 because any prime can be expressed as 6n+1 or 6n-1