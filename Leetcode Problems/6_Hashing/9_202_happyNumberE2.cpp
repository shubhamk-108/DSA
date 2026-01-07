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
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
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
    // Helper function: compute sum of squares of digits
    int nextNumber(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    

    bool isHappy(int n)
    {
        int tortoise = n;
        int hare = n;

        do
        {
            tortoise = nextNumber(tortoise);
            hare = nextNumber(nextNumber(hare));
        } while (tortoise != hare);

        return tortoise == 1;
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
Time Complexity: O(log n) per iteration × bounded iterations
Each iteration computes sum-of-squares of digits → O(log n) (number of digits in n)
Sequence converges to ≤243 → constant number of iterations → practically O(log n)
Space Complexity: O(1)
Only two pointers (tortoise and hare) are used
No extra memory for a set → strictly constant space
Important note: n is the numeric value, not the length of the number. Digit extraction depends on log n digits.

*/

//___________________________________________________________________________________________________________________________________________
// My imp concern
//___________________________________________________________________________________________________________________________________________

/*

concern:
tortoise might be 1 and at that time hare will not be 1 and when hare will be 1 , tortoise will not be 1 and when they both are same 
they might be at number 15 for ex. Then what is the guarantee that tortoise == 1 will be 1 since we are checking whle (tortoise == hare

answer:
Property of the sequence
For any number sequence in LC202, there are only two possibilities:
Sequence reaches 1 → fixed point.
Once n = 1, next(1) = 1.
So if tortoise or hare ever reaches 1, it stays at 1 forever.
Sequence enters a cycle not including 1 → unhappy number.
This cycle is disjoint from 1.
And before reaching 1 if cycle is detected then it is a cycle because tortoise was taking only one step so it didnt missed any steps
still we are getting hare == tortoise that means this is  a cycle..
*/
//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Determine if a number is a happy number.
Approach: Use Floyd’s cycle detection (Tortoise and Hare) instead of hashing
Steps
Compute the next number in the sequence as the sum of squares of digits.
Use two pointers
tortoise moves 1 step at a time
hare moves 2 steps at a time
Loop until tortoise == hare:
If they meet at 1 → number is happy
If they meet elsewhere → number is unhappy (cycle)
Key idea
In Happy Number sequences, 1 is a fixed point.
Any cycle that doesn’t include 1 is detected because tortoise == hare inside that cycle.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution {
public:
    // Compute sum of squares of digits of a number
    int nextNumber(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;     // extract last digit
            sum += digit * digit;   // square and add to sum
            n /= 10;                // remove last digit
        }
        return sum;                // next number in sequence
    }

    bool isHappy(int n) {
        int tortoise = n;          // slow pointer
        int hare = n;              // fast pointer

        // Loop until pointers meet
        do {
            tortoise = nextNumber(tortoise);          // 1 step
            hare = nextNumber(nextNumber(hare));      // 2 steps
        } while (tortoise != hare);

        // If meeting point is 1 → happy number
        return tortoise == 1;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Floyd’s Cycle Detection / Tortoise and Hare

*/
