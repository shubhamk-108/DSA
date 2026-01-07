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
            return {newInterval};

        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
        {
               res.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
         res.push_back(newInterval);
        while (i < n )
        {
            res.push_back(intervals[i]);
            i++;
        }
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
Time Complexity
Single pass through intervals → O(n) ✅
Space Complexity
Output array → O(n)
Extra space → O(1) (excluding output)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key guarantee from the problem:
Existing intervals are sorted and non-overlapping
Strategy:
Push intervals completely before newInterval
Merge overlapping intervals into newInterval
Push intervals completely after newInterval
Each interval fits into exactly one of these categories.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        // Edge case: no existing intervals
        if (n == 0)
            return {newInterval};

        int i = 0;

        // 1️⃣ Add all intervals that end BEFORE newInterval starts
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // 2️⃣ Merge all intervals that OVERLAP with newInterval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        // Add the merged newInterval
        res.push_back(newInterval);

        // 3️⃣ Add all intervals that start AFTER newInterval ends
        while (i < n)
        {
            res.push_back(intervals[i]);
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


Interval Classification + One-Pass Merge Pattern
This pattern relies on:
sorted, non-overlapping intervals
classifying each interval as:
before
overlapping
after

*/
