/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

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
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int currentWindowSum = 0;
        int finalWindowSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            currentWindowSum = max(currentWindowSum + nums[i], nums[i]);
            finalWindowSum = max(finalWindowSum, currentWindowSum);
        }
        return finalWindowSum;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Single pass through array → O(n)
Space Complexity
Only two variables → O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Keep track of currentWindowSum — the maximum sum of subarray ending at the current element.
For each element nums[i]:
Either extend the current subarray: currentWindowSum + nums[i]
Or start a new subarray from nums[i] if it’s bigger than the current sum.
currentWindowSum = max(currentWindowSum + nums[i], nums[i])
Update finalWindowSum (global max) whenever currentWindowSum is bigger.
Return finalWindowSum at the end.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int currentWindowSum = 0;          // max sum of subarray ending at current index
        int finalWindowSum = INT_MIN;      // global max subarray sum

        for (int i = 0; i < n; i++)
        {
            // Either extend current subarray or start a new one
            currentWindowSum = max(currentWindowSum + nums[i], nums[i]);

            // Update global maximum
            finalWindowSum = max(finalWindowSum, currentWindowSum);
        }

        return finalWindowSum;
    }
};



*/
