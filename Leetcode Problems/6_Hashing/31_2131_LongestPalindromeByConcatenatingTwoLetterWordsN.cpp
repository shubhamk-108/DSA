/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be
selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.



Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".

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
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();
        vector<bool> used(n, false); // tracks which words are already paired
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());

            for (int j = i + 1; j < n; j++)
            {
                if (!used[j] && reverseWord== words[j])
                {
                    maxLen += 4;
                    used[i] = true;
                    used[j] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!used[i] && words[i][0] == words[i][1])
            {
                maxLen += 2;
                break;
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<string> v = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << sol.longestPalindrome(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n²)
Nested loop to check reverse matches → n × n
Final center-search loop is O(n)
Total dominated by O(n²) → Bruteforce
Space Complexity: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


You loop through each word i.
Create its reverse.
Search linearly for a future word j that:
is unused
equals the reverse
If found → pair them → add 4 to palindrome length.
After all pairs, make one more pass:
Look for any unused word like "aa", "bb", "cc"…
Use exactly one of them for the center → add 2.
Return the maximum length.
This is pure brute force because for every word you scan all remaining words → O(n²).

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();
        vector<bool> used(n, false); // keeps track of which words have already been used
        int maxLen = 0;

        // STEP 1: Pair reverse words using brute-force O(n^2) search.
        for (int i = 0; i < n; i++)
        {

            if (used[i]) continue;  // skip already used words

            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());  // compute reverse of words[i]

            // try to find a matching reverse word at a higher index
            for (int j = i + 1; j < n; j++)
            {
                // match only unused words
                if (!used[j] && reverseWord == words[j])
                {
                    maxLen += 4;     // each pair contributes length = 4
                    // there is another loop of i from the start in step 2. For that we are making this i as used. Otherwise we dont have to
                    because i is visited only once here.
                    used[i] = true;  // mark both as used
                    used[j] = true;
                    break;           // stop after finding one pair
                }
            }
        }

        // STEP 2: Check if there is any unused symmetric word like "aa", "bb", ...
        for (int i = 0; i < n; i++)
        {
            // symmetric words can stay in the center
            if (!used[i] && words[i][0] == words[i][1])
            {
                maxLen += 2;  // only one such center allowed
                break;
            }
        }

        return maxLen;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
You are literally checking all pairs i, j



*/
