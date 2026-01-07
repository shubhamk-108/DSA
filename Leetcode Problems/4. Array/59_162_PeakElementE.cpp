/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks,
return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than
a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

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
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1])
                low = mid + 1;

            else if (nums[mid] > nums[mid + 1])
                high = mid;

        }
        return low; // or high both are same.

    }
};
int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 1};
    cout << sol.findPeakElement(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

check if correct and this time add extra info to comments like why low = mid + 1; but high is only mid and not mid - 1. and why returning low or high , how does it guarantee that high and low will give pick
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Why binary search if the array is not sorted
//___________________________________________________________________________________________________________________________________________

/*

Pick the middle index mid.
Compare nums[mid] and nums[mid + 1].

Case 1: nums[mid] < nums[mid + 1]
The slope is increasing.
That means we are on the left side of a mountain.
A peak must exist on the right half (because eventually it must fall).
👉 So we move left = mid + 1.

Case 2: nums[mid] > nums[mid + 1]
The slope is decreasing.
That means we are on the right side of a mountain (or at the top).
A peak must exist on the left half, including mid.
👉 So we move right = mid.


The element we have to find is the peak. Means imagine live mountain increasing slope and then decreasing slope.
So when we find mid in the binary search and if the mid element is smaller than mid+1 index element then we are assuming that
the number are in increasing mountain format and the greater number as a pick we want that must be in the right side because
the array will show mountail like tendency due to there is a pick element. So we assume this. That is why we shift our mid to the right
in such situation.
And if the mid element is greater than mid - 1 element then the increasing number tendency is being shown on the left side of mid so
we will check on the left side and this is also the assumption.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
