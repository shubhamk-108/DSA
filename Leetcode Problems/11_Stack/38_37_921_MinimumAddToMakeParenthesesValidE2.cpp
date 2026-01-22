/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.



Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3


Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'
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
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int depth = 0;
        int minAdd = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                depth++;
            }
            else
            {
                depth--;
                if (depth == -1)
                {
                    minAdd++;
                    depth = 0;
                }
            }
        }
        minAdd += depth;

        return minAdd;
    }
};

int main()
{
    Solution sol;
    string s = "))((";
    cout << sol.minAddToMakeValid(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(n) — single pass through the string

💾 Space Complexity
O(1) — constant extra space
✅ This is optimal
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We track the current balance (depth) of parentheses.
'(' increases balance
')' decreases balance.
If balance becomes negative, it means there is an extra closing parenthesis:
We need to add one '('
Increment minAdd
Reset balance to 0
After processing the entire string:
Any remaining positive balance means unmatched '('
Each unmatched '(' needs one ')'
The total additions required is the sum of:
Extra '(' needed for invalid ')'
Extra ')' needed for remaining '('


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();     // Length of the input string
        int depth = 0;          // Tracks current balance of parentheses
        int minAdd = 0;         // Number of parentheses to add

        // Traverse the string
        for (int i = 0; i < n; i++)
        {
            // Opening parenthesis increases balance
            if (s[i] == '(')
            {
                depth++;
            }
            else // Closing parenthesis
            {
                depth--;

                // If balance becomes negative,
                // we have an unmatched ')'
                if (depth == -1)
                {
                    minAdd++;   // Add one '(' to fix it
                    depth = 0;  // Reset balance
                }
            }
        }

        // Any remaining '(' need to be closed
        minAdd += depth;

        return minAdd; // Minimum insertions needed
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Balance / Depth Counting Pattern (Greedy Parentheses Validation)

*/
