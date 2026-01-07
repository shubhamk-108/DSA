/*
Given an integer numsay nums and an integer k, split nums into k non-empty subnumsays such that the largest sum of any subnumsay is minimized.

Return the minimized largest sum of the split.

A subnumsay is a contiguous part of the numsay.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subnumsays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subnumsays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subnumsays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subnumsays is only 9.

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
    int splitnumsay(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (k > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());

        int sum = 0;
        for (auto x : nums)
            sum += x;

        int high = sum;
        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int subarrayCount = 1;
            int subarraySum = 0;
            int j = 0;

            while (j < n)
            {
                subarraySum += nums[j];

                if (subarraySum > mid)
                {
                    subarrayCount++;
                    subarraySum = nums[j];
                }
                j++;
            }

            if (subarrayCount > k)
                low = mid + 1;
            else if (subarrayCount <= k)
            {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {7, 2, 5, 10, 8};
    cout << sol.splitnumsay(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n * log(sum(nums)))
Binary search range = sum − max → log(sum)
For each candidate, scan array → O(n)

💾 Space Complexity
O(1) → only a few extra variables used
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Understand the problem:
We want to split nums into k contiguous subarrays
Objective: minimize the maximum sum of any subarray.
Define search space for binary search:
Low = max(nums) → minimum possible largest sum (a single number must fit in a subarray)
High = sum(nums) → maximum possible largest sum (put everything in one subarray)
Binary search on candidate maximum sum (mid):
Check if it is possible to split the array into ≤ k subarrays with maximum sum ≤ mid.
Greedy method:
Start a subarray sum = 0
Add numbers sequentially
If sum exceeds mid, start a new subarray and increment the count
If number of subarrays needed > k → mid too small → increase low
Else → mid works → try smaller max sum → decrease high
Repeat until low > high.
The smallest mid that works is the answer.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Minimum possible max sum = max element (each subarray must at least hold largest number)
        int low = *max_element(nums.begin(), nums.end());

        // Maximum possible max sum = sum of all elements (all in one subarray)
        int sum = 0;
        for (auto x : nums)
            sum += x;
        int high = sum;

        int res = -1; // store answer

        while (low <= high)
        {
            int mid = low + (high - low) / 2; // candidate max sum

            // Count how many subarrays are needed if max sum = mid
            int subarrayCount = 1; // at least one subarray
            int subarraySum = 0;

            for (int j = 0; j < n; j++)
            {
                subarraySum += nums[j];

                // If adding nums[j] exceeds mid, start a new subarray
                if (subarraySum > mid)
                {
                    subarrayCount++;
                    subarraySum = nums[j];
                }
            }

            // If more than k subarrays → mid too small
            if (subarrayCount > k)
            {
                low = mid + 1;
            }
            else
            {
                // mid is valid → try smaller max sum
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Binary Search on Answer + Greedy Feasibility Check



*/
