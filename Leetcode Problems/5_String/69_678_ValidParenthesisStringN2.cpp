/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

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

// This code is exactly same as previous naive code. It is just that return value true or false is stored in isValid variable here.
// But this code might be useful in optimising problem using DP.
class Solution
{
public:
    bool solve(int idx, int open, string &s, int n)
    {
        // If we have processed the whole string
        if (idx == n)
            return open == 0;

        // If more closing brackets than opening — invalid
        if (open < 0)
            return false;

        bool isValid = false;

        // Case 1: current char is '*'
        if (s[idx] == '*')
        {
            // Treat '*' as ')'
            if (open > 0)
                isValid |= solve(idx + 1, open - 1, s, n);

            // Treat '*' as '('
            isValid |= solve(idx + 1, open + 1, s, n);

            // Treat '*' as empty string
            isValid |= solve(idx + 1, open, s, n);
        }
        // Case 2: current char is '('
        else if (s[idx] == '(')
        {
            isValid |= solve(idx + 1, open + 1, s, n);
        }
        // Case 3: current char is ')'
        else if (open > 0)
        {
            isValid |= solve(idx + 1, open - 1, s, n);
        }
        else
            return false;

        return isValid;
    }

    bool checkValidString(string s)
    {
        return solve(0, 0, s, s.length());
    }
};

int main()
{
    Solution sol;
    string s ="(*))";
    cout << sol.checkValidString(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*



*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


// This code is exactly same as previous naive code. It is just that return value true or false is stored in isValid variable here.
// But this code might be useful in optimising problem using DP.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


so even if we reassign isvalid = false in every fresh call, due to we are using or operator then if the function return true value then
false || true becomes true and this true is not overwritten in the next fresh call because this true has already been added in the recursion
call stack so this true is safe. is my analysis correct
Answer: Yes your analysis is correct.


Here we are checking if (open > 0) if we get closing bracket. This is because we want to make sure that if we get closing bracket,
we must have corresponding opening bracket for that to close. 
But if we dont get closing bracket then we should return false. This is correct but it seems that we havent implemented this, but 
that is not the case. we have implemented it in clean code.
Our current structure is like this.
if (s[idx] == '*')
{
    ...
}
else if (s[idx] == '(')
{
    ...
}
else if (open > 0)
{
    isValid |= solve(idx + 1, open - 1, s, n);
}
else
    return false;


This condition else if (open > 0) is written at the end. THis is for closing bracket ')'. We knew that if it is not * and not '(' then
it must be closing bracket. so we directly wrote else if (open > 0) because if that condition becomes false then we direclty goes into
else part which returns false means. this happens when there is no corrensponding openeing bracket to close. 
*/
