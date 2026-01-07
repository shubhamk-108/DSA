/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

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
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (n < m)
            return {};

        vector<int> res;
        vector<int> freqP(26, 0), freqS(26, 0);

        for (char c : p)
            freqP[c - 'a']++;

        for (int i = 0; i < n; i++)
        {
            freqS[s[i] - 'a']++;
            if (i >= m)
                freqS[s[i - m] - 'a']--; // remove leftmost char
            if (freqS == freqP)
                res.push_back(i - m + 1);
        }
        return res;
    }
};


int main()
{
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> ans = sol.findAnagrams(s, p);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Building freqP: O(m)
Sliding window over s: O(n)
Each comparison freqS == freqP takes O(26) = O(1) (constant, since alphabet size fixed)
👉 Total: O(n + m) ≈ O(n)
💾 Space Complexity
freqP and freqS → 26 each → O(1) (constant space)
res output vector → at most O(n) (for indices)
👉 Overall Space: O(1) auxiliary (excluding output)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Approach: Sliding Window + Frequency Counting
We want to find all start indices of p's anagrams in s.
Two strings are anagrams if they contain the same characters with the same frequencies.
Maintain two frequency arrays of size 26 (for lowercase letters):
freqP → frequency of characters in p
freqS → frequency of current window of s
Use a sliding window of size m (length of p) to move across s:
Add the current character to the window’s frequency (freqS[s[i]-'a']++)
If window size exceeds m, remove the leftmost character (freqS[s[i-m]-'a']--)
After updating, if both frequency arrays match (freqS == freqP),
the current window is an anagram — store its start index (i - m + 1).
Return all starting indices in a vector.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (n < m)
            return {}; // if s is shorter than p, no anagrams possible

        vector<int> res;               // stores result indices
        vector<int> freqP(26, 0);      // frequency of chars in p
        vector<int> freqS(26, 0);      // frequency of chars in current window of s

        // Build frequency count for pattern p
        for (char c : p)
            freqP[c - 'a']++;

        // Slide window over string s
        for (int i = 0; i < n; i++)
        {
            freqS[s[i] - 'a']++; // include current char in window

            // If window size > m, remove leftmost char
            if (i >= m)
                freqS[s[i - m] - 'a']--;

            // Compare frequency arrays — if equal, we found an anagram
            if (freqS == freqP)
                res.push_back(i - m + 1);
        }

        return res;
    }
};



*/

