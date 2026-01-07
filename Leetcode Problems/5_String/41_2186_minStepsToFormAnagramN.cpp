/*
You are given two strings s and t. In one step, you can append any character to either s or t.
Return the minimum number of steps to make s and t anagrams of each other.
An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
Example 1:
Input: s = "leetcode", t = "coats"
Output: 7
Explanation:
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
Example 2:
Input: s = "night", t = "thing"
Output: 0
Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.

*/

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <climits>


class Solution
{
public:
    int minSteps(string s, string t)
    {

       
// The efficient solution is considered "brute force" in a conceptual sense because it directly addresses the definition of an anagram. Anagrams are 
// all about character counts, so the most straightforward approach is to count the characters and see what's missing. You're not using a 
// complex data structure or advanced algorithmic technique; you're just counting.

// this same solution is also the "efficient" or "optimal"

    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    string t = "coats";
    cout << sol.minSteps(s, t);

    return 0;
}
