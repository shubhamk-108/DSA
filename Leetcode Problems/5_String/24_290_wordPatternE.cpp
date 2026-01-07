/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".
Example 2:
Input: pattern = "abba", s = "dog cat cat fish"

Output: false

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution
{
private:
    vector<string> splitWords(string s)
    {
        vector<string> words;
        stringstream ss(s);

        string current_Word;

        while(ss >> current_Word)
        {
            words.push_back(current_Word);
        }
        return words;
    }

public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> um_mapping_chart;
        unordered_set<string> us_words_already_processed;

        vector<string>words = splitWords(s);

        int n1 = pattern.length();
        int n2 = words.size();

        if (n1 != n2)
            return false;

        for (int i = 0; i < n1; i++)
        {
            if (um_mapping_chart.find(pattern[i]) != um_mapping_chart.end()) //  found
            {
                string itsMapping = um_mapping_chart[pattern[i]];
                if (words[i] != itsMapping )
                    return false;
            }
            else
            {
                if(us_words_already_processed.find(words[i]) == us_words_already_processed.end())
                {
                    um_mapping_chart[pattern[i]] = words[i];
                    us_words_already_processed.insert(words[i]);
                }
                else
                    return false;

            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << sol.wordPattern(pattern, s);
    return 0;
}

// timespace

/*

Variables
Let n = number of words in s = pattern.size()
Let m = total length of string s (number of characters)

1️⃣ Time Complexity
Splitting the string into words:
stringstream ss(s);
while (ss >> word) words.push_back(word);
Each character of s is processed once → O(m)
Loop through pattern & words:
for (int i = 0; i < pattern.size(); i++) { ... }
Runs n times.
Each unordered_map lookup (count and []) is O(1) average.
Total for loop = O(n)
Total time:
O(m+n)
Usually, m ≥ n (words are made of characters), so we often simplify to O(m).

2️⃣ Space Complexity
Vector of words → stores n words → O(n)
Two maps:
char -> string → at most 26 entries (or up to n, in theory) → O(n)
string -> char → at most n entries → O(n)
Total space:

O(n)
n = number of words


*/


// code

// similar code is already explained in 17_205_isomorphicStringsN and 18_205_isomorphicStringsE. Read explanation there.

/*

there mapping was char to char but here it is char to word. So we just extracted words first and then so;ved problem as it is.

*/