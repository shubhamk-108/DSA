/*
13_28_findIndexOfFirstOccurrenceInStringE2 using KMP Algorithm (lps array)

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // this solution is using kmp algorithm that is using lps arary. To get the explanation see - DSA->DSA_GFG->8_string -> 20_prerequisiteOfKmpAlgo,
    //  22_LpsArrayE,  23_KmpPatternSearch read these files. This code is same as that one.

    vector<int> lpsArray(string pattern)
    {
        int n2 = pattern.length();
        if (n2 == 0)
            return {};
        vector<int> lps(n2, 0);

        int len = 0;
        int i = 1;

        while (i < n2)
        {
            if (pattern[len] == pattern[i])
            {
                len++;
                lps[i] = len;

                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
    int SearchStringInAnotherStringNeedleInHaystack(string haystack, string needle)
    {
        int n1 = haystack.length();
        int n2 = needle.length();

        if (n2 == 0)
            return 0;
        if (n1 < n2)
            return -1;

        vector<int> lps = lpsArray(needle);

        int i = 0;
        int j = 0;

        while (i < n1)
        {
            if (needle[j] == haystack[i])
            {
                i++;
                j++;
            }
            if (j == n2)
            {
                // cout << i - n2 << " ";
                return i - j;
                // j = lps[j - 1];
            }
            else if (i < n1 && haystack[i] != needle[j])
            {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    // string haystack = "rcsadbutsad";
    // string needle = "sad";
    string haystack = "aabaaabaaac";

    string needle = "aabaaac";

    cout << sol.SearchStringInAnotherStringNeedleInHaystack(haystack, needle);
    return 0;
}

// time space code logic: for everything read comment above fundtion definition.
