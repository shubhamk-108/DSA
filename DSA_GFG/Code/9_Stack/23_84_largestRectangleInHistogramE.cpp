/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Diagram:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
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
};
int main()
{
    Solution sol;
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
Time: O(n)
Each element pushed & popped once in stack

Space: O(n)
Stack + helper arrays
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Idea
For every bar i, assume heights[i] is the minimum height of a rectangle.
To maximize its area:
Extend as far left as possible until a smaller bar blocks it
Extend as far right as possible until a smaller bar blocks it
So for each index i, we need:
Index of previous smaller element
Index of next smaller element
Then:
width = rightSmallerIndex - leftSmallerIndex - 1
area  = heights[i] * width
We compute these efficiently using monotonic stacks.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

vector<int> previousSmaller(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;                 // stores indices in increasing height order
    vector<int> prevSmallerEle(n);

    for (int i = 0; i < n; i++)
    {
        // Remove all elements >= current
        // because they cannot be previous smaller
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        // If stack is empty, no smaller element on left
        prevSmallerEle[i] = st.empty() ? -1 : st.top();

        // Push current index
        st.push(i);
    }
    return prevSmallerEle;
}


vector<int> NextSmaller(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;                 // stores indices in increasing height order
    vector<int> nextSmallEle(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // Remove all elements >= current
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        // If stack is empty, no smaller element on right
        nextSmallEle[i] = st.empty() ? n : st.top();

        // Push current index
        st.push(i);
    }
    return nextSmallEle;
}


int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // Get nearest smaller elements
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



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Monotonic Stack (Nearest Smaller to Left & Right)
Classic Histogram / Range Expansion pattern.

*/
