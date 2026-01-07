/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr


Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
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
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            minDiff = min(minDiff, abs(arr[i] - arr[i - 1]));
        }

        vector<vector<int>> res;
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) == minDiff)
                res.push_back({arr[i - 1], arr[i]});
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {4, 2, 1, 3};
    vector<vector<int>> res = sol.minimumAbsDifference(v);

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
Time:
Sorting → O(n log n)
Single pass scans → O(n)
Total: O(n log n) ✅ (best possible)

Space:
Output array + sort (in-place)
Aux space: O(1) (ignoring result) ✅
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Sorts the array ✔️
Finds the minimum difference between neighbors ✔️
Collects all adjacent pairs that match that minimum ✔️

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();

        // Step 1: Sort the array
        // After sorting, the minimum absolute difference
        // will always be between adjacent elements
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        // Step 2: Find the minimum difference
        // Compare only adjacent elements
        for (int i = 1; i < n; i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> res;

        // Step 3: Collect all pairs with minimum difference
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sorting + Adjacent Comparison Pattern
Why this works:
In an unsorted array, checking all pairs would take O(n²)
Sorting brings close numbers next to each other
The minimum absolute difference must occur between adjacent elements after sorting


*/
