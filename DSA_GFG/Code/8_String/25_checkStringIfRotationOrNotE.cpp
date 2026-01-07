#include <iostream>
#include <string>
using namespace std;

bool ifStringIsRotation(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    string temp = s1+s2;
    return ( temp.find(s2) != string :: npos ); 
}

int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";
    cout << ifStringIsRotation(s1, s2) << endl;
    return 0;
}


//time


/*

Time Complexity: O(N)
The performance is determined by the two main operations:

String Concatenation (s1 + s1): This operation creates a new string of length 2N. It requires copying 2N characters, which takes O(N) time, 
where N is the length of s1.

Substring Search (temp.find(s2)): Modern C++ libraries use efficient searching algorithms (like Boyer-Moore or similar). On average, these 
algorithms also run in O(N) time.

Since the steps are sequential, the total time complexity is O(N) + O(N), which simplifies to O(N).

Space Complexity: O(N)
The space complexity is determined by the extra memory allocated for the temporary string temp. Since temp has a length of 2N, the space 
required is proportional to N.

*/
// logic



/*




 * @brief Checks if string 's2' is a rotation of 's1' using an efficient concatenation method.
 * @param s1 The original string.
 * @param s2 The string to check.
 * @return true if 's2' is a rotation of 's1', false otherwise.

bool ifStringIsRotation(std::string s1, std::string s2)
{
    // --- Pre-condition Check ---
    // If the lengths are not equal, it's impossible for one to be a rotation of the other.
    // Also handles the case of empty strings. If s1 is empty, s2 must also be empty.
    if (s1.length() != s2.length())
    {
        return false;
    }

    // --- Core Logic ---
    // Create a temporary string by concatenating s1 with itself.
    // This new string will contain all possible rotations of s1 as substrings.
    // For example, if s1 = "abcde", temp becomes "abcdeabcde".
    // The rotations "bcdea", "cdeab", etc., are all present in temp.
    std::string temp = s1 + s1; // The correction is here: s1 + s1, not s1 + s2

    // --- Substring Check ---
    // The find() method searches for the first occurrence of s2 within temp.
    // If s2 is found, find() returns the starting index of the match.
    // If s2 is not found, it returns a special value: std::string::npos.
    // So, if the result is not npos, it means s2 is a substring, and thus a rotation.
    return (temp.find(s2) != std::string::npos); 
}




*/