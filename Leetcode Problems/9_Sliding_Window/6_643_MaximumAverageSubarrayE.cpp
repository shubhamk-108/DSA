/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted
Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

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
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        int windowSum = 0;
        double avg = -1e18;

        for (int i = 0; i < k; i++)
            windowSum += nums[i];

        avg = max(avg, (double)windowSum * 1.0 /k);

        int left = 0;
        int right = k;

        while (right < n)
        {
            windowSum -= nums[left];
            windowSum += nums[right];

            avg = max(avg, (double)windowSum * 1.0 /k);

            left++;
            right++;
        }

        return avg;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 12, -5, -6, 50, 3};
    cout << sol.findMaxAverage(v, 4);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time:
O(n)
You:
Compute the first window in O(k)
Slide the window across the remaining elements in O(n − k)
Total = O(n).
Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Compute the sum of the first k elements (first window).
Slide the window by:
Subtracting the element going out (nums[left])
Adding the new element coming in (nums[right])
After each slide, compute the average of the current window.
Keep track of the maximum average.
This avoids recomputing sums from scratch and reduces time from O(n·k) to O(n).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        int windowSum = 0;

        // Initialize max average to a very small number
        double avg = -1e18;

        // Step 1: Compute sum of the first window (size k)
        for (int i = 0; i < k; i++)
            windowSum += nums[i];

        // Calculate average of first window
        avg = max(avg, windowSum * 1.0 / k);

        int left = 0;
        int right = k;

        // Step 2: Slide the window across the array
        while (right < n)
        {
            // Remove element going out of the window
            windowSum -= nums[left];

            // Add new element entering the window
            windowSum += nums[right];

            // Update maximum average
            avg = max(avg, windowSum * 1.0 / k);

            // Move both pointers forward
            left++;
            right++;
        }

        return avg; // Return maximum average found
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

⭐ Sliding Window Pattern (Fixed-Size Sliding Window)


*/
