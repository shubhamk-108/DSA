/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// This is optimised solution but more cleaner solution is written in next file.
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        if (s.length() != t.length())
            return false;

        string temp = t;

        for (int i = 0; i < n; i++)
        {
            bool flag_hasSeen = false;

            for (int j = 0; j < n; j++)
            {
                if (s[i] == temp[j])
                {
                    flag_hasSeen = true;
                    temp[j] = '#';
                    break;
                }
            }

            if (flag_hasSeen == false)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s, t);
    return 0;
}


//time 

/*
Time Complexity
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²) → brute-force

Space Complexity
Extra copy of t (temp) → O(n)
No other extra storage

*/

// logic

/*

class Solution
{
public:

    // Brute-force approach to check if two strings are anagrams
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        // Step 1: If lengths differ, they cannot be anagrams
        if (s.length() != t.length())
            return false;

        // Step 2: Make a copy of t to mark characters as used
        string temp = t;

        // Step 3: For each character in s, check if it exists in temp
        for (int i = 0; i < n; i++)
        {
            bool flag_hasSeen = false;

            for (int j = 0; j < n; j++)
            {
                if (s[i] == temp[j])
                {
                    flag_hasSeen = true;  // character found
                    temp[j] = '#';        // mark as used
                    break;                // stop inner loop
                }
            }

            // If s[i] not found in t, return false
            if (flag_hasSeen == false)
                return false;
        }

        // All characters matched → strings are anagrams
        return true;
    }
};


*/