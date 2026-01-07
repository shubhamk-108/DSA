/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the
resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ...,
nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
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

            if (nums[mid] == target)
                return mid;

            if (nums[low] <= nums[mid])
            {
                if (nums[mid] > target && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            else
            {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {6, 7, 8, 9, 10, 11, 1, 2, 3, 4, 5};
    cout << sol.search(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(log n) — same as binary search, since we discard half of the array each iteration.

Space Complexity
O(1) — only a few integer variables are used, no extra data structures.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We use a modified binary search to handle rotation.
Even though the entire array isn’t globally sorted,
at least one half (left or right) will always be sorted in every step.
We identify which half is sorted using nums[low] <= nums[mid],
and then decide whether the target lies in that half.
If yes — we shrink our search to that side; otherwise — search in the other half.

Step-by-step logic
Calculate mid.
If nums[mid] == target, return mid.
If left half is sorted (nums[low] <= nums[mid]):
Check if target lies between nums[low] and nums[mid].
If yes → move high = mid - 1
Else → move low = mid + 1
Else (right half is sorted):
Check if target lies between nums[mid] and nums[high].
If yes → move low = mid + 1
Else → move high = mid - 1
Continue until low > high.
If not found, return -1.


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
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // 🎯 Found the target
            if (nums[mid] == target)
                return mid;

            // 🧩 Check if left half is sorted
            if (nums[low] <= nums[mid])
            {
                // If target lies in the sorted left half
                if (nums[mid] > target && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else // 🧩 Otherwise, right half is sorted
            {
                // If target lies in the sorted right half
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        // ❌ Target not found
        return -1;
    }
};


*/
