/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] +
nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        auto n = nums.size();
        if (n < 3)
            return {};

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = sol.threeSum(v);
    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Sorting: O(n log n)

Two-pointer traversal for each i: O(n²)
Total = O(n²)  (Optimal for 3Sum)

Space Complexity

O(1) (excluding result storage) 
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort the array to use the two-pointer technique efficiently.
Iterate through each element i as the fixed value.
Use two pointers:
left = i + 1
right = n - 1
to find pairs such that nums[i] + nums[left] + nums[right] == 0.
If the sum is less than 0 → move left++ (increase sum).
If the sum is greater than 0 → move right-- (decrease sum).
When a valid triplet is found, push it to res and skip all duplicates for both left and right.
Continue until all unique triplets are found.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


sort(nums.begin(), nums.end()); // Step 1: Sort the array
for (int i = 0; i < n - 2; i++) 
{
    if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate fixed elements

    int left = i + 1, right = n - 1;
    while (left < right) 
    {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) 
        {
            res.push_back({nums[i], nums[left], nums[right]});

            // Skip duplicates for left and right
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;

            left++; right--; // Move both pointers inward
        } 
        else if (sum < 0) left++;
        else right--;
    }
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer Technique
Applied on a sorted array to reduce 3Sum → multiple 2Sum subproblems.


*/
