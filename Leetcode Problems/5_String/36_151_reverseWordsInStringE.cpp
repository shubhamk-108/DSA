/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single
space separating the words. Do not include any extra spaces.
Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        int n = s.length();
        int write = 0;
        int start = 0;
        int end = 0;

        for (start; start < n; start++)
        {
            if (s[start] != ' ')
            {
                if (write != 0)
                {
                    s[write] = ' ';
                    write++;
                }

                end = start;
                while (end < n && s[end] != ' ')
                {
                    s[write] = s[end];
                    write++;
                    end++;
                }
                reverse(s.begin() + write - (end - start), s.begin() + write);
                start = end;
            }
        }
        s.erase(s.begin() + write, s.end());

        reverse(s.begin(), s.end());
        return s;
    }
};
int main()
{
    Solution sol;
    string s1 = "   I want this   ok   ";

    cout << sol.reverseWords(s1);

    return 0;
}

// timespace

/*

Time Complexity

Outer loop (for (start; start < n; start++)) → each character is visited at most twice (once by start, once by end).
→ O(n)

Copying characters into the write pointer → each char copied once.
→ O(n)

Reversing each word → every character participates in exactly one word reversal.
→ O(n)

Final reverse of whole string → reverses all n characters once.
→ O(n)

👉 Total = O(n) + O(n) + O(n) + O(n) = O(n)

🔹 Space Complexity

We’re modifying the string in place (using write pointer to overwrite).

Only a few integers (start, end, write) are used.

No extra arrays, stacks, or vectors.

👉 Extra space = O(1)

*/

// code

/*

Code walkthrough
string reverseWords(string s)
{
    int n = s.length();
    int write = 0;   // pointer where we "write" cleaned characters
    int start = 0, end = 0; // scan pointers

1. Loop through string
for (; start < n; start++)
{
    if (s[start] != ' ')
    {


We skip spaces until we find the beginning of a word.

2. Add space between words
        if (write != 0)  // <-- means we've already written at least one word
        {
            s[write] = ' ';
            write++;
        }


Ensures only single space between words.

No leading space because we check if (write != 0).

3. Copy current word
        // till this point if there were spaces before the first word then start must have come a lot forward. But we have to 
        // begin start and end pointer from the same point. so end becomes start and we begin from here. Now we keep start as
        // it is because we want that next to calculate length of word while reversing individual word. Once we set start
        // and end then we only advances end pointer until we see next space. If we see next space means there is a start of new word.
        end = start;
        while (end < n && s[end] != ' ')
        {
            s[write] = s[end];  // copy char from read to write
            write++;
            end++;
        }


We copy characters of the current word into the front of the string (compacting away extra spaces).

4. Reverse the copied word
        reverse(s.begin() + write - (end - start), s.begin() + write);


end - start is the length of the word.

So this reverses just the last written word.

At this point:

"the sky is blue" (input) → "eht yks si eulb" (compacted and words reversed individually).

// whereever the end finishes before that will be the start of new word so start becomes end.
5. Advance to next word
        start = end;


Skip past this word and continue.

6. Clean up leftovers
s.erase(s.begin() + write, s.end());


Erase whatever remains in the string after write.
Now string only has compacted words.

7. Reverse the whole string
reverse(s.begin(), s.end());
return s;


Since each word was reversed earlier, reversing the entire string puts each word back in correct order, but the word order itself gets reversed.

*/