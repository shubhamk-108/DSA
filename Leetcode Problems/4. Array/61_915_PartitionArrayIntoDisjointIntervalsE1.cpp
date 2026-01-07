/*
Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.



Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

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
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> soFarLeftMax(n);
        vector<int> soFarRightMin(n);

        // we can also calculate so far left max on the fly. We dont need any any extra space for storing soFarLeftMax
        soFarLeftMax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            soFarLeftMax[i] = max(soFarLeftMax[i - 1], nums[i]);
        }

        soFarRightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            soFarRightMin[i] = min(soFarRightMin[i+1], nums[i]);
        }

        for (int i = 1; i < n ; i++)
        {
            if (soFarLeftMax[i - 1] <= soFarRightMin[i])
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5, 0, 3, 8, 6};
    cout << sol.partitionDisjoint(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(N)
One pass for prefix max
One pass for suffix min
One pass to find partition
Space Complexity: O(N)
Two auxiliary arrays (soFarLeftMax, soFarRightMin)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Goal:
We need to split the array into two parts — left and right — such that
every element in left ≤ every element in right,
and left is as small as possible.

Idea:

For every index i, we must know:

the maximum element on the left up to i,

the minimum element on the right from i onward.

Once we have those two precomputed arrays,
we find the smallest i where
maxLeft[i - 1] <= minRight[i].

Steps:

Create a soFarLeftMax array where soFarLeftMax[i] = max(nums[0..i]).

Create a soFarRightMin array where soFarRightMin[i] = min(nums[i..n-1]).

Traverse the array once more:
For each index i, check if
soFarLeftMax[i - 1] <= soFarRightMin[i].
If yes, return i as the partition point.

This ensures both conditions hold and guarantees the smallest possible left partition.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        // soFarLeftMax[i] stores the maximum element from nums[0] to nums[i]
        vector<int> soFarLeftMax(n);
        // soFarRightMin[i] stores the minimum element from nums[i] to nums[n-1]
        vector<int> soFarRightMin(n);

        // Build prefix maximum array
        soFarLeftMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            soFarLeftMax[i] = max(soFarLeftMax[i - 1], nums[i]);

        // Build suffix minimum array
        soFarRightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            soFarRightMin[i] = min(soFarRightMin[i + 1], nums[i]);

        // Find the smallest index where leftMax <= rightMin
        for (int i = 1; i < n; i++)
        {
            if (soFarLeftMax[i - 1] <= soFarRightMin[i])
                return i;  // Partition point found
        }

        return -1; // Should not reach here (problem guarantees a solution)
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Prefix–Suffix Precomputation Pattern
(also known as the “Range Aggregate Preprocessing” pattern)
This pattern is used whenever you need
To compare or combine values from both left and right sides of each index.
Examples:
Trapping Rain Water
Product of Array Except Self
Partition Disjoint
Min/Max in Subarrays problems


*/
