/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:
Input: s = "([])"
Output: true
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
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                else if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))
                    st.pop();
                else
                    return false;
            }
        }
        return (st.empty());
    }
};

int main()
{
    Solution sol;
    string s = "([])";
    cout << sol.isValid(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
Each character is processed once.

🧠 Space Complexity
O(n)
In the worst case (all opening brackets), the stack stores all characters.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We use a stack to validate parentheses because the problem requires:
Matching opening and closing brackets
Maintaining correct order (LIFO)
Steps:
Traverse the string character by character.
If the character is an opening bracket ((, [, {), push it onto the stack.
If the character is a closing bracket:
If the stack is empty → invalid (no opening bracket to match).
Check if the top of the stack matches the closing bracket.
If yes → pop the opening bracket.
If no → invalid.
After processing the entire string:
If the stack is empty → all brackets matched → valid.
Otherwise → invalid.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();        // Length of the input string
        stack<char> st;            // Stack to store opening brackets

        for (int i = 0; i < n; i++)
        {
            // If current character is an opening bracket, push to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                // If a closing bracket appears but stack is empty → invalid
                if (st.empty())
                    return false;

                // Check if top of stack matches the current closing bracket
                else if ((st.top() == '(' && s[i] == ')') ||
                         (st.top() == '[' && s[i] == ']') ||
                         (st.top() == '{' && s[i] == '}'))
                    st.pop();   // Valid match → remove opening bracket
                else
                    return false; // Mismatched brackets
            }
        }

        // If stack is empty, all brackets matched correctly
        return st.empty();
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Stack + Matching / Parentheses Validation Pattern

Common problems using this pattern:
LC20 – Valid Parentheses
LC921 – Minimum Add to Make Parentheses Valid
LC1249 – Remove Invalid Parentheses
Expression evaluation
Compiler syntax checking


*/
