
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
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        unordered_map<int, int> um_prefixSum;

        int currentPrefixSum = 0;
        um_prefixSum[0] = 1; // this is as key : value = 0 : 1. That is 0 has appeared one time.when the prefix sum will 
        // be exact k , for ex k is 2 and prefix sum is 2 then required will be 2-2 = 0. But we will not see 0 in the map 
        // because to insert 0 that is never the case. So we have to insert it explicitely.
        for (int i = 0; i < n; i++)
        {
            currentPrefixSum += nums[i];
            int required = currentPrefixSum - k;

            if (um_prefixSum.find(required) != um_prefixSum.end())
                count += um_prefixSum[required];

            um_prefixSum[currentPrefixSum]++;
        }
        return count;
    }
};

// int main()
// {
//     Solution sol;
//     vector<int> v = {3, 2, 1, 1, 4, 5};
//     int k = 5;
//     cout << sol.subarraySum(v, k);
//     return 0;
// }

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n) — single pass through the array
Space: O(n) — for the hash map
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

You maintain a running prefix sum (currentPrefixSum) and use a hash map to record how many times each prefix sum has appeared so far.
At each step:
required = currentPrefixSum - k → checks if there’s a previous prefix sum that makes the current subarray’s sum = k.
If yes, add its frequency to count.
Then record the current prefix sum.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> um_prefixSum;

        um_prefixSum[0] = 1; // base case: handles subarrays starting at index 0
        int currentPrefixSum = 0;

        for (int i = 0; i < n; i++)
        {
            currentPrefixSum += nums[i];
            int required = currentPrefixSum - k;

            if (um_prefixSum.find(required) != um_prefixSum.end())
                count += um_prefixSum[required];

            um_prefixSum[currentPrefixSum]++;
        }
        return count;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Why um_prefixSum[0] = 1
//___________________________________________________________________________________________________________________________________________

/*

consider this input nums = [3, 4, 7, 2], k = 7.
Now {3,4 } is valid subarray but according to our logic to make it valid we need 0 to be found in map. But 0 is not in map because 
we never encounter 0 as prefixSum. So this is base case and we explicitely have to add this in map.
int required = currentPrefixSum - k;
required = (3+4) - 7 = 0
So 0 is required but 0 is not in map. But this is valid subarray. So we add it explicitely. THis is imp base condition.


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Prefix Sum + Hash Map (Cumulative Sum Counting Pattern)


*/