/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool ransomnoteAndMagzine(string r, string m)
    {
        int n1 = r.length();
        int n2 = m.length();

        int freq_r[26] = {0};
        int freq_m[26] = {0};

        for (int i = 0; i < n1; i++)
        {
            freq_r[r[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            freq_m[m[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {

            if (freq_r[i] > freq_m[i])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string ransom = "aa";
    string magzine = "aab";
    cout << sol.ransomnoteAndMagzine(ransom, magzine);
    return 0;
}

// time

/*
Time Complexity: O(M + R)

Let R be the length of the ransom note (r) and M be the length of the magazine (m).
You iterate through the ransom note once (O(R)).
You iterate through the magazine once (O(M)).
You iterate 26 times to compare frequencies (O(26), which is a constant).
The total time is O(R + M + 26), which simplifies to O(M + R) because the constant is insignificant for large inputs. This is a linear time solution.

Space Complexity: O(1)
You use two integer arrays, freq_r and freq_m, both of a fixed size (26).

*/


// logic

/*


class Solution
{
public:
    bool ransomnoteAndMagzine(string r, string m)
    {
        // Get the lengths of the strings (optional, can be removed
        // if using range-based for loops).
        int n1 = r.length();
        int n2 = m.length();

        // Create two frequency arrays of size 26, one for each string,
        // initialized to all zeros.
        int freq_r[26] = {0};
        int freq_m[26] = {0};

        // --- Pass 1: Count character frequencies in the ransom note ---
        for (int i = 0; i < n1; i++)
        {
            // Increment the count for the corresponding character.
            freq_r[r[i] - 'a']++;
        }
        
        // --- Pass 2: Count character frequencies in the magazine ---
        for (int i = 0; i < n2; i++)
        {
            freq_m[m[i] - 'a']++;
        }

        // --- Pass 3: Compare the frequencies ---
        // This is the correct logic you've implemented. Loop 26 times
        // for each letter of the alphabet.
        for (int i = 0; i < 26; i++)
        {
            // magzine string can be having larger length than string ransom. THat means when freq_r[i] <= freq_m[i] then this is correct condition.
            // we are checking for false condition so we flip the sign
            if (freq_r[i] > freq_m[i])
            {
                return false;
            }
        }

        // If the loop completes without finding any character deficits,
        // it means the ransom note can be successfully constructed.
        return true;
    }
};

*/
