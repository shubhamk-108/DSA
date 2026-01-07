
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
        int rowCheck[9][9] = {0};     // for checking rows
        int colCheck[9][9] = {0};     // for checking columns
        int subMatrix[3][3][9] = {0}; // for checking sub matrices/boxes

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if (rowCheck[i][num] or colCheck[j][num] or subMatrix[i / 3][j / 3][num])
                        return false;

                    rowCheck[i][num] = colCheck[j][num] = subMatrix[i / 3][j / 3][num] = 1;
                }
            }
        }
        return true;
    }
};

