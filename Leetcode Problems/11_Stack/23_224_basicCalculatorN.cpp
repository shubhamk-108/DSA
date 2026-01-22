/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().



Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

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
    int calculate(string s)
    {
        int n = s.length();
        stack<int>st;
        long long  num = 0;
        long long res = 0;
        int sign =1;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if(isdigit(c))
                num = num * 10 + (c - '0');

            else if(c == '+')
            {
                res += sign * num;
                sign = 1;
                num = 0;   
            }
            else if(c == '-')
            {
                res += sign * num;
                sign = -1;  
                num = 0;
            }
            else if(c == '(')
            {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')')
            {
                res += sign * num;
                num = 0;

                long long prevSign  = st.top(); 
                st.pop();

                long long prevRes = st.top();
                st.pop();

                res = prevRes + prevSign * res;                
            }
        }
        res += sign * num;
        return (int)res;
    }
};
int main()
{
    Solution sol;
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
⏱️ O(n)
Each character is processed once
Stack push/pop are O(1)

4️⃣ Space Complexity
📦 O(n) (worst case)
Stack stores intermediate results for nested parentheses
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The expression may contain:
digits (multi-digit numbers)
+ and -
parentheses ( and )
spaces
Key idea
Evaluate the expression left to right, while keeping track of:
the current number being built (num)
the current result (res)
the current sign (+1 or -1)
Parentheses create a new context, so we:
save the current result and sign on a stack
evaluate the sub-expression
merge it back when we see )


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();
        stack<int> st;        // stores previous result and sign
        int num = 0;          // current number being built
        int res = 0;          // result so far
        int sign = 1;         // current sign (+1 or -1)

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            // Build multi-digit numbers
            if (isdigit(c))
                num = num * 10 + (c - '0');

            // Handle '+'
            else if (c == '+')
            {
                res += sign * num;
                sign = 1;
                num = 0;
            }

            // Handle '-'
            else if (c == '-')
            {
                res += sign * num;
                sign = -1;
                num = 0;
            }

            // Handle '(' → save current context
            else if (c == '(')
            {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }

            // Handle ')' → resolve sub-expression
            else if (c == ')')
            {
                res += sign * num;
                num = 0;

                int prevSign = st.top(); st.pop();
                int prevRes  = st.top(); st.pop();

                res = prevRes + prevSign * res;
            }
            // spaces are ignored automatically
        }

        // Add last number
        res += sign * num;
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Stack + Expression Evaluation (Context Stack)
Also known as:
Recursive-descent simulation
Parentheses context preservation
Used in:
LC 224 – Basic Calculator
LC 227 – Basic Calculator II
LC 772 – Basic Calculator III

*/
