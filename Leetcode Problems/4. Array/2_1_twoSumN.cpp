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
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
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

Time complexity: 
O(n^2)
Space complexity: 
O(1) extra (ignoring the output).

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


The brute-force method simply tries all possible pairs (i, j) to check if their sum equals the target.
As soon as a valid pair is found, return their indices.

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
        // Outer loop picks the first element
        for (int i = 0; i < nums.size(); i++)
        {
            // Inner loop picks the second element (after i)
            for (int j = i + 1; j < nums.size(); j++)
            {
                // Check if the current pair sums up to the target
                if (nums[i] + nums[j] == target)
                    // Return indices as soon as the pair is found
                    return {i, j};
            }
        }

        // Return empty vector if no pair is found
        // (though problem guarantees one solution)
        return {};
    }
};


*/
