/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

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
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> st;

        for (auto &ch : tokens)
        {
            if (isdigit(ch[0]) || ch.size() > 1)
            {
                int num = stoi(ch);
                st.push(num);
            }
            else
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (ch == "+")
                    st.push(left + right);
                else if (ch == "-")
                    st.push(left - right);
                else if (ch == "*")
                    st.push(left * right);
                else if (ch == "/")
                    st.push(left / right);
            }
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    vector<string> v = {"2", "1", "+", "3", "*"};
    cout << sol.evalRPN(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
✅ O(n)
Each token is processed once
Stack operations are O(1)

🔹 Space Complexity
✅ O(n)
Stack may hold up to n numbers in the worst cas

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use a stack of integers
Operands are pushed
Operators pop two operands, compute, and push result
Traverse tokens from left to right
If token is a number → convert and push
If token is an operator:
Pop right operand
Pop left operand
Apply operation: left op right
Push result back
Final result
The last value left in the stack is the answer


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();   // Number of tokens (not strictly needed)
        stack<int> st;           // Stack to evaluate the expression

        // Traverse each token in RPN order
        for (auto &ch : tokens)
        {
            // If token is a number (single-digit, multi-digit, or negative)
            if (isdigit(ch[0]) || ch.size() > 1)
            {
                int num = stoi(ch);   // Convert string to integer
                st.push(num);         // Push operand
            }
            else
            {
                // Pop operands (order matters!)
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                // Apply operator
                if (ch == "+")
                    st.push(left + right);
                else if (ch == "-")
                    st.push(left - right);
                else if (ch == "*")
                    st.push(left * right);
                else if (ch == "/")
                    st.push(left / right);
            }
        }

        // Final result
        return st.top();
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
