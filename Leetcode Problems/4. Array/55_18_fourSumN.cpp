/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 4)
            return {};

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int p = k + 1; p < n; p++)
                    {
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[p] == target)
                        {
                            vector<int> a = {nums[i], nums[j], nums[k], nums[p]};
                            sort(a.begin(),a.end());
                            res.push_back(a);
                        }
                    }
                }
            }
        }
        sort(res.begin(), res.end());

        auto itToUniqueVectorsLastPair = unique(res.begin(), res.end());

        res.erase(itToUniqueVectorsLastPair, res.end());

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = sol.fourSum(v, 0);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric               | Complexity      | Explanation                                                                                                                        |
| -------------------- | --------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| **Time Complexity**  | **O(n⁴ log m)** | 4 nested loops (`O(n⁴)`) and sorting + deduplication adds a small overhead (`O(m log m)`, where `m` = number of valid quadruplets) |
| **Space Complexity** | **O(m)**        | Space required to store the resulting quadruplets (no extra data structures used)                                                  |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use four nested loops (i, j, k, p) to check all possible quadruplets in the array.
For each combination, compute their sum and compare with target.
If equal, store the quadruplet in the result vector res.
Sort the result and then call unique() to remove duplicate quadruplets.
Return the list of unique quadruplets that sum to the target.
This method exhaustively enumerates all combinations — hence the name Brute Force


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 4)
            return {};  // Early exit if fewer than 4 elements

        vector<vector<int>> res;

        // Try all possible combinations of four numbers
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int p = k + 1; p < n; p++)
                    {
                        // Use long long to prevent integer overflow
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[p] == target)
                            res.push_back({nums[i], nums[j], nums[k], nums[p]});
                    }
                }
            }
        }

        // Sort the quadruplets to make duplicates consecutive
        sort(res.begin(), res.end());

        // Remove duplicate quadruplets
        auto itToUniqueVectorsLastPair = unique(res.begin(), res.end());
        res.erase(itToUniqueVectorsLastPair, res.end());

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force Enumeration (Complete Search)

It directly explores every combination without optimization.

No sorting + two-pointer optimization, no hashing, no pruning.


*/
