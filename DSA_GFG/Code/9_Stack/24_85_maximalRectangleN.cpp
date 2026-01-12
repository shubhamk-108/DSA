/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Diagram:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
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
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int height = heights[i];

            // expand left
            int left = i;
            while (left >= 0 && heights[left] >= height)
                left--;

            // expand right
            int right = i;
            while (right < n && heights[right] >= height)
                right++;

            int width = right - left - 1;
            int area = height * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> resultant_1d_heights(cols, 0);
        int final_rectangleWithMaxOne = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (matrix[row][col] == '0')
                    resultant_1d_heights[col] = 0;
                else
                    resultant_1d_heights[col] += matrix[row][col] - '0';
            }
            int rectangleWithMaxOne = largestRectangleArea(resultant_1d_heights);
            final_rectangleWithMaxOne = max(final_rectangleWithMaxOne, rectangleWithMaxOne);
        }
        return final_rectangleWithMaxOne;
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << sol.maximalRectangle(matrix);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Let:
R = rows
C = cols
Time
Histogram building → O(R × C)
Brute LC84 per row:
For each bar, expand left & right → O(C)    
Done for all bars → O(C²)
Called for every row → O(R × C²)

✅ Total Time:
O(R×C
Space
Histogram array → O(C)
No extra data structures

✅ Space:
 O(R × C²)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Overall idea
Treat every row of the matrix as the base of a histogram
Maintain a 1D array resultant_1d_heights:
Each column stores how many consecutive '1's exist vertically up to this row
For each row’s histogram:
Try every bar as the minimum height
Expand left and right to find the widest rectangle
Keep the maximum rectangle area across all rows
So conceptually:
Maximal Rectangle = Brute Largest Histogram per Row



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;

    // Fix each bar as the minimum height
    for (int i = 0; i < n; i++)
    {
        int height = heights[i];

        // Expand to the left while bars are >= current height
        int left = i;
        while (left >= 0 && heights[left] >= height)
            left--;

        // Expand to the right while bars are >= current height
        int right = i;
        while (right < n && heights[right] >= height)
            right++;

        // Width between the first smaller bars
        int width = right - left - 1;

        int area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}


int maximalRectangle(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Histogram heights for each column
    vector<int> resultant_1d_heights(cols, 0);
    int final_rectangleWithMaxOne = 0;

    for (int row = 0; row < rows; row++)
    {
        // Build histogram for this row
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == '0')
                resultant_1d_heights[col] = 0;
            else
                resultant_1d_heights[col] += 1;
        }

        // Brute LC84 on histogram
        int rectangleWithMaxOne =
            largestRectangleArea(resultant_1d_heights);

        final_rectangleWithMaxOne =
            max(final_rectangleWithMaxOne, rectangleWithMaxOne);
    }

    return final_rectangleWithMaxOne;
}

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Pattern used (Brute version)
Fix minimum height and expand
Histogram per row
Range expansion brute force
This is the baseline brute that motivates the monotonic stack optimization.
*/
