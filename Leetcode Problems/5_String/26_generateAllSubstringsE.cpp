/*

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
#include <vector>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> generateAllSubstring(string s)
    {
        vector<pair<int, int>> allSubstringIndices;

        int n = s.length();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                allSubstringIndices.push_back({j, i});
            }
        }
        return allSubstringIndices;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcde";

    vector<pair<int, int>> ss = sol.generateAllSubstring(s1);
    for (auto x : ss)
        cout << x.first << " "<<x.second << ", ";
    return 0;
}

// timespace

/*

Total possible substring = ( n * (n + 1) ) / 2
Time: O(n²)

Space: O(n²)
Each substring is stored as a (start, end) pair → O(1) space per substring.
Number of substrings = O(n²).
✅ Space = O(n²)

*/




// logic


/*

1. Generate substrings in O(n²) time without storing
If you only need to process substrings (e.g., print them, check conditions), you don’t need to copy them into new strings:
Instead of creating new strings, store (start, end) pairs:



// code

/*

for (int i = 1; i <= n; i++) THis loop will be considered for length. Like first all substring of length 1, then lenght 2 and so on.      
for (int j = 0; j <= n-i; j++) This loop is for all possible combinations of length 1 substring. Then all length 2 substring then all 
length 3 substring and so on.
            
allSubstring.push_back(s.substr(j,i));
when i = 2 and j = 0,1,2,3, for string abcde then substrings will be             
 2, 0, = ab
 2, 1 = bc
 2, 2, = cd
 2, 3  = de
 
            
 

*/