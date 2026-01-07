/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int low = 0, high = n - 1;
        int first = -1, last = -1;

        // Find first occurrence
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;

            if (nums[mid] == target)
                first = mid;
        }

        // Reset search range
        low = 0;
        high = n - 1;

        // Find last occurrence
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;

            if (nums[mid] == target)
                last = mid;
        }

        return {first, last};
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5, 7, 7, 8, 8, 10};
    vector<int> res = sol.searchRange(v, 8);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

TIme : 
O(log n) — each binary search runs in logarithmic time.
Total = O(2 × log n) → O(log n).

Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Two Binary Searches
First search: bias towards left (nums[mid] >= target → high = mid - 1).
Second search: bias towards right (nums[mid] <= target → low = mid + 1).
Each search independently finds one boundary of the target’s range.
If target not found, both first and last remain -1.

Both binary search look same but one subtle difference. When we found mid we save it in variable but we still again search on left.
Look this condition: 
if (nums[mid] >= target)
    high = mid - 1;
When mid is greater than target then me ask high to come to left. But look at that equal to sign. THat is even when out mid is == target,
still come to left and search if there is any other mid == target present. 


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int low = 0, high = n - 1;
        int first = -1, last = -1;

        // 🔹 Step 1: Find the first (leftmost) occurrence of target
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If current element is greater or equal, we go left
            if (nums[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;

            // Record position if we found the target
            if (nums[mid] == target)
                first = mid;
        }

        // Reset search boundaries for second search
        low = 0;
        high = n - 1;

        // 🔹 Step 2: Find the last (rightmost) occurrence of target
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If current element is smaller or equal, we go right
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;

            // Record position if we found the target
            if (nums[mid] == target)
                last = mid;
        }

        // Return the result pair (first, last)
        return {first, last};
    }
};



*/
