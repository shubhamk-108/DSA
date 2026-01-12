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
        stack<int> st;
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                res[i] = i + 1;
                st.push(i);
            }
            else
            {
                while (!st.empty() && arr[st.top()] <= arr[i])
                    st.pop();
                if (st.empty())
                    {res[i] = i + 1;}
                else
                    res[i] = i - st.top();
                st.push(i);
            }
        }
        return res;
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
// what is amortized O(1) or O(n)?
//___________________________________________________________________________________________________________________________________________

/*

what is amortized O(1) or O(n)?
Simple meaning (no theory)

Amortized time means:
Even if some operations are slow, when you average the cost over many operations, each operation is fast.

It is NOT average case.
It is a guarantee over a sequence of operations.

🔹 Real-life analogy
Imagine:
You pay ₹100 once a year
Rest of the year you pay ₹0
Average per day ≈ ₹0.27
So amortized cost per day is small, even though one day was expensive.
🔹 In Stock Span / Monotonic Stack
For the stack:
Some next() calls pop many elements
But each element can be popped only once in total
So across N days:
Total pushes ≤ N
Total pops ≤ N

👉 Total work ≤ 2N → O(N)
👉 Amortized cost per operation = O(1)

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n)
Each index is:
pushed once
popped at most once

Space Complexity
🧠 O(n)
Stack stores indices
Result array

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want the stock span for each day i:
Number of consecutive days before i (including i) where price ≤ price[i]
Key idea
For each day, we need the nearest previous day with a higher price.
We use a monotonic decreasing stack that stores indices of days:
Prices at those indices are always strictly greater than the next ones below.
Steps
Traverse prices from left to right.
For current day i:
Pop all previous days whose price ≤ current price.
After popping:
If stack is empty → no previous greater price → span = i + 1
Else → span = i - index_of_previous_greater
Push current index into stack.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        int n = arr.size();

        stack<int> st;          // stores indices of days
        vector<int> res(n);     // result array for spans

        for (int i = 0; i < n; i++)
        {
            // Remove all previous days with price <= current day
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            // If no previous greater element exists
            if (st.empty())
                res[i] = i + 1;
            else
                // Distance from previous greater element
                res[i] = i - st.top();

            // Push current day's index
            st.push(i);
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern used (important for interviews)

👉 Monotonic Stack
👉 Previous Greater Element (PGE)
👉 Span / Range Query Pattern


*/
