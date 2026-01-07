#include <iostream>
#include <limits.h>
using namespace std;

 int gcd(int a, int b)
{
	if(b==0)
		return a;

	return gcd(b, a % b);
}

int main() {
    
    	int a = 12, b = 15;
    	
    	cout<<gcd(a, b);
    	
    	return 0;
}

// Time c:
// O(log(min(a, b))

// Logic: 


// The Fundamental Principle Behind GCD
// The greatest common divisor of two numbers doesn’t change if we replace the larger number with its difference from the smaller.

// This principle gives rise to two forms of the Euclidean Algorithm:

// Subtraction Form:

// gcd(a, b) = gcd(a - b, b) (when a > b)

// Modulo Form:

// gcd(a, b) = gcd(b, a % b)

// Using modulo does change the second number, but in a mathematically valid way that preserves the GCD.

// It’s just a faster way of doing repeated subtraction.