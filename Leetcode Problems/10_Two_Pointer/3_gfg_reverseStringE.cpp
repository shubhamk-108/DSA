/*
This is gfg code and not available on leetcode.

You are given a string s. You need to reverse each word in it where the words are separated by spaces and return
the modified string.

Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The
returned string should only have a single space separating the words, and no extra spaces should be included.

Examples:

Input: s = " i like this program very much "
Output: "i ekil siht margorp yrev hcum"
Explanation: The words are reversed as follows:
"i" -> "i","like"->"ekil",
"this"->"siht","program" -> "margorp",
"very" -> "yrev","much" -> "hcum".

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
    string reverseWords(string s)
    {
        int n = s.length();
        string res = "";
        string word = "";

        int i = 0;

        while (i < n && s[i] == ' ')
            i++;
        while (i < n)
        {
            if (s[i] != ' ')
            {
                word += s[i];
            }
            else
            {
                reverse(word.begin(), word.end());
                res += word;
                res += ' ';
                word = "";

                while (i < n && s[i] == ' ')
                    i++;
                continue;
            }

            i++;
        }
        reverse(word.begin(), word.end());
        res += word;
        while(!res.empty() && res.back() == ' ')
            res.pop_back();

        return res;
    }
};
int main()
{
    Solution sol;
    string s = "     program      written     ";
    cout << sol.reverseWords(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n)

Each character is processed at most once.

Reversing each word costs total O(n) across entire string.

✅ Space Complexity
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Skip leading spaces so output never begins with space.
Start scanning characters from the first non-space.
Build a word character by character until a space is found.
When a space is hit:
reverse the collected word
append it to result + ' '
clear word
skip all consecutive spaces (ensures only single spaces in result)
After the loop, reverse and append the last word.
Remove any trailing spaces using a while loop.
Return the cleaned-up string.
This is a single-pass solution with controlled space cleanup.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution 
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string res = "";   // final result string
        string word = "";  // temporary storage for current word

        int i = 0;

        // Skip leading spaces so result never starts with spaces
        while (i < n && s[i] == ' ')
            i++;

        // Process the string character by character
        while (i < n)
        {
            if (s[i] != ' ')            // if the character is part of a word
            {
                word += s[i];           // build word
            }
            else                        // space found → end of a word
            {
                reverse(word.begin(), word.end());  // reverse the collected word
                res += word;           // add reversed word to result
                res += ' ';            // add single space after the word
                word = "";             // reset word builder

                // Skip multiple consecutive spaces to avoid extra spaces in result
                while (i < n && s[i] == ' ')
                    i++;

                continue;               // continue without incrementing i again
            }

            i++;                        // next character
        }

        // Process the final word (there’s no space after it)
        reverse(word.begin(), word.end());
        res += word;

        // Remove trailing spaces if any
        while (!res.empty() && res.back() == ' ')
            res.pop_back();

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

⭐ Two-Pointer / String Parsing Pattern

*/
