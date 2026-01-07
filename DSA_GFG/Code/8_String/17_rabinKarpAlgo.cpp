// What is Rabin Karp Pattern Searching Algorithm


/*

The Rabin-Karp algorithm is an efficient string-searching algorithm that uses hashing to find a pattern within a larger text. Instead of comparing 
characters one-by-one, it converts the pattern and substrings of the text into numeric values (hashes) and compares those numbers first, significantly
 speeding up the process.[1][6][7]

A character-by-character comparison is only performed when the hash values match, ensuring accuracy.[5]

### Core Concept: Hashing and Rolling Hash

The algorithm's power comes from two key ideas: hashing and the "rolling hash".[7]

1.  **Hashing**: The algorithm converts a string into a fixed-size integer. If two strings are identical, their hash values will be identical. The 
reverse is not always true; different strings can occasionally have the same hash value (a "collision").[6]

2.  **Rolling Hash**: The main innovation of Rabin-Karp is the rolling hash. Instead of recalculating the hash from scratch for every substring in 
the text (which would be inefficient), it calculates the hash for the next substring by making a quick update to the previous one. This is typically 
done in constant time, O(1).[6][7]


### How the Rolling Hash Works

To calculate the hash for a new window, the algorithm performs three steps:
1.  **Remove** the value of the character that is leaving the window.
2.  **Shift** the remaining values by multiplying the hash by a base number.
3.  **Add** the value of the new character entering the window.

The formula for a polynomial rolling hash is:
`hash_new = (hash_old - val_old_char * base^(m-1)) * base + val_new_char`

Here, `m` is the length of the pattern. A prime number is often used as the base to minimize collisions.[4][7]

### The Algorithm Step-by-Step

Let's say we are searching for a pattern `P` in a text `T`.
1.  **Initialization**: Define a base (e.g., the number of characters in the alphabet) and a large prime number for the modulus to keep hash values
 manageable.[4]
2.  **Hash Pattern**: Calculate the hash value for the pattern `P`.
3.  **Hash First Window**: Calculate the hash value for the first substring of the text `T` that has the same length as `P`.
4.  **Slide and Compare**:
    *   Slide a window of the pattern's length across the text, one character at a time.
    *   At each step, compare the hash of the current text window with the pattern's hash.
    *   **If the hashes do not match**, move to the next window and update its hash using the rolling hash formula.[8]
    *   **If the hashes match**, it could be a genuine match or a hash collision. The algorithm then performs a character-by-character comparison 
    * of the substring and the pattern to verify.[5]
    *   If the characters match, a pattern occurrence is found at the current index.
5.  Repeat until the end of the text is reached.

### Example

*   **Text (T)**: `abacaabacaba`
*   **Pattern (P)**: `aaba`
*   Let `m = 4` (length of `P`) and `n = 12` (length of `T`).

1.  **Calculate Hash(P)**: Calculate the hash for "aaba".
2.  **Initial Window**: Calculate the hash for the first window of `T`, which is "abac".
3.  **Slide and Compare**:
    *   `Hash("abac")` != `Hash("aaba")`. Slide the window.
    *   Use the rolling hash to efficiently find `Hash("baca")` from `Hash("abac")`.
    *   Continue this process: `Hash("acaa")`, `Hash("caab")`.
4.  **Hash Match**: Eventually, the window is at index 5: "aaba". `Hash("aaba")` will match `Hash(P)`.
5.  **Verify**: The algorithm performs a character-by-character check on "aaba" and confirms it's a true match. It records that the pattern was 
found at index 5.
6.  The process continues until the end of the text.



### SLide window means:

abcdef and pattern is cde
first window will be abc then next window is bcd. This next window is calculated by substacting first element of previous window and 
adding the first element of next window. Like for second window substract a and add d so we will get bcd.



### Rabin-Karp Algorithm Example


Text: "abcdef"

Pattern: "cde"

for simplicity a,b,c,d... are considered as 1,2,3,4....


Step 1: Compute the Hash Value of the Pattern
Let's say hash("cde") = 3*31^2 + 4*31^1 + 5*31^0 = 2886.
If pattern length is 3 then exponential term will be 2, then 1 and then 0
31 is the base number. We can take any number as a base. Generally we take 256 because there are 256 values in ascii character.

Step 2: Compute the Hash Value of the First Substring of the Text
For the first substring "abc":

hash("abc") = 1*31^2 + 2*31^1 + 3*31^0 = 1026.

Step 3: Slide the Window Over the Text and Compare Hash Values
Slide the window to the next substring "bcd":

Update hash: hash("bcd") = (1026 - 1*31^2) * 31 + 4 = 1957.
here subtracting a therefore 1*31^2. Addititon should be - it is d therefore 4 * 31^0. = 4. And race to 0 because it is last term of window.
If third term is only 4 then why it is looking as * 31 + 4.
The reason that we multiplied with 4 because after subtracting first character we need to shift remaining character to the left side.
And if we shift it to left then everyone's power will be increase by 1. Because powers were 2,1,0. Element of power 2 got substracted.
So other element shifted to left. So power 1 become power 2 and power 0 become power 1. 
And outside the bracket if we multiply bracket by 31^1 then each power will increase by 1 that means they have shifted to left.
And now we have added our remaining 4. So therefore ( ) * 31 + 4



No match with the pattern's hash, so slide again.

Slide to the next substring "cde":

Update hash: hash("cde") = (1957 - 2*31^2) * 31 + 5 = 2886.

The hash matches the pattern’s hash.

Step 4: Check for Hash Collisions
Since the hash values match, we compare the actual substring "cde" with the pattern "cde".

They match, so we’ve found the pattern at index 2 in the text.





















### Performance and Complexity

*   **Best and Average Case Time Complexity**: **O(n + m)**, where `n` is the length of the text and `m` is the length of the pattern. This is 
achieved when hash collisions are rare. The `O(m)` part is for hashing the pattern, and `O(n)` is for iterating through the text.[3][6]
*   **Worst-Case Time Complexity**: **O(n \* m)**. This occurs if every substring of the text has the same hash as the pattern, forcing a 
character-by-character comparison at every step. This is called a "spurious hit". A good hash function makes this scenario extremely unlikely 
in practice.[6]

### Applications

The Rabin-Karp algorithm is particularly effective for certain tasks:
*   **Plagiarism Detection**: It can rapidly search a document for multiple sentences or phrases from a source material.[7][6]
*   **DNA Sequencing**: Finding specific gene sequences within a larger genome.
*   **Multiple Pattern Search**: It is efficient at searching for many different patterns within a single text because the text's substrings 
only need to be hashed once.[5]




*/