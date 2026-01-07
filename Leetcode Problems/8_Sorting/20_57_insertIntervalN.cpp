/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.


LC-57 guarantees:

The input intervals are
sorted by start time
and non-overlapping
That means:
There are no overlaps among existing intervals
So there is nothing to merge inside intervals
The only possible overlaps are between:
newInterval and some of the existing intervals


Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        if (n == 0)
            return {newInterval}; // if empty, just return newInterval

        intervals.push_back(newInterval);         // Step 1: Add the new interval
        sort(intervals.begin(), intervals.end()); // Step 2: Sort by start time

        int start = intervals[0][0]; // initialize first interval
        int end = intervals[0][1];

        // Step 3: Merge intervals
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end)
            { // overlapping intervals
                end = max(end, intervals[i][1]);
            }
            else
            { // no overlap, push previous
                res.push_back({start, end});
                start = intervals[i][0]; // update start/end
                end = intervals[i][1];
            }
        }
        res.push_back({start, end}); // push the last interval

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {
        {1, 2},
        {3, 5},
        {6, 7},
        {8, 10},
        {12, 16}};

    vector<int> newInterval = {4, 8};
    vector<vector<int>> res = sol.insert(intervals, newInterval);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n log n) — sorting dominates.
Space: O(n) — storing the resulting merged intervals.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Add newInterval to the list.
Sort all intervals by their start time.
Merge overlapping intervals in one pass:
If the current interval overlaps with the previous, extend the end.
Otherwise, push the previous interval and start a new one.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern used: Merge Intervals


*/
