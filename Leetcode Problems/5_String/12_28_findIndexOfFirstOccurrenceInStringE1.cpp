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

        string needle_word;

        for (int i = 0; i < n2; i++)
        {
            needle_word += haystack[i];
        }
        if (needle == needle_word)
            return 0;

        for (int i = n2; i < n1; i++) // haysatck
        {
            needle_word.erase(0, 1);
            needle_word += haystack[i];

            if (needle == needle_word)
                return i - n2 + 1;
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

// time

/*

Time Complexity: Still O(N * M) in the worst case.

 the string comparison needle == needle_word still takes O(M) time in each iteration of the loop. This cause O(n^2) in worst case
Since the loop runs about N times, the total complexity remains dominated by the repeated string comparisons, resulting in O(N * M). 
To get to a true O(N) solution, you would need to use more advanced algorithms like KMP or Rabin-Karp, 
which avoid this full string comparison at every step.

Space Complexity: O(M)
This is the same as before. You are still storing needle_word, which requires space proportional to the length of the needle (M).

*/

// logic

/*
remove the last char of previous window and add the next char to the current window. Use sliding window approach. But insted of comparing eevry 
time use subtract and add approach.

*/


// code

/*

int SearchStringInAnotherStringNeedleInHaystack(string haystack, string needle)
{
    // Get the length of the haystack and needle strings for easier access.
    int n1 = haystack.length();
    int n2 = needle.length();

    // Edge Case 1: If the needle is an empty string, the problem's convention is to return 0.
    if (n2 == 0)
        return 0;

    // Edge Case 2: A match is impossible if the needle is longer than the haystack.
    if (n2 > n1)
        return -1;

    // This string will act as our "sliding window".
    string needle_word;

    // --- Step 1: Create the initial window ---
    // Build the very first substring from the haystack to compare.
    for (int i = 0; i < n2; i++)
    {
        needle_word += haystack[i];
    }
    
    // Check if this first window is a match. If so, we are done.
    if (needle == needle_word)
        return 0;

    // --- Step 2: Slide the window across the rest of the string ---
    // The loop starts at index n2, as we've already processed characters up to n2-1.
    for (int i = n2; i < n1; i++) 
    {
        // To "slide" the window, first remove the character that is falling out of the window's left side.
        // This is always the character at index 0 of our 'needle_word' string.
        needle_word.erase(0, 1);
        
        // Then, add the new character from the haystack that is entering the window's right side.
        needle_word += haystack[i];

        // Now, compare the updated window with the needle.
        if (needle == needle_word)
        {
            // If a match is found, we need to return the *starting* index of the window.
            // The window ends at index `i`, so it must have started at `i - n2 + 1`.
            return i - n2 + 1;
        }
    }

    // If the loop completes without finding any matches, the needle is not present.
    return -1;
}


*/