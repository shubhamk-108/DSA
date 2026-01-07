/*
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.

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
    int numSub(string s)
    {

        long long count = 0;

        int start;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')
                {
                    count += 1;
                    count %= 1000000007;
                }
                else
                    break;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    string s = "1110011100";
    cout << sol.numSub(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:
O(n²) — for each i, inner loop may go up to n (worst case when all are '1').

Space Complexity:
O(1) — only uses a few integer variables (no extra data structures).


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

You need to count all substrings of s that contain only '1'.
For every possible starting index i, you extend the substring towards the right (j = i...n-1).
As long as you keep seeing '1', increment the count.
When you hit a '0', break — because any longer substring starting at i will be invalid.
Take modulo 1e9 + 7 to avoid overflow.
This checks every possible substring starting at each i → that’s why it’s the brute-force way.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int numSub(string s)
    {
        long long count = 0;      // to store the total count of valid substrings
        int n = s.length();        // length of input string

        // Outer loop: try every starting index
        for (int i = 0; i < n; i++)
        {
            // Inner loop: extend substring from i to j
            for (int j = i; j < n; j++)
            {
                if (s[j] == '1')   // substring s[i..j] is still valid (only 1s)
                {
                    count += 1;    // count this substring
                    count %= 1000000007;  // mod to handle large results
                }
                // if we dont break here then consider ....00011 the output should be 2 here and it should only count when it sees 1
                // but if we dont break it at 0 then for every 0 the 1 is counting or all the 1 till the last will be counted for 
                // every 0.
                else
                    break;         // stop if '0' appears (invalid beyond this point)
            }
        }

        return count;              // total number of substrings made of '1's
    }
};


*/
