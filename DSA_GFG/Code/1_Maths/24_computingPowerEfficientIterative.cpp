// C++ program to calculate iterative power (x^n)
#include <iostream>
using namespace std;

int power(int x, int n)
{
    // Initialize result
    int res=1;
    while(n>0)
    {
        // If n is odd,
		// multiply
		// x with result
        if(n&1)
        {
            res=(res*x); // odd asel tr one extra x ne multiply karayach
        }
            
        // n must be even now
        x=(x*x); // Change x to x^2. even asel tr x = x^2 karayach
        n=n>>1; // n = n/2
    }
    return res;
}
// Driver function
int main() {
	int x=4,n=5;
	cout<<power(x,n)<<endl;
	return 0;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)

// what is this  if(n & 1)
// This is a bitwise AND operation between n and 1.
//  Purpose:
// To check if n is odd.

//  How it works:
// Every integer is stored in binary.
// 1 in binary is: 0000 0001
// Suppose n = 5, which is: 0000 0101
// n & 1
//    0000 0101   (5)
// &  0000 0001   (1)
// -------------
//    0000 0001   → result is 1 → TRUE
// So if (n & 1) is true when n is odd 

//  Why use it instead of n % 2 == 1?
// It’s faster (though modern compilers optimize both)
// It’s often used in low-level programming, DSA, and competitive coding

// if(n&1) this n & 1 is evaluated and give us 1. so the expression becomes if(1) that is if(true) 

// (n & 1 ) checks whether the last (least significant) bit of n is 1.
// If the last bit is 1, then the number is odd.
// If the last bit is 0, then the number is even.


// What does >> mean?
// It’s the right shift operator in C++.
// What does n >> 1 do?
// It shifts all bits of n to the right by 1 position.
// This is equivalent to integer division by 2.

// Example:
// Let's say n = 10
// Binary: 1010
// Now apply:
// n >> 1  → 0101 → which is 5
// n = n >> 1;   // is the same as
// n = n / 2;
// But it is faster, because bitwise operations are lower-level and more efficient than division.