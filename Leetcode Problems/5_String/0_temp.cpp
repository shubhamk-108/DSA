#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        int n = words.size();
        vector<bool> used(n, false);   // tracks which words are already paired
        int maxLen = 0;

        // Step 1: find all pairs like "ab" + "ba"
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;

            string rev = words[i];
            reverse(rev.begin(), rev.end());

            for (int j = i + 1; j < n; j++)   // j starts at i+1 because used[] handles everything before
            {
                if (!used[j] && words[j] == rev)
                {
                    used[j] = true; // mark both words used
                    maxLen += 4;              // each pair contributes 4 length
                    break;                    // important: only one pair per i
                }
            }
        }

        // Step 2: check if any unused word like "aa","bb","cc" exists to place in center
        for (int i = 0; i < n; i++)
        {
            if (!used[i] && words[i][0] == words[i][1])
            {
                maxLen += 2;   // only one center allowed
                break;
            }
        }

        return maxLen;
    }
};
