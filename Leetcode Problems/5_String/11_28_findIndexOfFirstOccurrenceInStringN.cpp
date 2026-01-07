/*
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
    int SearchStringInAnotherStringNeedleInHaystack(string haystack, string needle)
    {
        int n1 = haystack.length();
        int n2 = needle.length();

        if (n2 == 0)
            return 0;

        if (n2 > n1)
            return -1;

        for (int i = 0; i <= n1 - n2; i++) // haysatck
        {
            string needle_word;

            for (int j = i; j < i + n2; j++) // needle
            {
                needle_word += haystack[j];
            }
            if (needle == needle_word)
                return i;
            needle_word = "";
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "rsadbutsad";
    string needle = "sad";

    cout << sol.SearchStringInAnotherStringNeedleInHaystack(haystack, needle);
    // cout<<haystack.find(needle);
    return 0;
}

// time

/*

Time Complexity: O(N * M)

The outer loop runs from i = 0 to N - M. This gives us approximately N iterations.
Inside the outer loop, you have two main operations:
The inner loop runs M times to build the needle_word string.
The string comparison needle == needle_word also takes M steps to compare the characters of two strings of length M.
Therefore, the total time is roughly (N - M) * (M + M), which simplifies to O(N * M). This is inefficient for very long strings but is a perfectly acceptable brute-force solution.

Space Complexity: O(M)
You are creating a new string variable, needle_word, inside the loop.
In each iteration, this string grows to a length of M (the length of the needle).
Because this is the only significant extra memory you use that scales with the input size, the space complexity is O(M)

*/



// logic

/*
Window Definition: Imagine a "window" with the same size as the needle's length (n2).
Sliding: You place this window at the very beginning of the haystack (index 0).
Comparison: You extract the substring from the haystack that's currently inside the window and compare it to the needle.
Action:
If they match, you have found the first occurrence, and you return the window's starting index (i).
If they don't match, you "slide" the window one position to the right and repeat the comparison.
Termination: If you slide the window all the way to the end of the haystack and find no match, you conclude the needle is not present and return -1.
Your outer loop (for i...) is responsible for sliding the window, and your inner loop (for j...) is responsible for building the substring within 
the current window.

*/


// code


/*

int SearchStringInAnotherStringNeedleInHaystack(string haystack, string needle) 
{
    // Get the lengths of the haystack and needle strings.
    int n1 = haystack.length();
    int n2 = needle.length();

    // Edge Case 1: If the needle is an empty string, LeetCode expects a return value of 0.
    if (n2 == 0) {
        return 0;
    }

    // Edge Case 2: If the needle is longer than the haystack, a match is impossible.
    if (n2 > n1) {
        return -1;
    }

    // The outer loop slides a "window" across the haystack.
    // It iterates from the start (i=0) up to the last possible starting position (n1 - n2).
    for (int i = 0; i <= n1 - n2; i++) 
    {
        // This variable will hold the substring from haystack for comparison.
        // It's re-created as empty for each new window position.
        string needle_word;

        // The inner loop builds the substring from haystack that is inside the current window.
        // It starts at the window's beginning (i) and runs for n2 characters.
        for (int j = i; j < i + n2; j++) 
        {
            // Append characters from the haystack to form the substring.
            needle_word += haystack[j];
        }

        // Compare the extracted substring with the needle.
        if (needle == needle_word) {
            // If they match, we've found the first occurrence. Return its starting index.
            return i;
        }
        // NOTE: The line `needle_word = "";` from your code is not needed here,
        // because `needle_word` is declared fresh at the start of the outer loop.
    }

    // If the loop completes without finding any matches, the needle is not in the haystack.
    return -1;
}


*/