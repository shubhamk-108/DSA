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
private:
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        int n1 = s.length();
        int n2 = p.length();
        vector<int> res;

        for (int i = 0; i <= n1 - n2 ; i++)
        {
            if(isAnagram(s.substr(i,n2), p))
                res.push_back(i);
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

Combined complexity: roughly O((n - m) * m),
Overall: O(n*m) or O(n1* n2)

space complexity: 
O(n1) to store result vector.
isAnagram space is O(1) as we are working only for 26 letters.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Iterate through every substring of s that has the same length as p.
For each substring:
Check if it’s an anagram of p by comparing character frequencies.
If yes, store the starting index in the result array.
Return all starting indices


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

isAnagram is already explained in 6_242_validAnagramE.cpp in the same folder.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to check if two strings are anagrams
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        // If lengths differ, cannot be anagrams
        if (s.length() != t.length())
            return false;

        int freq[26] = {0}; // Frequency array for lowercase letters

        // Count frequency difference between s and t
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // If all counts are zero, it's an anagram
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }

public:
    vector<int> findAnagrams(string s, string p)
    {
        int n1 = s.length();
        int n2 = p.length();
        vector<int> res;

        // Slide through all substrings of length n2
        for (int i = 0; i <= n1 - n2; i++)
        {
            // Extract substring of length n2 and check if anagram of p
            if (isAnagram(s.substr(i, n2), p))
                res.push_back(i); // Store starting index
        }

        return res;
    }
};



*/
