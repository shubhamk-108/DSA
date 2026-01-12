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

// Prerequisite : LC 84. Largest area of histogram
class Solution
{
public:
    vector<int> previousSmaller(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> prevSmallerEle(n);

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                prevSmallerEle[i] = -1;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if (st.empty())
                    prevSmallerEle[i] = -1;
                else
                    prevSmallerEle[i] = st.top();
                st.push(i);
            }
        }
        return prevSmallerEle;
    }

    vector<int> NextSmaller(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> nextSmallEle(n);

        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                nextSmallEle[i] = n;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                    st.pop();
                if (st.empty())
                    nextSmallEle[i] = n;
                else
                    nextSmallEle[i] = st.top();
                st.push(i);
            }
        }
        return nextSmallEle;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nextSmallerElementsIdx = NextSmaller(heights);
        vector<int> previousSmallerElementsIdx = previousSmaller(heights);
        int finalArea = 0;

        for (int i = 0; i < n; i++)
        {
            int width = (nextSmallerElementsIdx[i] - i) + (i - previousSmallerElementsIdx[i]) - 1;
            int height = heights[i];
            int area = height * width;
            finalArea = max(finalArea, area);
        }

        return finalArea;
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
Time

Histogram update per row → O(cols)
LC84 per row → O(cols)
Total:
O(rows × cols)

Step-by-step time analysis

Let:

R = rows

C = cols

1️⃣ Outer loop (rows)
for (int row = 0; row < rows; row++)


Runs R times.

2️⃣ Inner loop (building histogram)
for (int col = 0; col < cols; col++)


Runs C times per row
Total so far:

O(R × C)

3️⃣ largestRectangleArea(resultant_1d_heights)
This is the key confusion point.
What does LC84 do internally?
Uses monotonic stack
Each index is:
pushed once
popped once
So per call:
O(C)


And it is called once per row, so:

O(R × C)

🔢 Combine everything

Total work:

Histogram update   → O(R × C)
LC84 per row       → O(R × C)
--------------------------------
Total              → O(R × C)


Constants add, they don’t multiply.


-------------------------------

Space
Histogram array → O(cols)
Stack inside LC84 → O(cols)
Total:
O(cols)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

High-level idea
Convert each row of the matrix into a histogram
Each column stores the count of continuous '1's vertically up to that row
For every row’s histogram, compute the Largest Rectangle in Histogram (LC84)
The maximum among all rows is the answer
So:
LC85 = LC84 applied on every row as a histogram
Detailed flow
Step A: Build histogram row by row
Use a 1D vector resultant_1d_heights of size = number of columns
For each cell:
'0' → reset height to 0
'1' → increase height by 1
This converts:
matrix rows → histogram heights
Step B: Solve Largest Rectangle in Histogram (LC84)
For a given histogram:
Find previous smaller element index for each bar
Find next smaller element index for each bar
Width for bar i:
nextSmaller[i] - previousSmaller[i] - 1
Area:
heights[i] × width
Use a monotonic increasing stack to do this in O(n).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

vector<int> previousSmaller(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;                  // stores indices with increasing heights
    vector<int> prevSmallerEle(n);

    for (int i = 0; i < n; i++)
    {
        // Remove all bars >= current bar
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        // If stack empty → no smaller on left
        prevSmallerEle[i] = st.empty() ? -1 : st.top();

        // Push current index
        st.push(i);
    }
    return prevSmallerEle;
}



vector<int> NextSmaller(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;                  // stores indices with increasing heights
    vector<int> nextSmallEle(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // Remove all bars >= current bar
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        // If stack empty → no smaller on right
        nextSmallEle[i] = st.empty() ? n : st.top();

        // Push current index
        st.push(i);
    }
    return nextSmallEle;
}


int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // Get nearest smaller indices
    vector<int> nextSmallerElementsIdx = NextSmaller(heights);
    vector<int> previousSmallerElementsIdx = previousSmaller(heights);

    int finalArea = 0;

    for (int i = 0; i < n; i++)
    {
        // Width between smaller bars (excluding them)
        int width = (nextSmallerElementsIdx[i] - i)
                  + (i - previousSmallerElementsIdx[i]) - 1;

        int area = heights[i] * width;
        finalArea = max(finalArea, area);
    }

    return finalArea;
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
        // Update histogram for current row
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == '0')
                resultant_1d_heights[col] = 0;
            else
                resultant_1d_heights[col] += 1;
        }

        // Apply LC84 on this histogram
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



✅ Row-wise Histogram + Monotonic Stack
More specifically:
Nearest Smaller to Left / Right
Largest Rectangle in Histogram
Problem decomposition: LC85 → repeated LC84
*/
