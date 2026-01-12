/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

Examples:

Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more days behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 90 is greater than equal to 90 and 80 so the span is 2, 120 is greater than 90, 80 and 100 so the span is 4. So the output will be [1, 1, 2, 4].
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
    vector<int> calculateSpan(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> span(n);

        for (int i = 0; i < n; i++)
        {
            span[i] = 1; // span is at least 1 (current day)

            // check previous days
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] <= arr[i])
                    span[i]++;
                else
                    break; // stop when higher price is found
            }
        }
        return span;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = sol.calculateSpan(v);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
⏱ O(n²) (worst case)

Space Complexity
🧠 O(n)



*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


For each day i, we want to find how many consecutive previous days (including today) had stock prices less than or equal to arr[i].
Steps:
Start from the current day i.
Move backward day by day.
Count days until:
price ≤ current price → include in span
price > current price → stop
This directly follows the problem definition, hence it is brute force.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

for (int i = 0; i < n; i++)
{
    span[i] = 1;     // current day always counts

    for (int j = i - 1; j >= 0; j--)
    {
        // include previous days with lower or equal price
        if (arr[j] <= arr[i])
            span[i]++;
        else
            break;   // stop when higher price found
    }
}



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*


Pattern used

👉 Brute Force / Nested Loop
👉 Previous Element Scan

*/

