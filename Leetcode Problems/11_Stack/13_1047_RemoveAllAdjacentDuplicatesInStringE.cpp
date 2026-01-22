/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.



Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
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
    string removeDuplicates(string s)
    {
        int n = s.length();
        string res = "";
        for (auto &ch : s)
        {
            if (!res.empty())
            {
                if (res.back() == ch)
                    res.pop_back();
                else
                    res.push_back(ch);
            }
            else
                res.push_back(ch);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
🔹 Time Complexity
O(n)
Each character is pushed and popped at most once.

🔹 Space Complexity
O(n)
In the worst case (no duplicates), all characters are stored in res.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The idea is to remove adjacent duplicate characters repeatedly until no such duplicates remain.
Key Insight
If two adjacent characters are the same, tey should be removed.
A stack-like behavior works perfectly here.
Instead of using an explicit stack, you used a string (res) as a stack:
Traverse the input string character by character.
If the current character is the same as the last character in res, remove the last character.
Otherwise, add the current character to res.
At the end, res contains the final string with all adjacent duplicates removed.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    string removeDuplicates(string s)
    {
        int n = s.length();   // Length of the string (not strictly needed here)
        string res = "";      // Acts as a stack to store the result

        // Iterate through each character in the string
        for (auto &ch : s)
        {
            // If res is not empty, compare with the last character
            if (!res.empty())
            {
                // If current character is same as last character,
                // remove the last character (duplicate pair)
                if (res.back() == ch)
                    res.pop_back();
                else
                    // Otherwise, push the current character
                    res.push_back(ch);
            }
            else
            {
                // If res is empty, just push the character
                res.push_back(ch);
            }
        }

        // Final string after removing all adjacent duplicates
        return res;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

res behaves exactly like a stack:
push_back() → push
pop_back() → pop
Commonly used in problems involving:
Adjacent comparisons
Undoing previous characters


*/
