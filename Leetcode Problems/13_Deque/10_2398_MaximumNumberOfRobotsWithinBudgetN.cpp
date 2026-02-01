/*
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts), where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.



Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation:
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.

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
    int maximumRobots(vector<int> &chargeTimes,
                      vector<int> &runningCosts,
                      long long budget)
    {
        int n = chargeTimes.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int maxCharge = 0;
            long long sumRunning = 0;

            for (int j = i; j < n; j++)
            {
                maxCharge = max(maxCharge, chargeTimes[j]);
                sumRunning += runningCosts[j];

                int k = j - i + 1;
                long long cost =
                    maxCharge + (long long)k * sumRunning;

                if (cost <= budget)
                    ans = max(ans, k);
                else
                    break; 
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {3, 6, 1, 3, 4};
    vector<int> v2 = {2, 1, 3, 4, 5};
    cout << sol.maximumRobots(v1, v2, 25);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity (brute)
Outer loop → O(n)
Inner loop → O(n)
⛔ Worst case:
O(n²)

This TLEs for large constraints — and that’s expected.
📦 Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We want the maximum length subarray whose total cost does not exceed the budget.
Since the cost only increases when we expand the window, we use a variable-size sliding window.
To get the maximum charge time in the current window efficiently, we maintain a monotonic decreasing deque.
To compute the sum of running costs in O(1), we use a prefix sum (or running sum).
We expand the window using the right pointer, and if the cost exceeds the budget, we shrink it from the left.
At every valid window, we update the maximum length.


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
