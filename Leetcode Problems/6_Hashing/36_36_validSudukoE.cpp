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

        int row[9][9] = {0};
        int col[9][9] = {0};
        int subMatrix[3][3][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int numIdx = board[i][j] - '1';

                if (board[i][j] != '.')
                {
                    if (row[i][numIdx] != 0 || col[j][numIdx] != 0 || subMatrix[i / 3][j / 3][numIdx] != 0)
                        return false;
                    row[i][numIdx] = col[j][numIdx] = subMatrix[i / 3][j / 3][numIdx] = 1;
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
// code explanation
//___________________________________________________________________________________________________________________________________________
/*
A valid Sudoku must follow 3 rules:

Each row must contain digits 1–9 without repetition

Each column must contain digits 1–9 without repetition

Each 3×3 sub-grid must contain digits 1–9 without repetition

We don't need to solve the Sudoku — only validate.

🧠 Data Structures Used

You created three 2D/3D arrays to record whether a number has appeared:

1. row[9][9]

row[i][num] = 1 means
→ In row i, number num+1 has appeared.

2. col[9][9]

col[j][num] = 1 means
→ In column j, number num+1 has appeared.

3. subMatrix[3][3][9]

subMatrix[bi][bj][num] = 1 means
→ In 3×3 block (bi, bj), number num+1 has appeared.

Each number index is 0 to 8 (for digits '1' to '9').

🧩 Important concept: numIdx = board[i][j] - '1'

If board[i][j] = '1'
→ numIdx = '1' - '1' = 0

If board[i][j] = '9'
→ numIdx = '9' - '1' = 8

So numIdx always maps correctly to array index.

🧱 How do we find which 3×3 box a cell belongs to?

Use:

i / 3 gives block row (0, 1, 2)
j / 3 gives block column (0, 1, 2)


Example:
Cell (4, 7) → (i=4, j=7)

i/3 = 4/3 = 1 → middle row of blocks

j/3 = 7/3 = 2 → right column of blocks
So it belongs to block (1, 2).

🔬 Let’s break down your for-loops
for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
    {


You walk through every cell of the board.

🧮 Processing each cell
Step 1: Convert char digit → index (0–8)
int numIdx = board[i][j] - '1';

Step 2: Ignore empty cells
if (board[i][j] != '.')


If it's '.', move on.

🚨 Validation Check

Before marking the number as used, you verify if it already existed:

if (row[i][numIdx] != 0 ||
    col[j][numIdx] != 0 ||
    subMatrix[i/3][j/3][numIdx] != 0)
{
    return false;
}


Meaning:

If number already seen in row i → invalid

If number already seen in column j → invalid

If number already seen in subgrid (i/3, j/3) → invalid

Any collision → return false.

✍️ Mark the number as seen
row[i][numIdx] = col[j][numIdx] = subMatrix[i / 3][j / 3][numIdx] = 1;


This sets a flag so future occurrences detect the duplicate.

🟢 If you finish all loops without conflicts
return true;


The Sudoku is valid.


*/

//___________________________________________________________________________________________________________________________________________
// int subMatrix[3][3][9] explanation
//___________________________________________________________________________________________________________________________________________


/*

Question 1: 
isnt this behaving like a one dimentional array. ex. [1][3][5] . Go to position [1][3] and access index 5. Just like there are only one 3*3 
matrix and each position of 3*3 matrix is tied with a vector of size 9. So go to postion [1][3] and in that vector access index 9 and do what 
you want to do with that. Is it like that

Ans : Yes correct.


Question 2:

tell is is it correct. [3][3][9] is like a vector, vector<int>vec(9). And [3][3] means there are 3 rows and 3 cols and each cell has 
size of 1d array of 9. So this vec in vector is replace by for ex [2][3]. So calling [2][3][6], index is 6 , is just like calling vec[6]

Ans : Yes

Think of:

int subMatrix[3][3][9];


as a 3×3 grid, and each cell of that grid contains a 1-D array of size 9.

So it behaves like:

3 rows
  → each row has 3 columns
       → each column points to a list of 9 numbers

✅ Your example: subMatrix[1][3][5]

But careful: valid indices are 0,1,2.

So the valid example would be:

subMatrix[1][2][5]


This means:

✔ Step 1: Go to submatrix row = 1
✔ Step 2: Go to submatrix column = 2
✔ Step 3: Inside that submatrix, go to index 5 (out of 0–8)

This is exactly like:

"There is a 3×3 matrix, and each cell contains an array/vector of size 9."

Perfect analogy.

🔥 Visual Diagram (exactly how memory looks)
subMatrix
│
├── [0]
│    ├── [0] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│    ├── [1] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│    └── [2] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│
├── [1]
│    ├── [0] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│    ├── [1] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│    └── [2] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
│
└── [2]
     ├── [0] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
     ├── [1] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]
     └── [2] → [x0 x1 x2 x3 x4 x5 x6 x7 x8]


Each [i][j] maps to one Sudoku subgrid (3×3 box),
and the [9] represents the digits 1–9 (index 0–8).

⭐ So the meaning is:
✔ [3][3] → number of subgrids

(sudoku has 3 rows × 3 cols of boxes = 9 boxes)

✔ [9] → number of digits we must track inside each box




Question 3: 

So what we are assuming there are total 9 submatrices of 3*3 each is just the imagination. I means there is nothing like below 
structure. 
0 0 0 | 1 1 1 | 2 2 2 |
0 0 0 | 1 1 1 | 2 2 2 | 
0 0 0 | 1 1 1 | 2 2 2 | 

This was 0th row and 0th, 1st and 2nd col. similarly, 
for 1st row and 0th, 1st and 2nd col. And, for 2nd row and 0th, 1st and 2nd col.

Answer: 

We are NOT "imagining" the 9 submatrices. They actually exist in the Sudoku grid.

A standard Sudoku board IS made of:

9 rows

9 columns

9 submatrices (3×3 boxes)

These boxes really exist in the Sudoku layout.

✔ The structure you drew is 100% correct:
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
0 0 0 | 1 1 1 | 2 2 2
---------------------
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
3 3 3 | 4 4 4 | 5 5 5
---------------------
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8
6 6 6 | 7 7 7 | 8 8 8


This is exactly how Sudoku is divided into 3×3 boxes.

So:

Box (0,0) = top-left 3×3

Box (0,1) = top-middle 3×3

Box (0,2) = top-right 3×3

Box (1,0) = middle-left

…

Box (2,2) = bottom-right

There are exactly 3 rows × 3 columns = 9 submatrices.

This is NOT imagination.
This is the actual structure of Sudoku.

⭐ Why subMatrix[3][3][9] matches this exactly
subMatrix[3][3][9]


maps exactly to the real Sudoku board:

✔ [3] → 3 rows of boxes
✔ [3] → 3 columns of boxes

Together → 3×3 = 9 boxes

✔ [9] → digits 1–9 inside each box

So this code’s structure is a direct representation of the Sudoku submatrices.

💡 Example

If you are at cell (4, 8) in the Sudoku board:

row = 4 → middle row of big boxes → 4/3 = 1
col = 8 → rightmost big box        → 8/3 = 2


So this cell belongs to submatrix:

subMatrix[1][2]


Which matches this block from the diagram:

4th, 5th, 6th row AND 7th, 8th, 9th column


Everything aligns perfectly.


*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(1)
We always process exactly 81 cells
81 operations = constant time
→ O(1) (or O(81))
Space Complexity: O(1)
row → 9×9 = 81 integers
col → 9×9 = 81 integers
subMatrix → 3×3×9 = 81 integers
Total ~243 ints → constant
→ O(1)
Sudoku constraints are fixed, so space is constant.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


To validate Sudoku, make sure each number 1–9 appears at most once in:
Each row
Each column
Each 3×3 sub-grid
We maintain 3 tracking arrays:
row[9][9] → row[i][num] = 1 means num already used in row i
col[9][9] → col[j][num] = 1 means num already used in col j
subMatrix[3][3][9] → subMatrix[i/3][j/3][num] = 1 means num already used in that 3×3 box
As we scan each cell:
Convert char '1'–'9' → index 0–8
If that number is already marked used in row/col/subgrid → invalid
Otherwise mark it as used
If we finish scanning without conflict → the board is valid
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
        // Track numbers in rows, columns, and 3x3 subgrids
        int row[9][9] = {0};
        int col[9][9] = {0};
        int subMatrix[3][3][9] = {0};

        // Traverse each cell of the board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Skip empty cells
                if (board[i][j] == '.')
                    continue;

                // Convert '1'..'9' to 0..8
                int numIdx = board[i][j] - '1';

                // Check if the number is already used in:
                // - Row i
                // - Column j
                // - The corresponding 3x3 subgrid (i/3, j/3)
                if (row[i][numIdx] != 0 ||
                    col[j][numIdx] != 0 ||
                    subMatrix[i / 3][j / 3][numIdx] != 0)
                {
                    return false; // Duplicate found → invalid sudoku
                }

                // Mark the number as used
                row[i][numIdx] = 1;
                col[j][numIdx] = 1;
                subMatrix[i / 3][j / 3][numIdx] = 1;
            }
        }

        // All checks passed → valid sudoku
        return true;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

This problem uses the:
✔ Hashing / Counting Pattern
You maintain frequency tables (hash maps but implemented as fixed arrays) to count occurrences and detect duplicates.
Also known as:
✔ Constraint Validation
✔ Set-Based Duplicate Check
✔ Matrix Traversal + Hashing


*/
