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

        int currentCount = 0;

        for (int i = 0; i < k; i++)
        {
            if (uset.count(s[i]))
                currentCount++;
        }

        maxVovelCount = currentCount;

        for (int i = k; i < n; i++)
        {
            if (uset.count(s[i - k]))
                currentCount--;
            if (uset.count(s[i]))
                currentCount++;

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
Time Complexity: O(n)
Space Complexity: O(1)
The vowel set contains exactly 5 characters → constant space.
No additional space scales with n.
So O(1).

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Define a set of vowels: {a, e, i, o, u}.
Count vowels in the first window (first k characters).
Store this count as the current maximum
Slide the window one character at a time:
Remove the contribution of the character going out of the window.
Add the contribution of the new character coming in.
Update the maximum vowel count after each slide.
Return the maximum found.
This avoids re-checking the entire substring each time and reduces the complexity to O(n).



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

        // Set of vowels to check membership in O(1) average time
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        int maxVowelCount = 0;  // Stores the maximum vowels in any window
        int currentCount = 0;   // Vowels in the current window

        // Step 1: Count vowels in the initial window of size k
        for (int i = 0; i < k; i++)
        {
            if (vowels.count(s[i]))
                currentCount++;
        }

        maxVowelCount = currentCount;  // Initial maximum

        // Step 2: Slide the window from index k to n-1
        for (int i = k; i < n; i++)
        {
            // Remove char that slides out (at i - k)
            if (vowels.count(s[i - k]))
                currentCount--;

            // Add new char that slides in (at i)
            if (vowels.count(s[i]))
                currentCount++;

            // Update maximum
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
✔ Sliding Window Pattern



*/
