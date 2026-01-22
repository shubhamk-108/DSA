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
        stack<int> countSt;
        stack<string> tokenSt;
        string curr = "";
        int k = 0;


        for (char ch : s)
        {
            if (isdigit(ch))
            {
                k = k * 10 + (ch - '0');
                
            }
            else if (ch == '[')
            {
                countSt.push(k);
                k = 0;
                tokenSt.push("[");
                
            }
            else if (ch == ']')
            {
               
                string subToken = "";
                while (!tokenSt.empty() && tokenSt.top() != "[")
                {
                    subToken =  tokenSt.top() + subToken;
                    tokenSt.pop();
                }
                if(!tokenSt.empty() && tokenSt.top() == "[")
                    tokenSt.pop();
                int repeat = countSt.top();
                countSt.pop();
                
                string repeatedString = "";
                for (int i = 0; i < repeat; i++)
                {
                    repeatedString+=subToken;
                }
                
                tokenSt.push(repeatedString);
            }
            else
            {
                tokenSt.push(string(1, ch));
            }
        }
        string finalString = "";
        
        while(!tokenSt.empty())
        {
            finalString = tokenSt.top() + finalString;
            tokenSt.pop();
        }
        return finalString;
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
// convert or Push  char as string into stack
//___________________________________________________________________________________________________________________________________________
/*

tokenSt.push(string(1, ch));
or
tokenSt.push(std::string() + ch);
or
tokenSt.emplace(1, ch);


basic_string(size_type count, CharT ch);
Meaning
1 → number of times

ch → character to repeat

Result

string(1, 'a')  →  "a"
string(3, 'x')  →  "xxx"
Full line meaning

tokenSt.push(string(1, ch));

---

tokenSt.push(std::string() + ch);
Syntax breakdown
std::string()


Default constructor → creates an empty string ""

std::string() + ch


Uses operator+ overload

Which operator is called?
std::string operator+(const std::string&, char);

Step-by-step
"" + 'a'  →  "a"
"" + 'z'  →  "z"

Full line meaning
tokenSt.push(std::string() + ch);



*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
O(N × K)
N = length of string
K = maximum repetition count
Repeating strings dominates runtime

🧠 Space Complexity
O(N)
Stacks + result string in worst case

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This problem is about decoding nested encoded strings like:
3[a2[c]] → accaccacc
Key ideas
Numbers tell how many times to repeat a substring
[ starts a new encoded block
] ends a block and triggers expansion
Nested blocks must be handled LIFO, so we use stacks
Data structures used
countSt → stores repetition counts
tokenSt → stores string tokens and "[" as a boundary marker
Flow
Read characters one by one
Build multi-digit numbers
On '[' → save count and mark boundary
On ']' → build substring, repeat it, push back
At the end → merge everything into the final string

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
        int n = s.length();

        // Stack to store repeat counts (k)
        stack<int> countSt;

        // Stack to store string tokens and "[" as a marker
        stack<string> tokenSt;

        int k = 0; // current number being parsed

        for (char ch : s)
        {
            // If digit, build multi-digit number
            if (isdigit(ch))
            {
                k = k * 10 + (ch - '0');
            }
            // Opening bracket: save count and mark new block
            else if (ch == '[')
            {
                countSt.push(k);
                k = 0;
                tokenSt.push("[");
            }
            // Closing bracket: decode the current block
            else if (ch == ']')
            {
                // Collect substring inside the brackets
                string subToken = "";
                while (!tokenSt.empty() && tokenSt.top() != "[")
                {
                    subToken = tokenSt.top() + subToken;
                    tokenSt.pop();
                }

                // Remove "[" marker
                tokenSt.pop();

                // Get repetition count
                int repeat = countSt.top();
                countSt.pop();

                // Repeat the substring
                string repeatedString = "";
                for (int i = 0; i < repeat; i++)
                {
                    repeatedString += subToken;
                }

                // Push expanded string back
                tokenSt.push(repeatedString);
            }
            // Normal character
            else
            {
                tokenSt.push(string(1, ch));
            }
        }

        // Build final answer from stack
        string finalString = "";
        while (!tokenSt.empty())
        {
            finalString = tokenSt.top() + finalString;
            tokenSt.pop();
        }

        return finalString;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Stack-based Parsing
Also known as:
Decode String pattern
Nested structure evaluation
Expression parsing using stacks

*/
