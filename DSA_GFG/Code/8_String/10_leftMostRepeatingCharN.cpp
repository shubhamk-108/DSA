// "Leftmost Repeating Character" asks you to find the first character from the left that appears again later in the string.
// geeksforgeeks	g	'g' is the first character from the left (at index 0) that appears again (at index 8). e also
// repeats. But we have to find leftmost. 
// abccba	b is leftmost occuring again and again.



#include <iostream>
#include <string>
#include<algorithm>

using namespace std;


int leftMostOccuringCharacter( string & s1)
{
    
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = i+1; j < s1.length(); j++)
        {
            if(s1[i] == s1[j])
            {
                return i;
            }
        }
        
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

// Time Complexity: O(N²)
// Space Complexity: O(1)

//logic


/*

#include <iostream>
#include <string>

using namespace std;


 * @brief Finds the index of the leftmost repeating character in a string.
 * 
 * This function uses a brute-force approach with nested loops. It iterates
 * through each character and then scans the rest of the string to its right
 * to find a duplicate.
 * 
 * @param s1 The input string, passed by constant reference for efficiency and safety.
 * @return The index of the first occurrence of the leftmost repeating character.
 *         Returns -1 if no repeating character is found.
 
int leftMostOccuringCharacter(const string & s1)
{
    // The outer loop picks a character, one by one, from left to right.
    for (int i = 0; i < s1.length(); i++)
    {
        // The inner loop scans the remainder of the string to the right of the current character.
        // It starts from 'i + 1' to avoid comparing a character with itself.
        for (int j = i + 1; j < s1.length(); j++)
        {
            // If a duplicate is found...
            if(s1[i] == s1[j])
            {
                // ...we immediately return the index 'i' of the first occurrence.
                // Since the outer loop moves from left to right, this guarantees
                // that we are returning the index of the *leftmost* repeating character.
                return i;
            }
        }
    }
    
    // If the loops complete without finding any duplicates, it means all characters
    // are unique. In this case, we return -1 as a signal for "not found."
    return -1;
}

int main()
{
    string s1 = "abccba";
    
    // Store the returned index in a variable.
    int index = leftMostOccuringCharacter(s1);
    
    // Always check the return value to handle the "not found" case gracefully.
    if (index != -1) {
        cout << "The leftmost repeating character is: '" << s1[index] << "'" << endl;
    } else {
        cout << "No repeating character found." << endl;
    }

    return 0;
}


*/