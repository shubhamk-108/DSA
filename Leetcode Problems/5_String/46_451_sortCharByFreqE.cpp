/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


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
    string frequencySort(string s)
    {
        unordered_map<char, int> um_char_count;
        for (int i = 0; i < s.length(); i++)
        {
            um_char_count[s[i]]++;
        }

        vector<pair<char, int>> um_char_count_vector(um_char_count.begin(), um_char_count.end());

        sort(um_char_count_vector.begin(), um_char_count_vector.end(), [](auto &a, auto &b)
             { 
                if(a.second == b.second)
                    return a.first < b.first;
                return a.second > b.second; 
            });

        string res;
        for (auto &p : um_char_count_vector)
        {
            res += string(p.second, p.first);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s = "cccaaa";
    cout<< sol.frequencySort(s);
    return 0;
}

// timespace


/*

| Step                     | Time Complexity | Space Complexity                      |
| ------------------------ | --------------- | ------------------------------------- |
| Count frequencies in map | O(n)            | O(k) (distinct chars ≤ 128 for ASCII) |
| Copy map to vector       | O(k)            | O(k)                                  |
| Sort vector              | O(k log k)      | O(k)                                  |
| Build result string      | O(n)            | O(n)                                  |

Total Time Complexity: O(n + k log k) ≈ O(n) for ASCII (k ≤ 128)
Total Space Complexity: O(n) (for the result string + map/vector)

*/
// approach

/*
Count frequency of each character using unordered_map<char,int>.
Move map entries into a vector of pairs so we can sort them.
Sort the vector:
Primary key → frequency descending (higher frequency first)
Secondary key → character ascending (alphabetically) if frequency is same
Build the result string by repeating each character according to its frequency.

*/


// code

/*


class Solution
{
public:
    string frequencySort(string s)
    {
        // Step 1: Count frequency of each character
        unordered_map<char, int> um_char_count;
        for (int i = 0; i < s.length(); i++)
        {
            um_char_count[s[i]]++;
        }

        // Step 2: Copy map to vector for sorting
        vector<pair<char, int>> um_char_count_vector(um_char_count.begin(), um_char_count.end());

        // Step 3: Sort by frequency descending
        // If two characters have same frequency, sort alphabetically.
        // [](auto &a, auto &b) { return a.second > b.second; }
        // [] This means it’s a lambda (an inline anonymous function).
        // Empty brackets [] mean it doesn’t capture any outside variables.
        // (auto &a, auto &b) These are the two items being compared — both are elements of your vector.
        // Each element is a pair<char, int> (like {'h', 4}).
        // So:
        // a.first → the char
        // a.second → the frequency int
        // { return a.second > b.second; }
        // This returns true if a should come before b in the sorted order.
        // Since you used > (greater than), it means:
        // Higher frequency elements come first.
        // So the vector will be sorted in descending order of frequency
        sort(um_char_count_vector.begin(), um_char_count_vector.end(), [](auto &a, auto &b)
             { 
                if(a.second == b.second)
                    return a.first < b.first;  // alphabetically
                return a.second > b.second;    // higher frequency first
             });

        // Step 4: Build result string
        string res;
        for (auto &p : um_char_count_vector)
        {
            // string(count, char). this is string constructor functionality.
            res += string(p.second, p.first);  // repeat character by its frequency
        }

        return res;  // final sorted string
    }
};




*/

