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
using namespace std;

class Solution
{
public:
    vector<string> seperateWord(string s)
    {
        vector<string> words;

        int i = 0;
        string word = "";
        while (i < s.length())
        {
            if (s[i] == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
            {
                word += s[i];
            }
            i++;
        }
        words.push_back(word);
        return words;
    }


    bool wordPattern(string pattern, string s)
    {
        vector<string>words = seperateWord(s);

        int n1 = pattern.length();
        int n2 = words.size();

        if (n1 != n2)
            return false;

        

        // pattern = "abba", s = "dog cat cat fish"

        for (int i = 0; i < n1; i++)
        {
            char key = pattern[i];
            string its_mapping =  words[i];

            for (int j = i + 1; j < n2; j++)
            {
                if(words[j] == its_mapping)
                {
                    if(pattern[j] != key)
                        return false;
                }

                if(pattern[j] == key)
                {
                    if(words[j] != its_mapping)
                        return false;
                }
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

    // vector<string> words = sol.seperateWord()
    cout << sol.wordPattern(pattern, s);
    return 0;
}


// timespace

/*

Time Complexity: O(N^2)

Word Separation (seperateWord function): This function iterates through the input string s once. Let's say the length of string s is M. This step 
takes O(M) time.

Main Logic (wordPattern function): The core of the work happens in the nested loops. If the pattern has a length of N, the outer loop runs N 
times and the inner loop runs approximately N times as well.

for (int i = 0; i < n; i++) { ... } // Runs N times

for (int j = i + 1; j < n; j++) { ... } // Runs up to N-1 times

Inside the inner loop, you perform string comparisons (words[j] == its_mapping). In the worst case, comparing two strings takes time proportional 
to their length. Assuming an average word length of L, each comparison is O(L).

Therefore, the complexity of the nested loops is roughly O(N^2 * L). However, since N is the dominant factor and string comparisons are often 
treated as constant time in simplified analyses, it's commonly referred to as O(N^2). The initial O(M) for splitting the string is less 
significant than O(N^2), so it gets dropped.



*/

// code

// similar code is already explained in 17_205_isomorphicStringsN and 18_205_isomorphicStringsE. Read explanation there.

/*

there mapping was char to char but here it is char to word. So we just extracted words first and then so;ved problem as it is.

*/