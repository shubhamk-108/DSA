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
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       
        sort(s1.begin(), s1.end());

        do
        {
            if(s2.find(s1) != string::npos)
                return true;                
            
        } while (next_permutation(s1.begin(), s1.end()));
        
        return false;
    }
};


int main()
{
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

Time complexity (worst-case):
Let n = s1.length() and m = s2.length().

Number of permutations to check (distinct permutations of s1) is at most n! (less if there are repeated characters).

For each permutation, s2.find(s1) performs a substring search. A naive substring search is O(m * n) in the worst case (checking up to n characters at each of the m positions).

Therefore the worst-case time complexity is:
O(n!×m×n)

Space complexity:
O(1) extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Sort s1 so you start from the lexicographically smallest permutation.
Use std::next_permutation to iterate every distinct permutation of s1 (it modifies s1 in-place).
For each permutation, check if it appears in s2 using s2.find(s1):
If find returns a position (not npos) → return true.
If you exhaust all permutations without a match → return false.
This directly implements the brute-force idea: try every possible ordering of s1 and see if it occurs in s2.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Sort s1 so next_permutation will generate permutations
        // in lexicographic order and will visit every distinct permutation.
        sort(s1.begin(), s1.end());

        // Do-while loop: use current permutation first, then move to next.
        // next_permutation returns false when it has reached the last permutation.
        do {
            // Check if current permutation of s1 exists as a substring in s2.
            // s2.find(s1) returns npos if s1 is not found.
            if (s2.find(s1) != string::npos)
                return true;   // found a permutation, so return true immediately

        } while (next_permutation(s1.begin(), s1.end()));

        // No permutation of s1 was found as a substring of s2
        return false;
    }
};



*/
