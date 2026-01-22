/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
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
    string decodeString(string s)
    {

        int n = s.length();

        while (s.find('[') != string::npos)
        {
            int closeIdx = s.find(']');
            int openIdx = closeIdx;

            while (s[openIdx] != '[')
                openIdx--;

            int kIdx = openIdx - 1;
            while (kIdx >= 0 && isdigit(s[kIdx]))
                kIdx--;

            int repeat = stoi(s.substr(kIdx + 1, openIdx - kIdx - 1));
            string token = s.substr(openIdx + 1, closeIdx - openIdx - 1);

            string repeatedString = "";
            for (int i = 0; i < repeat;  i++)
                repeatedString += token;
            
            s = s.substr(0, kIdx + 1) + repeatedString + s.substr(closeIdx + 1);
            
        }

        return s;
    }
};

int main()
{
    Solution sol;
    string s = "2[a3[c2[x]]y]";
    cout << sol.decodeString(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*


⏱ Time Complexity
O(N² × K) (worst case)
Each replacement creates a new string
Nested replacements increase cost

🧠 Space Complexity
O(N)
New strings created during replacement
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key observation
Always decode the innermost k[substring] first
Replace it with its expanded form
Repeat until no brackets remain

Brute-Force Algorithm
While the string contains '[':
Find the first closing bracket ]
Scan left to find its matching '['
Extract:
Repeat count k
Inner substring
Build expanded string
Replace k[substring] in the original string
When no brackets are left, return the string

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    string decodeString(string s)
    {
        // Keep decoding until no brackets remain
        while (s.find('[') != string::npos)
        {
            int close = s.find(']');
            int open = close;

            // Find matching '['
            while (s[open] != '[')
                open--;

            // Find the number before '['
            int numStart = open - 1;
            while (numStart >= 0 && isdigit(s[numStart]))
                numStart--;

            int repeat = stoi(s.substr(numStart + 1, open - numStart - 1));
            string inner = s.substr(open + 1, close - open - 1);

            // Build expanded string
            string expanded = "";
            for (int i = 0; i < repeat; i++)
                expanded += inner;

            // Replace k[inner] with expanded string
            s = s.substr(0, numStart + 1) +
                expanded +
                s.substr(close + 1);
        }

        return s;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
