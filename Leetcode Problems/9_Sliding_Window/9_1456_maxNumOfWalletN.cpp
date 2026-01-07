/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

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
    int maxVowels(string s, int k)
    {
        int n = s.length();

        unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
        int maxVovelCount = 0;


        for (int i = 0; i <= n - k; i++)
        {
            int currentCount = 0;
            for (int j = i; j < i + k; j++)
            {
                if (uset.count(s[j]))
                    currentCount++;
            }
            maxVovelCount = max(maxVovelCount, currentCount);
        }
        return maxVovelCount;
    }
};

int main()
{
    Solution sol;
    string s = "abciiidef";
    int k = 3;
    cout << sol.maxVowels(s, k);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time: O(n * k)


🧠 Space Complexity
Space: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Loop over every possible substring of length k.
For each starting index i, check characters from i to i + k - 1.
Count how many vowels appear.
Keep track of the maximum number of vowels encountered.
Return the maximum.
This is the simplest approach but not optimal.




*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int n = s.length();

        // Set of vowels to check quickly
        unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};

        int maxVowelCount = 0;

        // Check every substring of length k → brute-force approach
        for (int i = 0; i <= n - k; i++)
        {
            int currentCount = 0;

            // Count vowels in substring s[i..i+k-1]
            for (int j = i; j < i + k; j++)
            {
                // BUG FIX: use s[j], not s[i]
                if (uset.count(s[j]))
                    currentCount++;
            }

            // Track the maximum vowel count
            maxVowelCount = max(maxVowelCount, currentCount);
        }

        return maxVowelCount;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force / Fixed-size Substring Check


*/
