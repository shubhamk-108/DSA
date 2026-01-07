#include<iostream>
using namespace std;
 
unsigned int countSetBits(unsigned int n)
{
    unsigned int res = 0;
    while(n>0)
    {
        if( (n & 1) == 1)
            res++;
        n = n>>1;
    }
    return res;
}

int main()
{
    int n = 10;
    cout<<countSetBits(n);
    cout << "\n control ends " << " ";
    return 0;
}

// TIme complexity: O(b) b is number of bits from last to msb

// In C++, int is signed. That means:

// The leftmost bit (MSB) is used to represent sign.
// and n is negative, the binary is all 1s, and this can lead to an infinite loop or wrong results.

// Why use unsigned int:
// It removes the concept of negative numbers.
// All 32 bits are treated as regular bits, no sign.
// Safer for bitwise operations.
// 2. Why use n % 2 instead of n & 1?
//  n % 2:
// Mathematically checks: is the number odd?
// Slower, because % is an arithmetic operation
// Works for any type (int, long long, etc.)

// 🔹 n & 1:
// Bitwise operation, faster and more efficient
// Checks the last bit
// Perfect for bit manipulation and DSA
// Both are equivalent operation
// Why use n = n / 2 instead of n = n >> 1?
// n / 2 (Arithmetic Division)
// This is slower, because it:
// Involves arithmetic operations (handled by ALU)
// Works on any data type (int, float, etc.)
// Takes more CPU cycles
// 🔹 n >> 1 (Right Shift)
// This is faster, because it:
// Simply shifts all bits one position to the right
// Equivalent to integer division by 2 for positive numbers
// Requires no actual division math, just shifts the bits

