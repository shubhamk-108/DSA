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

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        int n = s.length();

        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> ump;
            int currLen = 0;
            for (int j = i; j < n; j++)
            {
                ump[s[j]]++;
                if (ump.size() == k)
                    maxLen = max(maxLen, j - i + 1);
                if (ump.size() > k)
                    break;
            }
        }
        return maxLen == 0 ? -1 : maxLen;
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

Time Complexity → O(n²) 
Outer loop runs n times.
Inner loop can run up to n times for each starting index.
Hashmap operations are O(1) average.
So total = O(n²).

Space Complexity → O(k)
Hashmap can hold at most k distinct characters before breaking.
So auxiliary space = O(k), which is effectively O(1) if alphabet is fixed (like lowercase letters).


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Start a substring at every index i.
Use a hashmap to count character frequencies in the current substring from i to j.
For each expansion j:
Add s[j] to the map.
If map size becomes exactly K, update the answer length.
If map size becomes greater than K, break because adding more will not reduce distinct characters.
Reset the hashmap for the next starting index i.


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
        int maxLen = 0;

        // Outer loop: choose every index as starting point
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> ump;  // freq map for each new starting point

            // Expand substring from i to j
            for (int j = i; j < n; j++)
            {
                ump[s[j]]++; // include current character

                // Case: exactly k distinct characters → update longest length
                if (ump.size() == k)
                    maxLen = max(maxLen, j - i + 1);

                // Case: more than k → no point expanding further
                if (ump.size() > k)
                    break;
            }
        }

        // If no valid substring found return -1 (matches typical problem statements)
        return maxLen == 0 ? -1 : maxLen;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


✔ Brute Force (Nested Loops)

*/
