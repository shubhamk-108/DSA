/*
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.

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
private:
    bool isMountain(vector<int> &arr, int start, int end)
    {
        if (end - start + 1 < 3)
            return false;

        int i = start;
        while (i < end && arr[i] < arr[i + 1])
            i++;

        if (i == start || i == end)
            return false;

        while (i < end && arr[i] > arr[i + 1])
            i++;

        return i == end;
    }

public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();

        int longestSubarray = 0;
        if (n < 3)
            return 0;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (isMountain(arr, i, j))

                    longestSubarray = max(longestSubarray, j - i + 1);
            }
        }
        return longestSubarray;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {2, 1, 4, 7, 3, 2, 5};
    cout << sol.longestMountain(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop (i): O(n)
Inner loop (j): O(n)
isMountain check: O(n) in worst case
Total: O(n³) — brute force, very slow but conceptually clear.

Space Complexity
O(1) extra space — only a few variables.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Brute-force Enumeration:
For every possible subarray (i, j) with length ≥ 3, check if it forms a valid mountain.
Helper Function (isMountain):
First, climb up strictly (arr[i] < arr[i+1]) until the peak.
Ensure there is a valid increasing part (not flat, not empty).
Then, climb down strictly (arr[i] > arr[i+1]) till the end.
If both parts exist and traversal ends exactly at end, it’s a valid mountain.
Update Result:
For every valid mountain, track its length.
Return the longest mountain length.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
private:
    // Helper to check if subarray arr[start...end] is a mountain
    bool isMountain(vector<int> & arr, int start, int end)
    {
        if (end - start + 1 < 3)
            return false; // Must have at least 3 elements

        int i = start;

        // Step 1: climb up
        while (i < end && arr[i] < arr[i + 1])
            i++;

        // Peak can't be at start or end
        if (i == start || i == end)
            return false;

        // Step 2: climb down
        while (i < end && arr[i] > arr[i + 1])
            i++;

        // If we end exactly at 'end', it's a valid mountain
        return i == end;
    }

public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;

        int longestSubarray = 0;

        // Try all subarrays
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (isMountain(arr, i, j))
                    longestSubarray = max(longestSubarray, j - i + 1);
            }
        }

        return longestSubarray;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern
//___________________________________________________________________________________________________________________________________________


/*
Brute Force + Two-Pointer Validation (Peak Expansion)
This is the most fundamental way to detect “up-down” substructures before optimizing to O(n).
*/