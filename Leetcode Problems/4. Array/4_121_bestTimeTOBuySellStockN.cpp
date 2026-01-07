/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                profit = max(profit, prices[j] - prices[i]);
            }
        }
        return profit < 0 ? 0 : profit;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n²) → two nested loops check every pair.
Space: O(1) → constant extra memory.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Try every possible pair (i, j) such that i < j.
i → day to buy the stock.
j → day to sell the stock.
Compute the profit = prices[j] − prices[i].
Keep track of the maximum profit among all pairs.
If the best profit is negative (prices always decreasing), return 0.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = INT_MIN; // store maximum profit found so far

        // Try all pairs (i, j) where i < j
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate profit if you buy on day i and sell on day j
                profit = max(profit, prices[j] - prices[i]);
            }
        }

        // If all prices are decreasing, profit will be negative
        // Return 0 in that case (no transaction)
        return profit < 0 ? 0 : profit;
    }
};



*/
