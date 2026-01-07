/*

What is a Subsequence?
A subsequence is a sequence of characters derived from a string by deleting zero or more characters, without changing the
order of the remaining characters.
The key rules for a subsequence are:
Order is Preserved: The characters in the subsequence must appear in the same relative order as they did in the original
string.
Not Necessarily Contiguous: The characters do not have to be next to each other in the original string.
Let's use the string str = "apple" as an example
"ale" is a subsequence: You can get it by deleting 'p' and 'p'. The characters 'a', 'l', and 'e' are in the same order as
in "apple".
"pp" is a subsequence: You can get it by deleting 'a', 'l', and 'e'.
"ape" is a subsequence: You can get it by deleting 'p' and 'l'.
"eal" is NOT a subsequence: Even though 'e', 'a', and 'l' are all in "apple", their order is changed.
The original string "apple" is a subsequence of itself (by deleting zero characters).
An empty string "" is a subsequence of any string (by deleting all characters).


What is a Substring?
A substring is a sequence of characters that are contiguous (immediately next to each other) within a string.
For the same string str = "apple":
"app" is a substring: The characters 'a', 'p', 'p' are consecutive in the original string.
"ple" is a substring: 'p', 'l', 'e' are consecutive.
"p" is a substring.
"ale" is NOT a substring: The characters 'a' and 'l' are not next to each other in the original string.

*/




// solution


// To check if a string s1 is a subsequence of another string s2, a brute-force approach would involve generating all possible subsequences of s2 and
//  then checking if s1 is present among them.

// TIme and space: 

/*


Time Complexity: O(m * 2^n)

A string of length n has 2^n possible subsequences.
For each of these subsequences, you would need to compare it with s1. A string comparison takes up to O(m) time.
Therefore, the total time complexity is the number of subsequences multiplied by the comparison time, resulting in an exponential 
complexity of O(m * 2^n). This is extremely inefficient and not practical for even moderately sized strings.


Space Complexity: O(n)

To generate and store a single subsequence for comparison, you would need space proportional to its length, which can be up to n in the worst case.
If the algorithm were to generate and store all 2^n subsequences simultaneously before checking them, the space complexity would indeed be 
exponential. Storing 2^n subsequences, where each can have a length up to n, would lead to a massive space requirement.

However, a typical implementation of this brute-force approach wouldn't store all subsequences at once. Instead, it would use recursion to 
generate one subsequence at a time, check it, and then discard it before generating the next one.
Let's clarify the space complexity for that recursive generation:
Recursive Brute-Force Space Complexity: O(n)
When you use recursion to generate subsequences, the space complexity is determined by the maximum depth of the recursion call stack.
For a string of length n, the recursion depth to generate a subsequence will be at most n.


*/

