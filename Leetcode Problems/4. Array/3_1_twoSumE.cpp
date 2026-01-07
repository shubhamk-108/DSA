/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++)
        {
            int first_ele_of_pair = nums[i];
            int second_ele_of_pair;

            if (um.find(target - first_ele_of_pair) != um.end())
            {
                second_ele_of_pair = target - first_ele_of_pair;
                return {um[second_ele_of_pair], i};
            }
            else
            {
                um[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 4, 8, 2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    for (auto x : res)
        cout << x << " ";

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n)
Space: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal: Find two indices i and j such that nums[i] + nums[j] == target.
Idea:
Instead of checking every pair (which is O(n²)), use a hash map (unordered_map) to remember which numbers you’ve already seen and their indices.
Process:
Iterate through the array once.
For each number nums[i], calculate the number you need to reach the target:
complement = target - nums[i].
Check if that complement already exists in the map.
✅ If yes → You’ve found a pair → return both indices.
❌ If no → Store the current number and its index in the map for future lookups.
This way, every lookup is O(1) on average, and you only go through the array once.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Hash map to store value -> index mapping
        unordered_map<int, int> um;

        // Traverse the array once
        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];             // current element
            int complement = target - current; // the number we need to find

            // Check if the complement already exists in the map
            if (um.find(complement) != um.end())
            {
                // Found the pair: return their indices
                // um[complement] gives index of the earlier element
                return {um[complement], i};
            }

            // Otherwise, store the current number with its index
            um[current] = i;
        }

        // Return empty vector if no pair found (won’t happen per problem statement)
        return {};
    }
};


*/
