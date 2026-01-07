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
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int currentSum = 0;
            for (int j = i; j < n; j++)
            {
                currentSum += nums[j];
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
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

Total: O(n²)

Space Complexity
Only a few integer variables (maxSum, currentSum, n)
Space: O(1) — constant extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop through each possible starting index i of the subarray.
For each i, start another loop for ending index j.
Maintain a running sum currentSum for the subarray nums[i..j].
Update maxSum whenever you find a larger sum.
Return the largest subarray sum after checking all possibilities.


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
        int maxSum = INT_MIN; // should start from the smallest integer to handle negative arrays

        // Iterate over all possible starting points
        for (int i = 0; i < n; i++)
        {
            int currentSum = 0;

            // For each starting point, calculate sum for every ending point
            for (int j = i; j < n; j++)
            {
                currentSum += nums[j];            // Add the next element
                maxSum = max(maxSum, currentSum); // Update maximum sum found so far
            }
        }

        return maxSum; // Return the largest subarray sum
    }
};




*/

