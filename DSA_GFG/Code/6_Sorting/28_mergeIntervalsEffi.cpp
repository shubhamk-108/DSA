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


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
{

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        // this is not necessary condition because if current interval is  the part of interval then it is already managed 
        // oin if block 
        // if (res.back()[1] >= arr[i][1])
        // {
        //     continue;
        // }
        // else if (arr[i][0] <= res.back()[1])
        if (arr[i][0] <= res.back()[1])
        {
            res.back()[1] =  max(res.back()[1], arr[i][1]);
        }
        else
        {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

    for (vector<int> &interval : res)
        cout << interval[0] << " " << interval[1] << endl;

    return 0;
}




// Time and Space Complexity
// Time Complexity: O(n log n)
// The dominant part of this algorithm is the initial sort, which has a time complexity of O(n log n), where n is the number of intervals. 
// The subsequent loop to merge the intervals runs in O(n) time because it processes each interval just once. 
// Therefore, the total time complexity is governed by the sorting step.

// Space Complexity: O(n)
// The space complexity depends on the space used by the output vector res. In the worst-case scenario, if no intervals overlap, 
// the res vector will contain all n original intervals. Therefore, the space complexity is O(n). 



/*



// logic


// vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
{
    // If the array is empty, there's nothing to merge.
    if (arr.empty()) return {};

    // 1. Sort the intervals based on their start times.
    // This is the most critical step for this algorithm to work.
    sort(arr.begin(), arr.end());

    // Create a vector to store the merged intervals.
    vector<vector<int>> res;

    // 2. Add the first interval to the result as a starting point.
    res.push_back(arr);

    // 3. Iterate through the rest of the intervals.
    for (int i = 1; i < arr.size(); i++)
    {
        // Check for an overlap: Does the current interval's start
        // come before or at the same time as the last merged interval's end? If yes then there is the overlap.
        // Now because array is sorted so the one who is in result and res's start as in 0th element will always come before
        // the current array's start. As in {1,4} , {2, 6}. {1,4} is in the res. and {2,6} is the current ith elements for which we are
        // checking  in array.
        // What is means is that current array's 2 will always come after 1 in the res because they are sorted.And 1 is already there in the res stored.
        // so we just have to update the end element. that is who is larger between 4 and 6 and 6 is larger so that will be our end. SO 
        // interval got formed between {1,6}.
        // So we checked that does 2 lie in between {1,4}. Because of sorted we already know that 2 was anyway after 1, So we just have
        // to compare it to 4 that is it smaller that 4. If smaller that 4 that means this interval lie in {1,4} and now we just
        // have to check what will be the end. ANd we know that max element between (4 and 6) 
        if (arr[i] <= res.back()[1])
        {
            // they overlap, merge them by updating the end time of the
            // last interval in 'res' to the maximum of the two end times.
            res.back()[11] = max(res.back()[11], arr[i][11]);
        }
        else
        {
            // If there's no overlap, the current interval is a new,
            // separate interval. Add it to the result.
            res.push_back(arr[i]);
        }
    }

    // Return the final list of merged intervals.
    return res;
}



*/