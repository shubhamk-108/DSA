/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you
may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        vector<int> res1;

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    res.push_back(nums1[i]);
                    break;
                }
            }
        }

        sort(res.begin(), res.end());

        if (!res.empty())
            res1.push_back(res[0]);

        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] != res[i - 1])
                res1.push_back(res[i]);
        }
        return res1;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    vector<int> res = sol.intersection(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity

Nested loops: O(n1 × n2)
Sort res: O(k log k), where k ≤ min(n1, n2)
Remove duplicates: O(k)
Total: O(n1 × n2 + k log k) ≈ O(n1 × n2) (dominant term)

Space Complexity
res stores all matches → O(min(n1, n2)) in worst case
res1 stores unique results → O(min(n1, n2))
Total: O(min(n1, n2)) extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Loop through each element of nums1.
For each element, loop through all elements of nums2.
If a match is found, add it to a temporary result vector res and break (to avoid counting duplicates in the second array).
After collecting all matches (may have duplicates), sort res
Build a final result vector res1 that stores unique elements only by skipping consecutive duplicates.
✅ Works for any input arrays (sorted or unsorted)

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> res;   // store all matches (may contain duplicates)
    vector<int> res1;  // final result with unique elements

    // Brute-force check for each element of nums1 in nums2
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (i == j)      // ❌ unnecessary: i and j are indices of different arrays
                continue;

            if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);  // store the match
                break;                    // avoid duplicate matches in nums2
            }
        }
    }

    // Sort to remove duplicates
    sort(res.begin(), res.end());

    // Add the first element if it exists
    if (!res.empty())
        res1.push_back(res[0]);

    // Add remaining elements if they are different from previous
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] != res[i - 1])
            res1.push_back(res[i]);
    }

    return res1;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force / Nested Loops
Sorting + Duplicate Removal

*/
