/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
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
        int ans = INT_MAX;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= nums[high])
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }

            else if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
        }
        return ans;
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

| Complexity | Value                              |
| ---------- | ---------------------------------- |
| **Time**   | **O(log n)** (binary search)       |
| **Space**  | **O(1)** (no extra data structure) |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Find the minimum element in a rotated sorted array (no duplicates).

🧠 Key Insight:

In a rotated sorted array, at least one half (left or right) is always sorted.

Example:
[4,5,6,7,0,1,2]
Right half [0,1,2] is sorted.
🞂 Binary Search Logic
We compare:
nums[mid]  vs  nums[high]
✔ Case 1: nums[mid] <= nums[high]
This means:
The right half is sorted
So the minimum could be:
nums[mid]
or somewhere on the left side
Example: [4,5,6 | 1,2,3]
Since right half is sorted, mid might be the minimum—so store it:
ans = nums[mid]

Then move search to the left:
high = mid - 1
✔ Case 2: nums[mid] > nums[high]
This means:
The minimum is not in the sorted right half
It must be in the unsorted right portion
Example: [6,7,1 | 2,3,4]
So move search right:
low = mid + 1
🧵 Loop until low > high
Each time, we eliminate half the array.



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

        int ans = INT_MAX; // will store minimum

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // the min will surely in the right half. First ele of right half.
            // If right half is sorted, Then the store the current mid because that can be answer. But we dont know whether that is the '
            // start of right half or somewhere in between right half. So we again move towards left, aspiring that we have to go
            // to the left side of the right half.
            if (nums[mid] <= nums[high])
            {
                ans = min(ans, nums[mid]);  // update answer
                high = mid - 1;    // shrink search towards left
            }
            //if right half is not sorted then go to right side and look for right half.
            else // nums[mid] > nums[high], minimum is in right half
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Binary Search on Answer



*/
