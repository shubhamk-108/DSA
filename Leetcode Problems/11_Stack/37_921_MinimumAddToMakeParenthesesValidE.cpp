/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.



Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3


Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'
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
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        stack<char> st;
        int minAdd = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                    st.pop();
                else
                    minAdd++;
            }
        }
        minAdd += st.size();
        return minAdd;
    }
};

int main()
{
    Solution sol;
    string s = "())";
    cout << sol.minAddToMakeValid(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
⏱ Time Complexity
O(n) — single pass through the string
💾 Space Complexity
O(n) — stack can store up to n opening parentheses in worst case
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We use a stack to track unmatched opening parentheses '('.
Traverse the string:
If we see '(', push it onto the stack.
If we see ')':
If the stack is not empty, it matches a previous '(', so pop.
If the stack is empty, this ')' is extra → we need to add one '(', so increment minAdd.
After processing the string:
Any remaining '(' in the stack are unmatched → each needs a ')'.
The total number of insertions is:
extra ')' needed + extra '(' needed

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();     // Length of input string
        stack<char> st;         // Stack to track unmatched '('
        int minAdd = 0;         // Number of insertions needed

        // Traverse the string
        for (int i = 0; i < n; i++)
        {
            // If opening parenthesis, store it
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else // s[i] == ')'
            {
                // If there is an unmatched '(' available, match it
                if (!st.empty())
                    st.pop();
                else
                    // No '(' to match this ')', so we need to add one
                    minAdd++;
            }
        }

        // Any remaining '(' need to be closed
        minAdd += st.size();

        return minAdd; // Minimum insertions required
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Stack-Based Parentheses Validation Pattern


*/
