// // "Leftmost Repeating Character" asks you to find the first character from the left that appears again later in the string.
// geeksforgeeks	g	'g' is the first character from the left (at index 0) that appears again (at index 8). e also
// repeats. But we have to find leftmost. 
// abccba	b is leftmost occuring again and again.



#include <iostream>
#include <string>
#include<algorithm>

using namespace std;


int leftMostOccuringCharacter( string & s1)
{
    
    int freq[26] = {0};

    for(int i = 0; i<s1.length(); i++)
    {
        freq[s1[i] - 'a'] ++;
    }
    
    for (int  i = 0; i < s1.length(); i++)
    {
        if((freq[s1[i]-'a']) > 1)
            return i;
    }
    return -1;
    
    
}

int main()
{
    string s1 = "abccba";
    
    // 1. Store the result in a variable
    int index = leftMostOccuringCharacter(s1);
    
    // 2. Check if the index is valid before using it
    if (index != -1) {
        cout << "The leftmost repeating character is: '" << s1[index] << "'" << endl;
    } else {
        cout << "No repeating character found." << endl;
    }

    return 0;
}

// Time Complexity: O(N)

// Space Complexity: O(1)

// You allocate a single integer array of a fixed size (26). This amount of memory is constant and does not depend on the length of the input string N.
// logic

/*


#include <iostream>
#include <string>

using namespace std;

/*
 * @brief Finds the index of the leftmost repeating character using a frequency map.
 * 
 * This is an efficient two-pass approach. The first pass builds a frequency
 * count of all characters in the string. The second pass then traverses the
 * string from the left, and the first character it encounters that has a
 * frequency greater than 1 is the answer.
 * 
 * @param s1 The input string, passed by non-const reference. 
 *           (Note: Using 'const string&' would be better practice as the string is not modified).
 * @return The index of the first occurrence of the leftmost repeating character.
 *         Returns -1 if no character repeats.
 
int leftMostOccuringCharacter(const string & s1) // Changed to const string& for best practice
{
    // Create a frequency array for all 26 lowercase English letters, initialized to zero.
    int freq[26] = {0};

    // --- PASS 1: Build the frequency map ---
    // This loop counts the occurrences of each character in the entire string.
    for(int i = 0; i < s1.length(); i++)
    {
        // Increment the count for the current character.
        freq[s1[i] - 'a']++;
    }
    
    // --- PASS 2: Find the leftmost character with a count > 1 ---
    // This loop traverses the string again from the beginning.
    for (int i = 0; i < s1.length(); i++)
    {
        // Check the frequency map for the current character.
        if((freq[s1[i] - 'a']) > 1)
        {
            // If the count is greater than 1, this character is a repeating one.
            // Since we are traversing from the left, this is guaranteed to be the
            // leftmost one. We return its index immediately.
            return i;
        }
    }

    // If the second loop completes, it means no character had a frequency > 1.
    return -1;
}



*/

