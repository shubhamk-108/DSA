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

        vector<bool> isMerged(n, false);

        int start;
        int end;

        for (int i = 0; i < n; i++)
        {
            if (isMerged[i])
                continue;
            int start = intervals[i][0];
            int end = intervals[i][1];

            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    end = max(end, intervals[j][1]);
                    isMerged[j] = true;
                }
                else
                {
                    break;
                }
            }
            res.push_back({start, end});
        }

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

Sorting: O(n log n)
Nested merging loops: O(n²) (worst case when all intervals overlap)
Overall: O(n²)

Space Complexity
isMerged vector: O(n)
Result storage: O(n) (output space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Sort the intervals based on their start value.
Maintain a vector<bool> (isMerged) to mark intervals that have already been merged.
Traverse each interval i:
Skip it if it’s already merged.
Take it as the starting point (start, end).
Expand the current merged interval by checking all future intervals j.
If intervals[j][0] <= end, they overlap — extend end to max(end, intervals[j][1]) and mark j as merged.
If they don’t overlap, break the loop.
Push the merged [start, end] into the result vector.
Continue until all intervals are processed
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

        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        // To track intervals already merged
        vector<bool> isMerged(n, false);

        // Step 2: Iterate through intervals
        for (int i = 0; i < n; i++)
        {
            if (isMerged[i])
                continue; // skip already merged intervals

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Step 3: Merge overlapping intervals ahead
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    // Overlapping → merge
                    end = max(end, intervals[j][1]);
                    isMerged[j] = true;
                }
                else
                {
                    // No overlap → stop merging further
                    break;
                }
            }

            // Step 4: Store the merged interval
            res.push_back({start, end});
        }

        return res;
    }
};



*/
