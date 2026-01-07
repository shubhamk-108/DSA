/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        int diff = INT_MAX;

        for (int i = 0; i <= n - 3; i++)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int currSum = nums[i] + nums[left] + nums[right];
                if (abs(target - currSum) < diff)
                {
                    diff = abs(target - currSum);
                    sum = currSum;
                }
                if (currSum < target)
                    left++;
                else if (currSum > target)
                    right--;
                else
                    return target;
            }
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {-1, 2, 1, -4};
    cout << sol.threeSumClosest(v, 1);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²)
Sorting → O(n log n)
Outer loop → O(n)
Inner two-pointer loop → O(n)
Total: O(n²) (dominant)

Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Approach: Two-Pointer after Sorting
Sort the array
Sorting allows us to use the two-pointer technique efficiently.
Fix one element at a time (i from 0 to n-3)
For each i, we want to find two other elements that together with nums[i] form a sum closest to the target.
Use two pointers:
left = i + 1
right = n - 1
Calculate current sum:
currSum = nums[i] + nums[left] + nums[right]
Update the closest sum if needed:
If the absolute difference between currSum and target is smaller than previous best, update.
Move pointers:
If currSum < target → move left++ to increase sum
If currSum > target → move right-- to decrease sum
If currSum == target → exact match, return immediately
Continue this until all triplets are checked.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        
        // Initialize sum with the first triplet and diff with its distance from target
        int sum = nums[0] + nums[1] + nums[2];
        int diff = abs(sum - target);

        // Step 2: Fix one element and apply two-pointer technique
        for (int i = 0; i <= n - 3; i++)
        {
            int left = i + 1;  // Left pointer
            int right = n - 1; // Right pointer

            // Step 3: Move pointers and check all combinations
            while (left < right)
            {
                int currSum = nums[i] + nums[left] + nums[right];

                // Step 4: Update best sum if closer to target
                if (abs(currSum - target) < diff)
                {
                    diff = abs(currSum - target);
                    sum = currSum;
                }

                // Step 5: Move pointers based on how currSum compares to target
                if (currSum < target)
                    left++;   // Need a bigger sum
                else if (currSum > target)
                    right--;  // Need a smaller sum
                else
                    return target; // Perfect match found
            }
        }
        return sum; // Return the closest sum found
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Two Pointers (after sorting)
This is a classic Sorting + Two Pointer pattern, very common for:
3Sum
3Sum Closest
2Sum in sorted array
Pair sum problems
Triplets and combinations with closeness conditions

*/
