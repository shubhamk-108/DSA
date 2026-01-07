// Lps Array :

/*


In the Knuth-Morris-Pratt (KMP) algorithm, the LPS array, which stands for "Longest Proper Prefix which is also Suffix," is a precomputed array 
that helps optimize pattern searching by telling the algorithm how many characters to skip when a mismatch occurs. This avoids redundant comparisons
and allows the search to proceed more efficiently than naive approaches.

The core idea is to identify the length of the longest proper prefix of a pattern's substring that is also a suffix of that same substring.

Key Definitions
Prefix: A substring that starts at the beginning of the string. For ABCD, the prefixes are A, AB, ABC, and ABCD.

Suffix: A substring that ends at the end of the string. For ABCD, the suffixes are D, CD, BCD, and ABCD.

Proper Prefix/Suffix: Any prefix or suffix that is not the entire string itself. For ABCD, the proper prefixes are A, AB, ABC, and the proper 
suffixes are D, CD, BCD.

The LPS array stores, for each position i in the pattern, the length of the longest proper prefix of the substring pattern[0...i] that is also a 
suffix of that substring.

Constructing the LPS Array
The LPS array is constructed by iterating through the pattern and calculating the LPS value for each prefix. The value lps[i] represents the 
length of the longest proper prefix of pattern[0...i] that is also a suffix of pattern[0...i].

Example for pattern aabaaac:

Index   Substring   Proper Prefixes         Proper Suffixes       Longest Match   lps value
0       a           (none)                  (none)                (none)          0
1       aa          a                       a                     a               1
2       aab         a, aa                   b, ab                 (none)          0
3       aaba        a, aa, aab              a, ba, aba            a               1
4       aabaa       a, aa...                a, aa...              aa              2
5       aabaaa      a, aa, aaa...           a, aa, aaa...         aaa             2*
6       aabaaac     a, aa...                c, ac...              (none)          0

*Note: In the substring aabaaa at index 5, the longest prefix that is also a suffix is aa, not aaa, because the characters at index 2 (b) and 
index 5 (a) do not match when extending the aa prefix.


### Another Example

aabcdk

prefix: for prefix take every combination except last char. Always start prefix from initial char.
suffix: for suffix take every combination except first char.Always start suffix from last char.

prefix: a,aa,aab,aabc,aabcd
suffix:k, dk, cdk, bcdk, abcdk

*/