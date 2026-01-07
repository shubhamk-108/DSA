/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
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
        int soFarMin = prices[0];
        int totalProfit = 0;
        int n = prices.size();
        int currentProfit = 0;

        for (int i = 1; i < n; i++)
        {
            if (prices[i] - prices[i - 1] > 0)
                totalProfit += prices[i] - prices[i - 1];
        }

        return totalProfit;
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
Time: O(n)
Space: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

You can make multiple transactions (buy and sell multiple times), but you can’t hold more than one stock at a time.
Key Idea:
The goal is to capture all the upward price movements.
Whenever the price goes up from one day to the next (prices[i] > prices[i-1]), it means you could have made a profit by buying the previous 
day and selling today.
So, just sum all positive differences between consecutive days.
This effectively simulates buying at every local minimum and selling at every local maximum — without explicitly tracking them.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int totalProfit = 0; // store total accumulated profit
        int n = prices.size();

        // Traverse prices from the second day onward
        for (int i = 1; i < n; i++)
        {
            // If today's price is higher than yesterday's,
            // it means we can earn profit by buying yesterday and selling today.
            if (prices[i] - prices[i - 1] > 0)
                totalProfit += prices[i] - prices[i - 1];
        }

        // Return total profit after processing all days
        return totalProfit;
    }
};


*/
