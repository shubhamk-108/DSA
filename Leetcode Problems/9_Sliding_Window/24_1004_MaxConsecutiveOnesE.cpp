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

        int left = 0;
        int right = 0;
        int zerosCount = 0;

        while (right < n)
        {
            if (nums[right] == 0)
                zerosCount++;

            while (zerosCount > k)
            {
                if (nums[left] == 0)
                    zerosCount--;

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
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

Time: O(n) — each element is visited at most twice (once by right, once by left).

Space: O(1) — only a few integer variables.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Start with left = 0, right = 0, zerosCount = 0.
Expand the window by moving right:
If nums[right] == 0, increment zerosCount.
If zerosCount > k:
Move left forward, decrement zerosCount if nums[left] == 0.
After adjusting, the window [left..right] is valid. Update maxLen.
Continue until right reaches the end of the array.
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
        int n = nums.size();       // size of the input array
        int maxLen = 0;            // to store the maximum length of window
        int left = 0, right = 0;   // sliding window pointers
        int zerosCount = 0;        // number of zeros in current window

        // expand window by moving right pointer
        while (right < n)
        {
            // if current element is 0, increase zero count
            if (nums[right] == 0)
                zerosCount++;

            // if number of zeros exceeds k, shrink window from left
            while (zerosCount > k)
            {
                // if left element is 0, decrease zero count
                if (nums[left] == 0)
                    zerosCount--;

                left++;  // shrink window
            }

            // current window [left..right] is valid
            maxLen = max(maxLen, right - left + 1);

            right++; // expand window to the right
        }

        return maxLen; // return the maximum length of valid window
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window / Two Pointers

This is a classic “longest subarray with at most K replacements/changes” problem.


*/
