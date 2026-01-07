/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
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
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();
        int minSubarraySize = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    minSubarraySize = min(minSubarraySize, j - i + 1);
                    break;
                }
            }
        }

        return minSubarraySize == INT_MAX ? 0 : minSubarraySize;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²) — two nested loops checking all possible subarrays.

Space Complexity: O(1) — only uses a few integer variables.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Fix a starting index i.
From i, extend the subarray by moving j forward and keep adding nums[j] to sum.
As soon as the cumulative sum becomes ≥ target, record the current window length (j − i + 1) and break (since any longer subarray 
from the same start would be larger).
Keep track of the smallest valid window across all i.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int minSubarraySize = INT_MAX; // store the smallest valid window length

        // Try every possible starting index
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            // Expand the window to the right
            for (int j = i; j < n; j++)
            {
                sum += nums[j];

                // Once sum >= target, record and break (no need to extend further)
                if (sum >= target)
                {
                    minSubarraySize = min(minSubarraySize, j - i + 1);
                    break;
                }
            }
        }

        // If no valid subarray found, return 0
        return (minSubarraySize == INT_MAX) ? 0 : minSubarraySize;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force Enumeration (two-loop approach).

*/
