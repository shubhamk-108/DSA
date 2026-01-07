/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// This is optimised solution but more cleaner solution is written in next file.
class Solution
{
public:
    void toLowercaseAndRemoveNonAlphaNumeric(string &s)
    {
        // transform(start_iteraotr, end_iterator, where_to_store_iterator_begin_means_store_in_same_String, function)
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int write = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                s[write] = s[i];
                write++;
            }
        }
        s.erase(write, s.length());
    }

    bool isPalindrome(string &s)
    {
        toLowercaseAndRemoveNonAlphaNumeric(s);
        int i=0;
        int j=s.length()-1;

        while (i<=j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;

        }
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout<<sol.isPalindrome(s);
    return 0;
}

// time space

/*

Time Complexity
transform → O(n)
Loop to remove non-alphanumeric → O(n)
Palindrome check → O(n)
Total: O(n)
Space Complexity
In-place modification of string → O(1) auxiliary space
Total: O(1)

*/

// logic

/*

class Solution
{
public:

    // Function to convert all characters to lowercase
    // and remove non-alphanumeric characters in-place
    void toLowercaseAndRemoveNonAlphaNumeric(string &s)
    {
        // Step 1: Convert the entire string to lowercase
        // transform(start_iterator, end_iterator, where_to_store_begin_iterator, function)
        // ::tolower converts each character to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int write = 0; // pointer to place the next valid character

        // Step 2: Compact all alphanumeric characters at the beginning
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i])) // check if character is alphanumeric
            {
                s[write] = s[i]; // move valid character to 'write' position
                write++;         // increment write pointer
            }
        }

        // Step 3: Erase leftover characters after 'write' position
        // erase(start_index) removes all characters from start_index to end
        s.erase(write);
    }

    // Function to check if the string is a palindrome
    bool isPalindrome(string &s)
    {
        // Step 1: Clean and lowercase the string
        toLowercaseAndRemoveNonAlphaNumeric(s);

        int i = 0;            // start pointer
        int j = s.length() - 1; // end pointer

        // Step 2: Compare characters from both ends
        while (i <= j)
        {
            if (s[i] != s[j]) // mismatch found
                return false;
            i++;
            j--;
        }

        // Step 3: If all characters matched
        return true;
    }
};

*/