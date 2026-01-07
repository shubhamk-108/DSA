/*
Given an integer numsay nums and an integer k, split nums into k non-empty subnumsays such that the largest sum of any subnumsay is minimized.

Return the minimized largest sum of the split.

A subnumsay is a contiguous part of the numsay.

Example 1:

Input: nums = [7,2,5,10,8], k = 2subarraySum
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

        int lowestPagespossible = *max_element(nums.begin(), nums.end());

        int sum = 0;
        for (auto x : nums)
            sum += x;

        int largestPagesPossible = sum;
        int res = -1;
        

        for (int subarraySum = lowestPagespossible; subarraySum <= largestPagesPossible; subarraySum++)
        {
            int currSum = 0;
            int totalSubnumsays = 1;
            bool possible = true;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] > subarraySum)
                {
                    possible = false;
                    break;
                }

                currSum += nums[i];

                if (currSum > subarraySum)
                {
                    totalSubnumsays++;
                    currSum = nums[i];
                }

                if (totalSubnumsays > k)
                {
                    possible = false;
                    break;
                }
            }

            if (possible && totalSubnumsays <= k)
                return subarraySum;
        }
        return -1;
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
Outer loop: tries every possible sum from max(nums) to sum(nums) → O(sum)
Inner loop: scans array → O(n)
Total complexity: O(n × sum(nums)) → very slow for large numbers
Space complexity: O(1) → only a few variables used

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Split nums into at most k contiguous subarrays such that the maximum sum of any subarray is minimized.
Brute-force idea:
Try every possible candidate maximum sum (subarraySum) from max(nums) to sum(nums).
For each candidate, check if it is possible to split the array into ≤ k subarrays such that no subarray exceeds subarraySum.
Greedy check for each candidate:
Start with one subarray and sum = 0.
Add elements sequentially.
If adding an element exceeds subarraySum, start a new subarray.
Count total subarrays formed. If > k → candidate is invalid.
Return the first valid candidate.
This guarantees the minimum possible largest sum

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int splitnumsay(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Cannot split into more subarrays than elements
        if (k > n)
            return -1;

        // Minimum possible maximum sum = largest single element
        int lowestPagespossible = *max_element(nums.begin(), nums.end());

        // Maximum possible maximum sum = sum of all elements (single subarray)
        int sum = 0;
        for (auto x : nums)
            sum += x;
        int largestPagesPossible = sum;

        int res = -1;

        // Try every candidate maximum sum
        for (int subarraySum = lowestPagespossible; subarraySum <= largestPagesPossible; subarraySum++)
        {
            int currSum = 0;                // Current subarray sum
            int totalSubnumsays = 1;        // Count of subarrays (start with 1)
            bool possible = true;           // Flag to check feasibility

            for (int i = 0; i < n; i++)
            {
                // If a single element exceeds candidate sum → impossible
                if (nums[i] > subarraySum)
                {
                    possible = false;
                    break;
                }

                currSum += nums[i];          // Add element to current subarray

                // If current sum exceeds candidate → start new subarray
                if (currSum > subarraySum)
                {
                    totalSubnumsays++;
                    currSum = nums[i];
                }

                // Too many subarrays → candidate invalid
                if (totalSubnumsays > k)
                {
                    possible = false;
                    break;
                }
            }

            // If candidate is possible, return immediately
            if (possible && totalSubnumsays <= k)
                return subarraySum;
        }

        return -1; // No valid candidate found
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-force / Greedy feasibility check
Binary Search on Answer is the optimized pattern for this problem.


*/
