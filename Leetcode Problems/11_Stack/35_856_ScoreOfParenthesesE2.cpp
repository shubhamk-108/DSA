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
        int depth = 0;
        int score = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                depth++;
            else
            {
                depth--;
                if (s[i - 1] == '(')
                    score += (1 << depth);
            }
        }
        return score;
    }
};

int main()
{
    Solution sol;
    string s = "(())";
    cout << sol.scoreOfParentheses(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Intuition
//___________________________________________________________________________________________________________________________________________

/*

Problem reminder (LC 856)
Rules for scoring parentheses:
"()" → 1
"AB" → A + B
"(A)" → 2 × A

Rules:
"()" = 1
"AB" = A + B
"(A)" = 2 × A
These rules scream one thing:
Nesting doubles the score

2️⃣ Try small examples and observe patterns
Example 1
()
score = 1

Example 2
(())
= 2 × ()
= 2

Example 3
((()))
= 2 × (())
= 4

Example 4
(((())))
= 8

📌 Observation #1
For a single "()" wrapped k times:
score = 2^k

3️⃣ Look at mixed cases
Example
(()())
Break it:
( () () )

Inside:
() → 1
() → 1
Sum = 2
Outer parentheses doubles it → 4
But notice something important:
( () () )
  ↑  ↑
Each "()" is independent, and both get doubled by the outer pair.

4️⃣ Key realization (THIS is the intuition leap)
Instead of:
❌ computing big subexpressions
Think:
✅ count contribution of each "()"
Because:
Everything is built from "()"
Nesting just multiplies their value

5️⃣ How much does one "()" contribute?
Look at:
((()()))
   ↑
That "()" is inside:
1 outer ()
2 outer ()
3 outer ()
Each outer pair doubles its value.
So contribution:
1 × 2 × 2 × 2 = 2^3

📌 Observation #2
Contribution of "()" = 2^(number of open parentheses around it)

6️⃣ How do we count “open parentheses around it”?
That’s just:
DEPTH
While scanning the string:
'(' → go deeper
')' → come out

7️⃣ Why detect "()" specifically?
Because:
Only "()" has a base score of 1
Everything else is built from it
So:
if (s[i] == ')' && s[i-1] == '(')
means
👉 “I found a base unit”

8️⃣ Why depth is decremented first
At "()":
... ( ) ...
Depth before ):
depth = inside count + 1
Depth after ):
depth = number of outer parentheses
That’s exactly what we want.

9️⃣ Why 1 << depth
From math:
2^depth = 1 << depth
So every "()" contributes:
score += (1 << depth);
*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
We scan the string once.

💾 Space Complexity
O(1)
Only constant extra variables (depth, score)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Every valid parentheses string is composed of primitive pairs "()".
A primitive "()" has a base score = 1.
Each surrounding pair of parentheses doubles its score.
So the contribution of "()" is:
2^(number of surrounding parentheses)
While scanning the string:
Maintain a depth counter to track nesting.
Whenever we detect "()", add 2^depth to the answer.
This avoids using a stack and computes the score directly in one pass.
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
        int n = s.length();     // Length of the input string
        int depth = 0;          // Tracks current nesting depth
        int score = 0;          // Stores final score

        // Traverse the string character by character
        for (int i = 0; i < n; i++)
        {
            // Opening parenthesis increases nesting depth
            if (s[i] == '(')
                depth++;
            else
            {
                // Closing parenthesis reduces nesting depth
                depth--;

                // If previous character was '(',
                // we found a primitive "()"
                if (s[i - 1] == '(')
                {
                    // Add contribution of this "()"
                    // 1 << depth = 2^depth
                    score += (1 << depth);
                }
            }
        }
        return score; // Return total score
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern Name

Depth / Balance Counting (Stack Optimization Pattern)
🔹 Pattern Description
Instead of using a stack to evaluate nested structures,
Track nesting depth numerically
Count contributions directly rather than building subexpressions

🔹 Common Problems Using This Pattern
LC 856 — Score of Parentheses
LC 1111 — Maximum Nesting Depth Split
LC 921 — Minimum Add to Make Parentheses Valid
LC 1541 — Minimum Insertions to Balance Parentheses

*/
