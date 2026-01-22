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
        string result = "";
        int count = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (count > 0)
                    result += ch;
                count++;
            }
            else // ch == ')'
            {
                count--;
                if (count > 0)
                    result += ch;
            }
        }
        return result;
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
Single traversal of the string
O(n)

📦 Space Complexity
Auxiliary space: O(1) (only count)
Output space: O(n) (required to store result)
Interview-correct phrasing:
O(1) extra space excluding the output string

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We traverse the string once
Maintain a counter count that represents the current depth of parentheses
The outermost parentheses occur when:
'(' makes count go from 0 → 1
')' makes count go from 1 → 0
We skip these outermost parentheses
We append all inner parentheses to the result
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result = "";   // Stores final answer
        int count = 0;        // Tracks current depth of parentheses

        for (char ch : s)
        {
            if (ch == '(')
            {
                // If already inside a primitive, keep '('
                if (count > 0)
                    result += ch;

                count++;  // Increase depth
            }
            else // ch == ')'
            {
                count--;  // Decrease depth

                // If still inside a primitive, keep ')'
                if (count > 0)
                    result += ch;
            }
        }
        return result;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Parentheses Depth / Level Counter Pattern

*/
