// problem : count trailing number of zeros in factorial
// Input: 5
// Output: 1
// // Factorial of 5 = 5*4*3*2*1 = 120, which has one trailing 0.

// Input: 20
// Output: 4
// // Factorial of 20 = 20*19*18*.... 3*2*1 = 2432902008176640000 which has 4 trailing zeroes.

// Input: 100
// Output: 24



#include <iostream>
using namespace std;


int findTrailingZeroes(int n)
{
    int totalZeroes = 0;
    for (int i = 5; i<=n; i = i*5)
    {
        totalZeroes = totalZeroes + n/i;
    }
    return totalZeroes;

}

int main()
{
    int n = 100;
    cout<<"Trailing zeroes in factorial of  " << n << " is/are "<< findTrailingZeroes(n);
    cout<<"\ncontrol ends";
    
    return 0;
}










// TIme complexity: O(log n) because i*5
// space complexity: O(1)

// Logic to Count Trailing Zeroes in Factorial
// Problem:
// Given a number n, find the number of trailing zeroes in n! (factorial of n).

// Example:

// 5! = 120 → 1 trailing zero

// 10! = 3628800 → 2 trailing zeroes

// 100! → 24 trailing zeroes

// Why Do Trailing Zeroes Appear?
// Trailing zeroes come from factors of 10.

// But 10 = 2 × 5
// So each time we multiply a pair of (2, 5), we get a trailing zero.

// In a factorial, we multiply all numbers from 1 to n.
// So the total number of 2s and 5s in the prime factors of n! determine how many trailing zeroes it has.

// BUT...

// 2s are very common (e.g. from even numbers like 2, 4, 6, 8, etc.)

// 5s are rare, so we only need to count how many times 5 occurs in the factorization of n!.

// for  n = 100 we have 100/5 five. But number 25, 50, 75, etc has more than one five.
// Everytime me multiply our i by 5 we will get extra number of five.
// like 100/5 are normal number of five.
// But for extra five we have to do 100/25, 100/125, 100/625. Because each of these 
// number 25,125,625,etc has more number of five than normal. 
// How we will get that denominatior. We will start with i = 5 and then multiply that
// i with 5 everytime like... 5*5 = 25 this is one denominator. 25 has one extra five 
// like... 25*5 = 125 this is one denominator. 125 has two extra five 
// like... 125*5 = 625 this is one denominator. 625 has four extra five
// so (n/5) + (n/25) + (n/125) + n(625) + n(5*625)...... is our answer to trailing number of zeros. 

