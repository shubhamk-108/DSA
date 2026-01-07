/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
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
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int n = s.length();
        if(isPalindrome(s,0,n-1))
            return true;

        for (int i = 0; i < n; i++)
        {
            
            string temp = s.substr(0, i) + s.substr(i + 1);

            if (isPalindrome(temp, 0, temp.length() - 1))
                return true;
        }
        return false;        
    }
};


int main()
{
    Solution sol;
    string s = "abca";
    cout << sol.validPalindrome(s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n²)

Space Complexity
O(n)

Because you create a temporary string on each iteration.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Check if the string is already a palindrome.

For each index i, remove character s[i].

Check if the resulting string is a palindrome.

If ANY removal gives a palindrome → return true.

Otherwise return false.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


bool validPalindrome(string s)
{
    int n = s.length();

    // First check if original string is already a palindrome
    if(isPalindrome(s, 0, n - 1))
        return true;

    // Brute force: remove one character at every index
    for (int i = 0; i < n; i++)
    {
        // Remove char at index i
        string temp = s.substr(0, i) + s.substr(i + 1);

        // Check if the remaining string is palindrome
        if(isPalindrome(temp, 0, temp.length()-1))
            return true;
    }

    // If none worked, return false
    return false;
}


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Brute Force + Two Pointers



*/
