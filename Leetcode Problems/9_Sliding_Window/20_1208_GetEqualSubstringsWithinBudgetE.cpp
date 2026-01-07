/*
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.



Example 1:

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
Example 2:

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
Example 3:

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.

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
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int m = t.length();

        int maxLen = 0;

        int left = 0;
        int right = 0;
        int cost = 0;

        while (right < n)
        {
            cost += abs(s[right] - t[right]);

            while (cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }
        return maxLen;
    }
};
int main()
{
    Solution sol;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    cout << sol.equalSubstring(s, t, maxCost);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity → O(n)

Each index is visited at most twice
(once by right, once by left in worst case)

Space Complexity → O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We want the longest substring where:

sum(abs(s[i] - t[i])) <= maxCost


So we use a sliding window:

Expand right pointer (grow window)

Add the cost of converting s[right] → t[right]

If cost becomes larger than maxCost,
→ shrink window from the left until cost becomes valid again

Track the maximum valid window size

This ensures we always maintain the longest possible valid substring.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();

        int maxLen = 0;      // store longest valid substring length
        int left = 0;        // window start
        int right = 0;       // window end
        int cost = 0;        // current window cost

        // expand window by moving 'right'
        while (right < n)
        {
            // add cost of converting s[right] to t[right]
            cost += abs(s[right] - t[right]);

            // if cost is too high, shrink from left
            while (cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);  // remove left character's cost
                left++;                          // move window forward
            }

            // now cost <= maxCost, update answer
            maxLen = max(maxLen, right - left + 1);
            
            right++;  // expand window
        }

        return maxLen;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window (Two-Pointers Technique)
More specifically:
Variable-size sliding window

Because we expand and shrink window based on the condition.


*/
