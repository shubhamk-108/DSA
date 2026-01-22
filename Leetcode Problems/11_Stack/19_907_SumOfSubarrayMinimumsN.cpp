/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.



Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
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
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            int minVal = arr[i];

            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, arr[j]);
                sum = (sum + minVal) % M;
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 1, 2, 4};
    cout << sol.sumSubarrayMins(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Outer loop → n
Inner loop → n

➡ Time Complexity: O(n²)

6. Space Complexity
Only a few variables use
No extra data structures
➡ Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Fix a starting index i
Expand the subarray ending at j
Keep track of the minimum element seen so far
Add this minimum to the answer
Repeat for all possible subarrays
This directly follows the definition of the problem.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        int M = 1e9 + 7;

        // Fix the starting index of subarray
        for (int i = 0; i < n; i++)
        {
            int minVal = arr[i]; // minimum of current subarray

            // Extend subarray from i to j
            for (int j = i; j < n; j++)
            {
                // Update minimum for subarray [i..j]
                minVal = min(minVal, arr[j]);

                // Add the minimum to the total sum
                sum = (sum + minVal) % M;  // MUST use %
            }
        }
        return sum;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
