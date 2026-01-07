/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints
of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

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
        int left = 0;
        int right = n - 1;
        int finalArea = 0;

        while (left < right)
        {
            int width = right - left;

            int containerHeight = min(height[left], height[right]);

            finalArea = max(finalArea, width * containerHeight);

            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return finalArea;
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

| Type      | Complexity | Explanation                                   |
| --------- | ---------- | --------------------------------------------- |
| **Time**  | **O(n)**   | Each pointer moves at most once per iteration |
| **Space** | **O(1)**   | Only a few variables used                     |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


The goal is to find two vertical lines that together with the x-axis form a container which holds the maximum amount of water.

🔹 Key Idea
The amount of water a container can hold is determined by:
Area = width * height
Area = width × height

where
width = distance between two lines = (right - left)
height = minimum of the two lines’ heights (the shorter line limits the water level)

We take the shorter bar’s height because water needs support from both sides to stay contained.
Only as much water as the shorter bar can hold will actually remain — if we try to take the taller bar’s height, the water would overflow 
from the shorter side since it can’t hold that much.

🔹 Observation
If we fix two lines, moving the taller line does not help — because the shorter line is already limiting the height.
To potentially find a larger area, we must move the pointer pointing to the shorter line inward, hoping to find a taller line that increases height.

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
        int left = 0;              // pointer at start
        int right = n - 1;         // pointer at end
        int finalArea = 0;         // max area found so far

        while (left < right)
        {
            // Width between two lines
            int width = right - left;

            // Height limited by the shorter line
            int containerHeight = min(height[left], height[right]);

            // Compute area and update max if needed
            finalArea = max(finalArea, width * containerHeight);

            // Move the pointer of the shorter line
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return finalArea;
    }
};


*/
