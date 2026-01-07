/*

Given a string s, find the length of the longest substring without duplicate characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

A substring is a continuous sequence of characters taken from a string.
It must be contiguous (characters must be next to each other, without gaps).
Order is preserved.
Every string is a substring of itself.
The empty string is also considered a substring.
s = "abcde"
Substrings of "abcde":
Length 1: "a", "b", "c", "d", "e"
Length 2: "ab", "bc", "cd", "de"
Length 3: "abc", "bcd", "cde"
Length 4: "abcd", "bcde"
Length 5: "abcde"
Total substrings = n * (n + 1) / 2 = 5 * 6 / 2 = 15

*/

#include <iostream>
#include <algorithm>
#include<climits>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkDistinct(string s, int start , int end)
    {
        string str = s.substr(start, end);
        // cout << str << ", ";
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(str[j] == str[i])
                    return false;
            } 
        }
        return true;
        
    }
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int max_len = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                if(checkDistinct(s, j, i))
                    max_len = max(max_len, i);
            }
        }

        return max_len;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcde";

    cout << sol.lengthOfLongestSubstring(s1);
    return 0;
}

// timespace:

/*
TIme : 
for (int i = 1; i <= n; i++)
for (int j = 0; j <= n - i; j++)
as we saw in file no 25 and 26 that the there are (n*(n+1))/2 substring total. which comes to O(n^2)
So this will run O(n^2)
and  inside if(checkDistinct(s, j, i)) function str is of length k so it will take O(k^2) but in worst case k can be at most n which is O(n^2).
Thus O(n^2) * O(n^2) = O(n^4).


// space : 

Space Complexity
substr creates a copy of the substring → O(k).
Worst case = O(n).
No extra global structures.
✅ Space Complexity: O(n)

*/


// code


/*



class Solution
{
public:
    // Helper function to check if all characters in a substring are unique.
    // The 'end' parameter here is actually the length of the substring.
    // this function checkdistince is already studied and explained in i guess array chapter of gfg
    bool checkDistinct(string s, int start, int length)
    {
        // O(length): Create a new substring of the given length.
        string str = s.substr(start, length);

        // O(length^2): Use nested loops to compare every character with every other character.
        for (int i = 0; i < str.length(); i++)
        {
            // consider that i is in index 5. Then j will run from index 0 to 4. And it will see that in 0 to 4 is there same element 
            // as str[i]. If same element occurs then this can not be distinct string
            for (int j = 0; j < i; j++)
            {
                // If a character is found that was seen before, it's not distinct.
                if (str[j] == str[i])
                    return false;
            }
        }
        
        // If the loops complete, no duplicates were found.
        return true;
    }

    // this function is same as generate all possible combinations of substring . it is already explained in file no 25 and 26 of same folder.
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int max_len = 0;

        // Outer loop: Iterate through all possible substring lengths (from 1 to n).
        for (int i = 1; i <= n; i++)
        {
            // Inner loop: Iterate through all possible starting positions for a substring of length 'i'.
            for (int j = 0; j <= n - i; j++)
            {
                // Check if the current substring s.substr(j, i) has all unique characters.
                if (checkDistinct(s, j, i))
                {
                    // If it does, update the max_len. Since we iterate by length, this will be the new max.
                    max_len = max(max_len, i);
                }
            }
        }

        return max_len;
    }
};


*/