/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

What does # (backspace) mean?

# deletes the nearest character before it, if any

If there is no character before it, it does nothing

Example:
"a#c"
Process:
a → add a
# → delete a
c → add c
Final result: "c"
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
    bool backspaceCompare(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        stack<char> st1;
        stack<char> st2;

        for (auto &ch : s)
        {
            if (ch == '#')
            {
                if (!st1.empty())
                    st1.pop();
            }
            else
            {
                st1.push(ch);
            }
        }
        for (auto &ch : t)
        {
            if (ch == '#')
            {
                if (!st2.empty())
                    st2.pop();
            }
            else
            {
                st2.push(ch);
            }
        }

        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }
        return st1.empty() && st2.empty();
    }
};

int main()
{
    Solution sol;
    string s = "ab#c";
    string t = "ad#c";
    cout << sol.backspaceCompare(s, t);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Processing s → O(n)
Processing t → O(m)
Comparison → O(min(n, m))
✅ Overall: O(n + m)

Space Complexity
Two stacks storing characters
✅ O(n + m)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Core idea
Each string represents text typed into an editor where:
letters are added
# acts as a backspace
To simulate this behavior:
Use a stack
Push characters when typing
Pop characters when backspace (#) appears
After processing both strings:
Compare the final content character by character
If identical → return true
Otherwise → return false


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        // Stacks to store processed characters
        stack<char> st1;
        stack<char> st2;

        // Process string s
        for (auto &ch : s)
        {
            if (ch == '#')
            {
                // Backspace: remove previous character if exists
                if (!st1.empty())
                    st1.pop();
            }
            else
            {
                // Normal character: add to stack
                st1.push(ch);
            }
        }

        // Process string t
        for (auto &ch : t)
        {
            if (ch == '#')
            {
                // Backspace: remove previous character if exists
                if (!st2.empty())
                    st2.pop();
            }
            else
            {
                // Normal character: add to stack
                st2.push(ch);
            }
        }

        // Compare both processed strings
        while (!st1.empty() && !st2.empty())
        {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }

        // Both must be empty to be equal
        return st1.empty() && st2.empty();
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Stack Simulation / Undo Operation Pattern


*/
