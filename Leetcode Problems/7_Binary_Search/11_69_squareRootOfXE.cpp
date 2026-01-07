/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
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
    int mySqrt(int x)
    {
        int low = 1;
        int high = x;
        int ans = 0;

        if (x == 0)
            return 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (mid * mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (mid * mid > x)
                high = mid - 1;
            else
                return mid;
        }
        return ans;
    }
};




int main()
{
    Solution sol;

    cout << sol.mySqrt(9);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric               | Complexity   |
| -------------------- | ------------ |
| **Time Complexity**  | **O(log x)** |
| **Space Complexity** | **O(1)**     |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We use Binary Search on the answer:
Search space: 1 to x
For each mid, compare mid² with x
If too small → move right
If too big → move left
If exact → return
If we never find exact value, ans stores the floor square root

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int mySqrt(int x)
    {
        // For x = 0 or 1, the square root is the number itself
        if (x < 2) return x;

        long long low = 1;
        long long high = x;
        long long ans = 0;  // stores the floor square root

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;  // avoid overflow

            long long sq = mid * mid;  // compute mid^2 safely

            if (sq < x)
            {
                // mid is a possible answer (floor sqrt)
                ans = mid;

                // try to find a larger value whose square is <= x
                low = mid + 1;
            }
            else if (sq > x)
            {
                // mid^2 is too large, move left
                high = mid - 1;
            }
            else
            {
                // perfect square
                return mid;
            }
        }

        // loop ends when low > high
        // ans contains floor(sqrt(x))
        return ans;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer / Search Space Reduction


*/
