/*
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.



Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
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

// This is not a stack question
class Solution
{
public:
    string makeGood(string s)
    {
        int n = s.length();
        string res = "";

        for (int i = 0; i < n; i++)
        {
            if (!res.empty())
            {
                if (abs(s[i] - res.back()) == 32)
                {
                    res.pop_back();
                }
                else
                    res.push_back(s[i]);
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string s = "leEeetcode";
    cout << sol.makeGood(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n)
Each character is pushed once
Each character is popped at most once

💾 Space Complexity
O(n)
Required to store the resulting string
This is unavoidable (output itself needs space)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We process the string left to right
We use the result string res as a stack
For each character:
Compare it with the last character added (res.back())
If they are the same letter but opposite case, remove the last character
Otherwise, add the current character
This automatically handles chain reactions (new adjacent bad pairs)
Key insight:
In ASCII, lowercase and uppercase of the same letter differ by 32


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    string makeGood(string s)
    {
        int n = s.length();
        string res = "";   // acts like a stack

        for (int i = 0; i < n; i++)
        {
            // if res is not empty, check for bad pair
            if (!res.empty())
            {
                // same letter, opposite case → remove
                if (abs(s[i] - res.back()) == 32)
                {
                    res.pop_back();
                }
                else
                {
                    // otherwise, keep the character
                    res.push_back(s[i]);
                }
            }
            else
            {
                // res empty → just push
                res.push_back(s[i]);
            }
        }
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Stack-based adjacent cancellation / string reduction
Common in:
LC 1544 – Make The String Great
LC 1047 – Remove All Adjacent Duplicates
LC 844 – Backspace String Compare (stack version)


*/
