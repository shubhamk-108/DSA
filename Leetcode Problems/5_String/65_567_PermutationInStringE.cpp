/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Example 3
Input:
s1 = "adc"
s2 = "dcda"
Output:
true
Explanation:
Permutations of "adc" are "adc", "acd", "cad", "cda", "dac", "dca".
"dcda" contains substring "cda" ✅
So return true
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int>freqS1(26,0), freqS2(26,0);
        for (int i = 0; i < n1; i++)
        {
            freqS1[s1[i] - 'a']++;
        }

        for (int i = 0; i < n2; i++)
        {
            freqS2[s2[i] - 'a'] ++;
            if(i>=n1)
                freqS2[s2[i-n1] - 'a']--;
            if(freqS1 == freqS2)
                return true;
        }
        return false;
        
    }
};

int main() {
    Solution sol;
    string s1 = "adc";
    string s2 = "dcda";
    cout << sol.checkInclusion(s1, s2);
    return 0;
}



//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity:
O(n1 + n2)
→ Building frequency of s1 takes O(n1)
→ Sliding window over s2 takes O(n2)
→ Each comparison of 26 elements is constant time.

Space Complexity:
O(1)
→ Only two fixed-size arrays (26 integers each), independent of input size.

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


We want to know whether any permutation of s1 appears in s2.
Count frequency of each character in s1.
(e.g., for "ab", counts = {a:1, b:1})
Use a sliding window of size len(s1) over s2.
Maintain frequency counts for the current window.
Each time you move the window:
Add the new character (right side).
Remove the old character (left side).
Compare the two frequency arrays.
If both frequency arrays match at any point → found a permutation → return true.
If the entire s2 is scanned with no match → return false.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // Frequency count arrays for s1 and current window of s2
        vector<int> freqS1(26, 0), freqS2(26, 0);

        // Count frequency of each character in s1
        for (int i = 0; i < n1; i++) {
            freqS1[s1[i] - 'a']++;
        }

        // Slide a window over s2
        for (int i = 0; i < n2; i++) {
            // Add the new character to the window
            freqS2[s2[i] - 'a']++;

            // If window size exceeds s1 length, remove leftmost char
            if (i >= n1) {
                freqS2[s2[i - n1] - 'a']--;
            }

            // If frequency matches, we found a permutation
            if (freqS1 == freqS2)
                return true;
        }

        // No permutation found
        return false;
    }
};


*/

