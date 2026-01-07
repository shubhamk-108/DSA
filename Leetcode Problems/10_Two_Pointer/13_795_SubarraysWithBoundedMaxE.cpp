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

        int start = 0;
        int lastBoundedNumIdx = -1;
        int res = 0;

        for (int end = 0; end < n; end++)
        {
            if (nums[end] > right)
            {
                start = end + 1;
                lastBoundedNumIdx = -1;
            }

            else if (nums[end] < left)
            {
                if (lastBoundedNumIdx != -1)
                {
                    res += lastBoundedNumIdx - start + 1;
                }
            }

            else if (nums[end] >= left && nums[end] <= right)
            {
                lastBoundedNumIdx = end;
                res += end - start + 1;
            }
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {2, 9, 2, 5, 6};
    cout << sol.numSubarrayBoundedMax(v, 2, 8);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// My explanation  : if (nums[end] < left) why  res += lastBoundedNumIdx - start + 1;
//___________________________________________________________________________________________________________________________________________

/*

First what is end - start + 1: We can have end - start + 1 number of subarrays ending at index end. or j -  i + 1 we can have 
j - i + 1 number of subarrays ending at index j.

coming back to topic:

why not res += end - start + 1;
.......12, 7 8 ,9 1 for left = 7 and right = 10
suppose earlier valid window broke at 12. So we started new window from  7. start is 7. and last bounded index i got at 9.
consider 7, 8, 9, 1 at index 0, 1, 2, 3 resp.
So if we do end - start + 1 then we will have 3 - 0 + 1 = 4 subarrays. And if we do lastBoundedNumiIdx + 1 then 2 - 0 + 1 = 3 subarrays.
And when we write on paper then see we only have 3 subarrays which are valid here according to leetcode defination and ending at value 1.
{7,8,9,1} , {8,9,1}, {9,1} are the valid subarays and there no valid 4th subarary. {1} is not valid because subarray {1} does not contain
bounded element.
So we have to notice this using pen and paper.


*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)


Single-pass sliding window.
No nested loops.

💾 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We maintain two things:
1️⃣ start

The starting index of the current valid window (just after the last element > right).
Because any element greater than right invalidates a window.

2️⃣ lastBoundedNumIdx

The most recent index where nums[i] was within [left, right].
A subarray is valid only if it contains at least one such element.

How counting works

If nums[end] > right
→ Entire window is invalid. Reset everything.

If nums[end] < left
→ It can't validate a subarray, but it can extend an already valid one.
→ Only subarrays that include lastBoundedNumIdx are valid.
→ So add:

lastBoundedNumIdx - start + 1


If nums[end] ∈ [left, right]
→ Every subarray ending at end starting from start is valid.
→ So add:

end - start + 1


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();

        int start = 0;                // Start of the current valid window
        int lastBoundedNumIdx = -1;   // Last index where nums[i] ∈ [left, right]
        int res = 0;                  // Final count

        for (int end = 0; end < n; end++)
        {
            // Case 1: nums[end] > right → reset the entire window
            if (nums[end] > right)
            {
                start = end + 1;
                lastBoundedNumIdx = -1;
            }

            // Case 2: nums[end] < left → can extend previous valid window
            else if (nums[end] < left)
            {
                // Only valid if a bounded number existed earlier
                if (lastBoundedNumIdx != -1)
                {
                    res += lastBoundedNumIdx - start + 1;
                }
            }

            // Case 3: nums[end] ∈ [left, right] → fully valid element
            else
            {
                lastBoundedNumIdx = end;

                // All subarrays starting from start to end are valid
                res += end - start + 1;
            }
        }

        return res;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
✔ Sliding Window (Variable Window Size)

Specifically: "Window defined by invalid elements"



*/
