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
        for (int i = 0; i < n; i++)
        {
            if(nums[i]== target)
                return true;
        }
        return false;
        
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2,5,6,0,0,1,2};
    cout << sol.search(v,0);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity

O(n)
You potentially scan all elements.

💾 Space Complexity

O(1)
Uses no extra memory.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Your approach is simple linear search:
Iterate through the entire array from 0 to n-1
If you find an element equal to target, return true
If loop ends, return false
This works because duplicates and rotations do not matter; linear search always finds the element if it exists.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
Your approach is simple linear search:

Iterate through the entire array from 0 to n-1

If you find an element equal to target, return true

If loop ends, return false

This works because duplicates and rotations do not matter; linear search always finds the element if it exists.



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


👉 Brute Force / Linear Search Pattern

*/
