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

        int overallMaxSoFar = nums[0];
        int leftMax = nums[0];

        int partitionIdx = 0;
        for (int i = 1; i < n; i++)
        {
            overallMaxSoFar = max(overallMaxSoFar, nums[i]);

            if (nums[i] < leftMax)
            {
                partitionIdx = i ;
                leftMax = overallMaxSoFar;
            }
        }
        return partitionIdx + 1;
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
time  : O(n)
space  : O (1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We need to split the array into two parts — left and right — such that:
Every element in left ≤ every element in right, and
left has the smallest possible length.
To achieve this efficiently:
Maintain two variables:
overallMaxSoFar → the maximum element seen so far (for all indices till now).
leftMax → the maximum element in the current left partition.
Iterate through the array:
Always update overallMaxSoFar = max(overallMaxSoFar, nums[i]).
If you ever find nums[i] < leftMax, it means this element cannot belong to the right partition — the current partition boundary is invalid.
So, extend the left partition boundary to include this element:
partitionIdx = i + 1;
leftMax = overallMaxSoFar;
Return partitionIdx — which marks the length of the left partition.


*/

//___________________________________________________________________________________________________________________________________________
// code explanation
//___________________________________________________________________________________________________________________________________________

/*

if (nums[i] < leftMax) when this condn is true we do partitionIdx = i and also update leftMax . so are we assuming that we are having 
smaller element here so the right side or partition is from the next index and since we assume the partition is from next index, so in 
case if we dont get the partition then we need leftMax to check further element, so we also store leftMax in the same if loop or condn.

And when we get larget element than leftMax then we simply do nothing because we have already stored the partiton index when we
got smaller element.


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

        int overallMaxSoFar = nums[0];  // global maximum till current index
        int leftMax = nums[0];           // maximum in the current left partition
        int partitionIdx = 0;            // current boundary between left and right

        for (int i = 1; i < n; i++)
        {
            // Update global maximum
            overallMaxSoFar = max(overallMaxSoFar, nums[i]);

            // If current element is smaller than leftMax,
            // it can't be part of the right partition
            if (nums[i] < leftMax)
            {
                // Extend the left partition boundary
                partitionIdx = i;

                // Update leftMax to include all elements seen so far
                leftMax = overallMaxSoFar;
            }
        }

        return partitionIdx + 1; // length of the left partition
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy + Prefix Maximum Tracking
The algorithm greedily extends the left partition whenever it finds an element violating the partition condition.
It maintains running prefix maximums to make this decision in constant time.


*/
