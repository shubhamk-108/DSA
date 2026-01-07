/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
 
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
    }
};

int main() {
    Solution sol;
    string num1 = "3";
    string num2 = "4";
    cout << sol.multiply(num1, num2);
    return 0;
}


/*


Efficient / Optimized Algorithms (Beyond Brute Force)

“This is the classical grade-school O(n×m) solution, which is optimal for Leetcode constraints.
For larger numbers (like in big integer libraries), faster algorithms such as Karatsuba or FFT can be used to achieve sub-quadratic complexity.”

These are not required in interviews unless you’re in advanced rounds or research / comp-sci-heavy roles,
but still, here’s what exists:
1. Karatsuba Algorithm

2. FFT (Fast Fourier Transform) Multiplication
Represent numbers as polynomials
This is how Python’s int or C++ big integer libraries multiply internally when numbers are very large (e.g., 10⁵ digits).

3.Toom-Cook and Schönhage-Strassen
Even faster and used in libraries like GMP, but very complex

*/