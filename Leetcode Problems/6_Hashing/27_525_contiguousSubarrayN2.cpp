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
        int maxLengt = 0;
        for (int i = 0; i < n; i++)
        {
            int zerosCount = 0;
            int onesCount = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zerosCount++;
                else
                    onesCount++;

                if (zerosCount == onesCount)
                    maxLengt = max(maxLengt, j - i + 1);
            }
        }
        return maxLengt;
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

Use nested loops to consider every possible subarray.
Maintain counts of 0s and 1s while expanding the subarray from index i to j.
Whenever zerosCount == onesCount, update the maximum subarray length.
This checks all possible contiguous subarrays for equality of 0s and 1s.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²) → nested loops over n elements.
Space Complexity: O(1) → only a few counters and variables.


*/

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
        int maxLengt = 0; // To store maximum length of subarray with equal 0s and 1s

        // Outer loop: choose starting index of subarray
        for (int i = 0; i < n; i++)
        {
            int zerosCount = 0; // count of 0s in current subarray
            int onesCount = 0;  // count of 1s in current subarray

            // Inner loop: expand subarray from start index i to end index j
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zerosCount++; // increment zero count
                else
                    onesCount++;  // increment one count

                // Check if current subarray has equal zeros and ones
                if (zerosCount == onesCount)
                    maxLengt = max(maxLengt, j - i + 1); // update maximum length
            }
        }

        return maxLengt; // return maximum balanced subarray length
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force / Sliding Window Counting (without optimization)
Counting / Frequency tracking inside subarrays.


*/
