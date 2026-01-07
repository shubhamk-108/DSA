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
        int start = 0;
        int end = 0;
        int minSubarraySize = INT_MAX;
        int sum = 0;

        while (end < n || sum >= target)
        {
            while (end < n && sum < target)
            {
                sum += nums[end];
                end++;
            }
            if (sum >= target)
                minSubarraySize = min(minSubarraySize, end - start);

            sum -= nums[start];
            start++;
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

Time Complexity: O(n)
Each element is added and removed from the window at most once.

Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use a variable-size sliding window:
Maintain two pointers, start and end, that define the current subarray window.
Expand end to increase the sum until it becomes ≥ target.
Once the sum is large enough, update the minimum subarray length and shrink from start to try and minimize the window.
Continue this process until both ends of the array are processed and all possible minimal windows are checked.
This ensures we explore all valid windows in linear time without recomputing sums repeatedly.


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
        int start = 0;               // Left pointer of the window
        int end = 0;                 // Right pointer of the window
        int minSubarraySize = INT_MAX; // Stores the minimum window size found
        int sum = 0;                 // Current window sum

        // Continue until all elements are processed OR sum still >= target
        while (end < n || sum >= target)
        {
            // Expand window from the right while sum < target and end is valid
            while (end < n && sum < target)
            {
                sum += nums[end];
                end++;
            }

            // If current window satisfies condition, update min length
            if (sum >= target)
                minSubarraySize = min(minSubarraySize, end - start);

            // Shrink window from the left to try minimizing it further
            sum -= nums[start];
            start++;
        }

        // If no valid window found, return 0
        return minSubarraySize == INT_MAX ? 0 : minSubarraySize;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window (Variable Window Size)
This pattern is ideal for problems involving contiguous subarrays with a sum or condition that must be met or minimized.


*/
