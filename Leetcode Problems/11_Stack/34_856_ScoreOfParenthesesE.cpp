/*
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.


Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2

✅ Example: s = "(()(()))"

We need to compute its score using the rules:

🔹 Rule 1: () = 1
🔹 Rule 2: AB = score(A) + score(B)
🔹 Rule 3: (A) = 2 × score(A)
Step-by-step breakdown
Step 1: Add spaces to see structure
(  ( )  ( ( ) )  )


So the string is:

(   A   B   )


Where:

A = ()

B = (())

✅ Evaluate A
A = ()
score(A) = 1

✅ Evaluate B
B = (())


Break B:

( () )

So inside B is "()", which is score 1.

Then we wrap it once:

score(B) = 2 × 1 = 2

Now combine inside the outermost parentheses

Inside outermost parentheses we have:

A + B = 1 + 2 = 3

Final step: outer parentheses

The entire string is:

( A + B )

So we wrap 3 inside parentheses:

score = 2 × 3 = 6

✅ Final Answer
score("(()(()))") = 6
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
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(-1);
            else
            {
                if (st.top() == -1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int currGroupRes = 0;
                    while (!st.empty() && st.top() != -1)
                    {
                        currGroupRes += st.top();
                        st.pop();
                    }
                    if (!st.empty() && st.top() == -1)
                    {
                        currGroupRes *= 2;
                        st.pop();
                        st.push(currGroupRes);
                    }
                }
            }
        }
        int res = 0;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "(()(()))";
    cout << sol.scoreOfParentheses(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(n)
Each character is processed once
Each stack element is pushed and popped at most once

4️⃣ Space Complexity
📦 Space: O(n)
Stack can grow up to n in worst case (deep nesting)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


“The parentheses form a nested structure similar to expressions.
I use a stack to evaluate the score bottom-up.
I push a marker for '('.
When I see ')', there are two cases:
If the top is '(', then it represents '()' and contributes a score of 1.
Otherwise, I pop and sum all scores inside the current parentheses, double that sum, and push it back.
In the end, I add up all remaining values in the stack to get the total score.”

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            // Opening parenthesis → push marker
            if (s[i] == '(')
                st.push(-1);

            // Closing parenthesis
            else
            {
                // Case 1: "()"
                if (st.top() == -1)
                {
                    st.pop();       // remove '(' marker
                    st.push(1);     // "()" contributes 1
                }

                // Case 2: "(A)" where A has one or more scores
                else
                {
                    int currGroupRes = 0;

                    // Sum all scores inside the current parentheses
                    while (!st.empty() && st.top() != -1)
                    {
                        currGroupRes += st.top();
                        st.pop();
                    }

                    // Remove '(' marker, double the inner score
                    if (!st.empty() && st.top() == -1)
                    {
                        st.pop();
                        currGroupRes *= 2;
                        st.push(currGroupRes);
                    }
                }
            }
        }

        // Sum all top-level scores
        int res = 0;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


attern Used
This problem uses:
Stack

You learned something big here:
Every closed parenthesis produces exactly ONE score and pushes it back to the stack.
That rule applies to:
LC856
LC394
LC636
Expression parsing problems

*/
