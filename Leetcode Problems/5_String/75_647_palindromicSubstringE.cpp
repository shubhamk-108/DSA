/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

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
    int countSubstrings(string s)
    {
        int n = s.length();

        int left;
        int right;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            left = i;
            right = i;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    cout << sol.countSubstrings(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n²)
Space: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Observation:
Every palindrome has a center.
Odd-length palindrome: center is a single character.
Even-length palindrome: center is between two characters.
Iterate over all possible centers
For a string of length n, there are n possible single-character centers (odd) and n-1 possible two-character centers (even).
Expand around each center
Start with left and right pointers at the center.
Expand outwards as long as characters match (s[left] == s[right]).
Each expansion is a valid palindrome → increment count.


*/


//___________________________________________________________________________________________________________________________________________
// Logic
//___________________________________________________________________________________________________________________________________________

/*

Odd-length palindromes

left = i;
right = i;
while (left >= 0 && right < n && s[left] == s[right])
Expands around a single character center.
Counts palindromes like "a", "aba", "abcba", etc.
Even-length palindromes
left = i;
right = i + 1;
while (left >= 0 && right < n && s[left] == s[right])
Expands around between two characters.
Counts palindromes like "bb", "abba".
All palindromes are counted exactly once.
No recursion → O(1) space.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // ------------------------
            // Odd-length palindromes
            // Center is at i
            // single char is also palindrome
            // ------------------------
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;    // Found a palindrome
                left--;     // Expand left
                right++;    // Expand right
            }

            // ------------------------
            // Even-length palindromes
            // Center is between i and i+1
            // and both char of centres should also be same . Ex. baac here if we connsider aa as centre then both a should be same
            // only then even palindrome is possible there.
            // ------------------------
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;    // Found a palindrome
                left--;     // Expand left
                right++;    // Expand right
            }
        }

        return count; // Total number of palindromic substrings
    }
};



*/
