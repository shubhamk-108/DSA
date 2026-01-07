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

// //  Imp Note why brute is not possible
// Below is not correct brute solution. 

/*
“If we try a brute-force approach, for every overlapping pair of intervals i and j, we have two choices:
delete i or delete j.

These choices affect future overlaps, so we must consider all combinations of deletions to guarantee the minimum number removed.
This leads to an exponential number of possibilities (2ⁿ), which is not feasible.

Therefore, we use a greedy strategy (efficient sol) that makes a locally optimal decision:
when two intervals overlap, we always remove the one with the larger end time, because it leaves more room for future intervals.”

“Yes, we could choose to delete either interval i or j when they overlap.
However, deleting i does not guarantee a minimum number of deletions overall, because that decision affects future overlaps.

To guarantee the minimum deletions, we would need to explore both choices—delete i or delete j—for every overlap.
This leads to two choices per interval, resulting in 2ⁿ possible combinations, which is exponential and not feasible.

Therefore, we use a greedy strategy (efficient ) that makes a safe choice: when two intervals overlap, we remove the one with the larger end time, 
because keeping the interval that ends earlier always leaves more room for future intervals.”

*/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int res = 0;
        vector<bool> isIntervalDeleted(n, false);
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++)
        {
            int end_1 = intervals[i][1];

            for (int j = 0; j < n; j++)
            {
                if (i == j || isIntervalDeleted[j])
                    continue;


                int start_2 = intervals[j][0];

                if (end_1 > start_2)
                {
                    if (!isIntervalDeleted[j])
                    {
                        res++;
                        end_1 = min(end_1, intervals[j][1]);

                        if (end_1 < intervals[j][1])
                        {
                            end_1 = end_1;
                            isIntervalDeleted[j] = true;
                        }
                        else
                        {
                            end_1 = intervals[j][1];
                            isIntervalDeleted[i] = true;
                        }
                    }
                }
            }
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
//Imp Note why brute is not possible
//___________________________________________________________________________________________________________________________________________

// //  
// Below is not correct brute solution. 

/*
“If we try a brute-force approach, for every overlapping pair of intervals i and j, we have two choices:
delete i or delete j.

These choices affect future overlaps, so we must consider all combinations of deletions to guarantee the minimum number removed.
This leads to an exponential number of possibilities (2ⁿ), which is not feasible.

Therefore, we use a greedy strategy (efficient sol) that makes a locally optimal decision:
when two intervals overlap, we always remove the one with the larger end time, because it leaves more room for future intervals.”

“Yes, we could choose to delete either interval i or j when they overlap.
However, deleting i does not guarantee a minimum number of deletions overall, because that decision affects future overlaps.

To guarantee the minimum deletions, we would need to explore both choices—delete i or delete j—for every overlap.
This leads to two choices per interval, resulting in 2ⁿ possible combinations, which is exponential and not feasible.

Therefore, we use a greedy strategy (efficient ) that makes a safe choice: when two intervals overlap, we remove the one with the larger end time, 
because keeping the interval that ends earlier always leaves more room for future intervals.”

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




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




*/
