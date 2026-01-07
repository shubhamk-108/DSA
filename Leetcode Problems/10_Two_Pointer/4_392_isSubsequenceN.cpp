/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

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
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            bool found = false;
            while (j < m)
            {
                if (s[i] == t[j])
                {
                    count++;
                    j++;
                    found = true;
                    break;
                }
                j++;
            }
            if(!found)
                return false;
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
Time Complexity
O(n × m)
n = s.length(
m = t.length()
Worst case: for each character in s, you may scan almost all remaining characters in t.

💾 Space Complexity

O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Iterate over each character s[i] in the subsequence string s.
For each s[i], scan t starting from the last matched position j.
If s[i] == t[j], mark found = true, increment count, and move j to the next character.
If no match is found for a character → immediately return false.
After scanning all characters, if count == n → all characters were matched in order → return true.

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
        int n = s.length();  // length of subsequence string
        int m = t.length();  // length of main string
        int count = 0;       // number of matched characters
        int j = 0;           // pointer for scanning t

        // iterate over each character of s
        for (int i = 0; i < n; i++)
        {
            bool found = false;  // flag to check if s[i] is found in t

            // scan t starting from last matched index j
            while (j < m)
            {
                if (s[i] == t[j])  // match found
                {
                    count++;       // increment matched count
                    j++;           // move j forward for next search
                    found = true;  // mark as found
                    break;         // break inner loop, go to next character of s
                }
                j++;  // continue scanning t
            }

            if(!found)  // s[i] not found in t after last matched index
                return false;
        }

        return count == n;  // all characters of s matched in order
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-force / Nested Loop / Subsequence Checking


*/
