// 47_451_sortCharByFreqME.cpp here ME means more efficient

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
private:
    bool findInVector(const vector<pair<char, int>> &allCharCount, char c)
    {
        for (const auto &p : allCharCount)
        {
            if (p.first == c)
                return true;
        }
        return false;
    }

public: // cccdeeda
    string frequencySort(string s)
    {
        vector<pair<char, int>> allCharCount;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (findInVector(allCharCount, s[i]) == false)
            {
                int freq = 1;
                for (int j = 0; j < n; j++)
                {
                    if (s[i] == s[j] && i != j)
                        freq++;
                }
                allCharCount.push_back({s[i], freq});
            }
        }

        sort(allCharCount.begin(), allCharCount.end(), [](auto &a, auto &b)
             {
                if(a.second == b.second)
                    return a.first < b.first;
                return a.second > b.second; });

        string res;
        for (auto &x : allCharCount)
        {
            res += string(x.second, x.first);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s = "cccaaa";
    cout << sol.frequencySort(s);
    return 0;
}

// ____ _________________________________________________________________________________________________________________________________

// timespace

/*

Time Complexity:

Counting frequencies → O(n²) (nested loops)
Sorting → O(k log k) where k = number of unique chars (at most 26 for lowercase English letters)
✅ Overall → O(n²)

💾 Space Complexity:
Vector storing unique characters → O(k)
✅ Overall → O(k)

// ____ _________________________________________________________________________________________________________________________________



// appraoch

/*

We count the frequency of each unique character manually using nested loops — for each character, we scan the entire string to count its occurrences.
We then store {char, freq} pairs in a vector, sort them by frequency (descending) and lexicographically if tied, and finally build the result string
by repeating characters as per their frequency.

*/

// ____ _________________________________________________________________________________________________________________________________

// code

/*


class Solution
{
private:
    // Helper function to check if a character 'c' already exists in the vector.
    // It performs a linear search, iterating through the vector from the beginning.
    // NOTE: This approach is inefficient. Using a hash map (like std::unordered_map) for lookups
    // would be much faster, providing average O(1) time complexity instead of O(K),
    // where K is the number of unique characters.
    bool findInVector(const vector<pair<char, int>> &allCharCount, char c)
    {
        // Iterate through each pair in the vector.
        for (const auto &p : allCharCount)
        {
            // If the character in the pair matches the target character 'c'.
            if (p.first == c)
                return true; // Character is found.
        }
        return false; // Character was not found after checking the entire vector.
    }

public:
    // This function sorts a string based on the frequency of its characters in descending order.
    // For example, "tree" becomes "eert".
    string frequencySort(string s)
    {
        // A vector of pairs to store each unique character and its frequency.
        vector<pair<char, int>> allCharCount;

        int n = s.length(); // Get the length of the input string.

        // --- Step 1: Count Character Frequencies (Brute-Force Method) ---
        // This double-loop approach is a brute-force way to count frequencies and is very slow.
        // The overall time complexity for this block is approximately O(N^2).
        for (int i = 0; i < n; i++)
        {
            // For each character in the string, check if we've already counted it.
            if (findInVector(allCharCount, s[i]) == false)
            {
                // If it's a new character, count its occurrences.
                int freq = 1;
                // This inner loop re-scans the entire string to count the frequency.
                for (int j = 0; j < n; j++)
                {
                    // If we find the same character at a different index.
                    if (s[i] == s[j] && i != j)
                        freq++; // Increment the frequency counter.
                }
                // After counting, store the character and its total frequency.
                allCharCount.push_back({s[i], freq});
            }
        }

        // --- Step 2: Sort the Characters by Frequency ---
        // Sort the vector of pairs using a custom lambda function as the comparator.
        sort(allCharCount.begin(), allCharCount.end(), [](const auto &a, const auto &b)
             {
                 // If two characters have the same frequency, sort them alphabetically.
                 // This is a tie-breaker; the problem allows any order for same-frequency characters[web:2].
                 if (a.second == b.second)
                     return a.first < b.first;
                 // Primarily, sort by frequency in descending order (highest frequency first).
                 return a.second > b.second;
             });

        // --- Step 3: Construct the Result String ---
        string res; // Initialize an empty string to store the final result.
        // Iterate through the sorted vector of character-frequency pairs.
        for (const auto &x : allCharCount)
        {
            // Append the character (x.first) to the result string 'x.second' times.
            // For example, if the pair is {'e', 2}, this appends "ee" to the result.
            res += string(x.second, x.first);
        }

        return res; // Return the final, sorted string.
    }
};



*/