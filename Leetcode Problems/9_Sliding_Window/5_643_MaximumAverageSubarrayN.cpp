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

        int count = 0;

        for (int i = 0; i <= n - k; i++)
        {
            int windowSum = 0;
            for (int j = i; j < i + k; j++)
            {
                windowSum += nums[j];
            }
            avg = max(avg, (double)windowSum * 1.0 / k);
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
O(n × k)
Outer loop runs (n − k + 1) times
Inner loop runs k times
Worst case: n = 100,000, k = 50,000 → extremely slow.
✅ Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Loop i from 0 to n - k
For each starting index i, compute the sum of the next k elements
Compute the average of this window
Track the maximum average seen so far
This is correct but slow: each window sum takes O(k) and there are (n − k + 1) windows.

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
        double avg = -1e18;  // Initialize with very small value

        // Loop over all possible starting positions of windows of size k
        for (int i = 0; i <= n - k; i++)
        {
            int windowSum = 0;  // Sum of current window

            // Compute sum of subarray nums[i ... i+k-1]
            for (int j = i; j < i + k; j++)
            {
                windowSum += nums[j];
            }

            // Update max average
            avg = max(avg, windowSum * 1.0 / k);
        }

        return avg;  // Return maximum average found
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


✔ Brute Force / Nested Loop Pattern

*/
