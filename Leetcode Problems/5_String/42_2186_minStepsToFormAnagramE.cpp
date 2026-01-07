/*
You are given two strings s and t. In one step, you can append any character to either s or t.
Return the minimum number of steps to make s and t anagrams of each other.
An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
Example 1:
Input: s = "leetcode", t = "coats"
Output: 7
Explanation:
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
Example 2:
Input: s = "night", t = "thing"
Output: 0
Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.

*/

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <climits>


class Solution
{
public:
    int minSteps(string s, string t)
    {

        int freq_s[26] = {0};
        int freq_t[26] = {0};
        int n1 = s.length();
        int n2 = t.length();
        int count = 0;
        for (int i = 0; i < n1; i++)
        {
            freq_s[s[i] - 'a']++;
        }

        for (int i = 0; i < n2; i++)
        {
            freq_t[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            count += abs(freq_s[i] - freq_t[i]);
        }

        return count;
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    string t = "coats";
    cout << sol.minSteps(s, t);

    return 0;
}


// timespace

/*

Time Complexity
Counting frequencies in s → O(n1)
Counting frequencies in t → O(n2)
Summing differences over 26 letters → O(26) = O(1)
Total time complexity:
O(n1+n2+26)=O(n1+n2) or O(m+n)
✅ Linear in the size of the input strings.

Space Complexity
freq_s[26] → constant space
freq_t[26] → constant space

*/

// logic

/*
1.count the frequency of each char from both the string.
2.Then just check how many times the char has occured. We want to make them anagram means same char with same freq of char to make them 
anagram that means we just have to check difference of the frequency of char from both the string, that way we can get to know that
which char has occured and if the char is occured them how much more char are needed to make them anagram.

*/


// code


/*

class Solution
{
public:
    int minSteps(string s, string t)
    {
        // Arrays to store the frequency of each character 'a' to 'z'
        int freq_s[26] = {0}; // frequency of letters in string s
        int freq_t[26] = {0}; // frequency of letters in string t

        // Get lengths of both strings
        int n1 = s.length();
        int n2 = t.length();

        int count = 0; // To store total minimum deletions required

        // Count frequency of each character in string s
        for (int i = 0; i < n1; i++)
        {
            freq_s[s[i] - 'a']++; // Convert character to index (0 to 25) and increment
        }

        // Count frequency of each character in string t
        for (int i = 0; i < n2; i++)
        {
            freq_t[t[i] - 'a']++; // Convert character to index (0 to 25) and increment
        }

        // Compare the frequencies of each character in s and t
        // Add the absolute difference to count
        // This represents how many characters must be deleted to make s and t anagrams.
        // if for example in first string letter r is 5 times and in second string letter r is only 2 times, that means to make them
        // anagram you need 5-2 = 3 more letter r so that they can become anagram. if letters from both the string having same count 
        // then  no need to add or delete to make them anagram.
        for (int i = 0; i < 26; i++)
        {
            count += abs(freq_s[i] - freq_t[i]);
        }

        // Return total minimum deletions required
        return count;
    }
};

*/