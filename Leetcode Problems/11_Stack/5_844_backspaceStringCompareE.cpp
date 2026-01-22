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
        int i = s.size() - 1;
        int j = t.size() - 1;

        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                    break;
            }

            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }

            char charS =  i<0 ? '$' : s[i];
            char charT =  j<0 ? '$' : t[j];
            if(charS != charT)
                return false;
            i--;
            j--;
        }
        return true;
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

⏱ Time Complexity
Each character is visited once
O(n + m)

📦 Space Complexity
Only pointers and counters
O(1) (optimal)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Backspace (#) deletes the previous valid character
Instead of building final strings or using stacks:
Traverse both strings from right to left
Use counters (skipS, skipT) to track how many characters should be skipped
Compare only the valid characters
If all valid characters match → return true
This avoids extra space and gives the optimal solution.


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
        // Start from the end of both strings
        int i = s.size() - 1;
        int j = t.size() - 1;

        // Counters for backspaces
        int skipS = 0, skipT = 0;

        // Continue until both strings are fully processed
        while (i >= 0 || j >= 0)
        {
            // Process string s
            while (i >= 0)
            {
                if (s[i] == '#')
                {
                    skipS++;   // Found a backspace
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;   // Skip this character
                    i--;
                }
                else
                    break;     // Valid character found
            }

            // Process string t
            while (j >= 0)
            {
                if (t[j] == '#')
                {
                    skipT++;   // Found a backspace
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;   // Skip this character
                    j--;
                }
                else
                    break;     // Valid character found
            }

            // Compare valid characters
            char charS = (i < 0) ? '$' : s[i];
            char charT = (j < 0) ? '$' : t[j];

            if (charS != charT)
                return false;

            i--;
            j--;
        }
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer (Right-to-Left) with Skip Counter
Why this pattern work
Backspaces affect previous characters
Traversing from the end lets us:
Know exactly which characters to ignore
Avoid extra memory


*/
