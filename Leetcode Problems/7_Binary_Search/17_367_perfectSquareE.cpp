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
        int low = 1;
        int high = num;

        if (num < 2)
            return true;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid < num)
            {
                low = mid + 1;
            }
            else if (mid * mid > num)
                high = mid - 1;
            else
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

| Complexity         | Explanation                              |
| ------------------ | ---------------------------------------- |
| **Time: O(log n)** | Binary search halves the range each time |
| **Space: O(1)**    | Only variables used                      |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Idea: Use Binary Search on the range [1, num]
A perfect square x must satisfy:
x = mid * mid
Search for mid in the range 1 to num.
If:
mid * mid == num → num IS a perfect square.
mid * mid < num → we need a larger number → move right.
mid * mid > num → we need a smaller number → move left.
If no such mid exists → return false.
This avoids overflow using long long.
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
        // Edge case: 1 is a perfect square
        if (num < 2)
            return true;

        long long low = 1;
        long long high = num;

        // Binary search in the range [1, num]
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;  // check square

            if (sq == num)
                return true;          // perfect square found

            if (sq < num)
                low = mid + 1;        // need larger value
            else
                high = mid - 1;       // need smaller value
        }

        // No integer whose square equals num
        return false;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Binary Search on Answer



*/
