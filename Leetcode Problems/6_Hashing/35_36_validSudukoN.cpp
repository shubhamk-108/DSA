/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = board.size();

        // validate rows
        for (int row = 0; row < 9; row++)
        {
            unordered_set<char> uset;
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                    continue;
                if (!uset.count(board[row][col]))
                    uset.insert(board[row][col]);
                else
                    return false;
            }
        }

        // validate columns
        for (int col = 0; col < 9; col++)
        {
            unordered_set<char> uset;
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] == '.')
                    continue;
                if (!uset.count(board[row][col]))
                    uset.insert(board[row][col]);
                else
                    return false;
            }
        }

        // validate each 3*3 box

        for (int rowStart = 0; rowStart < 9; rowStart += 3)
        {

            for (int colStart = 0; colStart < 9; colStart += 3)
            {
                unordered_set<char> uset;
                for (int row = rowStart; row < rowStart + 3; row++)
                {
                    for (int col = colStart; col < colStart + 3; col++)
                    {
                        if (board[row][col] == '.')
                            continue;

                        if (!uset.count(board[row][col]))
                            uset.insert(board[row][col]);
                        else
                            return false;
                    }
                }
            }
        }

        return true;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << sol.isValidSudoku(board);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Even though we loop 3 times (rows, columns, boxes), each loop processes exactly 81 cells.
Row check: visits 81 cells
Column check: visits 81 cells
Box check: visits 81 cells
Total operations = 243 checks, but still constant.
Time Complexity: O(1).
But, O(n²) if expressed in terms of board size n.
Row scan: O(n²)
Column scan: O(n²)
Subgrid scan: O(n²)
But since n = 9 is constant for Sudoku, this simplifies to O(1)

Why?
Sudoku board is always 9×9.
Constant-size input → constant time.
If this were an N×N general Sudoku, the complexity would be O(N²).
But for LeetCode 36 → O(1).


space : O(1)
1. unordered_set<char> for rows
Each row uses a temporary unordered_set that can contain at most 9 characters.
→ Space = O(9) ≈ O(1)
Therefore overall Space = O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
You iterate through the Sudoku board and validate three constraints:

Each row should contain digits 1–9 without repetition.

Each column should contain digits 1–9 without repetition.

Each 3×3 subgrid should contain digits 1–9 without repetition.

For each row/column/box, you use an unordered_set to track seen numbers.
If a digit appears again → return false.
If all checks pass → return true.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Validate all 9 rows
        for (int row = 0; row < 9; row++)
        {
            unordered_set<char> uset;          // stores digits seen in this row
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')    // skip empty cells
                    continue;

                // If digit is already present → invalid board
                if (uset.count(board[row][col]))
                    return false;

                uset.insert(board[row][col]);  // mark digit as seen
            }
        }

        // Validate all 9 columns
        for (int col = 0; col < 9; col++)
        {
            unordered_set<char> uset;          // stores digits seen in this column
            for (int row = 0; row < 9; row++)
            {
                if (board[row][col] == '.')
                    continue;

                if (uset.count(board[row][col]))
                    return false;

                uset.insert(board[row][col]);
            }
        }

        // Validate each 3×3 subgrid (total 9 subgrids)
        for (int rowStart = 0; rowStart < 9; rowStart += 3)
        {
            for (int colStart = 0; colStart < 9; colStart += 3)
            {
                unordered_set<char> uset;  // stores digits seen in this small box

                // Iterate inside the 3×3 block
                for (int row = rowStart; row < rowStart + 3; row++)
                {
                    for (int col = colStart; col < colStart + 3; col++)
                    {
                        if (board[row][col] == '.')
                            continue;

                        if (uset.count(board[row][col]))
                            return false;

                        uset.insert(board[row][col]);
                    }
                }
            }
        }

        // All validations passed
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

This problem follows the Bruteforce + Hashing / Set-based Validation pattern.
Specifically:
Use a hash set to detect duplicates in fixed-size groups.


*/
