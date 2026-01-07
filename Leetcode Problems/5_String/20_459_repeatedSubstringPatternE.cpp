/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:
Input: s = "aba"
Output: false
Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // this lps arary is explained in dsa -> gfg -> 8_string. check aroung 19th 20th file.
    vector<int> lpsArray(string str)
    {
        int len = 0;
        int i = 1;
        int n = str.length();

        vector<int> lps(n, 0);

        while (i < n)
        {
            if (str[len] == str[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else // len = 0;
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool repeatedSubstringPattern(string s)
    {

        vector<int> lps = lpsArray(s);
        int n = s.length();

        int longest_prefix_suffix = lps[n - 1];
        int possible_substring_len = n - longest_prefix_suffix;

        if (longest_prefix_suffix > 0 && n % possible_substring_len == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution sol;
    // string s1 = "abcabcabcabc";
    string s1 = "abacababacab";

    cout << sol.repeatedSubstringPattern(s1);
    return 0;
}

// timespace

/*

Complexity Analysis
Time Complexity: O(N)
The algorithm's runtime is dominated by the lpsArray function. Although it has a nested if/else structure inside the while loop, the two
pointers i and len only move forward through the string. The pointer i is strictly increasing. The pointer len can decrease, but the total number of decreases cannot exceed the total number of increases. Therefore, the work done is proportional to the length of the string, N, making the complexity linear.

Space Complexity: O(N)
The space complexity is determined by the lps vector, which stores an integer for each character in the input string. This requires space
proportional to the length of the string, N.

*/

// logic

/*

lps array will give us longes length of prefix suffix.
ex: abcabcabcabc , n = 12
lps array : 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
if substract longest prefix suffix length from n then we will get the possible substring length. like 12 - 9 = 3.
3 cab be possible length. Now how did we find this. Because 0th, 1st and 2nd index is 0 in lps that means they do not match to each other
and that is true abc do not match to each other because they were creating substring pattern like abc. And if this is the substring we want
then after that everything keeps on adding because they were matching to the substring pattern lik .....1, 2, 3, 4, 5, 6, 7, 8, 9.

int longest_prefix_suffix = lps[n - 1];.
int possible_substring_len = n - longest_prefix_suffix;
possible_substring_len = 12 - 9 =3  and this is correct. check for abcabcabcabc = abc abc abc abc.

we are checking this longest_prefix_suffix > 0  because if there is no substring matched like abcdefg then lps of last char is 0.
possible_substring_len = n - longest_prefix_suffix; = 12 - 0 = 12. And this 12 is divisible by  n - longest_prefix_suffix that is
12 is divisible by 12 so this will return true even if ans should have been false.
*/

// abacababacab