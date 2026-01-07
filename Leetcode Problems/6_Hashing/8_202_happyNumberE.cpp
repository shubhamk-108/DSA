/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
Example 2:

Input: n = 2
Output: false
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> us;
        while (n != 1 && !us.count(n))
        {
            us.insert(n);

            long long squaredNumberSum = 0;

            while (n > 0)
            {
                int digit = n % 10;
                squaredNumberSum += digit * digit;
                n /= 10;
            }
            n = squaredNumberSum;
        }
        return n == 1;
    }
};

int main()
{
    Solution sol;
    int n = 19;
    cout << sol.isHappy(n);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

imp : n is not the lenght of number but n is the value of number.

Time Complexity: O(log n) per iteration, practically constant iterations
Each iteration computes the sum of squares of digits of the number n.
Number of digits in n = d = floor(log₁₀ n) + 1 → so extracting and squaring digits takes O(log n).
The sequence of numbers eventually converges to a number ≤ 243 (maximum sum-of-squares for any number).
Therefore, the loop runs at most a small constant number of times.
✅ Total time ≈ O(log n) practically.
Space Complexity: O(log n) in theory, O(1) practically
We store previously seen numbers in a set to detect cycles.
Maximum number of unique numbers before repeating is bounded (≤ 243).
Each number stored is O(1) space → total practically constant.
Key Insight:
The "log n" comes from number of digits, not the numeric value itself.
The sequence converges quickly → total iterations are small → time is very efficient


✅ How to say it confidently in an interview

"Each iteration of the loop computes the sum of squares of the digits of n, which takes O(log n) time because a number has log n digits. 
The sequence of numbers generated eventually converges to a number ≤ 243, so the loop runs a bounded number of times. We use a hash set 
to track seen numbers, which in practice holds at most 243 elements. Therefore, the overall time complexity is O(log n) and space 
complexity is effectively O(1)."
Max numbers stored ≤ 243 → O(1) practically, but formally O(log n) per number

What is that math 243 property ?
For any positive integer, if you repeatedly replace the number with the sum of squares of its digits, the resulting number will 
eventually fall below 243. That is why space is O(1).


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This is the hashing-based approach for detecting a happy number:
Use an unordered_set to track all numbers we have already seen.
If a number repeats, it means we are in a cycle → not happy.
Repeatedly replace the number n with the sum of the squares of its digits.
If n becomes 1, it is a happy number → return true.
If n repeats (already in the set), a cycle exists → return false.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us; // stores all previously seen numbers to detect cycles

        // Loop until we either reach 1 (happy) or detect a cycle
        while (n != 1 && !us.count(n)) {
            us.insert(n); // mark current number as seen

            long long squaredNumberSum = 0; // sum of squares of digits

            // Compute sum of squares of digits of n
            while (n > 0) {
                int digit = n % 10;
                squaredNumberSum += digit * digit;
                n /= 10;
            }

            n = squaredNumberSum; // update n to the next number in the sequence
        }

        return n == 1; // true if happy, false if cycle detected
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Hashing / HashSet → to track previously seen numbers and detect cycles.
Simulation / Iteration → compute the sequence step by step.


*/
