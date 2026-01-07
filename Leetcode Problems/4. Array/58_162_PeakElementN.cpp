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

        if (n == 1) return 0;
        else if (n == 2) return nums[0] > nums[1] ? 0 : 1;
        else if (nums[0] > nums[1]) return 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }

        if (nums[n - 1] > nums[n - 2])
            return n - 1;
        
        return -1; // to avoid warning. there is at least one peak
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

Time: O(n)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Handle small-size arrays (n = 1, n = 2) directly.
Check if the first element is greater than its right neighbor — it’s a peak.
Loop through the array and find the first element that’s greater than both neighbors.
If none found in the middle, check if the last element is a peak.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        // Case 1: Only one element → it’s trivially a peak
        if (n == 1)
            return 0;

        // Case 2: Two elements → whichever is larger is the peak
        else if (n == 2)
            return nums[0] > nums[1] ? 0 : 1;

        // Case 3: First element greater than second → first is a peak
        else if (nums[0] > nums[1])
            return 0;

        // Case 4: Check all middle elements (1 to n-2)
        // A peak occurs when the current element is greater than both neighbors
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i; // return the first peak found
        }

        // Case 5: Last element greater than second last → last is a peak
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        // Theoretically unreachable (problem guarantees at least one peak)
        return -1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


bruteforce checking every combination

*/
