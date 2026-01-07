/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0


Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.
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
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == nums[high])
                high--;

            else if (nums[mid] < nums[high])
                high = mid;

            else if (nums[mid] > nums[high])
                low = mid + 1;
        }
        return high;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Worst case: O(n)
Because duplicates can force the algorithm to shrink window by 1 repeatedly (high--).
Best/Average case: O(log n)
When duplicates do not interfere, it behaves like standard binary search.

📦 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This is Binary Search with duplicates (LC154).
Key idea:
Array is a rotated sorted array but may contain duplicates.
Compare nums[mid] with nums[high]:

If nums[mid] < nums[high]:
→ Minimum lies in left half including mid → high = mid

If nums[mid] > nums[high]:
→ Minimum lies in right half excluding mid → low = mid + 1

If nums[mid] == nums[high]:
→ We cannot decide, so we shrink the search by one → high--
Loop ends when low == high, which is the index of the minimum.
Returning nums[low] or nums[high] both work because they converge.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If nums[mid] and nums[high] are equal,
            // we cannot determine which side is strictly sorted.
            // Reduce the search space by shrinking high.
            if (nums[mid] == nums[high])
                high--;

            // If mid element is less than high element,
            // right part is sorted, so minimum is on left side or at mid.
            else if (nums[mid] < nums[high])
                high = mid;

            // If mid element is greater than high element,
            // left part is sorted, so minimum is on the right side. So go to right side.
            else if (nums[mid] > nums[high])
                low = mid + 1;
        }

        // low == high → index of minimum element.
        return high;  // returning low or high both work.
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Rotated Sorted Array (with duplicates)


*/
