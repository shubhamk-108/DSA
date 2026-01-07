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
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;

        int longestSubarray = 0;
        int i = 1;

        while (i < n - 1)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int left = i - 1;
                int right = i + 1;

                while (left > 0 && arr[left] > arr[left - 1])
                    left--;

                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;

                longestSubarray = max(longestSubarray, right - left + 1);

                i = right;
            }
            else
            {
                i++;
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
Each element is visited at most twice (once in left expansion, once in right expansion).
 O(n)

 Space Complexity
Only a few extra variables used.
 O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

A “mountain” has a strictly increasing sequence followed by a strictly decreasing sequence.
So, for any index i, if

arr[i-1] < arr[i] > arr[i+1]


→ arr[i] is the peak of a potential mountain.

Expand Left:
From that peak, move left while the numbers are strictly increasing when going backwards
(arr[left] > arr[left - 1]).

Expand Right:
From that peak, move right while the numbers are strictly decreasing (arr[right] > arr[right + 1]).

Calculate Length:
The length of that mountain = right - left + 1.

Skip Processed Elements:
Move i directly to right to skip the current mountain (avoids reprocessing) → ensures O(n) efficiency.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;

        int longestSubarray = 0;
        int i = 1;

        while (i < n - 1)
        {
            // Check if current element is a peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int left = i - 1;
                int right = i + 1;

                // Expand left: strictly increasing part
                while (left > 0 && arr[left] > arr[left - 1])
                    left--;

                // Expand right: strictly decreasing part
                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;

                // Update the longest mountain length
                longestSubarray = max(longestSubarray, right - left + 1);

                // Move i to end of this mountain to avoid overlap
                i = right;
            }
            else
            {
                // Move to next element if not a peak
                i++;
            }
        }

        return longestSubarray;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two-Pointer / Expand Around Peak Pattern
This pattern is similar to:
Expanding around a center (like in palindrome problems)
Using pointers to grow outward until a condition breaks

*/