/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = 0; j < n; j++)
            {
                if (s[i] == s[j] && i != j)
                    break;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string s = "loveleetcode";
    cout << sol.firstUniqChar(s);
    return 0;
}

// time :
/*
Time Complexity
Outer loop: O(n)
Inner loop: O(n)
Total: O(n²) → brute-force
Space Complexity
No extra data structures used → O(1)
*/

// logic

/*


int firstUniqChar(string s) {
    // Get the length of the string for loop bounds.
    int n = s.length();

    // The outer loop picks one character at a time, from left to right.
    // 's[i]' is the character we are currently checking.
    for (int i = 0; i < n; i++) {
        // 'j' is the index for our inner loop, which will scan the whole string
        // to check for duplicates of 's[i]'.
        int j;
        for (j = 0; j < n; j++) {
            // This is the core check:
            // Is there another character in the string that is the same as s[i]
            // AND is at a different index?
            if (s[i] == s[j] && i != j) {
                // If we find even one duplicate, we can stop searching for this 's[i]'.
                // We break out of the inner loop immediately.
                break;
            }
        }

        // After the inner loop finishes, we check the value of 'j'.
        // If 'j' made it all the way to 'n', it means the inner loop *never* broke.
        // This is the crucial part: it proves that no duplicates for 's[i]' were found.
        if (j == n) {
            // Since we are iterating from left to right (i = 0, 1, 2...),
            // the first time this condition is true, we have found our answer.
            return i;
        }
    }

    // If the outer loop completes without ever returning,
    // it means every character had at least one duplicate.
    return -1;
}


*/