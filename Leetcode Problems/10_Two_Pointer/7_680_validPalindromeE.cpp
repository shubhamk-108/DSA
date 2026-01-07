/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
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
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int n = s.length();

        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (s[i] != s[j])
            {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "abca";
    cout << sol.validPalindrome(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

time
O(n)

💾 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use two pointers:
i starting at the beginning
j starting at the end
Move both inward while characters match.
When a mismatch occurs:
You are allowed to delete one character.
So you check:
Skip s[i] → check substring s[i+1 .. j]
Skip s[j] → check substring s[i .. j-1]
If either substring is a palindrome → return true
If the loop completes without mismatch → string is already a palindrome


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;         // mismatch → not a palindrome
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        // Two-pointer approach
        while (i < j)
        {
            // Mismatch found → try skipping one char
            if (s[i] != s[j])
            {
                // Option 1: skip s[i]
                // Option 2: skip s[j]
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }

            // If characters match, continue inward
            i++;
            j--;
        }

        // Completed full scan without requiring >1 deletions
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Two-Pointer Technique + Conditional Skip (Greedy Palindrome Check)

*/
