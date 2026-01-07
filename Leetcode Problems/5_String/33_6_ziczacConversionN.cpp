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
    string convert(string s, int numRows)
    {
        int n = s.length();
        int column = n; // we dont know how many columns get formed in ziczac pattern so directly take n as there are at max n columns

        if (numRows == 1 || numRows >= n)
            return s;

        // making grid. outer vector is row and inner vector is column. And one row can have multiple column.
        // So, if there are 4 rows in the question then there are 4 outer vector and each vector can hold another seperate
        // vector of char. So outer vector is row and inner vector is columns and now you can hold as much as column in rows.
        vector<vector<char>> grid(numRows, vector<char>(n, '\0'));
        int row = 0;
        int col = 0;
        bool is_going_down = true;

        for (auto ch : s)
        {
            grid[row][col] = ch;

            // now find next position to put the character but first find out that are you going down or up
            if (is_going_down)
            {
                // be cautioned. while going down you hit the last row and if we hit last row then start going upward and chage you
                // row and col values because in that case we do have to make diagonal.
                if (row == numRows - 1)
                {
                    // new position to put char in grid:
                    col++;
                    row--;

                    // and when we hit the last row , next time we will have to go upward so make going_down = false
                    is_going_down = false; // means from downward to uppward movement
                }
                else // if we are not at the last row but somewhere in the middle
                {
                    row++;
                }
            }
            else // we are going from down to up
            {
                // while going up we will hit 0th row. when we hit that then we have to again start top to down movement so change going down
                // and change position
                if (row == 0)
                {
                    is_going_down = true;
                    row++;
                }
                else // we were in diagonal movement but not yet hit the oth row then
                {
                    row--;
                    col++;
                }
            }
        }

        string res;
        for (row = 0; row < numRows; row++)
        {
            for (col = 0; col < n; col++)
            {
                if (grid[row][col] != '\0')
                    res += grid[row][col];
            }
        }
        return res;
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

Complexity Analysis
Time Complexity: O(R * C) or O(numRows * n)

The first loop for populating the grid runs n times (where n is the length of the string), so that part is O(n).
However, the second part of the code involves iterating through the entire grid to build the result string. This grid has dimensions of 
numRows x n. This nested loop runs numRows * n times.
The overall time complexity is dominated by this final iteration, making it O(numRows * n). This is less efficient than the optimal O(n) 
solution.

Space Complexity: O(R * C) or O(numRows * n)
The dominant factor for space is the vector<vector<char>> grid itself.
You allocate a 2D vector of size numRows by n.
Therefore, the space complexity is O(numRows * n). This is the main drawback of the brute-force method, as it uses significantly more 
memory than the optimal approach, which only requires O(n) space.

*/


// code


/*


class Solution
{
public:
    string convert(string s, int numRows)
    {
        // Get the length of the input string.
        int n = s.length();
        
        // As you noted, the exact number of columns isn't easily known beforehand.
        // Taking 'n' as the number of columns is a safe upper bound, as in the worst
        // case (e.g., numRows=2), the number of columns is about n/2.
        int column = n;

        // Handle edge cases: If there's only one row or more rows than characters,
        // the string does not change.
        if (numRows == 1 || numRows >= n)
            return s;

        // --- Grid Initialization ---
        // Create a 2D grid (matrix) of characters.
        // It has 'numRows' rows and 'n' columns.
        // It's initialized with the null character '\0' to mark empty cells.
        vector<vector<char>> grid(numRows, vector<char>(n, '\0'));

        // 'row' and 'col' pointers to track the current position in the grid.
        int row = 0;
        int col = 0;
        // A boolean flag to control the direction of movement (down or diagonally up).
        bool is_going_down = true;

        // --- Grid Population ---
        // Iterate through each character of the input string 's'.
        for (auto ch : s)
        {
            // Place the current character at the current (row, col) in the grid.
            grid[row][col] = ch;

            // --- Determine the next position ---
            // If the current direction is downwards.
            if (is_going_down)
            {
                // If we've hit the last row, we must change direction.
                if (row == numRows - 1)
                {
                    // Move to the next column and up one row to start the diagonal.
                    col++;
                    row--;
                    // Flip the direction to start moving upwards.
                    is_going_down = false;
                }
                else // If not at the last row, just continue moving down.
                {
                    row++;
                }
            }
            else // If the current direction is upwards (diagonal).
            {
                // If we've hit the top row (row 0), we must change direction.
                if (row == 0)
                {
                    // Flip the direction to start moving downwards again.
                    is_going_down = true;
                    // Move down to the next row (which is row 1).
                    row++;
                }
                else // If not at the top row, continue the diagonal movement.
                {
                    // Move up one row and to the next column.
                    row--;
                    col++;
                }
            }
        }

        // --- Result Construction ---
        // Create an empty string to store the final result.
        string res;
        // Iterate through the entire grid, row by row.
        for (row = 0; row < numRows; row++)
        {
            for (col = 0; col < n; col++)
            {
                // If the current cell is not empty (i.e., not the initial null character).
                if (grid[row][col] != '\0')
                    // Append the character to the result string.
                    res += grid[row][col];
            }
        }
        return res;
    }
};


*/  