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
        for (int len = 1; len <= n; len++)
        {
            for (int start = 0; start + len <= n; start++)
            {
                int zerosCount = 0;
                int onesCount = 0;
                for (int k = 0; k < len; k++)
                {
                    if (nums[start + k] == 0)
                        zerosCount++;
                    else
                        onesCount++;
                }
                if (zerosCount  ==onesCount)
                    maxLengt = max (maxLengt, zerosCount + onesCount);
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

Outer loop over len → O(n)
Middle loop over start → O(n)
Inner loop over subarray → O(n)
Total = O(n³)
Space = O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Check every possible subarray and count how many zeros and ones it contains.
Fix a start index i
Fix an end index j
Count zeros and ones in the subarray nums[i…j]
If zeros == ones → update maximum length
This is the simplest, most direct way to solve the problem


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        int maxLengt = 0;

        // Try all subarray lengths
        for (int len = 1; len <= n; len++) {
            // Try all subarrays of this length
            for (int start = 0; start + len <= n; start++) {

                int zerosCount = 0;
                int onesCount = 0;

                // Count zeros and ones inside the subarray
                for (int k = 0; k < len; k++) {
                    if (nums[start + k] == 0)
                        zerosCount++;
                    else
                        onesCount++;
                }

                // If equal, update answer
                if (zerosCount == onesCount)
                    maxLengt = max(maxLengt, len);
            }
        }
        return maxLengt;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force
Counting
Checking all possible subarrays



*/
