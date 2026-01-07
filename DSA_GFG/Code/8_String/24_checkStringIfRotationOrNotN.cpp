#include <bits/stdc++.h>
using namespace std;

bool ifStringIsRotation(string str, string rotation)
{
    int n = str.length();

    if (rotation.length() != n)
        return false;
    
    for (int i = 0; i < n; i++)
    {
        char first_char = str[0];

        str.erase(0,1);
        str.push_back(first_char);
        if(str == rotation)
            return true;
    }
    return false;    
}

int main()
{
    string str = "abcde";
    string rotation = "deabc";
    cout<<ifStringIsRotation(str, rotation);
    return 0;
}


// time sapce


/*

Time Complexity: O(N²)

Space Complexity: O(N)
Your function signature is bool ifStringIsRotation(string str, string rotation). Because you pass the str and rotation strings by value, the 
C++ compiler creates copies of them when the function is called. The space required for these copies is proportional to their length, N. The 
operations inside the loop modify the str copy in-place, so no significant additional space is allocated within the loop itself. Therefore, 
the space complexity is dominated by the initial copies, making it O(N).


*/



// logic


/*


 * @brief Checks if a string 'rotation' is a rotation of string 'str' using a brute-force method.
 * @param str The original string (passed by value, so a local copy is made).
 * @param rotation The string to check.
 * @return true if 'rotation' is a rotation of 'str', false otherwise.
        
bool ifStringIsRotation(std::string str, std::string rotation)
{
    // Get the length of the original string.
    int n = str.length();

    // --- Pre-condition Check ---
    // If the lengths are not equal, it's impossible for one to be a rotation of the other.
    if (rotation.length() != n)
        return false;
    
    // An empty string can be considered a rotation of another empty string.
    if (n == 0) {
        return true;
    }

    // --- Brute-Force Rotation and Comparison ---
    // Loop 'n' times to generate all possible unique rotations.
    for (int i = 0; i < n; i++)
    {
        // Check if the current state of 'str' matches the 'rotation' string.
        // We check before rotating because the original string itself is the 0th rotation.
        if(str == rotation)
            return true;

        // Perform one left rotation on the 'str'.
        char first_char = str[0];      // Store the first character.
        str.erase(0, 1);               // Remove the first character from the string.
        str.push_back(first_char);     // Add the stored character to the end.
    }

    // If the loop completes without finding a match, they are not rotations.
    return false;   
}



*/