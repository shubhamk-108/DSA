// abababcd : find pattern abab: op is 0 and 2. That is we need to find all indices where such pattern is present
// aaaaa: search for aaa . op is 0, 1, 2

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

void patternSearching(string &str, string pattern)
{
    int n = str.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;

        for (j = 0; j < m; j++)
        {
            if (pattern[j] != str[i + j])
                break;
        }
        
        if(j==m)
            cout<<i<<" ";
    }
}

int main()
{
    string s1 = "abababcd";
    string s2 = "abab";
    patternSearching(s1, s2);

    return 0;
}


// Time Complexity: O(n * m)
// Space Complexity: O(1)

// logic

/*


void patternSearching(string &str, string pattern)
{
    // Get the length of the main string and the pattern
    int n = str.length();
    int m = pattern.length();

    // Loop through the main string from the beginning to the last possible starting point
    // A match can't start after index n-m
    for (int i = 0; i <= n - m; i++)
    {
        int j;

        // For the current starting index i, check if the pattern matches
        for (j = 0; j < m; j++)
        {
            // If a character does not match, break out of this inner loop
            if (pattern[j] != str[i + j])
                break;
        }
        
        // If the inner loop completed without breaking, it means all characters
        // of the pattern matched (j will be equal to m)
        if (j == m)
            cout << i << " "; // Print the starting index of the match
    }
}


*/
