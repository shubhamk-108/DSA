/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by
erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r]
for some (l,r).



Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

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
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> uset;
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                if (uset.count(nums[j]))
                    break;
                sum += nums[j];
                res = max(res, sum);
                uset.insert(nums[j]);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << sol.maximumUniqueSubarray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n²)

Worst case:
For each i, inner loop runs nearly n times → n + (n−1) + ... + 1 = O(n²).

Space: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

You try every possible starting index i.
For each i, you grow a subarray to the right (j = i … n-1) until you hit a duplicate.
While extending, you maintain:

a unordered_set to check if an element is already used

a running sum of the current unique-subarray

update res with the maximum sum found

This is the direct, simple brute-force way:
Generate all unique-element subarrays and track the maximum sum.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int res = 0;               // stores maximum score across all valid subarrays

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> uset;   // tracks which elements already occurred in current subarray
            int sum = 0;               // running sum of the current unique-element subarray

            for (int j = i; j < n; j++)
            {
                if (uset.count(nums[j]))   // if current element already seen, uniqueness breaks
                    break;                 // stop extending this subarray

                sum += nums[j];            // include current element into running sum
                res = max(res, sum);       // update the global maximum sum
                uset.insert(nums[j]);      // mark element as used in this subarray
            }
        }

        return res;                         // return maximum unique-subarray score
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Brute Force (Nested Loops) + Set for Uniqueness


*/
