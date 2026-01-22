/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.



Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
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
    string removeOuterParentheses(string s)
    {
        int n = s.length();
        stack<int> st;

        string output = "";
        string current = "";
        for (auto &ch : s)
        {
            if (ch == '(')
                st.push(ch);
            else
                st.pop();
            current += ch;
            if (st.empty())
            {
                current.pop_back();
                current.erase(current.begin());
                output += current;
                current = "";
            }
        }
        return output;
    }
};

int main()
{
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Traverses the string once → O(n)
📦 Space Complexity
Stack stores at most n/2 '(' → O(n)
current string also temporarily stores primitive → O(n)
So overall: O(n) time, O(n) space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Uses a stack to track parentheses balance
Builds a current primitive string in current
When the stack becomes empty → you have reached the end of a primitive string
Then
Remove the first and last character of current (outermost parentheses)Append it to output
Reset current for the next primitive



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


Uses a stack to track parentheses balance
Builds a current primitive string in current
When the stack becomes empty → you have reached the end of a primitive string
Then
Remove the first and last character of current (outermost parentheses)Append it to output
Reset current for the next primitive



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
