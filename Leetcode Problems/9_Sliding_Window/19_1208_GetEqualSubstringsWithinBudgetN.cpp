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

        for (int i = 0; i < n; i++)
        {
            int cost = 0;
            for (int j = i; j < n; j++)
            {
                cost += abs(s[j] - t[j]);
                if (cost <= maxCost)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};


int main()
{
    Solution sol;
    string s = "abcd";
    string t = "bcde";
    int maxCost = 3;
    cout << sol.equalSubstring(s, t, maxCost);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ Time Complexity: O(n²)
Outer loop runs n times
Inner loop runs up to n times
Worst case → n + (n-1) + (n-2) + … + 1 = O(n²)
🧠 Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For each starting index i:
Initialize cost = 0.
Expand the substring by moving j from i to the end.
For each extension, add the cost:
abs(s[j] - t[j])
If total cost ≤ maxCost, update the maximum length.
If total cost becomes > maxCost, break because extending further will only increase cost


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
        int maxLen = 0;

        // Try every possible starting index
        for (int i = 0; i < n; i++)
        {
            int cost = 0;  // cost of converting s[i..j] -> t[i..j]

            // Expand substring from j = i to end
            for (int j = i; j < n; j++)
            {
                // Add cost for the new character
                cost += abs(s[j] - t[j]);

                // If total cost is within allowed limit, update maxLen
                if (cost <= maxCost)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;  // No point expanding further; cost only increases
            }
        }

        return maxLen;  // longest valid substring length
    }
};





*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force (Nested Loops) sliding window

*/
