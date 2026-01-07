/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

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
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (target <= nums[i])
                return i;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 5, 6};
    cout << sol.searchInsert(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n)

Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop through the array from left to right.
For every index i, check:
If nums[i] is equal to the target → return i.
If nums[i] is greater than the target → target should be inserted at i.
If the loop finishes, it means all elements are smaller than the target, so insert at the end → return n.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        
        // Iterate through the array linearly
        for (int i = 0; i < n; i++)
        {
            // If the current element is equal to or greater than target,
            // this is the correct insert position (or exact match).
            if (target <= nums[i])
                return i;
        }

        // If we reach here, target is greater than all elements.
        // Insert at the end of the array.
        return n;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Linear Scan in a Sorted Array


*/
