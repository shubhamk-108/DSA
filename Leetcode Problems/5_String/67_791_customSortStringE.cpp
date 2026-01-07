/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character
y in order,
then x should occur before y in the permuted string.
Return any permutation of s that satisfies this property.

Example 1:
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:
Input: order = "bcafg", s = "abcd"
Output: "bcad"
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
    string customSortString(string order, string s)
    {

        int n = order.length();
        int m = s.length();

        unordered_map<char, int> um_freq;

        for (int i = 0; i < m; i++)
        {
            um_freq[s[i]]++;
        }

        string res = "";
        
        for (int i = 0; i < n; i++)
        {
            if (um_freq.find(order[i]) != um_freq.end())
            {
                while (um_freq[order[i]] > 0)
                {
                    res += order[i];
                    um_freq[order[i]]--;
                }
            }
        }

        for (auto &x : um_freq)
        {
            while (x.second > 0)
            {
                res += x.first;
                x.second--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string order = "cba";
    string s = "abcddd";
    cout << sol.customSortString(order, s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Step                 | Operation             | Time         |
| -------------------- | --------------------- | ------------ |
| Frequency counting   | Traverse `s`          | O(m)         |
| Build ordered result | Traverse `order`      | O(n)         |
| Add remaining chars  | Traverse leftover map | O(26) → O(1) |
| **Total**            |                       | **O(n + m)** |

Space Complexity

O(1) → Because at most 26 lowercase English letters (constant map size).
If extended to all ASCII characters, then O(k) where k = character set size.


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The goal is to reorder characters of string s so that their relative order follows the sequence given in order.
Brute-force idea (conceptually):
You could sort every character in s according to its position in order,
which would take O(m log m) time with a custom comparator (still not terrible).
A real brute-force would try every permutation — which is infeasible (O(m!)).
Your approach (efficient frequency-based idea):
Count the frequency of each character in s using a hash map (unordered_map<char,int>).
This tells you how many times each letter appears.
Iterate through order:
For every character order[i], check if it exists in s.
If yes, append it to the result as many times as it appears (um_freq[order[i]] times).
Decrease its count to zero after using it.
Add remaining characters:
After processing all characters in order, append the leftover characters (those not in order) to the result.
This ensures all characters appear the same number of times as in s, but with the desired ordering.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    string customSortString(string order, string s)
    {
        // Step 1: Store frequency of each character in s
        unordered_map<char, int> um_freq;
        for (int i = 0; i < s.length(); i++)
        {
            um_freq[s[i]]++;
        }

        string res = "";

        // Step 2: Add characters that appear in 'order' first, in given order
        for (int i = 0; i < order.length(); i++)
        {
            // If current character exists in s
            if (um_freq.find(order[i]) != um_freq.end())
            {
                // Append it as many times as it occurs
                while (um_freq[order[i]] > 0)
                {
                    res += order[i];
                    um_freq[order[i]]--;
                }
            }
        }

        // Step 3: Add remaining characters (not in 'order' string) at the end
        for (auto &x : um_freq)
        {
            while (x.second > 0)
            {
                res += x.first;
                x.second--;
            }
        }

        // Step 4: Return the final sorted string
        return res;
    }
};



*/
