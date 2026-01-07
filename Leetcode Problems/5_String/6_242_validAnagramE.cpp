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
#include <algorithm>

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        if (s.length() != t.length())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if(freq[i] != 0)
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
Loop over strings → O(n)
Loop over frequency array → O(26) → O(1)
Total: O(n)

Space Complexity
Frequency array of 26 letters → O(26) → O(1)
Total: O(1)

*/

// logic

/*

// Optimized solution to check if two strings are anagrams
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.length();

        // Step 1: If lengths differ, they cannot be anagrams
        if (s.length() != t.length())
            return false;

        // Step 2: Frequency array for 26 lowercase letters
        int freq[26] = {0};

        // Step 3: Count characters in s and subtract count using t.
        // if the letters are same in both the string then they cancel out each other. if there are two a in string 1 and two in string 2
        // then +2 - 2 cancel out each other.
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;  // increment for s[i]
            freq[t[i] - 'a']--;  // decrement for t[i]
        }

        // Step 4: Check if all counts are zero
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
                return false; // mismatch found → not an anagram
        }

        // All counts zero → strings are anagrams
        return true;
    }
};



*/