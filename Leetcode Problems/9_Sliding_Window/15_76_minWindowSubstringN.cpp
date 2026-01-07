/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

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
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        int startOfWin = 0;
        int minWinLen = INT_MAX;

        if (m > n)
            return "";

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> ump;

            for (auto c : t)
                ump[c]++;

            for (int j = i; j < n; j++)
            {
                if (ump.count(s[j]))
                {
                    ump[s[j]]--;
                    if (ump[s[j]] == 0)
                        ump.erase(s[j]);
                }
                if (ump.size() == 0)
                {
                    if ((j - i + 1) < minWinLen)
                    {
                        minWinLen = j - i + 1;
                        startOfWin = i;
                    }
                    break;
                }
            }
        }

        return minWinLen == INT_MAX ? "" : s.substr(startOfWin, minWinLen);
    }
};

int main()
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n² + n·|t|)

Which is essentially O(n²).
Explanation:
Outer loop runs n times
For each start index i, you:
Build a frequency map → O(|t|)
Inner loop runs up to n times → O(n)
Total = n × (n + |t|) = O(n²)
This brute-force solution will TLE on LeetCode 76.

Space Complexity: O(|t|)
Because of the frequency map storing at most all characters of t.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Your brute-force algorithm works like this:
For every possible starting index i in string s:
Reconstruct the frequency map of all characters needed from t.
Expand the end index j from i to the end of s:
If the current character s[j] is needed, decrement its count from the map.
If a character’s count becomes zero, remove it from the map.
When the map becomes empty:
We found a valid window s[i..j] containing all characters of t.
Update minimum window length if this one is smaller.
Break (because extending j only increases window size).
Return the smallest window found


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        int startOfWin = 0;          // stores best window's start index
        int minWinLen = INT_MAX;     // stores best window's length

        if (m > n)                   // if t is longer than s, impossible
            return "";

        // Try every possible starting index i
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> ump;  // fresh map for characters needed from t

            // Build frequency map of string t
            for (auto c : t)
                ump[c]++;

            // Expand window from i to j
            for (int j = i; j < n; j++)
            {
                // If current character is needed
                if (ump.count(s[j]))
                {
                    ump[s[j]]--;         // reduce required count
                    if (ump[s[j]] == 0)  // if fully satisfied
                        ump.erase(s[j]); // remove from map
                }

                // When all characters are found
                if (ump.size() == 0)
                {
                    // update minimum window
                    if ((j - i + 1) < minWinLen)
                    {
                        minWinLen = j - i + 1;
                        startOfWin = i;
                    }

                    break; // break because longer window is unnecessary
                }
            }
        }

        // return best window or empty string
        return minWinLen == INT_MAX ? "" : s.substr(startOfWin, minWinLen);
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Sliding Window (Two Pointers) Brute force

*/
