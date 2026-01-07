/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
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

// This is Dutch National Flag algorithm
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int i = 0;

        while (i <= right)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[right]);
                right--;
            }
            else
                i++;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 0, 2, 1, 1, 0};
    // vector<int> v = {2,0,1};
    sol.sortColors(v);

    for (auto x : v)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n) — every element is visited at most once.
Space Complexity
O(1) — in-place.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

// This is Dutch National Flag algorithm
Use three pointers —
left → next position for 0
right → next position for 2
i → current scanning index
Traverse once:
If nums[i] == 0: swap nums[i] ↔ nums[left], then increment both i and left.
If nums[i] == 2: swap nums[i] ↔ nums[right], then decrement right (⚠ don’t increment i yet, because the swapped value must be re-checked).
If nums[i] == 1: just i++.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Why direclty increment i when swapping it with nums[left] because the new value at i after swapping is not checked yet, So why ?
//___________________________________________________________________________________________________________________________________________

/*

The element that was at nums[left] comes into position i.
But notice:
All indices before left (0 … left-1) are already confirmed 0s.
So nums[left] was part of the middle region, which means it was either 0 or 1 — never a 2.
So after the swap:
The value that comes to i (from nums[left]) cannot be 2 (the only case that needs re-check).
Therefore, it’s already fine — either 0 or 1.
So we can safely move i forward. 
That’s why incrementing i is logically safe — it’s not arbitrary.

In short:
We don’t check after swapping with left because we already know the region we swapped from is clean (only 0s/1s).
But we must recheck after swapping with right because that region may still contain 2s or unprocessed elements.
You don’t need to reread the entire logic — just keep this intuition:
"Left side = safe region, Right side = unprocessed danger zone."


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Dutch National Flag / Three-pointer partitioning


*/
