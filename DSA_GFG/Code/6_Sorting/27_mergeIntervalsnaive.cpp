// Example 1
// Input:
// [[1, 3], [2, 4], [6, 8], [9, 10]]

// Output:
// [[1, 4], [6, 8], [9, 10]]

// Explanation:
// Intervals [1, 3] and [2, 4] overlap and are merged to [1, 4]. The rest do not overlap.

// Example 2
// Input:
// [[1, 3], [8, 10], [2, 6], [15, 18]]

// Output:
// [[1, 6], [8, 10], [15, 18]]

// Explanation:
// [1,3] and [2,6] overlap, merged to [1,6]. Others stay as is.

// Example 3
// Input:
// [[1, 4], [4, 5]]

// Output:
// [[1, 5]]

// Explanation:
// The intervals overlap at point 4, merged to [1, 5].

// --------------------------------------------------------------------------

// Some info about vectors
// ways of printing vectors of vector
// int main()
// {
// vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};

// sort(arr.begin(), arr.end());

// for (auto interval : arr)
//     cout << interval; This is wrong as interval is itself a vector

// ----------------------------------------------------------------
// way 1
// for (auto interval : arr)
// {
//     for (auto x : interval)
//         cout << x << " ";
//     cout << endl;
// }
// --------------------------------------------------------------------

// way 2

// for (auto interval : arr)
//     cout << interval[0] <<" "<< interval[1] << endl;

// ----------------------------------------------------------------
// way 3. But only works in c++ 17 and 17+
// for (auto [start, end] : arr)
//     cout << start << " " << end << endl;

// return 0;
// }
// cout << interval[0] << " " << interval[1] << endl;

// ------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// to understand this there is no logic as such. you have to take one example and then dry run
// it. These conditions are derived from there.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};

    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        // skip
        if (!ans.empty() && ans.back()[1] >= end)
            continue;

        for (int j = i + 1; j < n; j++)
        {
            // this condition is explained in efficient code file.
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

    vector<vector<int>> ans = mergeOverlappingIntervals(intervals);
    for (auto x : ans)
        cout << x[0] << " " << x[1] << endl;
}

// Time Complexity: O(n²)
// Space Complexity: O(n)



// logic


/*



// Function to merge overlapping intervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    if (n == 0)                       // Edge case: empty input
        return {};

    vector<vector<int>> ans;          // To store the merged intervals

    // Step 1: Sort intervals by starting point (and then by end if equal)
    sort(arr.begin(), arr.end());

    // Step 2: Traverse all intervals
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];        // Current interval's start
        int end = arr[i][1];          // Current interval's end

        // If the last interval in ans already covers this one, skip it
        // Example: ans = {{1,10}}, current interval = {2,5} → fully covered
        if (!ans.empty() && ans.back()[1] >= end)
            continue;

        // Step 3: Try to merge with following overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            // If next interval starts before or at current 'end', overlap exists
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]); // Extend 'end' to cover it
            else
                break; // No more overlap (since array is sorted)
        }

        // Step 4: Push the merged interval
        ans.push_back({start, end});
    }

    return ans;  // Step 5: Return all merged intervals
}




*/