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

        unordered_map<string, int> ump;
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());

            if (ump[reverseWord] > 0)
            {
                maxLen += 4;
                ump[reverseWord]--;
            }
            else
            {
                ump[words[i]]++;
            }
        }

        for (auto &it : ump)
        {
            string word = it.first;
            int freq = it.second;

            if (word[0] == word[1] && freq > 0)
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

Time: O(n)

Space: O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use a hash map ump<string,int> to store frequencies of 2-letter words.
For each incoming word:
Compute its reverse.
If the reverse exists in the map (freq > 0), then:
You have found a pair (e.g., "ab" + "ba").
Add 4 to answer.
Decrement the reverse count.
Else:
Store the current word in the map.
After processing all words:
Look for any word like "aa", "bb", "cc" that has freq > 0.
You can place one such word in the center → add 2.
Time = O(n)
Space = O(n)
This is the optimal solution.


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

        // Hash map to store frequency of each 2-letter word
        unordered_map<string, int> ump;
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end()); // compute reversed word

            // If reversed word exists, we can form a palindrome pair
            if (ump[reverseWord] > 0)
            {
                maxLen += 4;              // Each pair adds length 4 (e.g., "ab" + "ba")
                ump[reverseWord]--;       // Use one reverseWord from map
            }
            else
            {
                // Otherwise store the word for future pairing
                ump[words[i]]++;
            }
        }

        // After pairing, check if any word like "aa", "bb" remains
        // Only ONE such word can be placed in the center (adds +2)
        for (auto &it : ump)
        {
            string word = it.first;
            int freq = it.second;

            // Check for self-palindromic word (both chars same)
            if (word[0] == word[1] && freq > 0)
            {
                maxLen += 2; // place one in the middle
                break;       // only one middle word allowed otherwise palindrome will not form. Try with pen and paper and see.
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

Hashing + Greedy Pairing
Use hash map to track counts
Greedily pair reverse strings
Handle special center case for identical-character words


*/
