/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed
font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 0:

s = "PAYPALISHIRING", numRows = 4
Row 0: P        I         N
Row 1: A     L  S     I   G
Row 2: Y  A     H  R
Row 3: P        I

Final output = "PINALSIGYAHRPI"
Key Requirement
Place characters downward one row at a time until you reach the last row.
Then go diagonally upward until you reach the first row.
Repeat until the string ends.
Finally, concatenate all rows together.

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution
{
public:
    string convert(string s, int rows)
    {
        int n = s.length();
        vector<string> res(rows);

        int i = 0;

        while (i < n)
        {
            for (int j = 0; j < rows && i < n; j++)
            {
                res[j] += s[i];
                i++;
            }

            for (int k = rows - 2; k > 0 && i < n; k--)
            {
                res[k] += s[i];
                i++;
            }
        }

        string ans ;
        for(auto x : res) // for(auto row : res) 
            ans+=x;       // ans+=row;

        return ans;
    }
};

int main()
{
    Solution sol;
    string s1 = "PAYPALISHIRING";
    int rows = 4;
    cout << sol.convert(s1, rows);

    return 0;
}

// timespace 

/*

Time Complexity: O(n)

The code iterates through the input string s exactly once, placing each character into one of the res strings. The outer while loop and the two 
inner for loops work together to ensure that the index i moves from 0 to n-1 without repetition.
The final loop to concatenate the rows also processes a total of n characters.
Therefore, the total time is proportional to the length of the string s, making it a linear time complexity.

Space Complexity: O(n)
The primary space usage comes from the vector<string> res and the final string ans.
The total number of characters stored across all strings in the res vector is exactly n.
The final ans string also stores n characters.
Since the storage required is directly proportional to the length of the input string, the space complexity is O(n)

*/

// code

/*

class Solution
{
public:
    string convert(string s, int rows)
    {
        // Get the length of the input string.
        int n = s.length();
        
        // If there's only one row or the string is shorter than the number of rows,
        // no conversion is needed, so return the original string.
        if (rows == 1 || n <= rows) {
            return s;
        }

        // Create a vector of strings. Each string in the vector will hold the
        // characters for one row of the zigzag pattern.
        vector<string> res(rows);

        // 'i' is the index to track the current character in the input string 's'.
        int i = 0;

        // Loop as long as there are characters left to place in the zigzag pattern.
        while (i < n)
        {
            // --- Downward Movement ---
            // This loop simulates the vertical downward stroke of the 'Z'.
            // It iterates from the top row (j=0) to the bottom row (j=rows-1).
            for (int j = 0; j < rows && i < n; j++)
            {
                // Append the current character from 's' to the correct row-string.
                res[j] += s[i];
                // Move to the next character in 's'.
                i++;
            }

            // --- Upward Diagonal Movement ---
            // This loop simulates the diagonal upward stroke of the 'Z'.
            // It starts from the second to last row (k=rows-2) and moves up to the second row (k=1).
            // It skips the top and bottom rows as they are part of the vertical strokes.
            for (int k = rows - 2; k > 0 && i < n; k--)
            {
                // Append the current character from 's' to the correct row-string.
                res[k] += s[i];
                // Move to the next character in 's'.
                i++;
            }

            // |           |           |           |
            // |       |   |       |   |       |   |
            // |   |       |   |       |   |       |
            // |           |           |           |

            // look at this. if there are 4 rows then pattern like this will form. 
            // like first loop is 1,2,3,4 then second loop will skip 4th char and 1st char. so it will be 3,2
            // do this first loop- second loop as long as there is a char in the string .
            // then again first loop - second loop.
            // like (indices) - 0,1,2,3 - 2,1 then again 0,1,2,3 - 2,1 then again 0,1,2,3 - 2,1. Continue doing this as long as there 
            // is a char in the string .
        }

        // --- Concatenate the Rows ---
        // Create an empty string to build the final result.
        string ans;
        // Iterate through the vector of row-strings.
        for(auto x : res)
            // Append each row-string to the final answer.
            ans += x;

        // Return the final converted string.
        return ans;
    }
};


*/

