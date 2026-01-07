/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/

#include <iostream>
using namespace std;
#include <algorithm>

// This is optimised solution but more cleaner solution is written in next file.
class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int n = s.length();
        string cleaned = "";

        for (int i = 0; i < n; i++)
        {
            if (isalnum(s[i]))
            {
                cleaned += tolower(s[i]);
            }
        }

        int m = cleaned.length();

        string reverseStr = "";

        for (int i = m-1; i >= 0; i--)
        {
            reverseStr += cleaned[i];
        }

        for (int i = 0; i < m; i++)
        {
            if (cleaned[i] != reverseStr[i])
                return false;
            
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s);
    return 0;
}


//time space

/*
Time Complexity

Cleaning the string → O(n)

Reversing the string → O(n)

Comparing the two strings → O(n)

Total: O(n)

Space Complexity

cleaned → O(n)

reverseStr → O(n)

Total: O(n)

*/


// logic

/*

class Solution
{
public:

    // Brute-force approach to check if a string is a palindrome
    bool isPalindrome(string &s)
    {
        int n = s.length();
        string cleaned = ""; // store only alphanumeric characters in lowercase

        // Step 1: Build cleaned string
        for (int i = 0; i < n; i++)
        {
            if (isalnum(s[i]))        // check if alphanumeric
            {
                cleaned += tolower(s[i]); // convert to lowercase and append
            }
        }

        int m = cleaned.length();   // length of cleaned string

        string reverseStr = "";     // store reversed cleaned string

        // Step 2: Build reversed string
        for (int i = m - 1; i >= 0; i--)
        {
            reverseStr += cleaned[i];
        }

        // Step 3: Compare cleaned string and its reverse
        for (int i = 0; i < m; i++)
        {
            if (cleaned[i] != reverseStr[i])
                return false;  // mismatch found → not palindrome
        }

        return true; // all characters matched → palindrome
    }
};


*/