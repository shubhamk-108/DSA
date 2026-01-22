/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

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
    string minRemoveToMakeValid(string s)
    {
        int n = s.length();
        int depth = 0;
        string str1 = "";
        string str2 = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                depth++;
                str1 += s[i];
            }
            else if (s[i] == ')')
            {
                depth--;
                if (depth == -1)
                {
                    depth = 0;
                    continue;
                }
                str1 += s[i];
            }
            else
                str1 += s[i];
        }

        for (int i = str1.length() - 1; i >= 0; i--)
        {
            if (depth > 0 && str1[i] == '(')
            {
                depth--;
                continue; 
            }
            else
                str2 += str1[i];
        }

        reverse(str2.begin(), str2.end());

        return str2;
    }
};

int main()
{
    Solution sol;
    string s = "lee(t(c)o)de)";
    cout << sol.minRemoveToMakeValid(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
Two linear passes over the string

💾 Space Complexity
O(n)
Output strings (str1, str2)
This is optimal — you cannot do better than O(n).
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want to remove the minimum number of parentheses so that the string becomes valid.
A string is valid if:
Every ')' has a '(' before it
Every '(' has a ')' after it
So we solve this in two passes:
🔹 Pass 1: Left → Right
Goal: Remove invalid ')'
Maintain depth = number of currently open '('
If we see '(' → increase depth
If we see ')':
If depth == 0, it is invalid → skip it
Else, it is valid → keep it and decrease depth
After this pass:
There are no invalid closing parentheses
depth now equals extra unmatched '('
🔹 Pass 2: Right → Left
Goal: Remove extra '('
Traverse from the end
Remove the rightmost unmatched '(' first
Decrease depth when removing one
Keep all other characters
Finally, reverse the string to restore order.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int depth = 0;           // Tracks balance of '('
        string str1 = "";        // After removing invalid ')'
        string str2 = "";        // Final result

        // Pass 1: Left → Right (remove invalid ')')
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                depth++;             // Open parenthesis
                str1 += s[i];
            }
            else if (s[i] == ')')
            {
                depth--;             // Try to close '('
                if (depth == -1)     // No '(' available
                {
                    depth = 0;       // Reset and skip this ')'
                    continue;
                }
                str1 += s[i];        // Valid ')'
            }
            else
            {
                str1 += s[i];        // Letters stay as-is
            }
        }

        // Pass 2: Right → Left (remove extra '(')
        for (int i = str1.length() - 1; i >= 0; i--)
        {
            if (depth > 0 && str1[i] == '(')
            {
                depth--;             // Remove this unmatched '('
                continue;
            }
            str2 += str1[i];         // Keep character
        }

        reverse(str2.begin(), str2.end()); // Restore order
        return str2;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pass Parentheses Filtering (Depth / Balance Pattern)


*/
