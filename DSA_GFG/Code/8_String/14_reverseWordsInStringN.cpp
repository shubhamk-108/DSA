// Reverse words in sentence of string
// i love coding: coding love i
// shubh : shubh

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string reverseWordsInString(string &s1)
{
    stack<string> st;
    string current_word = "";
    for (int i = 0; i < s1.length(); i++)
    {
        // here give single quotes because s1[i] is a character and we are comparing characters here not string
        if (s1[i] != ' ')
        {
            current_word += s1[i];
        }
        else
        {
            // Only push the word if it's not empty (handles multiple spaces).
            if (!current_word.empty())
            {
                st.push(current_word);
                current_word = "";
            }
        }
    }

    if (!current_word.empty())
    {
        st.push(current_word);
    }

    string result;

    while (!st.empty())
    {
        result += st.top();
        st.pop();
        if (!st.empty())
            result += " ";
    }

    for (auto x : result)
    {
        cout << x;
    }

    return result;
}

int main()
{
    string input = "welcome to coding";
    string reversed = reverseWordsInString(input);

    cout << "Original string: \"" << input << "\"" << endl;
    cout << "Reversed words:  \"" << reversed << "\"" << endl;

    return 0;
}


// time and space 

/*

Time Complexity: O(N)
The complexity is determined by how many times you process the characters of the string.

First Loop (Pushing to Stack):
for (int i = 0; i < s1.length(); i++)
{
    // ... logic to build and push words
}
This loop iterates through every character of the string exactly once to identify words and push them onto the stack. This is a linear 
operation, so its complexity is O(N).

Second Loop (Popping from Stack):

while (!st.empty())
{
    result += st.top();
    // ...

}

This loop runs M times (once for each word). In this loop, you are appending words to the result string. The total number of characters
 appended across all loop iterations is N minus the spaces. This character-by-character appending also contributes linearly to the complexity. 
 The combined work of popping all words and building the new string is also proportional to the total number of characters, which is O(N).


 Third Loop (Printing):
for (auto x : result)
{
    cout << x;
}

O(N) operation.

O(N) + O(N) + O(N) simplifies to O(N)


Space Complexity: O(N)

In the worst-case scenario, the stack will hold all the words from the input string at the same time. The total number of characters across 
all these words is proportional to N. Therefore, the space required by the stack is O(N).

current_word string: This string holds one word at a time. In the worst case (a string with one very long word), its size could be up to N.

result string: This string is built at the end and will also store approximately N characters.

The dominant factor for auxiliary space is the stack (and the final result string), which needs to store all the characters of the original 
string. Therefore, the space complexity is O(N)


*/


// logic

/*


 * @brief Reverses the order of words in a string using a stack.
 * 
 * This function iterates through the input string, identifies words separated
 * by spaces, and pushes them onto a stack. It then pops the words from the
 * stack to construct a new string with the words in reverse order.
 * 
 * @param s The input string to be reversed word by word.
 * @return A new string with the words in reversed order.
 
string reverseWords(const string &s) {
    // A stack to store the words in LIFO (Last-In, First-Out) order.
    stack<string> wordStack;
    
    // A temporary string to build up the current word.
    string currentWord = "";

    // --- Pass 1: Extract words and push them onto the stack ---
    for (char c : s) {
        // If the character is not a space, add it to the current word.
        if (c != ' ') {
            currentWord += c;
        } 
        // If the character is a space, it marks the end of a word.
        else {
            // Only push the word if it's not empty (handles multiple spaces).
            if (!currentWord.empty()) {
                wordStack.push(currentWord);
                currentWord = ""; // Reset for the next word.
            }
        }
    }

    // After the loop, the last word needs to be pushed onto the stack.
    if (!currentWord.empty()) {
        wordStack.push(currentWord);
    }

    // --- Pass 2: Pop words from the stack to build the result ---
    string result = "";
    while (!wordStack.empty()) {
        // Add the top word from the stack to the result.
        result += wordStack.top();
        wordStack.pop(); // Remove the word from the stack.

        // Add a space after the word, but not for the very last one.
        if (!wordStack.empty()) {
            result += " ";
        }
    }

    return result;
}



*/