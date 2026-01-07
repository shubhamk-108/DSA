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
private:
    int subArraySum(vector<int> &nums, int start, int end)
    {
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += nums[i];
        }
        return sum;
    }

public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                maxSum = max(maxSum, subArraySum(nums, j, j + i - 1));
            }
        }
        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Outer loop → O(n) (subarray length)
Inner loop → O(n) (starting index)
Subarray sum calculation → O(n)
Total = O(n³)

Space Complexity
Only variables maxSum and sum are used.
Space = O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Generate all possible subarrays using two nested loops:
Outer loop → subarray length
Inner loop → starting index of subarray
For each subarray, calculate the sum.
Keep track of the maximum sum found.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
private:
    // Calculates sum of subarray from start to end (inclusive)
    int subArraySum(vector<int> &nums, int start, int end)
    {
        int sum = 0;
        for (int i = start; i <= end; i++) // include end
        {
            sum += nums[i];
        }
        return sum;
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN; // To handle negative numbers

        // Length of subarray
        for (int len = 1; len <= n; len++)
        {
            // Starting index
            for (int start = 0; start <= n - len; start++)
            {
                int sum = subArraySum(nums, start, start + len - 1);
                maxSum = max(maxSum, sum); // update maximum sum
            }
        }

        return maxSum;
    }
};


*/
