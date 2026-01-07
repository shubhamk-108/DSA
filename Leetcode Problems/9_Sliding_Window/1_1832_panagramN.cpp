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
        
        for (char  ch = 'a'; ch <= 'z'; ch++)
        {
            bool found = false;

            for(auto c: sentence)
            {
                if(c == ch)
                {
                    found = true;
                    break;
                }
            }
            if(!found)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "thequickbrownfoxjumpsoverthelazydog";
    cout << sol.checkIfPangram(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(26 × n) → O(n)
For each of the 26 letters, you scan the entire string of length n.
That is brute force.
Space Complexity: O(1)
No extra data structures.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop through each alphabet letter 'a' to 'z'.
For each letter:
Scan the entire sentence to check if it appears.
If any letter is missing → return false.
If all letters are found → return true.
This repeatedly scans the string → inefficient but correct.


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
        
        // Check each letter from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            bool found = false;

            // Scan entire sentence to find ch
            for (auto c : sentence)
            {
                if (c == ch)
                {
                    found = true;   // letter found
                    break;          // no need to continue scanning
                }
            }

            // If any letter is missing, it's not a pangram
            if (!found)
                return false;
        }

        // All 26 letters were found
        return true;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Brute Force / Nested Loop Scan


*/
