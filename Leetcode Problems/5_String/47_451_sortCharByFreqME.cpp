// 47_451_sortCharByFreqME.cpp here ME means more efficient

/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


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

// solved using bucket sort
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> um_char_count;
        for (int i = 0; i < s.length(); i++)
        {
            um_char_count[s[i]]++;
        }

       
        vector<vector<char>> bucket(s.length() + 1);

        for (auto &p : um_char_count)
        {
            char character = p.first;
            int its_count = p.second;

            bucket[its_count].push_back(character);
        }

        string res = "";
        for (int i = s.length(); i >=1 ; i--)
        {
            for(char & c : bucket[i])
            {
                res+=string(i, c);
            }
        }
              

        return res;
    }
};

int main()
{
    Solution sol;
    string s = "cccaaa";
    cout << sol.frequencySort(s);
    return 0;
}

// ____ _________________________________________________________________________________________________________________________________


// Leetcode in this problem does not expect that if two chars having same freq then smaller char (like k is smaller than p for ex)
// should come first. In previous code(means in efficient code, current code file  is most efficient code) i wrote that code for this - that code 
// is for when two different chars having same freq then smaller char will come first. for ex for cccaaa the output will be aaaccc.


// ____ _________________________________________________________________________________________________________________________________

// timespace

/*

Time Complexity
Counting frequencies → O(n)
Building buckets → O(n)
Constructing result → O(n)
✅ Overall: O(n)

💾 Space Complexity
Frequency map → O(k) (k = unique characters ≤ 26 for lowercase letters)
Buckets + result string → O(n)
✅ Overall: O(n)


// ____ _________________________________________________________________________________________________________________________________



// appraoch

/*

Count frequency of each character using an unordered map.
Group characters by frequency in a bucket (where index = frequency).
Build the result string by iterating from highest to lowest frequency, repeating each character based on its count.


*/
 
// ____ _________________________________________________________________________________________________________________________________



// code


/*

class Solution
{
public:
    string frequencySort(string s)
    {
        // Step 1: Count frequency of each character
        unordered_map<char, int> um_char_count;
        for (char c : s)
        {
            um_char_count[c]++;
        }

        // Step 2: Create buckets where index = frequency
        // There can be at most s.length() frequency, hence +1 size.
        // why one extra bucket here.
        // Reason 1 — Indexing starts from 0
        // In C++ (and most languages), arrays and vectors are 0-indexed.
        // That means:
        // If you make vector<vector<char>> buckets(5);
        // → valid indices are 0, 1, 2, 3, 4
        // But you actually need a bucket for frequency = 5.
        // So:
        // buckets[0] → unused (no character has frequency 0)
        // buckets[1] → chars that appear once
        // buckets[2] → chars that appear twice
        // ...
        // buckets[5] → chars that appear 5 times
        vector<vector<char>> bucket(s.length() + 1);

        // Step 3: Put each character into the bucket based on its frequency
        for (auto &p : um_char_count)
        {
            char character = p.first;
            int freq = p.second;
            bucket[freq].push_back(character);
        }

        
        // Leetcode in this problem does not expect that if two chars having same freq then smaller char (like k is smaller than p for ex)
        // should come first. In previous code(means in efficient code, current code file  is most efficient code) i wrote that code for this - 
        that code is for when two different chars having same freq then smaller char will come first. for ex for cccaaa the output will be aaaccc.
        // Step 4: Build result string from high to low frequency
        string res = "";
        for (int i = s.length(); i >= 1; i--)
        {
            for (char &c : bucket[i])
            {
                // Add character 'i' times (its frequency)
                // this is string constructor. string(freq, char). Ex : string(4, h) then ans will be hhhh
                res += string(i, c);
            }
        }

        return res;
    }
};


*/