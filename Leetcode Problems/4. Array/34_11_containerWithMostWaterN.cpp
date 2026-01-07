/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints
of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Image is given on leetcode:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water
(blue section) the container can contain is 49.
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
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int finalMax = INT_MIN;
        int currentMax;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int minBarHeight = min(height[i], height[j]);
                currentMax = (j-i) * minBarHeight;
                finalMax = max(finalMax, currentMax);
            }
        }
        return finalMax;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Type                 | Complexity | Explanation                                               |
| -------------------- | ---------- | --------------------------------------------------------- |
| **Time Complexity**  | **O(n²)**  | Two nested loops checking every pair `(i, j)`             |
| **Space Complexity** | **O(1)**   | Only constant extra space used (`finalMax`, `currentMax`) |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This is the brute-force approach for Leetcode 11 – Container With Most Water.
You consider every pair of lines (i, j) in the array.
For each pair:
The width between the lines is (j - i).
The height of water the container can hold is determined by the shorter line → min(height[i], height[j]).
The area is width * height.
Keep track of the maximum area among all pairs.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int finalMax = INT_MIN;  // stores the maximum area found so far
        int currentMax;           // area for the current pair

        // Check every possible pair of lines
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // The container height is limited by the shorter line
                int minBarHeight = min(height[i], height[j]);

                // Calculate area for this pair
                currentMax = (j - i) * minBarHeight;

                // Update finalMax if we found a larger area
                finalMax = max(finalMax, currentMax);
            }
        }

        // Return the largest area possible
        return finalMax;
    }
};



*/
