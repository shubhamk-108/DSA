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
        stack<int> open_index;
        stack<int> asterisk_index;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                open_index.push(i);
            else if (s[i] == ')')
            {
                if (!open_index.empty())
                    open_index.pop();
                else
                {
                    if (!asterisk_index.empty())
                        asterisk_index.pop();
                    else
                        return false;
                }
            }
            else
                asterisk_index.push(i);
        }

        while (!open_index.empty() && !asterisk_index.empty())
        {
            if (open_index.top() < asterisk_index.top())
            {
                asterisk_index.pop();
                open_index.pop();
            }
            else
                return false;
        }
        return open_index.empty();
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

Time Complexity
O(n) — each character is pushed/popped once.
Space Complexity
O(n) — two stacks store indices.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Idea:
We need to check if a string with '(', ')', and '*' can form a valid parenthesis sequence.
'*' can be treated as '(', ')', or empty.

Steps:
Use two stacks:
open_index → stores indices of '(' characters.
asterisk_index → stores indices of '*' characters.
Traverse the string from left to right:
If '(' → push index to open_index.
If '*' → push index to asterisk_index.
If ')' → try to match:
Pop from open_index first (prefer real '(').
If empty, pop from asterisk_index (treat '*' as '(').
If both empty → invalid → return false.
After traversal, there may still be unmatched '(' in open_index.
Try to match each '(' with a '*' that occurs after it:
If open_index.top() < asterisk_index.top() → pop both.
Else → invalid → return false.
Finally, if open_index is empty → valid string → return true.
Otherwise → return false.


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
        stack<int> open_index;      // Stores indices of '('
        stack<int> asterisk_index;  // Stores indices of '*'

        // Step 1: Traverse the string
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                open_index.push(i);  // Push '(' index
            
            // when we see closing bracket then if it has corresponding openeing bracket in stack then this is valid so pop open bracket and 
            // this bracket is done now. But if we dont havecorreponding open bracket in stack then we have to check if there is 
            // asterisk present. If the asterisk is present,it can act as opening bracket and this astersik index should be before
            // current closing bracket and only then it is valid. THis is already taken care of as asterisk is already push in 
            // previous iterations. If no asterisk also, then return false.
            else if (s[i] == ')')
            {
                if (!open_index.empty())
                    open_index.pop();          // Match with '(' if possible
                else if (!asterisk_index.empty())
                    asterisk_index.pop();     // Otherwise use '*' as '('
                else
                    return false;             // No '(' or '*' available → invalid
            }
            // if currnet character is '*' then push its index to stack.
            else
                asterisk_index.push(i);       // Push '*' index
        }

    
        // Step 2: Match remaining '(' with '*' that occur after them.
        // after traversing all characters, if there are still open brackets left in the stack then we need to check them.
        // to make this open brackets valid we need asterisk working as closing bracket but we need to make sure that this asterisk
        // occurs after the index of opening bracket like ( and then * becomes (). But if we have asterisk present before the index 
        // of open bracket like * ( then this becomes )( which is invalid.
        while (!open_index.empty() && !asterisk_index.empty())
        {
            if (open_index.top() < asterisk_index.top())
            {
                open_index.pop();
                asterisk_index.pop();
            }
            else
                return false;  // '*' appears before '(' → cannot match
        }

        // Step 3: If any '(' left unmatched → invalid
        return open_index.empty();
    }
};





*/
