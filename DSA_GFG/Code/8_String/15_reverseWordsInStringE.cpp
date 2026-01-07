// Reverse words in sentence of string
// i love coding: coding love i
// shubh : shubh

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

void reverseStr(string &s, int begin, int end)
{
    while (begin <= end)
    {
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}

void reverseWordsInString(string &s1)
{

    reverseStr(s1, 0, s1.length() - 1);

    int start_of_word = 0;

    for (int i = 0; i <= s1.length(); i++)
    {

        if (s1[i] == ' ' || i == s1.length())
        {
            int end = i - 1;
            reverseStr(s1, start_of_word, end);
            start_of_word = i + 1;
        }
    }
}

int main()
{
    string s1 = "I want to code";
    reverseWordsInString(s1);

    for (auto x : s1)
        cout << x;

    return 0;
}


// Time Complexity: O(N)
// Space Complexity: O(1)


// logic

/*


 * @brief Reverses a portion of a string in-place using two pointers.
 * @param s The string to modify, passed by reference.
 * @param begin The starting index of the portion to reverse.
 * @param end The ending index of the portion to reverse.
 
void reverseStr(string &s, int begin, int end)
{
    // Use two pointers, one at the start and one at the end, moving towards the center.
    while (begin < end) // Using '<' is slightly more efficient than '<='
    {
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}


 * @brief Reverses the order of words in a string using an in-place algorithm.
 * @param s1 The string to be modified, passed by reference.
 
void reverseWordsInString(string &s1)
{
    // Step 1: Reverse the entire string.
    // "I want to code" becomes "edoc ot tnaw I"
    reverseStr(s1, 0, s1.length() - 1);

    // Step 2: Reverse each individual word in the now-reversed string.
    int start_of_word = 0;

    // Loop one past the end of the string to handle the last word.
    // = because in below if condition for ||  s1[i] == ' ' this will go out of bound to check for i == s1.length()
    for (int i = 0; i <= s1.length(); i++) 
    {
        // A word ends when a space is found or we reach the end of the string.
        if (i == s1.length() || s1[i] == ' ')
        {
            // The end of the current word is the character just before the space/end.
            int end_of_word = i - 1;
            
            // Reverse the individual word.
            // e.g., "edoc" becomes "code"
            reverseStr(s1, start_of_word, end_of_word);
            
            // The next word will start after the current space.
            start_of_word = i + 1;
        }
    }
}




*/