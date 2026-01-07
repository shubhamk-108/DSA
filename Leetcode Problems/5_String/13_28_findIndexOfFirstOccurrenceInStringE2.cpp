/*
13_28_findIndexOfFirstOccurrenceInStringE2 using Rabin Karp Algorithm

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
#include <unordered_map>
using namespace std;

class Solution
{
public:
// this solution is using rabin karp. To get the explanation DSA->DSA_GFG->8_string 17_rabinKarpAlgo, 18_RabinKarpPrerequisite,
//  19_patternSearchingRabinKarpE read these files. This code is same as that one.
    int SearchStringInAnotherStringNeedleInHaystack(string haystack, string needle)
    {
        int n1 = haystack.length();
        int n2 = needle.length();
        int base = 256;
        int q = 101; // prime no to do modulo
        int p = 0;   // hash of pattern
        int t = 0;   // hash of text
        int h = 1;   // to create incremental exponential

        // when we delete first char during rolling hash then we need haystack[i] * base^m-1.
        // this base^m-1 we are calculating here. We need it every time we delete fist char of window.
        // we can simply do it pow(base, m-1) like 256^2, but directly doing this increases the computational complexity.
        // So we need incremental exponential. Like just multiply the current thing to the previous result.

        if (n2 == 0)
            return 0;

        if (n2 > n1)
            return -1;

        // needed this to remove base^m-1 when we substract the first char of window in rolling hash
        for (int i = 0; i < n2 -1 ; i++)
        {
            h =( h * base) %q;
        }

        // compute first window hash value for haystack(pattern) and needle(text)
        for (int i = 0; i < n2; i++)
        {
            p = (needle[i] + p * base) % q;
            t = (haystack[i] + t * base) % q;
        }

        // slide the window

        for (int i = 0; i <= n1-n2; i++)
        {
            if (p == t)
            {
                bool flag_Matched = true;
                for (int j = 0; j < n2; j++)
                {
                    if (needle[j] != haystack[i + j])
                    {
                        flag_Matched = false;
                        break;
                    }
                }
                if (flag_Matched == true)
                    return i;
            }

            // compute rolling hash
            if (i < n1 - n2)
                t = (((t - haystack[i] * h) * base) + haystack[i + n2]) % q;

            if (t < 0)
                t += q;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "rcsadbutsad";
    string needle = "sad";

    cout << sol.SearchStringInAnotherStringNeedleInHaystack(haystack, needle);
    // cout<<haystack.find(needle);
    return 0;
}

// time space code logic: for everything read comment above fundtion definition.