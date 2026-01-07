/*

Given two strings a and b, find the minimum number of times a has to be repeated such that b becomes a substring of the repeated a. If b cannot be a substring of a no matter how many times it is repeated, return -1.

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: After repeating a three times,
we get "abcdabcdabcd".
Example 2:

Input: a = "aa", b = "a"
Output: 1
Explanation: B is already a substring of a.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> lpsArray(string str)
    {
        int n = str.length();
        vector<int> lps(n, 0);

        int len = 0;
        int j = 1;

        while (j < n)
        {
            if (str[len] == str[j])
            {
                len++;
                lps[j] = len;
                j++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }

        return lps;
    }

    bool PatternSearchingKmpAlgo(string text, string pattern)
    {
        vector<int> lps = lpsArray(pattern);

        int n1 = text.length();
        int n2 = pattern.length();
        int i = 0;
        int j = 0;

        while (i < n1)
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            if (j == n2)
                return true;
            else if (i < n1 && text[i] != pattern[j])
            {
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    j = lps[j - 1];
                }
            }
        }
        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        string repeated_string_a = a;
        int count_of_repeated_string = 1;

        while (repeated_string_a.length() < b.length())
        {
            repeated_string_a += a;
            count_of_repeated_string += 1;
        }
        if (PatternSearchingKmpAlgo(repeated_string_a, b))
            return count_of_repeated_string;

        repeated_string_a += a;
        count_of_repeated_string += 1;

        if (PatternSearchingKmpAlgo(repeated_string_a, b))
            return count_of_repeated_string;

        return -1;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcd";
    string s2 = "cdabcdab";

    cout << sol.repeatedStringMatch(s1, s2);
    return 0;
}

// timespace

/*

Complexity of Each Function
(a) lpsArray(pattern)

Builds the Longest Prefix Suffix (LPS) array.

Runs in O(m) where m = |b|.

(b) PatternSearchingKmpAlgo(text, pattern)

Builds LPS once → O(m).

KMP search through text → O(n) where n = |text|.

Total = O(n + m).

(c) repeatedStringMatch(a, b)

Builds the repeated string until its length ≥ |b|.
THough while loop runs ceil(|b| / |a|) + 1 times 
Worst case, we need about ceil(|b| / |a|) + 1 concatenations.
----------------------------------------------------------------------
(This line is very important.) But concatenating strings naively costs O(length of result) each time,
---------------------------------------------------------------------- but in C++ this is implemented efficiently, so effectively total
concatenation cost is O(|b| + |a|) =  O(|n| + |m|)  =  O(|text| + |pattern|).

At most two KMP checks are done:

Once when repeated length ≥ |b|

Once more with one extra copy of a.

So each KMP is O(n + m), where n ≈ |b| + |a| and m = |b|.

: Final Time Complexity

String building: O(|b| + |a|)

Two KMP runs: 2 × O(|b| + |a|) = O(|b| + |a|)

Total:

Time Complexity=O(∣a∣+∣b∣) where a is m that is text that is what we are adding repeatedly and b is m that is patterm.
so time complexity is O(m+n)

*/


// ________________________________________________________________________________________
// Logic
// ____________________________________________________________________________________________


/*

problem statement is there are two strings a and b. And we have to check whether b is substring of a. But there is a catch.
string a is so small so we have to keep adding a to itself and then we check. so string a is text and string b is pattern.
so keep on checking whether pattern is in the string. this is pattern searching algorithm so use kmp algo.

You’re using KMP (Knuth-Morris-Pratt) algorithm for substring search. The flow is:
Build the repeated string a until its length is at least |b|.
Use KMP to check if b is a substring of this repeated string.
If not found, append a once more and check again.

The minimum number of repetitions required can be determined more precisely. A string 'a' needs to be repeated until its length is at least the
length of 'b'. After that, one more repetition is sufficient to catch any alignment issues
keep repeating 'a' until the generated string is at least as long as 'b'.
This ensures 'b' has a chance to be a substring.

*/





// ________________________________________________________________________________________
// code
// ____________________________________________________________________________________________
/*



class Solution
{
public:
// this lps array code is explained in gfg -> 8_string , file number around 20-21.
    // Function to compute the Longest Proper Prefix Suffix (LPS) array.
    // The LPS array for a pattern helps in skipping characters when a mismatch occurs.
    vector<int> lpsArray(string str)
    {
        int n = str.length();
        // lps[i] stores the length of the longest proper prefix of str[0...i] which is also a suffix of str[0...i].
        vector<int> lps(n, 0);

        // 'len' tracks the length of the previous longest prefix suffix.
        int len = 0;
        // 'j' iterates through the pattern to build the lps array, starting from the second character.
        int j = 1;

        while (j < n)
        {
            // Case 1: Characters match.
            // The prefix-suffix length increases by 1.
            if (str[len] == str[j])
            {
                len++;
                lps[j] = len;
                j++;
            }
            else // Case 2: Characters do not match.
            {
                // If len is not 0, we fall back using the lps value of the previous character.
                // This is the key optimization of KMP. We don't reset to the beginning.
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else // If len is 0, there is no prefix to fall back to.
                {
                    // Set lps[j] to 0 and move to the next character.
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps;
    }
// this kmp algo code is explained in gfg -> 8_string , file number around 20-21.
    // KMP algorithm to find if 'pattern' exists as a substring in 'text'.
    bool PatternSearchingKmpAlgo(string text, string pattern)
    {
        // First, compute the LPS array for the pattern. This is pre-processing.
        vector<int> lps = lpsArray(pattern);

        int n1 = text.length();    // Length of the text
        int n2 = pattern.length(); // Length of the pattern
        int i = 0;                 // Pointer for text
        int j = 0;                 // Pointer for pattern

        while (i < n1)
        {
            // If characters match, advance both pointers.
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }

            // If 'j' reaches the end of the pattern, a full match is found.
           if (j == n2)
                return true;
            // This 'else if' handles a mismatch.
            else if (i < n1 && text[i] != pattern[j])
            {
                // If mismatch occurs at the beginning of the pattern (j=0),
                // just move to the next character in the text.
                if (j == 0)
                {
                    i++;
                }
                else
                {
                    // For a mismatch after some partial match, use the LPS array to "jump"
                    // the pattern forward, avoiding re-checking already matched prefixes.
                    // We do not increment 'i'.
                    j = lps[j - 1];
                }
            }
        }
        // If the end of the text is reached and no full match was found.
        return false;
    }

    // Main function to solve the "Repeated String Match" problem.
    int repeatedStringMatch(string a, string b)
    {
        // Start with one repetition of 'a'.
        string repeated_string_a = a;
        int count_of_repeated_string = 1;


        The minimum number of repetitions required can be determined more precisely. A string a needs to be repeated until its length is at least the
        length of b. After that, one more repetition is sufficient to catch any alignment issues
        // Keep repeating 'a' until the generated string is at least as long as 'b'.
        // This ensures 'b' has a chance to be a substring.
        while (repeated_string_a.length() < b.length())
        {
            repeated_string_a += a;
            count_of_repeated_string += 1;
        }

        // Check if 'b' is a substring of the generated string using KMP.
        if (PatternSearchingKmpAlgo(repeated_string_a, b))
            return count_of_repeated_string;

        // If not found, add 'a' one more time. This handles cases where 'b'
        // spans across the boundary of two 'a's (e.g., a="abc", b="ca").
        repeated_string_a += a;
        // The count is now one more than the previous value.

        // Check again.
        if (PatternSearchingKmpAlgo(repeated_string_a, b))
            return count_of_repeated_string + 1; // You had a small bug here, it should be count + 1

        // If it's still not found, it's impossible.
        return -1;
    }
};


*/