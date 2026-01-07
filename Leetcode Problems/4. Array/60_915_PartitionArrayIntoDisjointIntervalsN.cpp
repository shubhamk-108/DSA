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
        for (int i = 0; i < n - 1; i++)
        {
            int leftMax = INT_MIN;
            for (int j = 0; j <= i; j++)
            {
                leftMax = max(nums[j], leftMax);
            }

            int rightMin = INT_MAX;
            for (int j = i + 1; j <n; j++)
            {
                rightMin = min(nums[j], rightMin);
            }

            if (leftMax <= rightMin)
                return i + 1;
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

time : O(n^2)
space : O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Compute the maximum value in the left part nums[0...i].
Compute the minimum value in the right part nums[i+1...n-1].
If max(left) ≤ min(right), then i + 1 can be a valid partition length.
Return the smallest such i + 1.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

using namespace std;

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            // Find max on the left side (0 to i)
            int leftMax = INT_MIN;
            for (int j = 0; j <= i; j++)
                leftMax = max(leftMax, nums[j]);

            // Find min on the right side (i+1 to n-1)
            int rightMin = INT_MAX;
            for (int j = i + 1; j < n; j++)
                rightMin = min(rightMin, nums[j]);

            // Check if valid partition
            if (leftMax <= rightMin)
                return i + 1; // partition index (length of left)
        }

        return n; // fallback, though problem guarantees a valid answer
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


This brute approach uses Exhaustive Search + Range Comparison.

*/
