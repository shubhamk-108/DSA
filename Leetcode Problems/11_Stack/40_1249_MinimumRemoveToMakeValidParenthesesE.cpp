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
        stack<int> st;
        vector<bool> toBeRemoved(n, false);
        string res = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else
                    toBeRemoved[i] = true;
            }
        }
        while (!st.empty())
        {
            toBeRemoved[st.top()] = true;
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            if (toBeRemoved[i])
                continue;
            else
                res += s[i];
        }

        return res;
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
One pass to mark invalid parentheses
One pass to build the result
💾 Space Complexity

O(n)
Stack + boolean array + result string
This is optimal, because we must at least store the output string

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Traverse the string and identify invalid parentheses.
Use a stack to store indices of unmatched '('.
If a ')' cannot be matched with a '(', mark it for removal.
After traversal, any '(' still in the stack are unmatched → mark them for removal.
Build the result string by skipping marked indices.
This ensures:
Minimum removals
Original order preserved
Resulting string is valid

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
        int n = s.length();                 // Length of input string
        stack<int> st;                      // Stack to store indices of '('
        vector<bool> toBeRemoved(n, false); // Marks indices to remove
        string res = "";                    // Result string

        // First pass: identify invalid ')'
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                // Store index of opening parenthesis
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    // Match ')' with a '('
                    st.pop();
                }
                else
                {
                    // Unmatched ')', mark for removal
                    toBeRemoved[i] = true;
                }
            }
        }

        // Any remaining '(' in stack are unmatched
        while (!st.empty())
        {
            toBeRemoved[st.top()] = true;
            st.pop();
        }

        // Build the final valid string
        for (int i = 0; i < n; i++)
        {
            if (toBeRemoved[i])
                continue;   // Skip invalid parentheses
            else
                res += s[i];
        }

        return res; // Valid parentheses string
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern Name
Stack + Index Marking (Validation and Reconstruction Pattern)

*/
