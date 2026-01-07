/*
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that
 no points are inside the area.
A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest
vertical area is the one with the maximum width.
Note that points on the edge of a vertical area are not considered included in the area
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
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_set<int> uset;
        int maxDiff = 0;
        for (auto &p : points)
        {
            uset.insert(p[0]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int left = min(points[i][0], points[j][0]);
                int right = max(points[j][0], points[i][0]);

                bool flag = false;
                for (auto x : uset)
                {
                    if(x > left && x < right)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag == false)
                {
                    int diff = right - left;
                    maxDiff = max(maxDiff, diff);
                }
            }
        }
        return maxDiff;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {
        {8, 7},
        {9, 9},
        {7, 4},
        {9, 7}};
    cout << sol.maxWidthOfVerticalArea(points);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer double loop → O(n²)
Inner scan through all x's → O(n)
Total → O(n³)

Space Complexity
Only storing unique x-values → O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Extract all x-coordinates into an unordered_set so you can quickly check if some x-value exists.
Try every pair of points (i, j) → this gives two x-coordinates.
For each pair:
Compute left = min(x[i], x[j])
Compute right = max(x[i], x[j])
Check if any other x lies strictly between left and right
If yes → this vertical area is invalid
If no → update maxDiff = right - left
Return the maximum width found.
This directly matches your implementation logic and is a correct brute.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

// naive O(n^3) brute-force
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        int n = points.size();

        // store all x-coordinates for quick lookup
        unordered_set<int> uset;
        int maxDiff = 0;

        for (auto &p : points)
        {
            uset.insert(p[0]);   // insert every x into the set
        }

        // check every pair of points (i, j)
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // get the smaller and larger x among the two
                int left = min(points[i][0], points[j][0]);
                int right = max(points[j][0], points[i][0]);

                bool flag = false;

                // check if any other x lies strictly between left and right
                for (auto x : uset)
                {
                    if (x > left && x < right)
                    {
                        flag = true;  // some x lies inside → break the check
                        break;
                    }
                }

                // if no x is between left and right → valid empty vertical area
                if (flag == false)
                {
                    int diff = right - left;  // width of this vertical gap
                    maxDiff = max(maxDiff, diff);
                }
            }
        }

        return maxDiff;  // return the largest empty vertical gap
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Brute Force / Try All Pairs Pattern
Evaluate every pair of coordinates
Check validity conditions for each pair
Set Lookup Pattern
Use unordered_set to quickly check presence of x-values



*/
