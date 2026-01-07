// Before doint this please read file no 20_prerequisiteOfKmpAlgo and file 22_lpsArrayE.cpp and in my dsa book problem no 5

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> longProperPrefixSuffix(string str)
{
    int n = str.length();

    vector<int> lps(n);

    // length will work as length of current longest prefix-suffix
    int length = 0;

    // i will work as pointer traversing the string
    int i = 1;

    lps[0] = 0;

    while (i < n)
    {
        if (str[length] == str[i])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void kmpAlgo(string pattern, string text)
{
    vector<int> lps = longProperPrefixSuffix(pattern);

    int n = text.length();
    int m = pattern.length();
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - m << " ";
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    std::string text = "GEEKSFORGEEKS";
    std::string pattern = "GEEKS";

    kmpAlgo(pattern, text);
    return 0;
}

// time space

/*

Complexity Analysis
Time Complexity: O(n + m)

longProperPrefixSuffix(pattern) takes O(m) time, where m is the length of the pattern.

The while loop for searching in the kmpAlgo function takes O(n) time, where n is the length of the text. Although the text pointer i doesn't always advance, the number of times the pattern pointer j can be "decremented" (by j = lps[j-1]) is bounded by the number of times it was incremented. The total operations are proportional to n.

The overall time is the sum of these two steps: O(m) + O(n) = O(n + m).

Space Complexity: O(m)

The dominant factor for space is the lps vector, which stores an integer for each character in the pattern.

*/

/*


Although the text pointer i doesn't always advance, the number of times the pattern pointer j can be "decremented" (by j = lps[j-1]) is
bounded by the number of times it was incremented. The total operations are proportional to n.

The overall time is the sum of these two steps: O(m) + O(n) = O(n + m).

Space Complexity: O(m)

The dominant factor for space is the lps vector, which stores an integer for each character in the pattern. Therefore,

*/
// logic
// LPS arraya's logic is already covered in previous file 22.
/*

void kmpAlgo(std::string pattern, std::string text)
{
    // BUG FIX: The LPS array must be computed for the 'pattern', not the 'text'.
    // This array tells us about the structure of the pattern to enable smart shifts.
    std::vector<int> lps = longProperPrefixSuffix(pattern);

    int n = text.length();      // Length of the text
    int m = pattern.length();   // Length of the pattern

    int i = 0; // Pointer for the text
    int j = 0; // Pointer for the pattern

    while (i < n)
    {
        // Case 1: Characters match.
        // Advance both the text and pattern pointers.
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        // Case 2: A full pattern match is found.
        if (j == m)
        {
            // Print the starting index of the found pattern.
            // (i is the end position, j=m is the length, so i-j is the start).
            std::cout << "Found pattern at index " << i - j << " ";

            // This is the key to finding subsequent (and overlapping) matches.
            // We update j to the LPS value of the last character of the pattern.
            // This effectively shifts the pattern to align a known prefix-suffix,
            // avoiding redundant character checks.
            j = lps[j - 1];
        }
        // Case 3: Mismatch after some characters have matched.


        The while loop condition (while (i < n)) is only checked at the beginning of each iteration. It ensures that when a new iteration
        starts, i is a valid index for text.

        The i pointer can be incremented inside the loop. In your code, when a character matches (text[i] == pattern[j]), the program executes i++.

        A "race condition" can occur within a single loop iteration. It is possible for i to be less than n at the start of the loop, but after
        being incremented by i++, its new value becomes equal to n.

        The else if is checked after the potential increment. If i becomes equal to n after a character match, the program will then evaluate the
        else if condition in the same iteration. Without the i < n check, the code would attempt to access text[i] (which would be text[n]), 
        causing an out-of-bounds error since the last valid index is n-1.


        why check i < n again. When pattern length is larger than text then after matching with some chars i increments and we have to
        // ensure i doesnt get out of bound.
        consider a different case: text = "a", pattern = "ac"
        n=1, m=2.
        i=0, j=0.
        while(0<1) is true.
        if(text == pattern) is true. i becomes 1, j becomes 1.
        Now we reach else if (i < n && ...)
        The check i < n becomes 1 < 1, which is false
        else if (i < n && text[i] != pattern[j])
        {
            // If j is not 0, it means we have a partial match.
            // We consult the LPS array to find the length of the next-best
            // prefix of the pattern that could match the text we just saw.
            // We DON'T increment i; we retry the comparison at the current `i`.
            if (j != 0)
                j = lps[j - 1];
            else
                // If j is 0, no part of the pattern was matching.
                // We simply move on to the next character in the text.
                i++;
        }
    }
}

*/

// dry run

/*


Setup
Text: A B A C A B A B D

Pattern: A B A B

LPS Array for ABAB: We will assume this is pre-computed as ``.

Pointers:

i: pointer for the text (starts at 0)

j: pointer for the pattern (starts at 0)

Dry Run


Step   i   j   text[i]   pattern[j]   Match?    Action
--------------------------------------------------------------
1      0   0     'A'        'A'       Yes       i=1, j=1
2      1   1     'B'        'B'       Yes       i=2, j=2
3      2   2     'A'        'A'       Yes       i=3, j=3
4      3   3     'C'        'B'       No        j=lps[2]=1, i=3
5      3   1     'C'        'B'       No        j=lps[0]=0, i=3
6      3   0     'C'        'A'       No        i=4, j=0
7      4   0     'A'        'A'       Yes       i=5, j=1
8      5   1     'B'        'B'       Yes       i=6, j=2
9      6   2     'A'        'A'       Yes       i=7, j=3
10     7   3     'B'        'B'       Yes       i=8, j=4
11     8   4      -           -       Match!    Found at i-j=4, j=lps[3]=2
12     8   2     'D'        'A'       No        j=lps[1]=0, i=8
13     8   0     'D'        'A'       No        i=9, j=0
14     9   0      -           -        -        Loop ends (i=9==n)



*/