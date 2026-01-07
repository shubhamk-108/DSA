/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end());

        long long end = points[0][1];
        int count = 1;

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= end)
            {
                end = min(end, (long long)points[i][1]);
            }
            else
            {
                count++;
                end = points[i][1];
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << sol.findMinArrowShots(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Why we use min
//___________________________________________________________________________________________________________________________________________

/*
Take this ex
(1,6), (2,4), (5,7)

[1------------------------6]
    [2---------4] 
                    [5---------7]

All overlaps with (1,6) but still one arraow cant shoot all baloon. So we need to find intersection where arraw can hit all overlapping
baloon. That is why we need to find the minimum end, if the arraow is hitting minimum then it will definitely hit max end.
Now add(3,4) and see it will overlap with 4 and we can shoot those 3 baloons with 1 arrao and we need one more for (5,7)

[1------------------------6]
    [2---------4] 
                    [5---------7]
            3---4
*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity

Sorting: O(n log n)

Single pass scan: O(n)

✅ Overall: O(n log n)

Space Complexity

No extra data structures used

Sorting in-place

✅ O(1) auxiliary space 
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Each balloon is an interval [start, end].
One arrow shot at position x bursts all balloons where:

start ≤ x ≤ end


To minimize arrows, we want one arrow to burst as many balloons as possible.

Greedy strategy

Sort balloons by starting coordinate

Assume we shoot the first arrow at the end of the first balloon

For every next balloon:

If it overlaps with the current arrow position
→ shrink the valid arrow range using min(end)

If it does not overlap
→ shoot a new arrow and reset the range

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // Edge case: no balloons
        if (points.empty())
            return 0;

        // Sort balloons by start coordinate
        sort(points.begin(), points.end());

        // 'end' represents the rightmost position
        // where the current arrow can still be placed
        long long end = points[0][1];

        // At least one arrow is needed for the first balloon
        int count = 1;

        for (int i = 1; i < points.size(); i++)
        {
            // If current balloon overlaps with the arrow position
            if (points[i][0] <= end)
            {
                // Shrink the valid arrow range (intersection)
                end = min(end, (long long)points[i][1]);
            }
            else
            {
                // No overlap → need a new arrow
                count++;

                // Reset arrow range for the new balloon
                end = points[i][1];
            }
        }

        // Total arrows required
        return count;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


More specifically:
Interval intersection greedy
Closely related to:
LC435 – Non-overlapping Intervals
LC56 – Merge Intervals (but with min, not max)

*/
