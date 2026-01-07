/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping
intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res = sol.merge(v);
    for (auto x : res)
    {
        cout << "{";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "}, ";
    }

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity           | Explanation                                                  |
| -------------------- | ------------------------------------------------------------ |
| **Time:** O(n log n) | Sorting dominates the runtime. The single traversal is O(n). |
| **Space:** O(n)**    | For storing the merged result (O(1) extra if done in-place). |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort intervals by their starting point.
→ This ensures that any overlapping intervals will be next to each other.
Initialize the first interval (start, end) as the current merge range.
Traverse the rest of the intervals:
If the current interval overlaps (intervals[i][0] <= end), merge it by updating end = max(end, intervals[i][1]).
Otherwise, push the merged interval to the result and start a new merge.
Push the last interval after the loop ends.


*/


//___________________________________________________________________________________________________________________________________________
// dry run
//___________________________________________________________________________________________________________________________________________

/*

[[1,3], [2,6], [8,10], [15,18]]
Step 1: Sort
→ Already sorted
    
Step 2: Initialize start=1, end=3
Step 3:
i=1 → [2,6] overlaps (2 <= 3) → merge → end = max(3,6) = 6
i=2 → [8,10] doesn’t overlap (8 > 6) → push [1,6], reset start=8, end=10
i=3 → [15,18] doesn’t overlap (15 > 10) → push [8,10], reset start=15, end=18

Step 4: Push last [15,18]
✅ Output:
lua
Copy code
[[1,6], [8,10], [15,18]]


*/
//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        // Step 1: Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 3: Traverse remaining intervals
        for (int i = 1; i < n; i++)
        {
            // If overlapping, extend the end boundary
            if (intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                // No overlap → push current merged interval
                res.push_back({start, end});
                // Start new merge range
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Step 4: Push the last interval
        res.push_back({start, end});

        return res;
    }
};


*/
