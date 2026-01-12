#include <bits/stdc++.h>
using namespace std;

class PrefixEvaluation
{
public:
    int evaluate(string prefix)
    {
        stack<int> st;

        // Traverse from right to left
        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            char ch = prefix[i];

            // If operand, push to stack
            if (isdigit(ch))
            {
                st.push(ch - '0');
            }
            else
            {
                // Operator: pop two operands
                int left = st.top(); st.pop();
                int right= st.top(); st.pop();

                int result;
                if (ch == '+') result = left + right;
                else if (ch == '-') result = left - right;
                else if (ch == '*') result = left * right;
                else if (ch == '/') result = left / right;
                else if (ch == '^') result = pow(left, right);

                st.push(result);
            }
        }

        return st.top();
    }
};
