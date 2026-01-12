/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
#include<cmath>
using namespace std;

class PostfixEvaluation
{
public:
    int evaluate(string postfix)
    {
        stack<int> st;

        for (char ch : postfix)
        {
            // If operand, push its value
            if (isdigit(ch))
            {
                st.push(ch - '0'); // convert char to int
            }
            else
            {
                // Pop two operands
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                // Apply operator
                int result;
                if (ch == '+')
                    result = left + right;
                else if (ch == '-')
                    result = left - right;
                else if (ch == '*')
                    result = left * right;
                else if (ch == '/')
                    result = left / right;
                else if (ch == '^')
                    result = pow(left, right);

                // Push result back
                st.push(result);
            }
        }

        return st.top(); // final result
    }
};
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time
O(N)

Space
O(N)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Postfix expressions are evaluated left to right using a stack:

Operand → push onto stack

Operator →

Pop right operand

Pop left operand

Apply operator:

result = left op right


Push result back onto stack

At the end, stack contains one value → final answer

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Stack-based Expression Evaluation

*/
