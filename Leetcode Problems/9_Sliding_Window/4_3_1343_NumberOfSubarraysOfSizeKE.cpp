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

        int windowSum = 0;
        int count = 0;

        for (int i = 0; i < k; i++)
            windowSum += nums[i];
        if ((windowSum / k) >= threshold)
            count++;

        int left = 0;
        int right = k;

        while (right < n)
        {
            windowSum -= nums[left];
            windowSum += nums[right];

            if ((windowSum / k) >= threshold)
                count++;

            left++;
            right++;
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

if correct , please give me approach of code, comment my code, then say time and space and then tell which pattern is used to solve problem.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Compute the sum of the first window of k elements.
Check if the average ≥ threshold → increment count.
Slide the window:
Remove nums[left]
Add nums[right]
Check the new window average.
Move left and right until the end of the array.

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

        int windowSum = 0;
        int count = 0;

        // Build the first window of size k
        for (int i = 0; i < k; i++)
            windowSum += nums[i];

        // Check the first window
        if ((windowSum / k) >= threshold)
            count++;

        int left = 0;
        int right = k;

        // Slide the window across the array
        while (right < n)
        {
            windowSum -= nums[left];   // remove left element
            windowSum += nums[right];  // add new right element

            // Check average of current window
            if ((windowSum / k) >= threshold)
                count++;

            left++;
            right++;
        }

        return count;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
Each element is added once and removed once.
Space Complexity: O(1)
Uses constant extra space.


*/
