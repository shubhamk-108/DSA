/*

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

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
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'A'] ++;

                int currLen = j - i + 1;
                int maxFreqOfChar = 0;

                for (int p = 0; p < 26; p++)
                    maxFreqOfChar = max(maxFreqOfChar, freq[p]);

                int replacementPossible = currLen - maxFreqOfChar;

                if (replacementPossible <= k)
                    maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
int main()
{
    Solution sol;
    string s = "AABABBA";
    cout << sol.characterReplacement(s, 1);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop: n
Inner loop: n
Scan freq[26]: 26

Total:
O(n * n * 26)  →  O(n²)
Since 26 is constant.

Space Complexity
freq array = 26 integers → O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want the longest substring that can be turned into all the same letter by doing at most k replacements.
For a substring of length L:
Let maxFreq = the count of the most frequent character
To make the entire substring equal to that character:
replacementsNeeded = L - maxFreq

If this value is ≤ k → we can make the substring uniform
So we try every substring and compute this.


For every substring s[i..j]:
    freq[] = frequency of characters
    maxFreq = most frequent character count
    replacementsNeeded = len - maxFreq
    if replacementsNeeded <= k:
        update answer

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        int maxLen = 0;  // stores the longest valid substring

        // Fix the starting point of the substring
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0); // frequency array for A-Z

            // Expand the substring from i to j
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'A']++;  // update frequency of current character
                
                int currLen = j - i + 1;  // current substring length
                int maxFreqOfChar = 0;    // highest frequency in this substring

                // Find the max frequency character in current substring
                for (int p = 0; p < 26; p++)
                    maxFreqOfChar = max(maxFreqOfChar, freq[p]);

                // Characters that need to be replaced to make the whole
                // substring equal to the most frequent character
                int replacementsNeeded = currLen - maxFreqOfChar;

                // If we can make substring uniform with at most k operations
                if (replacementsNeeded <= k)
                    maxLen = max(maxLen, currLen);  // update answer
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


Brute Force + Frequency Counting

And more specifically:

🟩 Sliding Window (BUT in brute-force form)

*/
