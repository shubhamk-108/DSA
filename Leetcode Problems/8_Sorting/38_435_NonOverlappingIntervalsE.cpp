/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int res = 0;

        int end = intervals[0][1];

        int i = 1;

        while (i < n)
        {
            if (end > intervals[i][0])
            {
                res++;
                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }

            i++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sol.eraseOverlapIntervals(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Why keep small end
//___________________________________________________________________________________________________________________________________________

/*
When intervals overlap, you must keep the interval that ends earlier, not later.
Using max(end, …) keeps the longer interval, which causes more future overlaps.


//___________________________________________________________________________________________________________________________________________
//why did we change end when no overalap in else part
//___________________________________________________________________________________________________________________________________________

/*

Why do we change end when there is NO overlap?

This line 👇

else {
    end = intervals[i][1];
}
Core idea (one sentenc
👉 When there is no overlap, the current interval becomes the new “active” interval, so its end should now be tracked.
Step-by-step intuition (with diagrams)
Assume this situation:

Current kept interval:
[1 -------- 3]
             ^
            end = 3
Next interval:
                [5 -------- 7]
Do they overlap?
5 < 3 ❌ → NO overlap
So:
We did not remove anything
The previous interval [1,3] is done
The new interval [5,7] is now the one we are keeping
👉 Therefore, end must move forward:
end = 7
If you don’t update end, your logic would still think you are inside [1,3], which is wrong.

/*

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Sorting: O(n log n)
Single pass through intervals: O(n)
Total: O(n log n)

🧠 Space Complexity
No extra data structures used
O(1) extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort intervals by start time
This lets us process intervals in order.
Keep track of the current interval’s end
end represents the interval we are currently keeping.
Iterate through remaining intervals
If the current interval overlaps (intervals[i][0] < end):
We must remove one interval → increment res
Keep the interval that ends earlier using min(end, intervals[i][1])
If there is no overlap:
Update end to the current interval’s end
Return the total number of removed intervals.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        int res = 0;                 // number of intervals removed
        int end = intervals[0][1];   // end of the interval we keep

        int i = 1;
        while (i < n)
        {
            // If current interval overlaps with previous kept interval
            if (intervals[i][0] < end)
            {
                // Remove one interval
                res++;

                // Keep the interval with smaller end
                end = min(end, intervals[i][1]);
            }
            else
            {
                // No overlap, update end
                end = intervals[i][1];
            }

            i++;
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Greedy + Interval Scheduling
Key greedy idea:
When intervals overlap, remove the one with the larger end to leave more room for future intervals.
This same pattern appears in:
LC435 – Non-overlapping Intervals
LC452 – Minimum Arrows to Burst Balloons
Activity Selection problems



*/
