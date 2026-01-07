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
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        res.push_back(triplet);
                    }
                }
            }
        }

        sort(res.begin(), res.end());

        auto it = unique(res.begin(), res.end());

        res.erase(it, res.end());

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

Time Complexity:
Generating triplets → O(n³)
Sorting each triplet (3 log 3 ≈ constant) → O(n³)

Sorting + unique on results → O(m log m) (m = # triplets)
→ Overall ≈ O(n³) — pure brute-force.
Space Complexity: O(m) for storing triplets.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Iterate over all possible triplets (i, j, k) where i < j < k.
For each triplet, if the sum is 0, store it.
Sort each triplet so {−1, 0, 1} and {0, −1, 1} are treated the same.
Sort the full list of triplets (res) lexicographically.
Use unique + erase to remove duplicate triplets.
Return the resulting list.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;

        // Try every combination of three distinct indices
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // If sum is zero, record the triplet
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end()); // normalize order
                        res.push_back(triplet);
                    }
                }
            }
        }

        // Sort all triplets lexicographically
        sort(res.begin(), res.end());

        // Remove duplicate triplets
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-Force Enumeration of Triplets
(also known as triple nested-loop or combinatorial search)


*/
