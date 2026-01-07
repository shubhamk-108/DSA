/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
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

        for (int i = 0; i < n; i++)
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
            }
        }
        reverse(word.begin(), word.end());
        res += word;
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

You traverse the string → O(n)

You reverse each word → total across all words is O(n)
So total = O(n)

💾 Space Complexity

Uses two extra strings res and word: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Iterate over the string.

Build characters into a temporary word until hitting a space.

When a space is found:

Reverse the collected word

Append it to result

Append the space

Reset the word

After loop ends, reverse the last collected word and append it.


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
        string word = "";  // current word being built

        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')              // keep collecting characters
            {
                word += s[i];
            }
            else                           // space encountered → word ends
            {
                reverse(word.begin(), word.end()); // reverse the word
                res += word;                        // add reversed word
                res += ' ';                         // keep the space
                word = "";                          // reset for next word
            }
        }

        // After loop ends, last word still needs processing
        reverse(word.begin(), word.end());
        res += word;

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
✔️ String Building Pattern

– Building pieces (words) and concatenating results.

✔️ Two-Phase Processing Within One Loop



*/
