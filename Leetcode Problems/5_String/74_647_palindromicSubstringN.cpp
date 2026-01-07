/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

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
private:
    bool isPalindrome(string s, int start, int end)
    {

        while (start <= end)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }

public:
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.length();
        for (int len = 1; len <= s.length(); len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                if (isPalindrome(s, start, start + len - 1))
                    count += 1;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    cout << sol.countSubstrings(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n³)
O(n²) substrings × O(n) to check each substring for palindrome.
Space Complexity: O(1) extra
No extra space used (we pass indices, not substrings).


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Idea:

Generate all possible substrings of s.

For each substring, check if it is a palindrome.
Count it if it is.
How it works in this code:
Outer loop: len = 1..n → all possible substring lengths.
Inner loop: start = 0..n-len → all valid starting indices for the given length.
isPalindrome(s, start, start+len-1) checks if the substring is a palindrome using two-pointer method.
Increment count if palindrome.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/
