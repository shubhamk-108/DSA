/*
1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or
equal to threshold.

Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less
than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.

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
    int numOfSubarrays(vector<int> &nums, int k, int threshold)
    {
        int n = nums.size();

        int count = 0;

        for (int i = 0; i <= n - k; i++)
        {
            int windowSum = 0;
            for (int j = i; j < i + k; j++)
            {
                windowSum += nums[j];
            }
            if ((windowSum / k) >= threshold)
                count++;
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;
    cout << sol.numOfSubarrays(v, k, threshold);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n × k)
Outer loop runs n - k + 1 times
Inner loop runs k times
Total is O(nk) (much slower than sliding window)
Space Complexity: O(1)
Uses only a few variables

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For each possible starting index i (from 0 to n - k):
Compute the sum of the subarray from i to i + k - 1.
After computing the sum of that window:
Check if windowSum / k ≥ threshold.
Increase count if true.
Repeat for all windows.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int numOfSubarrays(vector<int> &nums, int k, int threshold)
    {
        int n = nums.size();
        int count = 0;

        // Try every possible starting index for a window of size k
        for (int i = 0; i <= n - k; i++)
        {
            int windowSum = 0;

            // Compute sum of subarray nums[i ... i + k - 1]
            for (int j = i; j < i + k; j++)
            {
                windowSum += nums[j];
            }

            // Check whether average >= threshold
            if ((windowSum / k) >= threshold)
                count++;
        }

        return count;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Brute Force / Nested Loops

*/
