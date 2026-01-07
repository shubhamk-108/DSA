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
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> um;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            um[s[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (um[s[i]] == 1)
            {
                return i;
            }
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

//logic

/*
//put all chars and there count in map. then traverse string and see which char has count of 1. return that char.
    int firstUniqChar(string s)
    {
        // Use an unordered_map to store the frequency of each character.
        unordered_map<char, int> um;
        int n = s.length();

        // First pass: build the frequency map.
        for (int i = 0; i < n; i++)
        {
            um[s[i]]++;
        }

        // Second pass: find the first character with a count of 1.
        for (int i = 0; i < n; i++)
        {
            // We can simplify this check. Since we iterate through the same string 's',
            // every s[i] is guaranteed to be in the map.
            if (um[s[i]] == 1)
            {
                // This is the first unique character. Return its index immediately.
                return i;
            }
        }

        // If the loop finishes, no unique character was found.
        return -1;
    }
};


*/