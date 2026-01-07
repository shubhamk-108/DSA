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
private:
    int solve(vector<int> &prices, int start)
    {

        if (start >= prices.size())
            return 0;

        int currentProfit = 0;
        int totalProfit = 0;

        for (int i = start; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] > prices[i])
                {
                    currentProfit = prices[j] - prices[i] + solve(prices, j + 1);
                    totalProfit = max(totalProfit, currentProfit);
                }
            }
        }

        return totalProfit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return solve(prices, 0);
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
Time : T(n)=O(n^2 * 2^n)

Two nested loops → O(n²)
Inside the inner loop, whenever prices[j] > prices[i], you call:
solve(prices, j + 1);
That means:
From one function call (say starting at day start), you might make multiple further recursive calls — one for each possible transaction pair (i, j).
Each recursive call again does its own O(n²) loop work and then calls further subproblems.
At each step, you can choose to take or skip a profitable transaction.
There can be up to 2^n combinations of "buy-sell decisions" (whether to perform a transaction or not).
Hence, the recursion tree has exponential size.
T(n)=O(n^2 * 2^n)


Space Complexity
Recursion depth up to O(n) (worst case, each call moves forward one day).
Apart from that, only a few integer variables are used.
Space Complexity: O(n) (due to recursion stack)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
This is a brute-force recursive solution that tries all possible pairs of buy and sell days to find the maximum achievable profit.
Start from a given index start in the price array.
For each possible buy day i, try every possible sell day j > i.
If selling at j gives profit (prices[j] > prices[i]):
Calculate the profit from this transaction.
Add the best possible profit from subsequent transactions → solve(prices, j + 1).
Take the maximum over all possible (buy, sell) pairs.
Base case: If start exceeds the array length, return 0 (no profit possible).
This explores every possible sequence of buy-sell decisions, ensuring no overlapping transaction



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
private:
    // Recursive helper to find max profit starting from index 'start'
    int solve(vector<int> &prices, int start)
    {
        // Base case: if no more days left, no profit
        if (start >= prices.size())
            return 0;

        int totalProfit = 0; // Stores the best profit starting from 'start'

        // Try buying on every possible day 'i'
        for (int i = start; i < prices.size(); i++)
        {
            // Try selling on every possible later day 'j'
            for (int j = i + 1; j < prices.size(); j++)
            {
                // Only consider profitable transactions
                if (prices[j] > prices[i])
                {
                    // Profit = (current transaction) + (best future profit)
                    // see example below to see why it uses recursion
                    int currentProfit = prices[j] - prices[i] + solve(prices, j + 1);

                    // Update best total profit
                    totalProfit = max(totalProfit, currentProfit);
                }
            }
        }

        // Return the best profit found from this starting point
        return totalProfit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        // Start recursion from day 0
        return solve(prices, 0);
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Example
//___________________________________________________________________________________________________________________________________________

/*

7,1,5,6,3,4
If i buy at 1 and sell at 6 then i can not buy at 5 and sell at 6. This is because i cant hold two stocks at a time. I had to sell before
buying new one. SO 1's and 5's stock was sold at  6  then in this case i have two stocks in my portfolio which is wrong.
That is why if i buy at 1 and sell at 6 then i have to start new buing and selling from one next from 6 which is 3 in this case.
So we gave a fresh call using recursion and told recursion to check after 6 because till 6 i am already holding one stock.

*/