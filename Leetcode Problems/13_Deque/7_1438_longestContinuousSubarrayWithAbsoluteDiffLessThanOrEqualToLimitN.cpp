/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;



class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int currMin = nums[i];
            int currMax = nums[i];

            for (int j = i; j < n; j++)
            { // start from i, not i+1
                currMax = max(currMax, nums[j]);
                currMin = min(currMin, nums[j]);

                if (currMax - currMin <= limit)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }

        return maxLen;
    }
};

// int main()
// {
//     Solution sol;
//     vector<int> v = {10, 1, 2, 4, 7, 2};
//     cout << sol.longestSubarray(v, 5);
//     return 0;
// }

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ Time Complexity
Outer loop: O(n)
Inner loop: O(n) in worst case
Total: O(n²)

🪙 Space Complexity
Only a few integers used (currMin, currMax, etc.)
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


For each possible starting index i in the array:
Initialize currMin and currMax with nums[i].
Expand the window to the right by iterating j from i to n-1.
Update currMin and currMax with the new element nums[j].
If currMax - currMin <= limit, the current window is valid → update maxLen.
Otherwise, break, because adding further elements will only increase the difference.
Return the maximum length found.
Pattern used: Brute Force / Sliding Window Concept (without optimized data structure)

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        int maxLen = 0;  // store the maximum length found

        // consider every starting index i
        for (int i = 0; i < n; i++)
        {
            int currMin = nums[i];  // initialize min of current window
            int currMax = nums[i];  // initialize max of current window

            // expand the window to the right
            for (int j = i; j < n; j++)
            {
                currMax = max(currMax, nums[j]); // update max in window
                currMin = min(currMin, nums[j]); // update min in window

                // check if current window satisfies the limit
                if (currMax - currMin <= limit)
                    maxLen = max(maxLen, j - i + 1); // update maximum length
                else
                    break; // window invalid, stop expanding further
            }
        }

        return maxLen; // return the longest valid window length
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force / Sliding Window Concept

Brute-force generates all possible subarrays starting at every index.

Checks the condition (max - min ≤ limit) for each subarray.

*/