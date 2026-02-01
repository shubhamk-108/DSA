/*
Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        int ans = INT_MAX;

        // Try all subarrays
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                long long sum = prefix[j] - prefix[i];
                if (sum >= k)
                {
                    ans = min(ans, j - i);
                    break; // further j will only increase length
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, -1, 2};
    cout << sol.shortestSubarray(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time & Space Complexity
Time
O(n²) → nested loops

Space
O(n) → prefix sum array
We can even solve without prefix sum so O(n ) space wont be necessary in that case.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Idea

Try every possible subarray
Compute its sum
If sum ≥ k, update the minimum length
To avoid recomputing sums again and again, we’ll still use prefix sums, but no deque, no tricks.

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
