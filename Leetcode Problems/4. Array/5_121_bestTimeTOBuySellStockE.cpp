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
        int bestProfit = INT_MIN; // stores maximum profit found so far
        int minSoFar = prices[0]; // stores the minimum price seen so far

        // Start from second day (index 1)
        for (int i = 1; i < prices.size(); i++)
        {
            // Update minimum price if current price is smaller
            if (prices[i] < minSoFar)
                minSoFar = prices[i];

            // Calculate profit if we sell today and update bestProfit
            bestProfit = max(bestProfit, prices[i] - minSoFar);
        }

        // If all prices are decreasing, return 0
        return bestProfit < 0 ? 0 : bestProfit;
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
Time: O(n) — single traversal of the array.
Space: O(1) — only two extra variables used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Keep track of the minimum price so far (minSoFar) as you traverse the array.
For each price prices[i], calculate the potential profit if you sold today:
profit = prices[i] - minSoFar
Update bestProfit if this profit is higher.
Also update minSoFar if the current price is lower than any previous price.
At the end, return bestProfit (or 0 if negative).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = INT_MIN;      // stores maximum profit found so far
        int minSoFar = prices[0];      // stores the minimum price seen so far

        // Start from second day (index 1)
        for(int i = 1; i < prices.size(); i++) {
            // Update minimum price if current price is smaller
            if(prices[i] < minSoFar)
                minSoFar = prices[i];

            // Calculate profit if we sell today and update bestProfit
            bestProfit = max(bestProfit, prices[i] - minSoFar);
        }

        // If all prices are decreasing, return 0
        return bestProfit < 0 ? 0 : bestProfit;
    }
};



*/
