// Leftmost Non-repeating Element
// apple. a is leftmost char which repeats
// abcbda : c is leftmost

#include <iostream>
#include <string>
#include<algorithm>

using namespace std;


int leftMostNonRepeatingCharacter(string &s1)
{
    
    int freq[26] = {0};

    for(int i = 0; i<s1.length(); i++)
    {
        freq[s1[i] - 'a'] ++;
    }
    
    for (int  i = 0; i < s1.length(); i++)
    {
        if((freq[s1[i]-'a']) == 1)
            return i;
    }
    return -1;
    
    
}
int main()
{
    string s1 = "abcbda";
    // string s1 = "geeksforgeeks";

    // 1. Store the result in a variable
    int index = leftMostNonRepeatingCharacter(s1);

    // 2. Check if the index is valid before using it
    if (index != -1)
    {
        cout << "The leftmost non repeating character is: '" << s1[index] << "'" << endl;
    }
    else
    {
        cout << "No non repeating character found." << endl;
    }

    return 0;
}

// Time Complexity: O(N)

// Space Complexity: O(1)



// logic

/*



 * @brief Finds the index of the leftmost non-repeating character using a frequency map.
 * 
 * This is an efficient two-pass algorithm.
 * 1. The first pass iterates through the string to count the occurrences of every character.
 * 2. The second pass iterates through the string again from the left. The first
 *    character it encounters with a frequency of exactly 1 is the answer.
 * 
 * @param s1 The input string. Using 'const string&' is better practice here.
 * @return The index of the leftmost non-repeating character, or -1 if none exists.
 
int leftMostNonRepeatingCharacter(const string &s1) // Changed to const& for best practice
{
    // Create a frequency array for 26 lowercase English letters.
    // Initialize all counts to 0.
    int freq[26] = {0};

    // --- PASS 1: Build the frequency map ---
    // This loop populates the freq array with the count of each character.
    for(int i = 0; i < s1.length(); i++)
    {
        // Increment the count for the character s1[i].
        freq[s1[i] - 'a']++;
    }
    
    // --- PASS 2: Find the first unique character ---
    // This loop scans the string from left to right.
    for (int i = 0; i < s1.length(); i++)
    {
        // Check the frequency of the character at the current position.
        if((freq[s1[i] - 'a']) == 1)
        {
            // If the frequency is 1, it means this character is unique.
            // Since we are iterating from the left, this is the first
            // unique character we have found. Return its index.
            return i;
        }
    }
    
    // If the second loop completes without finding any character with a
    // frequency of 1, it means no unique characters exist.
    return -1;
}




*/