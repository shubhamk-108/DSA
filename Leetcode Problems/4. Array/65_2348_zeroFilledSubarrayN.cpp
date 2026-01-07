/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.

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
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        for (int len = 1; len <= n; len++)
        {
            for (int start = 0; start + len <= n; start++)
            {
                bool flag = false;
                for (int k = 0; k < len; k++)
                {
                    if (nums[start + k] != 0)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 0, 0, 2, 0, 0, 4};
    cout << sol.zeroFilledSubarray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n³)
Length loop → n
Start loop → n
Check loop → n
Worst case → n * n * n = n³.

📦 Space: O(1)

No extra structures used.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Try all possible subarray lengths from 1 to n.
For each length, try all starting positions.
For every subarray, check each element and verify whether all values are 0.
If the entire subarray contains only zeros, increment the count.
This brute approach matches the literal definition of “zero-filled subarray.”


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        // try all possible subarray lengths
        for (int len = 1; len <= n; len++)
        {
            // try all starting indices for this length
            for (int start = 0; start + len <= n; start++)
            {
                bool flag = false;

                // check if the subarray [start, start+len-1] is all zeros
                for (int k = 0; k < len; k++)
                {
                    if (nums[start + k] != 0)
                    {
                        flag = true;    // non-zero found → not a zero-filled subarray
                        break;
                    }
                }

                // if no non-zero found, this subarray is valid
                if (flag == false)
                    count++;
            }
        }

        return count; // return total number of zero-filled subarrays
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force — Generate All Subarrays
This is the raw definition-based brute pattern where you:
Enumerate all subarrays by (start, length)
Validate each subarray completely


*/
