/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.



Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
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
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();

        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int zerosCount = 0;

            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zerosCount++;
                if(zerosCount <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << sol.longestOnes(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n²) — two nested loops.

Space: O(1) — only counters and pointers used.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Consider every possible subarray starting at index i.
For each subarray, track the number of zeros (zerosCount).
Expand the subarray to the right with index j.
If the number of zeros is ≤ k, the subarray is valid → update maxLen.
If zeros > k, break, because further expansion will only make it worse.
After checking all subarrays, return the maximum length found.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0; // to store maximum length of valid subarray

        // consider every starting index i
        for (int i = 0; i < n; i++)
        {
            int zerosCount = 0; // count zeros in current window

            // expand subarray from i to j
            for (int j = i; j < n; j++)
            {
                // increment zerosCount if current element is 0
                if (nums[j] == 0)
                    zerosCount++;

                // if zeros in subarray ≤ k, update maxLen
                if (zerosCount <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break; // window invalid, stop expanding further
            }
        }

        return maxLen; // return the maximum length found
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


rute Force / Sliding Window Concept

*/
