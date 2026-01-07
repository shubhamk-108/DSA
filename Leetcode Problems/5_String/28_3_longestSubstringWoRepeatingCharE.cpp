/*

Given a string s, find the length of the longest substring without duplicate characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

A substring is a continuous sequence of characters taken from a string.
It must be contiguous (characters must be next to each other, without gaps).
Order is preserved.
Every string is a substring of itself.
The empty string is also considered a substring.
s = "abcde"
Substrings of "abcde":
Length 1: "a", "b", "c", "d", "e"
Length 2: "ab", "bc", "cd", "de"
Length 3: "abc", "bcd", "cde"
Length 4: "abcd", "bcde"
Length 5: "abcde"
Total substrings = n * (n + 1) / 2 = 5 * 6 / 2 = 15

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> um_checkIfAppearedBefore;
        int n = s.length();

        int start = 0;
        int end = 0;
        int max_len = 0;

        for (end; end < n; end++)
        {
            if (um_checkIfAppearedBefore.find(s[end]) != um_checkIfAppearedBefore.end())
            {
                if (um_checkIfAppearedBefore[s[end]] >= start)
                {
                    max_len = max(max_len, end - start);
                    start = um_checkIfAppearedBefore[s[end]] + 1;
                }
            }

            um_checkIfAppearedBefore[s[end]] = end;
        }
        max_len = max(max_len, end - start);
        return max_len;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcadcbb";

    cout << sol.lengthOfLongestSubstring(s1);
    return 0;
}

// timespace

/*
Time Complexity: O(n)
Space Complexity: O(min(n, m))

The space is determined by the unordered_map which stores the characters encountered.
Let n be the length of the string and m be the size of the character set (e.g., 128 for ASCII or 256 for extended ASCII).
The number of unique characters in the map can never exceed the size of the character set, m. It also cannot exceed the length of the string 
itself, n.
So, the space required is the minimum of these two values.
In many contexts, since the character set size m is a fixed constant, the space complexity is often simplified to O(1).

*/


// logic

/* 

1. Use sliding window and hashmap
2. take current char. See if it is already there in map. If it is already there then check if it comes after the start_index_of_current_window.
If it comes after the start of current window then we have to change that start element because duplicate element will occur if we take that 
index as well. And we break that substring means we start new making new substring there. But before starting new substring make sure that
you compute length of that previous substring. How to start new substring. if we previously processed char 'a' suppose and lets say
after going 4-5 positions ahead in the string we saw that char 'a' is again coming. Then we chagnge our start to one position past the previous 'a'
so that we do not have double-double char 'a'.
Remember if the char repeats itself but it is before the start of window then we do not break our substring. Means our window start is at 3
There and going forward on index 7 if we see repeating char. But if the same char is present on index 1 then we do not break our string,
BEcause our window is starting at index 3 and the repeated char is not the part of current window. It was the part of previous window or 
substirng so ignore it.
3. Even if char is not there in hash map or char is there in hash map, in both cases we have to put latest index of char in hashmap,
so we do it after coming out of if block.
4. outside loop we again calculate length because if string is unique like abcde then we just keep on putting in hash map but dont calculate
its length, so we do it outside loop for that condition.



*/


//code


/*

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // A map to store the last seen index of each character.
        // Key: character, Value: index in the string.
        unordered_map<char, int> um_checkIfAppearedBefore;
        int n = s.length();

        // 'start' is the beginning of the current non-repeating substring (the left side of the window).
        int start = 0;
        // 'end' is the end of the current non-repeating substring (the right side of the window).
        int end = 0;
        // 'max_len' stores the maximum length found so far.
        int max_len = 0;

        // Iterate through the string with the 'end' pointer to expand the window.
        for (end; end < n; end++)
        {
            // Check if the current character has been seen before.
            if (um_checkIfAppearedBefore.find(s[end]) != um_checkIfAppearedBefore.end())
            {
                // If it has been seen, check if its last occurrence is within the current window.
                // The window is defined by the range [start, end).
                if (um_checkIfAppearedBefore[s[end]] >= start)
                {
                    // A repeat character is found inside our current window.
                    // First, calculate the length of the valid substring we just completed (from 'start' to 'end'-1).
                    max_len = max(max_len, end - start);

                    // Then, shrink the window from the left by moving 'start' to the position
                    // right after the previous occurrence of this character.
                    start = um_checkIfAppearedBefore[s[end]] + 1;
                }
            }

            // No matter what, always update the map with the latest index of the current character.
            // This is crucial for the next iterations.
            um_checkIfAppearedBefore[s[end]] = end;
        }
        
        // After the loop, one final check is needed. The last valid substring (from the
        // last 'start' position to the end of the string) has not been measured yet.
        max_len = max(max_len, end - start);
        
        return max_len;
    }
};


*/