// Leftmost Non-repeating Element
// apple. a is leftmost char which repeats
// abcbda : c is leftmost

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int leftMostNonRepeatingCharacter(string &s1)
{

    for (int i = 0; i < s1.length(); i++)
    {
        bool flag_hasSeen = false;
        for (int j = 0; j < s1.length(); j++)
        {

            if (s1[i] == s1[j] && i != j)
            {
                flag_hasSeen = true;
                break;
            }
        }
        if (flag_hasSeen == false)
            return i;
    }
    return -1;
}

int main()
{
    // string s1 = "abcbda";
    string s1 = "geeksforgeeks";

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

// Time Complexity: O(N²)
// Space Complexity: O(1)

// logic


/*


 * @brief Finds the index of the leftmost non-repeating character.
 * 
 * This function uses a brute-force approach. For each character in the string,
 * it scans the entire string again to check for any duplicates.
 * 
 * @param s1 The input string. Using a 'const' reference is better practice
 *           as the string is not modified.
 * @return The index of the leftmost non-repeating character, or -1 if none exists.
 
int leftMostNonRepeatingCharacter(const string &s1) // Changed to const& for best practice
{
    // The outer loop picks a candidate character, s1[i].
    for (int i = 0; i < s1.length(); i++)
    {
        // A flag to track if we find a duplicate for the character s1[i].
        bool flag_hasSeen = false;
        
        // The inner loop scans the *entire* string to check for duplicates.
        // why entire loop. ex: geeksforgeeks. see last third e, there are no e after that if we take j = i+1 but e has already appeared many times
        before
        for (int j = 0; j < s1.length(); j++)
        {
            // We find a duplicate if the characters match but their indices are different.
            if (s1[i] == s1[j] && i != j)
            {
                // If a duplicate is found, set the flag and break the inner loop.
                // There's no need to continue searching for more duplicates of s1[i].
                flag_hasSeen = true;
                break;
            }
        }
        
        // After checking the whole string, if the flag is still false,
        // it means no duplicates were found for s1[i].
        if (flag_hasSeen == false)
        {
            // Since the outer loop moves from left to right, this is the
            // first non-repeating character we've encountered. Return its index.
            return i;
        }
    }
    
    // If the outer loop finishes, it means every character had at least one duplicate.
    return -1;
}




*/