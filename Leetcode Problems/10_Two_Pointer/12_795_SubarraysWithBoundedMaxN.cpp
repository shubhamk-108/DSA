/*
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8 
Output: 7


Constraints:
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
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int mx = nums[i];
            for (int j = i; j < n; j++)
            {
                mx = max(mx, nums[j]);
                if (mx >= left && mx <= right)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {12, 7, 8, 9, 1};
    cout << sol.numSubarrayBoundedMax(v, 7, 10);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²)

Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For every starting index i, extend to the right (j)
and maintain the running maximum of the subarray [i … j].

If the updated max is within [left, right],
→ that subarray is valid → count it.

If the max becomes > right,
→ we still continue, but those subarrays won’t count
(your brute-force does not early-break; this is fine and correct).

This guarantees we catch every possible subarray.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

For every starting index i, extend to the right (j)
and maintain the running maximum of the subarray [i … j].

If the updated max is within [left, right],
→ that subarray is valid → count it.

If the max becomes > right,
→ we still continue, but those subarrays won’t count
(your brute-force does not early-break; this is fine and correct).

This guarantees we catch every possible subarray.


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force + Subarray Enumeration

Enumerate all subarrays


*/
