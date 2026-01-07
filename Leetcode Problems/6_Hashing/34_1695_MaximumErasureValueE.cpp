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
        unordered_set<int> uset;
        int score = 0;
        int maxScore = 0;

        int j = 0;
        int i = 0;
        while (i < n)
        {
            if (!uset.count(nums[i]))
            {
                score += nums[i];
                maxScore = max(maxScore, score);
                uset.insert(nums[i]);
                i++;
            }
            else
            {
                while (j < n && nums[j] != nums[i])
                {
                    score -= nums[j];
                    uset.erase(nums[j]);
                    j++;
                }
                score -= nums[j];
                uset.erase(nums[j]);
                j++;
            }
        }
        return maxScore;
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

Time: O(n) — each element is visited at max twice

Space: O(n) — for the set
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
You used Sliding Window + Hash Set:
Pointer i expands the window.
If nums[i] is not present → add it, update score, update max.
If it's a duplicate → move j forward, removing elements until the duplicate is cleared.
Maintain a running sum of the current unique window.



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
        unordered_set<int> uset;  // stores elements currently in the sliding window
        int score = 0;            // running sum of the current window
        int maxScore = 0;         // maximum sum of any unique-element window

        int j = 0;  // left pointer of sliding window
        int i = 0;  // right pointer of sliding window

        while (i < n)
        {
            // If nums[i] is NOT in the current window, we can safely expand the window
            if (!uset.count(nums[i]))
            {
                score += nums[i];                 // include this element in window sum
                maxScore = max(maxScore, score);  // update the maximum score seen so far
                uset.insert(nums[i]);             // add it to the set of unique elements
                i++;                              // expand window to the right
            }
            else
            {
                // Duplicate found → shrink window from the left
                // Remove elements until nums[i] becomes unique
                while (j < n &&nums[j] != nums[i])
                {
                    score -= nums[j];     // subtract value of element removed
                    uset.erase(nums[j]);  // remove from set
                    j++;                  // move left pointer forward
                }
                score -= nums[j];
                uset.erase(nums[j]);
                j++;
            }
        }

        return maxScore;  // final maximum erasure value
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window + Hashing
This is the standard LeetCode pattern for:
LC 3 – Longest Substring Without Repeating Character
LC 1695 – Maximum Erasure Value


*/
