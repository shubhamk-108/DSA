/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
 of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a
 subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
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
    bool isSubsequence(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        int i = 0;
        int j = 0;
        int count = 0;
        while (j < m && i < n)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
                count++;
            }
            else
                j++;
        }
        return count == n;
    }
};

int main()
{
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    cout << sol.isSubsequence(s, t);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(m)

You scan through string t once.
(m = t.length())

📦 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use two pointers:
i → points into s (the subsequence we want to match)
j → points into t (the larger string)
Scan through t from left to right:
If characters match → move both pointers forward.
If they don't match → move only j.
Count how many characters from s were matched in order.
If we matched all characters from s (count == n), then s is a subsequence of t.

This is a classic two-pointer subsequence matching technique.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.length();   // length of subsequence
        int m = t.length();   // length of main string

        int i = 0;  // pointer for s
        int j = 0;  // pointer for t
        int count = 0; // how many characters of s we have matched

        // Move through both strings while both pointers are valid
        while (j < m && i < n)
        {
            // If characters match, move both pointers
            if (s[i] == t[j])
            {
                i++;       // matched s[i]
                j++;       // move in t
                count++;   // increment number of matched characters
            }
            else
                j++;       // mismatch → move only in t
        }

        // If we matched all characters of s in order, it's a subsequence
        return count == n;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer Technique (Linear Scan)
One pointer walks through s
One pointer walks through t

Compare and advance based on matching


*/
