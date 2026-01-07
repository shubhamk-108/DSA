/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
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

// Bruteforce
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int firstOccurance = -1;
        int lastOccurance = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (firstOccurance == -1)
                {
                    firstOccurance = i;
                }
                lastOccurance = i;
            }
        }

        return {firstOccurance, lastOccurance};
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5, 7, 7, 8, 8, 10};
    vector<int> res = sol.searchRange(v, 8);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n) — single pass through the array.
Space Complexity
O(1) — constant extra space.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the array once.
When you find the first match, record it in firstOccurance.
Keep updating lastOccurance whenever you encounter another match.
Return both indices; if no match is found, both stay -1.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int firstOccurance = -1;
        int lastOccurance = -1;

        // 🔹 Linear scan of the array
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                // If firstOccurance not yet set, this is the first match
                if (firstOccurance == -1)
                    firstOccurance = i;

                // Keep updating lastOccurance for every match
                lastOccurance = i;
            }
        }

        return {firstOccurance, lastOccurance};
    }
};



*/
