/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:
Input: s = "aba"
Output: false
Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++)
        {
            if (n % len == 0)
            {
                string substring = s.substr(0, len);

                bool is_matched = true;

                for (int i = len; i < n; i += len)
                {
                    if (substring != s.substr(i, len))
                    {
                        is_matched = false;
                        break;
                    }
                }
                if (is_matched)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    string s1 = "abcabcabcabc";

    cout << sol.repeatedSubstringPattern(s1);
    return 0;
}


// timesapce


/*

Time Complexity: O(n²)
The time complexity is determined by the nested operations within the loops. Let's analyze it from the inside out:
String Comparison: The line substring != s.substr(i, len) is the most expensive operation. It compares two strings of length len. In the worst 
case, this takes time proportional to the length of the strings, which is O(len).
Inner Loop: The loop for (int i = len; i < n; i += len) iterates through the "blocks" of the string. It runs approximately n/len times.
Work per len: For any given len, the total work done is the number of times the inner loop runs multiplied by the cost of the comparison inside 
it. This is (n/len) * O(len) = O(n).
Outer Loop: The outer loop for (int len = 1; len <= n / 2; len++) runs up to n/2 times.
Combining these, the total time complexity is the work done by the outer loop multiplied by the work done inside it for each iteration: 
(n/2) * O(n) = **O(n²)**.
While the if (n % len == 0) check provides a significant optimization in practice (as it skips many values of len), in the worst-case analysis of 
algorithms, we consider the upper bound, which remains O(n²).


Space Complexity: O(n)
The space complexity is determined by the extra memory allocated by the algorithm, not including the input string itself.

substring: The line string substring = s.substr(0, len); creates a new string. The maximum possible value for len is n/2. Therefore, in the 
worst case, this allocation requires O(n) space.
Temporary Substring: Inside the inner loop, s.substr(i, len) also creates a temporary string for the comparison. This also requires a maximum 
of O(n) space.
Since these allocations are not nested in a way that multiplies their space requirements, the peak memory usage is determined by the largest 
single allocation, which is proportional to n.
Therefore, the space complexity is O(n).

*/

// code:



/*

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();

        // we have been told to appending multiple copies of the substring together. So we cant take whole string as a substring because
        // whatever substring  we take we have to make complete string only by appending substring. Take ex abcabcabcabc
        // so there can be blocks like a or ab or abc etc. at max we can take n/2 lenght substring like abcabc so that we can append that
        // string at least once to make compelte string.
        for (int len = 1; len <= n / 2; len++)
        {

            // Optimization: A repeating pattern is only possible if its length
            // is a divisor of the total string length. if n = 12 and our substring is of length 5 then we can not append it 
            // like append once then length = 10 and append twice , length will be 15. So for 12 appending is not possible.
            if (n % len == 0)
            {

                // This is our candidate repeating substring.
                // syntax : s.substr(0, how_many_chars_from_here);
                string substring = s.substr(0, len);
                bool is_a_match = true; // Assume it's a match until we find a problem.

                // Check all the other blocks in the string to see if they match. for abcabcabcabc, suppose substring is abc
                // then we will have 4 blocks of abc. abc abc abc abc. Each block will start with 0,3,6,9. 0th block is substring itself
                // so no need to check.
                // We start from the second block (index 'len') because 1st block is substring itself so it is already checked.
                for (int j = len; j < n; j += len)
                {

                    // Compare the current block with our candidate substring.
                    if (s.substr(j, len) != substring)
                    {
                        is_a_match = false; // Mismatch found!
                        break;              // No need to check any further for this 'len'.
                    }
                }

                // If is_a_match is still true after checking all blocks,
                // it means we found our repeating pattern.
                if (is_a_match)
                {
                    return true;
                }
            }
        }

        // If the main loop finishes without finding any repeating pattern,
        // we can conclude that none exists.
        return false;
    }
};


*/