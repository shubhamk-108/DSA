/*
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;

        string palindrome;
        int start_index = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++)
        {
            int left = i;
            int right = i;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                int current_length = right - left + 1;
                if (current_length > max_len)
                {
                    max_len = current_length;
                    start_index = left;
                }
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                int current_length = right - left + 1;
                if (current_length > max_len)
                {
                    max_len = current_length;
                    start_index = left;
                }
                left--;
                right++;
            }
        }
        palindrome = s.substr(start_index, max_len);
        return palindrome;
    }
};

int main()
{
    Solution sol;
    string s1 = "babad";

    cout << sol.longestPalindrome(s1);

    return 0;
}


// timespace


/*

Time Complexity: O(N²)

The main for loop runs N times, where N is the length of the string.
Inside the loop, we perform two while loop expansions. In the worst-case scenario (a string that is one long palindrome, like "aaaaa"), 
each expansion can take up to O(N) time.
The total time is therefore N (for the outer loop) * O(N) (for the expansion) = O(N²). This is efficient enough to pass the time limits on LeetCode.

Space Complexity: O(1)
This algorithm is very space-efficient. It uses only a few integer variables (left, right, start_index, max_len) to keep track of the pointers 
and the result.
The amount of extra space used does not grow with the size of the input string s.
Therefore, the space complexity is constant, or O(1).



*/
// logic

/*

A palindrome mirrors around its center.

A palindrome can have:

Odd length (like "aba") → single character center
Even length (like "abba") → between two characters center
So for each index i in the string, you try both:
Treat s[i] as the middle of a palindrome (odd length).
Treat s[i] and s[i+1] as the middle (even length).
You expand outward from the center until characters don’t match.
While expanding, you track the longest palindrome found

int left = i;
int right = i;
these left and right are for odd length palindrome. left will go to left and right will go to rigth.

int left = i;
int right = i+1;
these are for even length palindrome. 


*/

// code

/*

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        // A string with 0 or 1 characters is always a palindrome.
        if (n < 2)
        {
            return s;
        }

        int start_index = 0;   // The starting index of the longest palindrome found so far.
        int max_len = 1;       // The length of the longest palindrome found so far.

        // Iterate through each character of the string to treat it as a potential center.
        for (int i = 0; i < n; i++)
        {
            // --- Case 1: Find the longest ODD-length palindrome with center at 'i' ---
            // Example: For "racecar", the center is 'e' at index i=3.
            int left = i;
            int right = i;

            // Expand outwards as long as we are within the string's bounds
            // and the characters on the left and right match.
            while (left >= 0 && right < n && s[left] == s[right])
            {
                // If the current palindrome (right - left + 1) is longer than what
                // we've recorded, update our result.
                if (right - left + 1 > max_len)
                {
                    max_len = right - left + 1;
                    start_index = left;
                }
                left--;  // Move left pointer one step to the left.
                right++; // Move right pointer one step to the right.
            }

            // --- Case 2: Find the longest EVEN-length palindrome with center between 'i' and 'i+1' ---
            // Example: For "abba", the center is between 'b' and 'b' at indices i=1 and i+1=2.
            left = i;
            right = i + 1;

            // Same expansion logic as the odd case.
            while (left >= 0 && right < n && s[left] == s[right])
            {
                // If this even-length palindrome is the new longest, record it.
                if (right - left + 1 > max_len)
                {
                    max_len = right - left + 1;
                    start_index = left;
                }
                left--;
                right++;
            }
        }

        // After checking all 2N-1 possible centers, we have the starting index and length
        // of the longest palindromic substring. We can now extract it and return it.
        return s.substr(start_index, max_len);
    }
};


*/