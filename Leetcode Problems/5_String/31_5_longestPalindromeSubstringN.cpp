/*
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string str)
    {
        int n = str.length();
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            if (str[i] != str[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();
        int max_len = 0;
        string longestSubstring = "";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                if (isPalindrome(s.substr(j, i)))
                {
                    if (i > max_len)
                    {
                        max_len = i;
                        longestSubstring = s.substr(j, i);
                    }
                }
            }
        }
        return longestSubstring;
    }
};

int main()
{
    Solution sol;
    string s1 = "babad";

    cout << sol.longestPalindrome(s1);

    return 0;
}



// timespace

/*

Time Complexity: O(N³)

Let N be the length of the input string s.
The outer loop runs N times (for lengths 1 to N).
The inner loop runs approximately N times for each length. This gives us O(N²) for the nested loops, which generate all substrings.
Inside the loops, you call isPalindrome(s.substr(j, i)).
s.substr(j, i) creates a new string. This operation itself can take O(i) time, where i is the length of the substring (up to N).
The isPalindrome check on that new substring takes another O(i) time.
Combining these, the work inside the loop is roughly O(N). Therefore, the total time complexity is O(N²) (for the loops) * O(N) (for 
substring creation and checking) = O(N³). This is generally too slow for LeetCode constraints and will result in a "Time Limit Exceeded" error.


Space Complexity: O(N)
The primary use of extra space is for the sub string created inside the inner loop by s.substr(j, i).
In the worst case, this substring can be as long as the original string s.
Therefore, the space complexity is O(N) to hold the temporary substring.


*/




// code
// THis code is based on generate all possible substring which is already explained in same folder file no. 25_generateAllSubstringN and 
// 26_generateAllSubstringE. First see that.


/*


class Solution
{
public:
    // --- Helper Function: isPalindrome ---
    // This function checks if a given string 'str' reads the same forwards and backwards.
    bool isPalindrome(string str)
    {
        int n = str.length();
        int i = 0;      // Pointer starting from the beginning of the string.
        int j = n - 1;  // Pointer starting from the end of the string.

        // Loop until the pointers meet or cross each other.
        while (i <= j)
        {
            // If characters at the two pointers do not match, it's not a palindrome.
            if (str[i] != str[j])
                return false;

            // Move the pointers towards the center.
            i++;
            j--;
        }
        // If the loop completes without finding any mismatches, it is a palindrome.
        return true;
    }

    // --- Main Function: longestPalindrome ---
    // This function finds the longest palindromic substring within string 's'.
    string longestPalindrome(string s)
    {
        int n = s.length();
        int max_len = 0;
        string longestSubstring = "";

        // The outer loop iterates through all possible substring lengths, from 1 to n.
        // 'i' represents the length of the substring being checked.
        for (int i = 1; i <= n; i++)
        {
            // The inner loop iterates through all possible starting indices for a substring of length 'i'.
            // 'j' is the starting index. The loop ensures we don't go out of bounds.
            for (int j = 0; j <= n - i; j++)
            {
                // Extract the substring of length 'i' starting at index 'j'.
                string sub = s.substr(j, i);

                // Check if this substring is a palindrome.
                if (isPalindrome(sub))
                {
                    // If it is a palindrome and its length 'i' is greater than the
                    // max length found so far, we have a new longest palindrome.
                    if (i > max_len)
                    {
                        max_len = i;
                        longestSubstring = sub;
                    }
                }
            }
        }
        // After checking all possible substrings, return the longest one found.
        return longestSubstring;
    }
};


*/