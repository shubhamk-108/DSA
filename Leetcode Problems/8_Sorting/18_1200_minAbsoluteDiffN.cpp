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
        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                minDiff = min(minDiff, abs(arr[i] - arr[j]));
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) == minDiff)
                {
                    int a1 = min(arr[i], arr[j]);
                    int a2 = max(arr[i], arr[j]);
                    res.push_back({a1, a2});
                }
            }
        }
        sort(res.begin(), res.end());
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
Time Complexity
Pair comparison: O(n²)
Pair collection: O(n²)
Sorting result: O(k log k)
Overall: O(n²) ❌ (will TLE for large inputs)
Space Complexity
Extra space: O(1)
Output space: O(k)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Compare every pair (i, j) where i < j
Track the minimum absolute difference
Loop again to collect all pairs having that difference
Sort the result to meet output ordering requirements
This directly implements the problem statement with no optimization.
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
        int minDiff = INT_MAX;

        // Step 1: Find the minimum absolute difference
        // Check all possible pairs (brute force)
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                minDiff = min(minDiff, abs(arr[i] - arr[j]));
            }
        }

        vector<vector<int>> res;

        // Step 2: Collect all pairs with the minimum difference
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) == minDiff)
                {
                    // Ensure the pair is in ascending order
                    int a1 = min(arr[i], arr[j]);
                    int a2 = max(arr[i], arr[j]);
                    res.push_back({a1, a2});
                }
            }
        }

        // Step 3: Sort result pairs as required by LC-1200
        sort(res.begin(), res.end());

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Brute Force / Exhaustive Search Pattern
Try every possible pair
*/
