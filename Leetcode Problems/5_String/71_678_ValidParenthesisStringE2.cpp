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

class Solution
{
public:
    bool checkValidString(string s)
    {
        int open = 0;
        int close = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '*')
                open++;
            else
                open--;
            if (open < 0)
                return false;
        }

        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
                close++;
            else
                close--;
            if (close < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "*(())(*";
    cout << sol.checkValidString(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n) time 
O(1) space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The key observation:

A '*' can be '(', ')', or an empty string.

We just need to ensure that at no point do we have too many closing brackets when scanning from left to right,
and too many opening brackets when scanning from right to left.

So, we perform two scans:

Left → Right scan:
Assume each '*' acts like '(' (so we have maximum possible opens).
→ If we ever have more ')' than possible '(', return false.

Right → Left scan:
Assume each '*' acts like ')' (so we have maximum possible closes).
→ If we ever have more '(' than possible ')', return false.

If both scans are valid, the string can be balanced.


*/


//___________________________________________________________________________________________________________________________________________
// Logic
//___________________________________________________________________________________________________________________________________________

/*

If open bracket count is 4 and closing bracket count is 2 after both traversal then dont worry because the * is assumed as open bracket
or close bracket. That should have been considered empty but it doesnt matter.
The main thing is at any point the open or close count should not become zero because that is invalid brackets ,for ex.
)(. Now this become -1 means the brackets were not in proper format. 

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool checkValidString(string s)
    {
        int open = 0, close = 0;

        // Pass 1: Left to Right
        // Treat '*' as '(' to maximize open brackets.
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '*')
                open++;    // potential open bracket
            else
                open--;    // closing one open bracket

            if (open < 0)
                return false; // too many ')' — impossible
        }

        // Pass 2: Right to Left
        // Treat '*' as ')' to maximize close brackets.
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')' || s[i] == '*')
                close++;   // potential closing bracket
            else
                close--;   // closing one opening bracket

            if (close < 0)
                return false; // too many '(' — impossible
        }

        // If both passes succeed, it's valid
        return true;
    }
};



*/
