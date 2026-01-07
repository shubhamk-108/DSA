/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array
Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();

        unordered_map<int, int> um;
        um[0] = 1;
        int count = 0;

        int prefixSum = 0;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];

            int required = prefixSum - goal;
            if (um.find(required) != um.end())
                count += um[required];

            um[prefixSum]++;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 0, 0, 0, 0};
    // vector<int> v = {1, 0, 1, 0, 1};
    int goal = 0;
    cout << sol.numSubarraysWithSum(v, goal);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(n) → single pass through the array.
Space: O(n) → hash map stores frequencies of prefix sums.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Prefix Sum Technique: The core idea is to keep a running sum (prefix sum) of all elements while iterating through the array. For every index 
i, the prefix sum represents the total of all elements from the start up to that index.​
Hash Map for Frequency Counting: An unordered_map (hash map) stores how many times each prefix sum has been seen so far. This allows quick 
lookup to determine if a previous prefix sum allows forming a valid subarray ending at the current index with the target sum.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();

        // HashMap to store frequency of prefix sums
        unordered_map<int, int> um;
        um[0] = 1;  // Handles subarrays starting at index 0

        int count = 0;       // Total number of subarrays with sum = goal
        int prefixSum = 0;   // Running prefix sum

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];             // Update prefix sum

            int required = prefixSum - goal;  // Previous prefix sum needed for subarray sum = goal

            if (um.find(required) != um.end())
                count += um[required];        // Add all subarrays ending at i with sum = goal

            um[prefixSum]++;                   // Record this prefix sum
        }

        return count;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Code Explanation
//___________________________________________________________________________________________________________________________________________

/*
ip : {1,0,1,0,1}
prefix sum : {1,1,2,2,3}
goal = 2

When prefix sum == goal means 2 == 2 then that is the valid subarray. Check index 2 and 3 is valid subarray because there prefix sum is 2.
Therefore subarray:
1,0,1
1,0,1,0

When prefix sum becomes 3 then we do not need extra 1 because our goal was 2. So 3-2 = 1 So we do not need 1.
So, we check that if 1 has occured before anywhere, if it occurs then we can assume that 3-1 = 2 which is a valid subarray.
But we check how many times that 1 has appeared because that many times we can subtract that 1 and get out goal 2.
Check at index 4 prefix sum is 3. And there are tow occurances of 1 at index 0 and 1.
SO, SO if we subtract index 0 1 then we get 0,1,0,1 which is valid. And if we remove index 1's 1 then we get 1,0,1 which is also valid.

*/




//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Prefix Sum + Hashing
Counts all subarrays with a given sum efficiently.
Sliding window cannot be used because zeros make sum non-monotonic.

*/
