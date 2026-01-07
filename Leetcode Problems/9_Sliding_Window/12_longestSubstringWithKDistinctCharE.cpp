/*
This question is not part of leetcode. Similar leetcode question was available to premium so i took this question from gfg.

Longest Substring with K Uniques
Longest Substring With At Most K Distinct Characters
url - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

Examples:
Input : s = "aababbcaacc" , k = 2

Output : 6

Explanation : The longest substring with at most two distinct characters is "aababb".

The length of the string 6.

Input : s = "abcddefg" , k = 3

Output : 4

Explanation : The longest substring with at most three distinct characters is "bcdd".

The length of the string 4.
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

// while ( ump.size() != k)

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        int n = s.length();
        unordered_map<char, int> ump;
        int maxLen = 0;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            ump[s[right]]++;

            if (ump.size() > k)
            {
                
                while (ump.size() > k)
                {
                    ump[s[left]]--;
                    if (ump[s[left]] == 0)
                        ump.erase(s[left]);
                    left++;
                }
            }

            if (ump.size() == k)
                maxLen = max(maxLen, right - left + 1);

            right++;
            
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    string s = "aababbcaacc";
    cout << sol.kDistinctChar(s, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n) where n = s.length().
Each character is touched at most twice: once when right includes it and once when left excludes it. unordered_map operations are average O(1).

✅ Space Complexity
O(min(n, m)) where m is the alphabet size (number of distinct characters possible).
For ASCII/English letters this is effectively O(1) (bounded by 128 or 26),
In the general case it’s O(k) (at most k+1 keys in the map during contraction).

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Maintain a window [left, right].
Add s[right] to the window and update its frequency in a hash map.
If the number of distinct characters becomes greater than K, shrink the window from the left:
Decrement frequency.
Remove character from map if its frequency becomes 0.
Whenever distinct characters ≤ K, update the maximum window size.
Continue until right reaches the end.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        int n = s.length();
        unordered_map<char, int> freq;  // stores frequency of chars inside window
        int maxLen = 0;

        int left = 0;

        for (int right = 0; right < n; right++)
        {
            freq[s[right]]++;  // expand window by including s[right]

            // If window contains more than K distinct chars → shrink from left
            while (freq.size() > k)
            {
                freq[s[left]]--;    // remove leftmost char from window
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);  // erase if freq becomes zero

                left++;  // shrink window
            }

            // Now window has at most K distinct chars → update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};





*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Variable-Size Sliding Window
Here, the window size grows and shrinks dynamically depending on the number of distinct characters.
This is the classic pattern for substring problems involving:
at most K,
at least K,
exactly K distinct characters.



*/
