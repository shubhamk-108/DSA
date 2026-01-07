/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.

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
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        unordered_map<int, int> ump_prefixIndes;
        int maxSubarrayLen = 0;

        int prefixSum = 0;
        ump_prefixIndes[0] = -1;

        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i] == 0 ? -1 : 1;

            if (ump_prefixIndes.count(prefixSum))
                maxSubarrayLen = max(maxSubarrayLen, i - ump_prefixIndes[prefixSum]);

            if (!ump_prefixIndes.count(prefixSum))
                ump_prefixIndes[prefixSum] = i;
        }
        return maxSubarrayLen;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    cout << sol.findMaxLength(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
Space Complexity: O(n) for the hashmap
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Convert 0 → -1. ✅
Maintain prefix sum while iterating. ✅
Store first occurrence of each prefix sum in a hashmap. ✅
Compute max length as i - firstIndex(prefixSum). ✅
Initialize prefixIndex[0] = -1 to handle subarrays starting at index 0. ✅


*/


//___________________________________________________________________________________________________________________________________________
// Edge case
//___________________________________________________________________________________________________________________________________________

/*
when sum becomes 0 then we have to explicitely put 0 in the hash map and its index as 1. Because see ex.
0,0,0,0,1,1,1,1. The prefix sum at index 7 becomes 0. And generally we do length as i - indexOfFoundPrefixSum.
So here i is 7 and indexOfFoundPrefixSum is -1. So, i - indexOfFoundPrefixSum will be 7 - (-1) = 8. 
So the length is 8.


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) 
            return 0; // Single element cannot have equal 0s and 1s

        unordered_map<int, int> ump_prefixIndex; // Map prefixSum -> first occurrence index
        int maxSubarrayLen = 0; // To keep track of maximum balanced subarray length

        int prefixSum = 0; 
        ump_prefixIndex[0] = -1; 
        // Important initialization:
        // Treat prefixSum 0 as occurring at index -1.
        // This allows subarrays starting from index 0 to be counted correctly.

        for (int i = 0; i < n; i++)
        {
            // Convert 0 -> -1, 1 -> 1, and maintain cumulative prefix sum
            prefixSum += nums[i] == 0 ? -1 : 1;

            // If this prefixSum has been seen before, we found a subarray with sum 0
            if (ump_prefixIndex.count(prefixSum))
                maxSubarrayLen = max(maxSubarrayLen, i - ump_prefixIndex[prefixSum]);
                // Length = current index - first occurrence of this prefixSum

            // Store the first occurrence only, to maximize subarray length
            if (!ump_prefixIndex.count(prefixSum))
                ump_prefixIndex[prefixSum] = i;
        }

        return maxSubarrayLen; // Return maximum length of subarray with equal 0s and 1s
    }
};


//___________________________________________________________________________________________________________________________________________
// Explanation. How prefix sum is working.
//___________________________________________________________________________________________________________________________________________

/*

input : 0, 1, 1, 1, 1, 1, 0, 0, 0

Treat 0 and -1. So for ex 0, 1. We have -1, 1 and its sum will be 0. That means problem narrow downs to the after putting 0 and -1
find the sum equal to 0.

prefixSum : -1 , 0, 1, 2, 3, 4, 3, 2, 1.
So at index 2 we get 1 and at index 8 we get 1. Same prefix sum is repeating ahead that means all the things between those two prefix sum 
becomes 0. That is same number of -1 and 1 cancel out each other. And 0 are treated as -1. So we got our answer.
*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
