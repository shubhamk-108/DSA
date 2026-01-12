#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;


class InfixToPostfix
{
private:
    // Return precedence of operators
    int precedence(char op)
    {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }

    // Check if operator is right associative
    bool isRightAssociative(char op)
    {
        return op == '^';
    }

public:
    string convert(string infix)
    {
        stack<char> st; // stack for operators
        string postfix = "";

        for (char ch : infix)
        {
            // Operand
            if (isalnum(ch))
            {
                postfix += ch;
            }
            // Opening bracket
            else if (ch == '(')
            {
                st.push(ch);
            }
            // Closing bracket
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // remove '('
            }
            // Operator
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

        // Pop remaining operators
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};



//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________
/*

Big Picture (What problem this code solves)

We want to convert an infix expression (human-readable):

A + B * C


into postfix (machine-friendly):

A B C * +

Key constraint

Operator precedence must be preserved

Associativity must be preserved

Parentheses must be respected

This code is a mechanical implementation of those mathematical rules.

Core Rules (These are the “laws” the code follows)
Rule 1️⃣ Operands go directly to output

Postfix notation places operands before operators.

So whenever we see:

A, B, x, 7


→ we immediately append them to postfix.

Code
if (isalnum(ch))
{
    postfix += ch;
}

Rule 2️⃣ Parentheses control evaluation order

Parentheses don’t appear in postfix — they only force order.

Opening bracket (

Marks a new sub-expression

Must stop operator popping across it

Code
else if (ch == '(')
{
    st.push(ch);
}

Closing bracket )

End of sub-expression

Pop operators until matching (

Discard both brackets

Code
else if (ch == ')')
{
    while (!st.empty() && st.top() != '(')
    {
        postfix += st.top();
        st.pop();
    }
    st.pop(); // remove '('
}

Rule 3️⃣ Operators are delayed until safe

Operators are not output immediately because:

They must wait until their operands are processed

Higher precedence operators must execute first

So operators are:

Temporarily stored in a stack

Rule 4️⃣ Higher precedence operators must execute first

When a new operator ch arrives:

If the stack top has higher precedence
→ pop it first

Example:

A + B * C


* must execute before +

Code
precedence(st.top()) > precedence(ch)

Rule 5️⃣ Equal precedence → associativity decides

When precedence is equal:

Left associative (+ - * /)

Execute left to right

Pop existing operator

Example:

A - B - C


→ (A - B) - C

Right associative (^)

Execute right to left

Do NOT pop

Example:

A ^ B ^ C


→ A ^ (B ^ C)

Code
(precedence(st.top()) == precedence(ch) &&
 !isRightAssociative(ch))


This means:

Same precedence

AND operator is left associative
→ pop

Rule 6️⃣ Push current operator after popping

Once all higher / equal (left-assoc) operators are handled,
we can safely push current operator.

Code
st.push(ch);

Rule 7️⃣ End of expression → flush stack

At the end, no more operands are coming.
So all remaining operators must be output.

Code
while (!st.empty())
{
    postfix += st.top();
    st.pop();
}

Helper functions (why they exist)
precedence(op)

Encodes math priority rules:

^  → 3
* / → 2
+ - → 1

isRightAssociative(op)

Encodes evaluation direction:

^ → true
others → false

Mental model (IMPORTANT)

Think of the stack as:

“Operators waiting for their operands”

We only pop an operator when we are sure:

Both its operands are already in postfix

One-line interview explanation (gold answer)

“We scan the infix expression left to right, output operands immediately, and use a stack to delay operators until precedence, associativity, and parentheses rules guarantee correct evaluation order.

| Symbol                        | Action             |
| ----------------------------- | ------------------ |
| Operand                       | Output immediately |
| `(`                           | Push to stack      |
| `)`                           | Pop until `(`      |
| Higher precedence operator    | Pop stack first    |
| Same precedence (left assoc)  | Pop                |
| Same precedence (right assoc) | Don’t pop          |
| End                           | Pop all            |


*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

⏱ Time Complexity
O(N)
Each character is pushed and popped at most once.

💾 Space Complexity
O(N)
Stack can hold up to N operators in worst case

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

To convert an infix expression to postfix, we process the expression from left to right while maintaining operator precedence, associativity, and parentheses rules.
Operands are added directly to the postfix result.
Operators are temporarily stored in a stack until it is safe to output them.
Parentheses are used only to control order and are removed in postfix.
When an operator with higher precedence appears, it is processed before lower-precedence operators.
For operators with equal precedence, associativity determines whether we pop from the stack.
After processing the entire expression, any remaining operators in the stack are appended to the postfix result.
This guarantees that the postfix expression preserves the same evaluation order as the infix expression.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class InfixToPostfix
{
private:
    // Returns precedence level of an operator
    int precedence(char op)
    {
        if (op == '^') return 3;          // Highest precedence
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    // Checks if operator is right associative
    bool isRightAssociative(char op)
    {
        // Exponentiation is right associative
        return op == '^';
    }

public:
    string convert(string infix)
    {
        stack<char> st;      // Stack to hold operators
        string postfix = ""; // Resulting postfix expression

        // Traverse the infix expression
        for (char ch : infix)
        {
            // Rule 1: Operand → add directly to postfix
            if (isalnum(ch))
            {
                postfix += ch;
            }
            // Rule 2: Opening parenthesis → push to stack
            else if (ch == '(')
            {
                st.push(ch);
            }
            // Rule 3: Closing parenthesis → pop till '('
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // Remove '(' from stack
            }
            // Rule 4: Operator
            else
            {
                // Pop operators with higher precedence
                // OR equal precedence and left associativity
                while (!st.empty() &&
                       (precedence(st.top()) > precedence(ch) ||
                       (precedence(st.top()) == precedence(ch) &&
                        !isRightAssociative(ch))))
                {
                    postfix += st.top();
                    st.pop();
                }
                // Push current operator
                st.push(ch);
            }
        }

        // Rule 5: Pop remaining operators
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

Pattern Name
Stack-based Expression Parsing


*/

