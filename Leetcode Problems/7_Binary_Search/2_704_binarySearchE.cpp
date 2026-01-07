/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

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
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            
            int mid = low + (high - low) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-1, 0, 3, 5, 9, 12};
    cout << sol.search(v, 9);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(log N)

Binary search divides the array in half at each step.

Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We are given a sorted array nums.
Use binary search by maintaining two pointers:
low → beginning
high → end
Repeatedly find the middle index:
mid = low + (high - low) / 2

Compare nums[mid] with the target:
If nums[mid] < target → target is in the right half → low = mid + 1
If nums[mid] > target → target is in the left half → high = mid - 1
If equal → return mid
If the loop ends without finding the target → return -1.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int low = 0;               // Start index
        int high = n - 1;          // End index

        // Continue until search space is valid
        while (low <= high)
        {
            // Mid point to divide array into halves
            int mid = low + (high - low) / 2;

            // If middle value is smaller, search in right half
            if (nums[mid] < target)
                low = mid + 1;

            // If middle value is larger, search in left half
            else if (nums[mid] > target)
                high = mid - 1;

            // Found target at mid
            else
                return mid;
        }

        // Target not found
        return -1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Pattern: Classic Binary Search on Sorted Array (Search Space Halving)
*/
