// abcdabc
// op : 4 , expln: cdab
// aaa
// op : 1 , expln : a
// ""
// op : 0
// substring means contiguous characters and subsequences means
// substring: A contiguous sequence of characters within a string. For s = "abcde": "abc", "bcd" are substrings. "ace" is not a substring.
// Subsequence: A sequence of characters that appears in the same order in a string, but not necessarily contiguous. For s = "abcde": "ace", "bd",
// are subsequences. Contiguity not required. Only order should be preserved

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LongestSubstringWithDistinctCharactersN(string str)
{
    int n = str.length();
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[256] = {0};

        string temp = "";
        for (int j = i; j < n; j++)
        {
            if (freq[str[j]] > 0)
            {
                break;
            }
            else
            {
                temp += str[j];
                freq[str[j]]++;
                max_len = max(max_len, j - i + 1);
            }
        }
    }
    return max_len;
}

int main()
{
    string str = "abcdabc";
    cout << LongestSubstringWithDistinctCharactersN(str);
    return 0;
}


// time and space
// Time Complexity: O(n²)
// Space Complexity: O(1) 256 size array is considered O(1) becasue it(memory usage) does not grow as input size grows.

// logic

/*

int LongestSubstringWithDistinctCharactersN(std::string str)
{
    int n = str.length();
    int max_len = 0;

    // Outer loop considers each character as a starting point
    for (int i = 0; i < n; i++)
    {
        // A new, fresh frequency array is created and zeroed-out for each starting position 'i'
        int freq[256] = {0};

        // Inner loop extends the substring from the start 'i'
        for (int j = i; j < n; j++)
        {
            // If we've already seen this character in the current substring, it's no longer distinct
            if (freq[str[j]] > 0)
            {
                break; // End the inner loop and move to the next starting character
            }
            else
            {
                // Mark this character as seen
                freq[str[j]]++;
                // Check if this new substring is the longest we've seen so far
                max_len = std::max(max_len, j - i + 1);
            }
        }
        // The redundant and incorrect reset line is now removed.
    }
    return max_len;
}



*/













