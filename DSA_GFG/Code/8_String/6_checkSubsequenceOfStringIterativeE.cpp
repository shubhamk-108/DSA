/*

What is a Subsequence?
A subsequence is a sequence of characters derived from a string by deleting zero or more characters, without changing the 
order of the remaining characters.
The key rules for a subsequence are:
Order is Preserved: The characters in the subsequence must appear in the same relative order as they did in the original 
string.
Not Necessarily Contiguous: The characters do not have to be next to each other in the original string.
Let's use the string str = "apple" as an example
"ale" is a subsequence: You can get it by deleting 'p' and 'p'. The characters 'a', 'l', and 'e' are in the same order as 
in "apple".
"pp" is a subsequence: You can get it by deleting 'a', 'l', and 'e'.
"ape" is a subsequence: You can get it by deleting 'p' and 'l'.
"eal" is NOT a subsequence: Even though 'e', 'a', and 'l' are all in "apple", their order is changed.
The original string "apple" is a subsequence of itself (by deleting zero characters).
An empty string "" is a subsequence of any string (by deleting all characters).


What is a Substring?
A substring is a sequence of characters that are contiguous (immediately next to each other) within a string.
For the same string str = "apple":
"app" is a substring: The characters 'a', 'p', 'p' are consecutive in the original string.
"ple" is a substring: 'p', 'l', 'e' are consecutive.
"p" is a substring.
"ale" is NOT a substring: The characters 'a' and 'l' are not next to each other in the original string.

*/



// SOlved using two pointer approach
#include <iostream>
#include <string>

// Function to check if s2 is a subsequence of s1
bool isSubsequence(const std::string & s1, const std::string & s2) {
    
    int i = 0;
    int j = 0;
    while(i < s1.length() && j < s2.length())
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            i++;
        
        
    }
    if(j==s2.length())
        return true;
    else 
        return false;
    
}

int main() {

    std::string s1 = "geeksforgeeks";
    std::string s2 = "gksrek";
    
    
    if (isSubsequence(s1, s2)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    
    return 0;
}




// time space


/*
Time Complexity: O(N)
N is the length of the main string (s1).
Space Complexity: O(1)
*/



// logic


/*

// Function to check if s2 is a subsequence of s1
// A subsequence means all characters of s2 appear in s1 in the same order,
// but not necessarily contiguously.
bool isSubsequence(const std::string & s1, const std::string & s2) {
    
    int i = 0; // pointer for s1
    int j = 0; // pointer for s2

    // Traverse both strings
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])  
        {
            // If characters match, move both pointers
            i++;
            j++;
        }
        else
        {
            // If characters don't match, move only pointer of s1
            i++;
        }
    }

    // If we traversed the entire s2 (j reached its length),
    // it means every character of s2 was found in order in s1.
    if (j == s2.length())
        return true;
    else 
        return false;
}


*/