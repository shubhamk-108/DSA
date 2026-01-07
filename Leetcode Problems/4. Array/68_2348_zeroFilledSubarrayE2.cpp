
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

        int countOfZeros = 0;
        int totalCount = 0;

        for (auto &x : nums)
        {
            if (x == 0)
            {
                countOfZeros++;
                totalCount += countOfZeros;
            }
            else
                countOfZeros = 0;
        }

        return totalCount;
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
Single pass through the array.

Space Complexity: O(1)
Only uses constant additional memory.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We scan the array once and count consecutive zeros.
Let countOfZeros represent the length of the current zero segment.

Whenever we encounter a 0, we extend the current zero-run:
countOfZeros++

Each time we extend a zero segment, we add countOfZeros to the total because:

A segment of length k contributes:
1+ 2+ 3 + 4 + .... + n = (n * (n+1) / 2 )
	​ 
But instead of computing the formula at the end of the segment, we accumulate it incrementally.
If we encounter a non-zero, we reset countOfZeros = 0.
This counts all zero-filled subarrays in a single pass.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


long long countOfZeros = 0;
long long totalCount = 0;

for (auto &x : nums)
{
    if (x == 0)
    {
        countOfZeros++;          // extend zero segment
        totalCount += countOfZeros; // add all new subarrays formed
    }
    else
    {
        countOfZeros = 0;        // break zero segment
    }
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

This is a classic pattern where you track the length of a continuous segment to derive total subarrays formed inside that 
segment without restarting loops or using two pointers.
This pattern appears in problems like:
counting subarrays with only 1s
counting consecutive sequences
counting valid windows based on runs of same elements


*/
