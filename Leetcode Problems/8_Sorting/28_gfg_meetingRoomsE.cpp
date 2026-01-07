/*
Given a 2D array arr[][], where arr[i][0] is the starting time of ith meeting and arr[i][1] is the ending time of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

Note: A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

Examples:

Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: Since the second and third meeting overlap, a person cannot attend all the meetings.
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
    bool canAttend(vector<vector<int>> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int start = arr[0][0];
        int end = arr[0][1];

        for (int i = 1; i < n; i++)
        {
            if (arr[i][0] < end)
                return false;
            else
            {
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{2, 4}, {9, 12}, {6, 10}};
    cout << sol.canAttend(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Sorting meetings: O(n log n)
Single traversal: O(n)
Total:
O(nlogn)
	​

💾 Space Complexity
No extra data structures used
Sorting done in-place (ignoring internal sort stack)
Extra space:
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Sort all meetings by their start time.
Start with the end time of the first meeting.
Traverse the remaining meetings:
If the next meeting starts before the current meeting ends → overlap → return false.
Otherwise, update the current end time.
If all meetings are processed without overlap → return true.
The key observation is that after sorting, we only need to compare adjacent meetings.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        int n = arr.size();

        // Step 1: Sort meetings based on start time
        sort(arr.begin(), arr.end());

        // Step 2: Track the end time of the first meeting
        int end = arr[0][1];

        // Step 3: Check each subsequent meeting
        for (int i = 1; i < n; i++)
        {
            // If current meeting starts before the previous one ends,
            // then meetings overlap
            if (arr[i][0] < end)
                return false;

            // Update end time to current meeting's end
            end = arr[i][1];
        }

        // Step 4: No overlaps found
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________
/*
Interval Scheduling / Overlap Detection Pattern
More specifically:
Sort + Linear Scan on Intrvals
This pattern is used when:
You’re given time intervals
You need to detect overlap, merge intervals, or validate scheduling
Related problems using the same patter
Meeting Rooms 
Merge Intervals
Non-overlapping Intervals
Interval Scheduling Greedy Problems


*/
