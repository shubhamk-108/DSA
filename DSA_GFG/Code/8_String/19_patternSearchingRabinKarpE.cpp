// Read previous two files to understand. 17_rabinKarpAlgo and 18_rabinKarpPrerequisite
// Read prerequisite of this rabin karp algorithm in previous code file

#include <iostream>
#include <string>

#include <iostream>
#include <string>

#define d 256

void rabinKarp(const std::string &pattern, const std::string &text, int q)
{
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
{
    std::string text = "GEEKSFORGEEKS";
    std::string pattern = "GEEKS";
    int q = 101;
    rabinKarp(pattern, text, q);
    return 0;
}

// time and space

/*

Precomputation of h - for (i = 0; i < m - 1; i++)  - Runs m−1 times → O(m).

Initial Hash Calculation - for (i = 0; i < m; i++)  - Runs m times → O(m).

Sliding the Pattern Over Text - for (i = 0; i <= n - m; i++)  -
Outer loop runs (n−m+1) ≈ O(n) times.
Inside:
Hash comparison (p == t) is O(1).
Character-by-character check runs O(m) in the worst case — but usually it’s skipped (only happens when hashes match, which is rare).
Rolling hash update is O(1).
So:
Average case:
Hash comparisons are quick, very few character-by-character checks →
O(n+m)
Worst case:
Lots of spurious hash matches → each match costs O(m) →
O((n−m+1)⋅m)≈O(nm)
(Example: text = "AAAAAA...", pattern = "AAA", many false matches.)
Time Complexity Summary:
Average: O(n + m)
Worst case: O(nm)


Space Complexity
Variables used: p, t, h, i, j → constant space.
No extra arrays, no recursion.
Input strings are given, so we don’t count them.
Space Complexity = O(1)



*/

// Logic

/*



// d is the number of characters in the input alphabet
#define d 256


    // text: The text to search within
    // pattern: The pattern to search for
    // q: A prime number used for the modulo operation

void rabinKarp(const std::string &pattern, const std::string &text, int q)
{
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for the current text window
    int h = 1;

    // 1. Pre-computation: Calculate h = (d^(m-1)) % q
    // This value is used to remove the leading digit from the hash.
    // In the end in the hash formula: right most char will be substracted. So it will have char * base^m-1.
    // So we are calculating this base^m-1. So everytime it substracts the first char when we shifts window, we do not have to calculate it
    // again and again

    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    // 2. Initial Hashes: Calculate the hash of the pattern. This is calculated using incremented technique and not directly like for ex 2^8.
    // and the first window of the text
    // see file 18
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // 3. Slide the pattern over the text one by one
    // i is less equals because first we are checking the p == t and at the end we are calculating next window's t.
    // So when we calculate t for very last window then we need one more iteration to check p == t for that last window.
    // that is why there is equal to sign in i<=n
    for (i = 0; i <= n - m; i++)
    {
        // Step 3a: Check if the hash values match
        if (p == t)
        {
            // If hashes match, verify character by character (to handle collisions)
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            // If the inner loop completed, a true match was found
            if (j == m)
            {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }

        // after creating the hash for very last window we need one more iteration to check if that hash mathches to pattern;s hash
        so it will take one more pass and that is why in above loop we take i <= n-m. So in that pass we do not need to compute more
        // hash because we would have calculated all the windows till then. so to ensure it will not go out of bound index we are
        // applying check here that i < n - m.
        // Step 3b: Calculate the hash for the next window
        if (i < n - m)
        {
            // Use the rolling hash formula
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // We might get a negative value for t, convert it to positive
            // see file 18. Negative Modulo
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}



*/

// Question

// wont rabin karp pattern search be better than above solution giving O(n+m) time and O(1) space

/*


The Critical Details
1. Time Complexity: Reliability Matters
The biggest advantage of the concatenation method is its guaranteed O(N) performance. The Rabin-Karp algorithm, while O(N) on average, can degrade to a quadratic O(N²) in the worst case (e.g., strings like "aaaaa" and "aaaba" with a poorly chosen hash function). For an interview, a solution with a reliable worst-case guarantee is almost always preferred over one that is only fast on average.

2. Space Complexity: The O(1) is Tricky
You are absolutely right that Rabin-Karp's algorithm uses O(1) auxiliary space. However, to use it here, we need to search within the "text" s1+s1.

If you first create the s1+s1 string and then run Rabin-Karp, your space complexity is still O(N) because you allocated that temporary string.

To achieve true O(1) space, you would have to write a more complex implementation that simulates moving over s1+s1 without actually creating it.

For a typical coding interview: The concatenation (s1+s1) method is better.


*/