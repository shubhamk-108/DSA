/*
Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5

operators allowed: +,-,*,/.
Parenthesis not allowed.

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
        int current_num = 0;
        int last_num = 0;
        int res = 0;
        int last_operator = '+';

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                current_num = current_num * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i])) && s[i] != ' ' || i == s.length() - 1)
            {
                if (last_operator == '+' || last_operator == '-')
                {
                    res += last_num;
                    last_num = (last_operator == '+') ? current_num : -current_num;
                }
                if (last_operator == '*')
                {
                    last_num = last_num * current_num;
                }
                if (last_operator == '/')
                {
                    last_num = last_num / current_num;
                }

                last_operator = s[i];
                current_num = 0;
            }
        }
        res += last_num;
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "4+8*3/2+1";
    cout << sol.calculate(s);
    return 0;
}

//______________________________________________________________________________________________________________________
// Timespace
//______________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
→ We traverse the string once and perform constant-time operations for each character.
Space Complexity: O(1)
→ Only a few integer variables are used.
(No stack or extra arrays.)

*/

//______________________________________________________________________________________________________________________
// Approach
//______________________________________________________________________________________________________________________

/*


We maintain three variables:

current_num: number currently being formed.
last_num: result of the last multiplication/division (or the last processed number for + / -).
res: cumulative result (sum of all processed terms except the last one).
We also keep track of the last_operator seen (+, -, *, /).
As we traverse the string:
Build current_num for continuous digits.
When an operator or end of string is reached:
Apply the previous operator (last_operator) to last_num and current_num:
If + or -: add last_num to result, then set last_num = ±current_num.
If * or /: update last_num directly with multiplication or division.
Reset current_num and update last_operator to the new one.
After the loop, add last_num to res (for the final number).
This approach works because last_num holds the latest high-precedence term (for * and /), and res stores the final accumulated sum.

*/

//______________________________________________________________________________________________________________________
// Code
//______________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int calculate(string s)
    {
        int current_num = 0;  // Current number being formed
        int last_num = 0;     // Last processed number (handles * and / precedence)
        int res = 0;          // Final result accumulator
        char last_operator = '+'; // Tracks the last operator seen

        for (int i = 0; i < s.length(); i++)
        {
            // Build current number
            if (isdigit(s[i]))
                current_num = current_num * 10 + (s[i] - '0');

            // When an operator or end of string is reached
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
            {
                if (last_operator == '+' || last_operator == '-')
                {
                    // Add last_num to result before starting a new term
                    res += last_num;
                    // Set new last_num depending on operator sign
                    last_num = (last_operator == '+') ? current_num : -current_num;
                }
                else if (last_operator == '*')
                {
                    // Multiply current number with previous last_num
                    last_num = last_num * current_num;
                }
                else if (last_operator == '/')
                {
                    // Divide current number with previous last_num (integer division)
                    last_num = last_num / current_num;
                }

                // Update operator for next iteration
                last_operator = s[i];
                current_num = 0; // Reset current number
            }
        }

        // Add final number to result
        res += last_num;

        return res;
    }
};



*/

