/*
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.
Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
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
    bool isPerfectSquare(int num)
    {

        for (long long i = 0; i * i <= num; i++)
        {
            if (i * i == num)
                return true;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {0, 1, 0, 3, 12};
    cout << sol.isPerfectSquare(16);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity        | Explanation                   |
| ----------------- | ----------------------------- |
| **Time: O(√num)** | Loop runs until `i * i > num` |
| **Space: O(1)**   | Only one variable used        |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
A perfect square is a number that can be written as:
x = k * k for some integer k.
So we try every integer i starting from 0 and check whether:
i * i == num
We continue looping as long as i * i <= num because:
If i * i becomes greater than num, it will never match afterward.
So we stop early instead of looping all the way to num.
If any i satisfies i * i == num, return true;
otherwise return false after the loop ends.
This is the most basic brute-force method to check perfect squares.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // We try every number starting from 0
        // until i*i becomes greater than num.
        // Use long long to avoid overflow for i*i.
        for (long long i = 0; i * i <= num; i++)
        {
            // If i*i equals num, then num is a perfect square.
            if (i * i == num)
                return true;
        }

        // If we checked all i and found no match,
        // then num is NOT a perfect square.
        return false;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


This brute-force does not use any pattern — it's simple linear checking.

*/
