/*
Anagram Search is a classic problem where you need to find all occurrences of a smaller string (the "pattern") and its permutations within
a larger string (the "text").

In simpler terms, you are looking for any substring in the text that is an anagram of the pattern. An anagram is a word or phrase formed by
rearranging the letters of another, such as listen and silent


We need to find all substrings of length 3 in the text that are anagrams of abc. An anagram of abc must contain one 'a', one 'b', and one 'c'.
cba (starts at index 0): Contains 'c', 'b', 'a'. This is an anagram.
bae (starts at index 1): Contains 'b', 'a', 'e'. Not an anagram.
aeb (starts at index 2): Contains 'a', 'e', 'b'. Not an anagram.
eba (starts at index 3): Contains 'e', 'b', 'a'. Not an anagram.
bab (starts at index 4): Contains 'b', 'a', 'b'. Not an anagram.
aba (starts at index 5): Contains 'a', 'b', 'a'. Not an anagram.
bac (starts at index 6): Contains 'b', 'a', 'c'. This is an anagram.
acd (starts at index 7): Contains 'a', 'c', 'd'. Not an anagram.

*/

#include <iostream>
#include <string>
#include <algorithm> // Required for std::sort
using namespace std;

bool checkAnagram(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for (int j = 0; j < n - m + 1; j++)
    {
        int window_start = j;
        int freq[26] = {0};

        for (int i = 0; i < m; i++)
        {
            freq[text[window_start + i] - 'a']++;
            freq[pattern[i] - 'a']--;
        }

        int k;
        for (k = 0; k < 26; k++)
        {
            if (freq[k] != 0)
                break;
        }
        if (k == 26)
            return true;
    }
    return false;
}

int main()
{
    std::string str1 = "geeksforgeeks";
    std::string str2 = "frog";

    if (checkAnagram(str1, str2))
    {
        std::cout << "'" << str1 << "' and '" << str2 << "' are anagrams." << std::endl;
    }
    else
    {
        std::cout << "'" << str1 << "' and '" << str2 << "' are NOT anagrams." << std::endl;
    }

    std::string str3 = "geeksforgeeks";
    std::string str4 = "rseek";

    if (checkAnagram(str3, str4))
    {
        std::cout << "'" << str3 << "' and '" << str4 << "' are anagrams." << std::endl;
    }
    else
    {
        std::cout << "'" << str3 << "' and '" << str4 << "' are NOT anagrams." << std::endl;
    }

    return 0;
}

// time space

/*

Time Complexity: O(N * M)

The outer checkAnagram loop runs N - M + 1 times, which is roughly O(N) (where N is the length of the text).
Inside the loop, areAnagramsInWindow is called. This function has a loop that runs M times (where M is the length of the pattern) to build
the frequency map.
Therefore, the total time complexity is O(N * M). This is a correct brute-force complexity.

Space Complexity: O(1)
The only extra space you use is the freq array. Since this array always has a fixed size of 26, regardless of the input string lengths,
its space requirement is constant.




*/
// logic

/*


bool checkAnagram(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        return false;
    }

    // Loop through each possible starting position of a window in the text.
    for (int j = 0; j <= n - m; j++) {
        const int CHAR_COUNT = 26;
        int freq[CHAR_COUNT] = {0};

        // For the current window, build the frequency map from scratch.
        for (int i = 0; i < m; i++) {
            // Increment for the character in the text's window.
            freq[text[j + i] - 'a']++;
            // Decrement for the character in the pattern.
            freq[pattern[i] - 'a']--;
        }

        // Check if the frequency map is all zeros.
        int k;
        for (k = 0; k < CHAR_COUNT; k++) {
            if (freq[k] != 0) {
                // Mismatch found, this window is not an anagram. Break and move to the next window.
                break;
            }
        }

        // If the inner loop completed without breaking, it means all counts were zero.
        if (k == CHAR_COUNT) {
            // We found an anagram, so we can stop searching and return true.
            return true;
        }

        // --- IMPORTANT ---
        // If k != CHAR_COUNT, we do nothing here. The main 'for' loop will simply
        // continue to the next window (the next value of j).
    }

    // If the main 'for' loop finishes without ever finding an anagram,
    // then we can safely return false.
    return false;
}



*/
