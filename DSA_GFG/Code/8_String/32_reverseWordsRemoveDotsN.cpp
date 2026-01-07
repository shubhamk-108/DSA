#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#include<stack>
string reverseWords(string &s)
{
    // code here

    stack<string> st;
    string word;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '.')
        {
            word += s[i];
        }
        else
        {

            if(!word.empty())
            {
                st.push(word);
                word = "";
            }
        }
    }
    if(!word.empty())
        st.push(word);

    string res;
    while(!st.empty())
    {
        res+=st.top()+'.';
        st.pop();
    }
    // remove dot after very last word. pass index to erase funtion.
    res.erase(res.length()-1);
    return res;
}

int main()
{
    string str = "..i.like.this.program.very....much....";
    string all_words = reverseWords(str);
    for (auto x : all_words)
        cout << x;
    return 0;
}



// time space

/*

Time Complexity

Traversal of string (for loop) → O(n)
Each character is checked once.
Word construction is O(1) amortized (since appending to string).
Pushing words into stack → In total across the loop, still O(n) (each character belongs to exactly one word).
Building the result (while (!st.empty())) → Again O(n) (each character copied once into res).
So, overall:
O(n)


Space Complexity
Stack: Stores all words → in the worst case, if string is "a.b.c.d", the stack holds ~n/2 words, each totaling O(n) characters. So O(n).
Result string: Another O(n) for res.
Auxiliary: Few variables, negligible.
So, total:
O(n)

✅ Final Answer:

Time Complexity = O(n)
Space Complexity = O(n)


complexity of res.erase(res.length() - 1);

Complexity of erase in C++ std::string
In general, erase(pos) shifts all characters after pos one step left.
That’s why erase at the front or middle is O(n).
But here:
pos = res.length() - 1 → the last character.
No shifting needed, just reduce the internal size counter.
So the complexity is:
O(1)


*/

// logic


/*

// Function to reverse the order of words in a string
// Words are separated by dots ('.')
string reverseWords(string &s)
{
    // Stack will hold words in the order they appear
    stack<string> st;
    string word;

    // Traverse the string character by character
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '.')
        {
            // Build the current word
            word += s[i];
        }
        else
        {
            // When we hit a dot, push the completed word onto the stack
            if (!word.empty())
            {
                st.push(word);
                word = "";   // reset for next word
            }
        }
    }

    // Push the last word (if there is one) after loop ends
    if (!word.empty())
        st.push(word);

    // Pop words from the stack to build the reversed string
    string res;
    while (!st.empty())
    {
        res += st.top() + '.';   // append word + dot
        st.pop();
    }

    // Remove the extra dot added after the final word
    res.erase(res.length() - 1);

    return res;
}



*/