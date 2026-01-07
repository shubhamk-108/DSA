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

bool areAnagrams(std::string text, std::string pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m > n)
    {
        return false;
    }

    const int CHAR_COUNT = 26;
    int text_freq[CHAR_COUNT] = {0};
    int pattern_freq[CHAR_COUNT] = {0};

    for (int i = 0; i < m; i++)
    {
        text_freq[text[i] - 'a']++;
        pattern_freq[pattern[i] - 'a']++;
    }

    int i;

    for (i = 0; i < CHAR_COUNT; i++)
    {
        if (text_freq[i] != pattern_freq[i])
            break;
    }
    if (i == CHAR_COUNT)
        return true;

    for (int j = m; j < n; j++)
    {
        text_freq[text[j - m] - 'a']--;
        text_freq[text[j] - 'a']++;

        int k;
        for (k = 0; k < CHAR_COUNT; k++)
        {
            if (text_freq[k] != pattern_freq[k])
                break;
        }
        if (k == CHAR_COUNT)
            return true;
    }

    return false;
}

int main()
{
    if (areAnagrams("geeksforgeeks", "frog"))
    {
        std::cout << "Anagram of 'frog' is present." << std::endl;
    }

    if (areAnagrams("cbaebabacd", "abc"))
    {
        std::cout << "Anagram of 'abc' is present." << std::endl;
    }

    if (!areAnagrams("hello", "world"))
    {
        std::cout << "Anagram of 'world' is NOT present." << std::endl;
    }

    return 0;
}

// time

/*


Time Complexity: O(N)

The first loop for initialization runs M times.

The main sliding loop runs N - M times. Inside this loop, you do a constant number of operations: two array updates (O(1)) and a check loop that runs a maximum of 26 times (O(1)).

The total complexity is O(M + (N - M)), which simplifies to O(N). This is the optimal time complexity.

Space Complexity: O(1)

You use two fixed-size arrays (text_freq and pattern_freq) of size 26. Since the size of this storage does not depend on the input length N or M, the space complexity is constant, or O(1).


*/

// logic

/*



bool areAnagrams(std::string text, std::string pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        return false;
    }

    const int CHAR_COUNT = 26;
    int text_freq[CHAR_COUNT] = {0};
    int pattern_freq[CHAR_COUNT] = {0};

    // --- Step 1: Build the frequency map for the pattern and the first window ---
    for (int i = 0; i < m; i++)
    {
        text_freq[text[i] - 'a']++;
        pattern_freq[pattern[i] - 'a']++;
    }

    // --- Step 2: Check if the very first window is an anagram ---
    int i;
    for (i = 0; i < CHAR_COUNT; i++)
    {
        if (text_freq[i] != pattern_freq[i])
            break; // Mismatch found, break the loop.
    }
    // If the loop completed without breaking, it's a match.
    if (i == CHAR_T)
        return true;

    // --- Step 3: Slide the window across the rest of the text ---
    // The loop starts from where the first window ended.
    for (int j = m; j < n; j++)
    {
        // --- a) The "Slide" ---
        // Decrement the count of the character leaving the window (from the left).
        text_freq[text[j - m] - 'a']--;
        // Increment the count of the character entering the window (from the right).
        text_freq[text[j] - 'a']++;

        // --- b) Check the new window ---
        int k;
        for (k = 0; k < CHAR_COUNT; k++)
        {
            if (text_freq[k] != pattern_freq[k])
                break; // Mismatch found, no need to check further for this window.
        }
        // If the inner loop completed, we found an anagram.
        if (k == CHAR_COUNT)
            return true;
    }

    // If the entire text has been scanned and no match was found.
    return false;
}





*/

// Question

/*

in naive algo we we were only checkig once our freq array after building freq array from text using ++ increment and  -- decrement operator.
But here in efficient solu we are checking that whether or not freq array of text and pattern is same . also we are using extra freq array for
pattern. so how it is optimised solution.

Answer:

"The sliding window solution is more efficient because each step of the slide is an O(1) operation. To move the window, we perform only two
constant-time operations: decrementing the count of the character leaving the window and incrementing the count of the character entering.
After this update, we check for an anagram by comparing the two frequency arrays. Since the arrays have a fixed size of 26, this comparison
is also a constant-time, O(1) operation.

Because each slide is O(1), and we slide the window N-M times, the total time complexity for the sliding part is O(N). This is a significant
optimization over the naive approach, which rebuilds the entire frequency map for each window, resulting in an O(N * M) complexity."

Why "Checking Two Arrays of Length 26 is O(1)"
This is a key concept in complexity analysis that you've correctly identified.
Complexity measures how an algorithm's runtime or memory usage scales with the size of the input.

*/