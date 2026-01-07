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

        int i = 0;
        int start;
        int n = s.length();

        while (i < n)
        {
            if (s[i] == '1')
            {
                start = i;
                while (i < n && s[i] == '1')
                {
                    i++;
                }
                int len = i - start;
                count += (1LL * len * (len + 1)) / 2;
                count %= 1000000007;
            }
            else
                i++;
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

Time Complexity: O(n) → single pass.
Space Complexity: O(1) → only a few variables used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Problem: Count the number of substrings that consist of only '1' in a binary string.

Observation:

Consecutive '1's form blocks.

For a block of length L, the number of substrings is:

1 + 2 + 3 + ... + L = L ∗ ( L + 1 ) / 2
So, we can scan the string once, identify each consecutive '1' block, calculate its substrings using the formula above, and sum them up.
Steps:
Initialize count = 0.
Iterate over the string:
If current character is '1', find the length of the consecutive '1' block.
Calculate len * (len + 1)/2 and add to count.
Apply modulo 1e9 + 7 after each addition.
Return count.

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
        long long count = 0; // store total substrings (long long to prevent overflow)
        int n = s.length();
        int i = 0;

        while (i < n)
        {
            if (s[i] == '1')
            {
                int start = i; // mark the start of consecutive '1's

                // move i until the end of this block of '1's
                while (i < n && s[i] == '1')
                    i++;

                int len = i - start; // length of the consecutive '1's block

                // add number of substrings in this block
                1LL is long long to avoid integer overflow if the count is initialised as int
                len * (len + 1) could overflow int
                len is int. For long strings (like 10^5 consecutive '1's), len * (len + 1) can exceed int limit. 
                To avoid overflow, multiply by 1LL to promote calculation to long long:
                count += (1LL * len * (len + 1)) / 2;

                // keep count within modulo limits
                // this is asked in question. % 1000000007 ensures the answer stays within limits. Avoid overflow.
                count %= 1000000007;
            }
            else
            {
                i++; // move past '0'
            }
        }

        return count;
    }
};


*/
