
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
        long long n = nums.size();
        long long count = 0;

        int right = 0, left = 0;

        while (right < n)
        {
            if (nums[right] == 0)
            {
                right++;
            }
            else if (nums[right] != 0)
            {
                long long a = right - left;
                long long b = (a * (a + 1)) / 2;
                count += b;
                right++;
                left = right;
            }
        }
        if (nums[n - 1] == 0)
        {
            long long a = right - left;
            long long b = (a * (a + 1)) / 2;
            count += b;
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


Time Complexity: O(n)
Each element is visited at most once by right pointer.

Space Complexity: O(1)
Only constant extra variables used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We scan the array using two pointers (left and right) to detect continuous segments of zeros.
Expand right as long as nums[right] == 0.
When we hit a non-zero, the zero-segment ends at index right - 1.
Length of zero segment = right - left.
Number of zero-filled subarrays in that segment =
(len⋅(len+1)) / 2	​

Add it to the total count.
Reset both pointers to the start of the next segment.
After the loop ends, we again check for a final zero segment that reaches the end.
This correctly counts all zero-filled subarrays in O(n) time.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

int right = 0, left = 0;
// Two pointers defining current zero segment boundaries

while (right < n)
{
    if (nums[right] == 0)
    {
        right++;
        // Expand the segment of zeros
    }
    else
    {
        // End of a zero segment – calculate its length
        int a = right - left;                       // segment length
        count += (long long)a * (a + 1) / 2;        // add zero subarrays

        right++;
        left = right;
        // Move both pointers to start searching new segment
    }
}

// Final segment check (if array ends with zeros)
if (nums[n - 1] == 0)
{
    int a = right - left;
    count += (long long)a * (a + 1) / 2;
}
int right = 0, left = 0;
// Two pointers defining current zero segment boundaries

while (right < n)
{
    if (nums[right] == 0)
    {
        right++;
        // Expand the segment of zeros
    }
    else
    {
        // End of a zero segment – calculate its length
        int a = right - left;                       // segment length
        count += (long long)a * (a + 1) / 2;        // add zero subarrays

        right++;
        left = right;
        // Move both pointers to start searching new segment
    }
}

// Final segment check (if array ends with zeros)
if (nums[n - 1] == 0)
{
    int a = right - left;
    count += (long long)a * (a + 1) / 2;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Two Pointers + Counting Segments

This is a classic pattern where you detect continuous segments of similar elements (here, zeros) and compute something about the segment length—in this case, the number of subarrays inside each zero segment.

The mathematical formula
len⋅(len+1)/2

is a standard method for counting subarrays inside a continuous block.


*/
