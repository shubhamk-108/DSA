/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false

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
    bool checkIfPangram(string sentence)
    {
        int n = sentence.length();
        vector<int> freq(26,0);

        for (auto c : sentence)
        {
            if(c < 'a' || c > 'z')
                continue;
            int idx = c - 'a';
            freq[idx]++;
        }
        for(auto c : freq )
        {
            if(c==0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    // string s = "thequickbrownfoxjumpsoverthelazydog";
    string s = "shubha";
    cout << sol.checkIfPangram(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n)
We loop through the sentence once → O(n).
Then we check 26 letters → O(1).
Overall: O(n).
Space Complexity: O(1)
Frequency array has constant size (26).

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Create an array freq of size 26 initialized to 0.
→ Each index represents a letter (0 = 'a', 1 = 'b', ... 25 = 'z').
Loop through every character in the sentence:
If it is a lowercase letter a–z, compute its index (c - 'a').
Increment the frequency of that letter.
After processing the string, check if any frequency is still 0:
If yes → that letter is missing → not a pangram.
If all letters appear → pangram
This solves the problem in a simple linear scan.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int n = sentence.length();

        // Frequency array for 26 lowercase letters
        vector<int> freq(26, 0);

        // Count occurrences of each letter
        for (auto c : sentence)
        {
            // Ignore characters that are not lowercase letters.
            // (LeetCode guarantees input is lowercase, but this check makes it robust.)
            if (c < 'a' || c > 'z')
                continue;

            // Map 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            int idx = c - 'a';
            freq[idx]++;
        }

        // Check if any letter is missing
        for (auto c : freq)
        {
            if (c == 0)
                return false;   // missing at least one letter → not a pangram
        }

        return true; // all letters appear → pangram
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Hashing / Frequency Counting

*/
