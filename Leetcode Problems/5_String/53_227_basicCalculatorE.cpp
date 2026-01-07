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
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num = 0;
        int last_operator = '+';

        for (int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }

            if( (!isdigit(s[i])) && s[i] != ' ' || i == s.length() -1)
            {
                if(last_operator == '+')
                    st.push(num);
                else if (last_operator == '-')
                    st.push(-num);
                else if (last_operator == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (last_operator == '/')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }

                last_operator = s[i];
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
        
    }
};

int main() {
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
We traverse the string once (O(n)), stack operations are O(1) each.
Space Complexity: O(n)
Stack may store up to n/2 numbers in worst case (every number separated by + or -).

*/


//______________________________________________________________________________________________________________________
// Approach
//______________________________________________________________________________________________________________________


/*


This is a stack-based solution for evaluating a string arithmetic expression with +, -, *, /.
Traverse the string character by character.
Build the current number (num) from consecutive digits.
When an operator or end of string is reached:
Apply the previous operator (last_operator) to num.
Push result to stack if + or -.
Pop stack, compute * or /, and push back.
After the loop, sum all values in the stack — this is the final result.
This handles operator precedence correctly (* and / before + and -) without using recursion.


When there are + or - then push into the stack
when there are * or / then compute expression then and there.
and at the end we just add the stack elements because * and / is already done so now just add the result of that numebrs.

*/


//______________________________________________________________________________________________________________________
// Code
//______________________________________________________________________________________________________________________



/*

class Solution {
public:
    int calculate(string s) {
        stack<int> st;              // Stack to handle numbers with precedence
        int num = 0;                // Current number being processed
        // why last operator is already + in the very beginning. BEcause it can not be * or /. have you seen /33+2 or *33+2 these type of 
        // equation. No. / and * can not be at start.
        // Then it must be - or +. We consider it +. Why not -. Bacause it automatically handles -. If we initially get - sign then
        // due to it is at the very beginning, we do not have num formed. So num is 0 initially. And it directly goes into if(!isgigit).
        // sign is - and num is 0 so it pushes 0 in the stack. Now last_operator becomes - and next time num will be formed correctly and 
        // then it will be pushed as -num in the stack. 
        // Ex -33 + 2 * 5. Here initially last operaor will be + but no number formed till then because we encounter  - sign at the very 
        // beginning. so we put num which is 0 in the start. then last operator becomes - and then num will formed which is 33 and 
        // then when i will be pointing to * at that time  last operator is - and num is 33 so we will push -33 to stack. 
        // And initially we pushed 0 to stack that does not matter because at the end we are just adding all the elements in the stack.
        // there also - sign is taken care of because when we were putting in the stack at that time we also pushed -num if number was negative
        // like -33.
        int last_operator = '+';    // Previous operator; initialized as '+'

        for (int i = 0; i < s.length(); i++)
        {
            // If current character is a digit, build the number
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }

            // If current character is an operator or last character of string
            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
            {
                // Apply the last operator to the current number
                if(last_operator == '+')
                    st.push(num);
                else if (last_operator == '-')
                    st.push(-num);
                else if (last_operator == '*')
                {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                }
                else if (last_operator == '/')
                {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }

                // Update last_operator to current character
                last_operator = s[i];
                num = 0;  // Reset number
            }
        }

        // Sum all numbers in stack to get final result
        int res = 0;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};



*/

