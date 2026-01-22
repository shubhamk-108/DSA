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
    int evaluateParenthesis(string s)
    {
        long long num = 0;
        int sign = 1;
        long long res = 0;

        for (auto &ch : s)
        {
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '+')
            {
                num = sign * num;
                res += num;
                num = 0;
                sign = 1;
            }
            else if (ch == '-')
            {
                num = sign * num;
                res += num;
                num = 0;
                sign = -1;
            }
        }
        res += sign * num;
        return (int)res;
    }

    int calculate(string s)
    {

        // auto startIterator = remove(s.begin(), s.end(), ' ');
        // s.erase(startIterator, s.end());
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        while (s.find('(') != string::npos)
        {
            int r = s.find(')');
            int l = r;

            while (l >= 0 && s[l] != '(')
                l--;

            int val = evaluateParenthesis(s.substr(l + 1, r - l - 1));
            s = s.substr(0, l) + to_string(val) + s.substr(r + 1);
        }

        return evaluateParenthesis(s);
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
// Explanation
//___________________________________________________________________________________________________________________________________________
/*

🔹 High-level idea (before code)

The expression may contain:

digits

+, -

parentheses ( )

spaces

Strategy

Remove spaces

Repeatedly evaluate the innermost ( ... )

Replace it with its numeric value

When no parentheses remain → evaluate the final flat expression

This mimics how humans solve math expressions.

🔹 Code walkthrough (line by line)
Function signature
int calculate(string s)


Takes a mathematical expression as a string and returns its integer result.

🔹 Step 1: Remove spaces
s.erase(remove(s.begin(), s.end(), ' '), s.end());

Why?

Spaces are meaningless in evaluation:

"1 + (2 - 3)"  →  "1+(2-3)"

How it works

remove(...) shifts all non-space characters to the front

Returns iterator to the “new end”

erase(...) deletes the extra characters

✅ After this line:

s = "1+(2-3)"

🔹 Step 2: Process parentheses
while (s.find('(') != string::npos)

Meaning

As long as any ( exists, there is a parenthesized expression to solve

We keep simplifying until no parentheses remain

🔹 Step 3: Find the innermost parentheses
int r = s.find(')');


Finds the first closing bracket

This guarantees it belongs to the innermost (

Example:

"1+(2-(3+4))"
        ^
        r

int l = r;
while (l >= 0 && s[l] != '(')
    l--;

What this does

Move left from )

Stop when we find the matching (

Now:

s[l] == '('
s[r] == ')'


This pair encloses the innermost expression.

🔹 Step 4: Extract inside expression
int val = evalSimple(s.substr(l + 1, r - l - 1));

Break it down
s.substr(l + 1, r - l - 1)

Extracts text inside parentheses.

Example:

"(3+4)"
 l   r

substr(l+1, r-l-1) → "3+4"

evalSimple(...)

This helper:

Evaluates expressions without parentheses

Only +, -, digits

So:

evalSimple("3+4") → 7

🔹 Step 5: Replace (expression) with result
s = s.substr(0, l) + to_string(val) + s.substr(r + 1);

What this means

We rebuild the string:

Part	Meaning
s.substr(0, l)	Everything before (
to_string(val)	Evaluated result
s.substr(r + 1)	Everything after )
Example
Before: "1+(2-3)"
After:  "1+-1"


The parentheses are gone.

🔹 Step 6: Loop continues

The while loop repeats until:

s.find('(') == string::npos


Now s contains no parentheses.

🔹 Step 7: Final evaluation
return evalSimple(s);


At this point:

s = "1+-1"


evalSimple handles this easily and returns 0.

🔹 Complete flow example
Input
"1 + (2 - (3 + 4))"

Steps
"1+(2-(3+4))"
→ "1+(2-7)"
→ "1+-5"
→ -4


*/

//___________________________________________________________________________________________________________________________________________
// Some questions
//___________________________________________________________________________________________________________________________________________
/*

Q1. is l exclding here s.substr(0, l)

Yes — l is excluded in this call 👇
s.substr(0, l)

Q2.
and here last is not given so it will go uptp n and n is excluded here s.substr(r + 1);

ans: Yes — your understanding is 100% correct ✅

Q3.
will this return index or iterator s.find(')');
ans:It returns an index (position), NOT an iterator.

Q4.if this return index then why here we are checking it with string ::npos , shoudnt it be checking with size n s.find('(') != string::npos

ans:
string::npos means “not found”, not “last index”.
We do NOT compare with n because:
n can be a valid index
npos is a special sentinel value
1️⃣ What exactly is string::npos?
string::npos
npos = 18446744073709551615
This value can never be a valid index.
if found it returns index and if not then it returns npos value.

We are getting inside loop only when we are getting opening parenthesis and so here npos is fine. And inside loop if there is
opening parenthesis  then there must be closing parenthesis also so we can safely store it in int.


Q5.
why this is not like s.substr(l+1, r)); insted it is int val = evaluateParenthesis(s.substr(l+1, r-l-1));. is it because we have to give
how many chars as end and not the index as end

ans:Exactly ✅ — you’ve got the idea. Let me explain clearly.
substr signature
string substr(size_t pos, size_t len)
pos → starting index (included)
len → number of characters (count), not the ending index
So, substr(l+1, r) would be wrong because it interprets r as “length,” not “ending index.”

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
| Aspect    | Complexity | Explanation                                                                                                                               |
| --------- | ---------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| **Time**  | O(n²)      | Each iteration of the while loop rebuilds the string using `substr` + `+` + `to_string`. Worst case: nested parentheses in a long string. |
| **Space** | O(n)       | Rebuilding strings, storing substrings. The maximum space needed is linear in input size.                                                 |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This is a brute-force approach for Basic Calculator (LC224):
Remove all spaces from the input string.
Iteratively evaluate innermost parentheses
Find the first ')'
Find the matching '(' going left
Extract the substring inside
Evaluate the simple expression (+ and - only) inside
Replace the parentheses with the computed value
After all parentheses are gone, evaluate the remaining flat expression.
Return the final integer result.
Key idea: Brute-force simplifies innermost expressions first, like humans would, rather than using a stack to track context.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Helper function to evaluate flat expressions (no parentheses)
    int evaluateParenthesis(string s)
    {
        long long num = 0;      // current number being built
        int sign = 1;           // current sign (+1 or -1)
        long long res = 0;      // cumulative result

        for (auto &ch : s)
        {
            if (isdigit(ch))
            {
                num = num * 10 + (ch - '0'); // build multi-digit numbers
            }
            else if (ch == '+')
            {
                res += sign * num;   // add previous number
                num = 0;
                sign = 1;            // next number is positive
            }
            else if (ch == '-')
            {
                res += sign * num;   // add previous number
                num = 0;
                sign = -1;           // next number is negative
            }
        }
        res += sign * num;           // add last number
        return (int)res;
    }

    int calculate(string s)
    {
        // Step 1: Remove spaces
        auto startIterator = remove(s.begin(), s.end(), ' ');
        s.erase(startIterator, s.end());

        // Step 2: Resolve innermost parentheses iteratively
        while (s.find('(') != string::npos)
        {
            int r = s.find(')');   // first closing parenthesis
            int l = r;

            // find matching '('
            while (l >= 0 && s[l] != '(')
                l--;

            // evaluate expression inside parentheses
            int val = evaluateParenthesis(s.substr(l + 1, r - l - 1));

            // replace "(expression)" with result
            s = s.substr(0, l) + to_string(val) + s.substr(r + 1);
        }

        // Step 3: Evaluate the remaining flat expression
        return evaluateParenthesis(s);
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
