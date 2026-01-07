/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
Example 1:

Input: arr = [0,1,0]

Output: 1

Example 2:

Input: arr = [0,2,1,0]

Output: 1

Example 3:

Input: arr = [0,10,5,2]

Output: 1


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
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 10, 5, 2};
    cout << sol.peakIndexInMountainArray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
You scan the array once.

Space Complexity: O(1)
No extra space used except variables.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



A mountain array strictly increases to a peak, then strictly decreases.
You iterate from index 1 to n-2.
At each index i, you check:
if arr[i] is greater than both neighbors (arr[i-1] < arr[i] > arr[i+1]).
This condition identifies the peak element, and you return its index.
If no peak is found (should not happen in valid input), return -1.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        // Loop from 1 to n-2 since peak cannot be at boundaries
        for (int i = 1; i < n - 1; i++)
        {
            // Check if current element is a peak
            // Mountain property: arr[i-1] < arr[i] > arr[i+1]
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
                return i;   // Found the peak index
        }

        // Should not reach here for valid mountain array, but return -1 for safety
        return -1;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
✔ Linear Scan / Single Pass



*/
