/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class InfixToPrefix
{
private:
    int precedence(char op)
    {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isRightAssociative(char op)
    {
        return op == '^';
    }

    string infixToPostfix(string infix)
    {
        stack<char> st;
        string postfix = "";

        for (char ch : infix)
        {
            if (isalnum(ch))
            {
                postfix += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            else
            {
                while (!st.empty() &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch) &&
                        !isRightAssociative(ch))))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }

public:
    string convert(string infix)
    {
        // 1. Reverse infix
        reverse(infix.begin(), infix.end());

        // 2. Swap '(' and ')'
        for (char &ch : infix)
        {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        // 3. Convert reversed infix to postfix
        string postfix = infixToPostfix(infix);

        // 4. Reverse postfix to get prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
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


The goal is to convert an infix expression (human-readable) into a prefix expression (operator before operands) while preserving evaluation order.

Instead of designing a complex direct algorithm, we use a safe and well-known transformation that relies on the already-understood infix → postfix process.

🔑 Core Idea (One-line)

Prefix of an expression = Reverse of the postfix of the reversed infix expression.

This insight simplifies the entire problem.

🚀 Step-by-Step Approach
Step 1: Reverse the infix expression

Reversing flips left and right operands

Example:

A + B * C
↓
C * B + A

Step 2: Swap parentheses

After reversing:

( becomes )

) becomes (

This preserves correct grouping

Example:

(A + B) * C
↓ reverse
C * ) B + A (
↓ swap
C * ( B + A )

Step 3: Convert modified infix to postfix

Now we apply the standard infix → postfix rules:

Operands → output

Operators → handled by precedence & associativity

Parentheses → control popping

This step ensures correct execution order.

Step 4: Reverse the postfix expression

Reversing postfix gives prefix of original infix

Example:

Postfix: C B * A +
Reverse: + A * B C   ← PREFIX

🧩 Why This Works (Important Insight)

Reversal switches pre-order ↔ post-order

Parentheses swapping keeps structure valid

Operator precedence remains unchanged

Associativity rules are still respected

Thus, postfix on reversed infix maps directly to prefix on original infix.

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

Stack-based Expression Parsing


*/

