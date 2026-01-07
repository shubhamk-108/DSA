/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
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
    string reverseWords(string s)
    {
        int n = s.length();

        int start = 0;

        for (int i = 0; i <= n; i++)
        {
            if (i == n || s[i] == ' ')
            {
                int end = i - 1;

                while (start < end)
                {
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time
O(n)

Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Iterate through the string using an index i.
A word boundary occurs when:
i == n → end of string
s[i] == ' ' → space character
When you hit a boundary:
The current word is from index start to i - 1
Reverse the characters in that range using two pointers
Set start = i + 1 to mark the beginning of the next word.
Continue until the entire string is processed.
Return the modified string.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int start = 0;  // start index of the current word

        // Loop through the string including one step beyond the last index
        for (int i = 0; i <= n; i++)
        {
            // A word ends when we see a space OR when we reach the end of string
            if (i == n || s[i] == ' ')
            {
                int end = i - 1;  // end index of the current word

                // Reverse the characters of the current word
                while (start < end)
                {
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }

                // Move start to the beginning of the next word
                start = i + 1;
            }
        }

        return s;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer String Reversal (In-Place Reversal Pattern)
This is a classic pattern where:
One pointer scans the string
Another pair (start, end) is used to reverse segments
Space is saved by modifying the string directly
This same pattern is used in:
LC344 (Reverse String)
LC541 (Reverse String II)
LC186 (Reverse Words II)


*/
