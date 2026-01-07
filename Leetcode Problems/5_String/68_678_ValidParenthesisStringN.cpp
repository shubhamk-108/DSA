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
    bool solve(string s, int n, int open_bracket_count, int i)
    {
        if (open_bracket_count < 0)
            return false;

        if (i == n)
            return open_bracket_count == 0;

        if (s[i] == '(')
            return solve(s, n, open_bracket_count + 1, i + 1);

        else if (s[i] == ')')
            return solve(s, n, open_bracket_count - 1, i + 1);

        else if (s[i] == '*')
        {
            return solve(s, n, open_bracket_count + 1, i + 1) ||
                   solve(s, n, open_bracket_count, i + 1) ||
                   solve(s, n, open_bracket_count - 1, i + 1);
        }

        return false;
    }
    bool checkValidString(string s)
    {
        int open = 0;

        return solve(s, s.length(), open, 0);
    }
};

int main()
{
    Solution sol;
    string s = "(*))";
    cout << sol.checkValidString(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Each '*' causes 3 recursive branches.
In the worst case (all *), there are 3ⁿ possibilities.
👉 O(3ⁿ)

💾 Space Complexity
The recursion stack depth is proportional to the string length.
👉 O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We explore all possible interpretations of * — it can act as:

'('

')'

or an empty string.
We keep track of open_bracket_count, i.e., how many '(' are currently unmatched.
For each character:
If '(' → increment open count
If ')' → decrement open count (and if it becomes negative → invalid)
If '*' → try all 3 possibilities recursively.
When we reach the end of the string (i == n), the string is valid if and only if all open brackets are closed (open_bracket_count == 0).
This explores all possibilities, returning true as soon as one valid configuration is found.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    // Recursive helper function
    bool solve(string s, int n, int open_bracket_count, int i)
    {
        // If at any point we have more closing than opening brackets → invalid
        if (open_bracket_count < 0)
            return false;

        // Base case: reached end of string
        if (i == n)
            return open_bracket_count == 0; // Valid only if all brackets matched

        // Case 1: '(' → increase open count
        if (s[i] == '(')
            return solve(s, n, open_bracket_count + 1, i + 1);

        // Case 2: ')' → decrease open count
        else if (s[i] == ')')
            return solve(s, n, open_bracket_count - 1, i + 1);

        // Case 3: '*' → try as '(', empty, or ')'
        else if (s[i] == '*')
        {
            return solve(s, n, open_bracket_count + 1, i + 1) ||  // treat as '('
                   solve(s, n, open_bracket_count, i + 1) ||      // treat as empty
                   solve(s, n, open_bracket_count - 1, i + 1);    // treat as ')'
        }

        // Should never reach here for valid input
        return false;
    }

    bool checkValidString(string s)
    {
        return solve(s, s.length(), 0, 0);
    }
};



*/
