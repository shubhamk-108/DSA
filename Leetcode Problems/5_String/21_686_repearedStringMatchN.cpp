/*

Given two strings a and b, find the minimum number of times a has to be repeated such that b becomes a substring of the repeated a. If b cannot be a substring of a no matter how many times it is repeated, return -1.

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: After repeating a three times,
we get "abcdabcdabcd".
Example 2:

Input: a = "aa", b = "a"
Output: 1
Explanation: B is already a substring of a.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:

    int repeatedStringMatch(string a, string b)
    {
        int n1 = a.length();
        int n2 = b.length();

        int count = 1;
        string repeat_str_a = a;

        while (repeat_str_a.length() < b.length())
        {
            repeat_str_a += a;
            count++;
        }

        if (repeat_str_a.find(b) != string ::npos)
            return count;

        repeat_str_a += a;
        count++;

        if (repeat_str_a.find(b) != string ::npos)
            return count;

        return -1;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcd";
    string s2 = "cdabcdab";

    cout << sol.repeatedStringMatch(s1, s2);
    return 0;
}



// timespace:

/*

Time Complexity: O((N + M) * M)
n is text length that is string 'a'
m is pattern length that is string 'b'.

String Creation: The while loop runs to make repeat_str_a have a length of at least M. In the worst case, the final length of repeat_str_a will 
be less than M + 2N. The complexity of building this string is roughly O(M + N).

string::find: The C++ string::find method, in its typical implementation, performs a brute-force substring search. The worst-case complexity of 
searching for a pattern of length M in a text of length N is O(N * M).

Combined: Since N (the length of repeat_str_a) is O(M + N), the search operation dominates the time complexity. Therefore, the total time complexity 
is O((M + N) * M).

O(N * M) of find function will dominate over O(N + M) of repeatedStringMatch function while loop.
So we take dominated time complexity and O(N * M). Here N is length of text and M is length of pattern. Our string 'a' that is text 
is keep on adding. So string 'a'  length is at least O(m+n). So we substitute this  O(m+n) in O(n*m) and it becomes O(m+n) * m as total time 
complexity.

Note: Why repeatedStringMatch function having time complexity as O((N + M) is explained in efficient solution of same problem, 
22_686_repearedStringMatchE.






*/


// logic

/*

The logic is sound and correctly follows the required strategy:

Build a Candidate String: You start with repeat_str_a = a and keep appending a until repeat_str_a is at least as long as b. This is the 
minimum possible length the repeated string could be to contain b.
Handle the Boundary Case: You correctly identify that b might span across the seam of two a strings. By adding a one more time 
(repeat_str_a += a;), you create a string that is guaranteed to contain b if it's possible at all.

Use string::find: The string::find method is a built-in C++ function that searches for a substring. string::npos is a constant that is 
returned when the substring is not found. Your use of if (repeat_str_a.find(b) != string::npos) is the standard way to check for substring existence.

*/


// code:

/*

int repeatedStringMatch(string a, string b) {
    string temp_a = a;
    int count = 1;

    // 1. Build the string until it's at least as long as b.
    while (temp_a.length() < b.length()) {
        temp_a += a;
        count++;
    }

    // 2. First check: Is b in the current string?
    if (temp_a.find(b) != string::npos) {
        return count;
    }

    // 3. Second check: Add 'a' one more time for the boundary case.
    temp_a += a;
    if (temp_a.find(b) != string::npos) {
        return count + 1;
    }

    // 4. If not found after both checks, it's impossible.
    return -1;
}



*/