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
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
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
// Imp observation
//___________________________________________________________________________________________________________________________________________
/*
so low is the last guarantee that target will be there but if it is not there then it will be the place for its occurance

When nums[mid] < target, we do:

low = mid + 1

➝ meaning everything left of low is guaranteed to be too small.

When nums[mid] > target, we do:

high = mid - 1

➝ meaning everything right of high is guaranteed to be too big.

Eventually, the loop stops when:

low > high

At this moment:

✔ All numbers before low are < target
✔ All numbers from low onward are ≥ target

*/

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


We maintain two pointers:

low → start of search range

high → end of search range

We compute mid each iteration.

Three cases:

If nums[mid] == target:
➝ We found the exact index → return mid.

If nums[mid] < target:
➝ Target must be to the right → update low = mid + 1.

If nums[mid] > target:
➝ Target must be to the left → update high = mid - 1.

If the loop ends without finding the target:

low will automatically be at the correct insertion position.

Hence return low.

This works because binary search continuously eliminates invalid regions until low becomes the smallest index where nums[i] >= target.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // Standard binary search loop
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If we found target, return its index
            if (nums[mid] == target)
                return mid;

            // If target is bigger, ignore left half
            else if (nums[mid] < target)
                low = mid + 1;

            // If target is smaller, ignore right half
            else
                high = mid - 1;
        }

        // If target not found, low will be the correct
        // position to insert target keeping the array sorted.
        return low;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Sorted Array

(Also called Search Insert Position, or Lower Bound Pattern)


*/

