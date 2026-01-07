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
        string temp = m;

        for (int i = 0; i < n1; i++)
        {
            int j;
            for (j = 0; j < n2; j++)
            {
                if (r[i] == temp[j])
                {
                    temp[j] = '#';
                    break;
                }
            }
            if(j==n2)
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
Time Complexity: O(R * M)

Let R be the length of the ransom note (r) and M be the length of the magazine (m).
The outer loop runs R times (for each character in the ransom note).
The inner loop, in the worst-case scenario, has to scan the entire magazine string, which takes M operations.
This results in a total time complexity of O(R * M). This approach can be slow if the strings are very long.

Space Complexity: O(M)
The line string temp = m; creates a full copy of the magazine string.
The space required for this copy is proportional to the length of the magazine, M.
Therefore, the space complexity is O(M).

*/


//logic


/*

// This function checks if a ransom note 'r' can be constructed from a magazine 'm'.
// Each character in the magazine can only be used once.
bool ransomnoteAndMagzine(string r, string m)
{
    // Get the lengths of the ransom note and the magazine strings.
    int n1 = r.length();
    int n2 = m.length();

    // Create a copy of the magazine string. We will modify this copy to
    // simulate "using up" characters.
    string temp = m;

    // Iterate through each character of the ransom note.
    for (int i = 0; i < n1; i++)
    {
        int j;
        // For each ransom note character, search for it in the magazine copy.
        for (j = 0; j < n2; j++)
        {
            // If we find a matching character...
            if (r[i] == temp[j])
            {
                // ...mark it as used by replacing it with a placeholder symbol (e.g., '#').
                // This prevents us from using the same magazine letter twice.
                temp[j] = '#';
                
                // We've found the character we need, so we can break the inner loop
                // and move to the next character in the ransom note.
                break;
            }
        }
        
        // After the inner loop, if 'j' is equal to 'n2', it means the loop
        // finished without finding the required character (r[i]).
        if (j == n2)
        {
            // Therefore, the ransom note cannot be constructed.
            return false;
        }
    }

    // If the outer loop completes, it means every character in the ransom note
    // was successfully found in the magazine.
    return true;
}


*/