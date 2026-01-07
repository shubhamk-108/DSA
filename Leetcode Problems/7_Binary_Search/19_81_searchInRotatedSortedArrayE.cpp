/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
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
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (nums[mid] <= nums[high])
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 5, 6, 0, 0, 1, 2};
    cout << sol.search(v, 0);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Worst-case: O(n)
Due to the duplicate scenario where we do: low++ and high--.

average case : log(n)

Space Complexity

O(1) — no extra space used.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We are searching a target in a rotated sorted array with duplicates.
Duplicates break the usual binary search logic, so the solution must handle them carefully.
Approach Summary
Use binary search (low, high, mid).
If nums[mid] == target, return true.
If nums[low], nums[mid], nums[high] are equal → duplicates cause ambiguity.
So shrink the search space:
low++, high--
Otherwise, one half must be sorted:
Left half sorted: nums[low] <= nums[mid]
Check if target lies in left half.
Right half sorted: nums[mid] < nums[high]
Check if target lies in right half.
Binary search continues until low > high.


*/


//___________________________________________________________________________________________________________________________________________
// Edge case: 
// Case 1: duplicates at both ends → cannot decide which half is sorted
            // if (nums[low] == nums[mid] && nums[mid] == nums[high])

/*



with duplicates:

[1, 1, 1, 1, 1, 1, 1]
 ^              ^
 low            high
        ^
        mid


Here:

nums[low] = 1
nums[mid] = 1
nums[high] = 1

All three are the same, so:
left half may be sorted
right half may be sorted
rotation point may be anywhere
you cannot decide anything
So, we shrink the search space by doing:

low++;
high--;


This removes the duplicates from boundaries without losing the target.*/
//___________________________________________________________________________________________________________________________________________


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            // Found target
            if (nums[mid] == target)
                return true;

            // Case 1: duplicates at both ends → cannot decide which half is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            // Case 2: left half is sorted
            else if (nums[low] <= nums[mid])
            {
                // Check if target lies in the sorted left half
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Case 3: right half is sorted
            else if (nums[mid] < nums[high])
            {
                // Check if target lies in the sorted right half
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Binary Search on Rotated Sorted Array (with duplicates)
Also known as:
Modified Binary Search
Search in Rotated Sorted Array II pattern
*/
