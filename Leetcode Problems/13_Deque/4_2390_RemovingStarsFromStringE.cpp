/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.


Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        int n = s.length();
        string res = "";

        for (auto ch : s)
        {
            if (ch != '*')
                res.push_back(ch);
            else
                res.pop_back();
        }
        return res;
    }
};
int main()
{
    Solution sol;
    string s = "leet**cod*e";
    cout << sol.removeStars(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
Time
O(n)
Each character is processed once.

Space
O(n)
Result string acts as a stack.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key observation

Every '*' removes the closest non-star character before it
This is Last In, First Out behavior → Stack
Strategy
Traverse the string from left to right
Use a container (string res) as a stack
Normal character → push into res
'*' → remove last character from res
LeetCode guarantees the pop is always valid.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    string removeStars(string s)
    {
        int n = s.length();

        // This string works like a stack
        string res = "";

        // Traverse the input string
        for (auto ch : s)
        {
            // If it's a normal character, add it
            if (ch != '*')
                res.push_back(ch);
            else
                // If it's '*', remove the last added character
                // Guaranteed safe by problem constraints
                res.pop_back();
        }

        // The final string after all removals
        return res;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
🧩 Pattern used
Stack pattern
Implemented using a string (very common in interviews)



*/
