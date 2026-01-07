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
#include <stack>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {

        int n = s.length();
        stack<string> st;
        int i = 0;
        string word;
        while (i < n)
        {

            if (s[i] != ' ')
            {
                word += s[i];
            }
            else
            {
                if (!word.empty())
                {
                    st.push(word);
                    word = "";
                }
            }
            i++;
        }
        if (!word.empty())
        {
            st.push(word);
        }

        string ans;
        if (!st.empty())
        {
            ans = st.top();
            st.pop();
            while (!st.empty())
            {
                ans += ' ';
                string single_word = st.top();
                ans += single_word;
                st.pop();
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s1 = "   I want this   ok   ";

    cout << sol.reverseWords(s1);

    return 0;
}



//timespace

/*

class Solution
{
public:
    string reverseWords(string s)
    {
        // Get the length of the input string for loop bounds.
        int n = s.length();
        // A stack is used to store words. Its Last-In, First-Out (LIFO) nature
        // is perfect for reversing the order of words.
        stack<string> st;
        // Index 'i' to iterate through the input string 's'.
        int i = 0;
        // 'word' is a temporary string to build up characters of a single word.
        string word;

        // --- Step 1: Parse the string and push words onto the stack ---
        while (i < n)
        {
            // If the current character is not a space, it's part of a word.
            if (s[i] != ' ')
            {
                word += s[i];
            }
            // If the current character is a space, it marks the end of a word.
            else
            {
                // If the 'word' string is not empty, it means we've just finished a word.
                if (!word.empty())
                {
                    // Push the completed word onto the stack.
                    st.push(word);
                    // Reset 'word' to be empty for the next word.
                    word = "";
                }
            }
            // Move to the next character.
            i++;
        }
        
        // After the loop, there might be a trailing word that wasn't followed by a space.
        // For example, in "hello world", the loop ends after 'd'.
        // We need to push this last word onto the stack.
        if (!word.empty())
        {
            st.push(word);
        }

        // --- Step 2: Pop words from the stack to build the reversed string ---
        string ans;
        // Check if the stack contains any words.
        if (!st.empty())
        {
            // The first word popped is the last word from the original string.
            // Initialize 'ans' with this word. No leading space is needed.
            ans = st.top();
            st.pop();

            // Continue popping words as long as the stack is not empty.
            while (!st.empty())
            {
                // Add a single space before appending the next word.
                ans += ' ';
                // Get the next word from the top of the stack.
                string single_word = st.top();
                // Append it to the answer.
                ans += single_word;
                // Pop the word from the stack.
                st.pop();
            }
        }
        
        // Return the final reversed string.
        return ans;
    }
};


*/


// code
// same question is alreadt solved in dsa - > gfg -> 8_string -  >32_reverseWordsRemoveDotsN.cpp and and 33_reverseWordsRemoveDotsE.cpp
// There is it well explained.


/*

Time Complexity: O(n)

The first while loop iterates through the entire input string of length n exactly once. This is an O(n) operation.
The second while loop pops each word from the stack. Since each character from the original string is pushed and popped exactly once 
(as part of a word), this process is also proportional to the total number of characters, n.
Therefore, the overall time complexity is O(n) + O(n), which simplifies to O(n), where n is the length of the input string s.

Space Complexity: O(n)
In the worst-case scenario, the entire string could be a single word, or a series of words that collectively have n characters.
The stack<string> st will store all the words from the string. The total number of characters stored in the stack will be equal to the 
number of non-space characters in the string, which is at most n.
Additionally, the ans string is built, which also stores up to n characters.
The space required is therefore proportional to the length of the string, making the space complexity O(n).

*/