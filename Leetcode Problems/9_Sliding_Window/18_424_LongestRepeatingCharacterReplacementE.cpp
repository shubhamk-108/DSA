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

        int maxWinSize = 0;
        int maxFreqChar = 0;
        unordered_map<char, int> freq;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            freq[s[right]]++;

            maxFreqChar = max(maxFreqChar, freq[s[right]]);

            int currWinSize = right - left + 1;

            while (currWinSize - maxFreqChar > k)
            {
                freq[s[left]]--;

                left++;
                currWinSize = right - left + 1;
            }

            maxWinSize = max(maxWinSize, currWinSize);
            right++;
        }
        return maxWinSize;
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

Time Complexity: O(n)

Each character enters and leaves the window at most once.

Space Complexity: O(1)

freq stores at most 26 uppercase letters.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want the longest substring that can be turned into all the same character using at most k replacements.
Key idea:
A window is valid if:
window_size - count_of_most_frequent_char_in_window <= k

Why?
Because:
The most frequent character in the window doesn't need changes.
All other characters must be replaced.
If the number of these "other characters" is at most k, the window is valid.
Steps:
Expand the right pointer, adding characters to the frequency map.
Track the max frequency of any character inside the window.
If the window becomes invalid:
Slide the left pointer forward to shrink the window.
Keep track of the maximum length of a valid window.
This ensures an O(n) solution because each pointer moves at most n times.



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

        int maxWinSize = 0;         // stores the maximum valid window size
        int maxFreqChar = 0;        // frequency of the most frequent character in the window
        unordered_map<char, int> freq;  // frequency map of characters in the current window

        int left = 0;               // left pointer of sliding window
        int right = 0;              // right pointer of sliding window

        while (right < n)
        {
            // Add current character to frequency map
            freq[s[right]]++;

            // Update the highest frequency character in the window
            maxFreqChar = max(maxFreqChar, freq[s[right]]);

            // Current window size
            int currWinSize = right - left + 1;

            // If window needs more than k replacements, shrink it
            // Condition for invalid window:
            // total chars - most frequent char count > k
            while (currWinSize - maxFreqChar > k)
            {
                freq[s[left]]--;   // remove leftmost char from window
                left++;            // move left pointer to shrink window
                currWinSize = right - left + 1;   // recalculate window size
            }

            // Window is valid now → update max window length
            maxWinSize = max(maxWinSize, currWinSize);

            // Expand window by moving right pointer
            right++;
        }

        return maxWinSize;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Sliding Window (Expand → Shrink)
✔ Two Pointers (left & right)
✔ Frequency Map (Hash Map)
✔ Window validity condition

→ a classic pattern called:

Sliding Window with Character Frequency Constraint

*/
