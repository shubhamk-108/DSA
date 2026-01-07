/*
395. Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
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
    int longestSubstring(string s, int k)
    {
        return solve(s, 0, s.size(), k);
    }

private:
    int solve(string &s, int start, int end, int k)
    {
        if (end - start < k)
            return 0;

        vector<int> freq(26, 0);

        for (int i = start; i < end; i++)
            freq[s[i] - 'a']++;

        for (int i = start; i < end; i++)
        {
            if (freq[s[i] - 'a'] < k)
            {
                int leftPart = solve(s, start, i, k);
                int rightPart = solve(s, i + 1, end, k);
                return max(leftPart, rightPart);
            }
        }
        return end - start;
    }
};

int main()
{
    Solution sol;
    string s = "aaabb";

    cout << sol.longestSubstring(s, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Why it is not sliding window
//___________________________________________________________________________________________________________________________________________


/*

we first check which char has occured how many times. If some char has not occured at least k times then that char can not be part of any 
of the substring. Because with that invalid char even if we go till very end , still we wont get answer because of that invalid char.  
And we cant even shrink window from left. That is why to remove that invalid (less occured char) we need to split string into left part
and right part ignoring that invalid char.


*/



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
The worst-case time complexity is:
O(26 * n) = O(n) on average
(because each recursive split removes at least one bad character)
But worst case (all same characters) recursion depth is high:
Worst case: O(n²)
Still accepted on LeetCode, and this is the official expected solution.

Space Complexity
Frequency array: O(1) (26 integers)
Recursion depth: worst case O(n) → stack
So:
Space: O(n) worst-case, O(1) extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This problem cannot be solved using sliding window or two pointers, because the substring must satisfy:
Every character in the substring must have frequency ≥ k
This condition does NOT behave well with windows, because shrinking/growing doesn't fix violations inside the substring.
So the standard and optimal method for LC 395 is:
Divide and Conquer Logic
Count the frequency of every character in the current substring [start, end).
If all characters in this substring occur at least k times → the whole substring is valid → return end - start.
If any character occurs less than k, that character cannot be part of the answer.
So we use it as a split point and recursively compute:
Max valid substring in the left part
Max valid substring in the right part
Return max(left, right).
This ensures we divide only around "bad" characters that prevent the substring from being valid.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        return solve(s, 0, s.size(), k);  // start recursion on full string
    }

private:
    // solve substring s[start...end)
    int solve(string &s, int start, int end, int k)
    {
        // If length < k, no valid substring possible
        if (end - start < k)
            return 0;

        // Frequency map for current substring
        vector<int> freq(26, 0);
        for (int i = start; i < end; i++)
            freq[s[i] - 'a']++;

        // Find a character that breaks the rule (freq < k)
        for (int i = start; i < end; i++)
        {
            if (freq[s[i] - 'a'] < k)
            {
                // This character cannot be in the answer -> split here
                int leftPart = solve(s, start, i, k);  // substring before i
                int rightPart = solve(s, i + 1, end, k);  // substring after i
                //every right and left child return maximum of them. So only max value will get propogated to the main parent that 
                // is why it is not like max(maxLen, max(leftpart, rightpart))
                return max(leftPart, rightPart);
            }
        }

        // If we reach here, whole substring is valid
        // end - start is the length
        return end - start;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


ivide and Conquer Pattern
This is the exact pattern used:
Identify invalid breakpoints
Recursively solve left and right segments
Return the maximum
It is not sliding window, not two pointers, not DP.
This problem is a classic example of:
📌 “Split by invalid character” Divide & Conquer

*/
