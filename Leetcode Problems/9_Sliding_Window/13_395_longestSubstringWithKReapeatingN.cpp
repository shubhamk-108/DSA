/*
395. Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
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

// This Q is not part of sliding window. Still I kept this in sliding window and to know that why this Q doesnt belong to sliding window.
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++)
            {
                freq[s[j]]++;

                bool valid = true;
                for (auto ch : freq)
                {
                    if (ch.second < k)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};



int main()
{
    Solution sol;
    string s = "aaabb";

    cout << sol.longestSubstring(s, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n³) worst-case
Two loops for all substrings → O(n²)
Validation loop inside → O(n) or O(26) depending on map size

So: O(n³)
Space Complexity: O(1) or O(26)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Generate every possible substring s[i…j].
Count the frequency of characters inside that substring.
Check if all characters appear at least k times.
If yes → update the maximum length

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;

        // Try all possible starting points
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;

            // Try all possible ending points
            for (int j = i; j < n; j++)
            {
                // Add current character to our freq map
                freq[s[j]]++;

                // Check whether current substring is valid
                bool valid = true;
                for (auto &entry : freq)
                {
                    // If any character appears less than k times → invalid
                    if (entry.second < k)
                    {
                        valid = false;
                        break;
                    }
                }

                // If valid → update answer
                if (valid)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
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



❌ Not sliding windows
Because we require:
"all characters appear at least k times in the substring"
This condition cannot be tested by adding/removing one character only.
Sliding window works only when a condition stays monotonic when expanded/contracted (like “at most K distinct characters”).
Here, the substring often becomes invalid again later → not sliding window.

✔ Brute Force Enumeration of Substrings
This is a pure brute-force solution using:
“All Substrings Enumeration” + Frequency Counting
*/
