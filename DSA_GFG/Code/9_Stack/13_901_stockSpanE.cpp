/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.


Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6

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

class StockSpanner
{
public:
    stack<pair<int, int>> st;

    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// int main() {
//     Solution sol;
//     vector<int> v ;
//     cout << sol.(v);
//     return 0;
// }

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
⏱ Amortized O(1) per next() call
Why?
Each price is pushed once
Each price is popped once
Total operations over N calls = O(N)
So:
Total O(N) → Amortized O(1) per operation

5️⃣ Space Complexity
🧠 O(N)
Stack may store up to N (price, span) pairs in worst case
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This is an online problem:
Stock prices arrive one by one, and for each price we must immediately return its span.

Key idea
Use a monotonic decreasing stack that stores:
(price, span)
For each new price:
Start span as 1 (current day).
Pop all previous prices that are less than or equal to current price.
While popping, add their spans to the current span.
Push (current price, computed span) onto the stack.
Return the span.
This works because previously computed spans can be reused, avoiding re-counting.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class StockSpanner
{
public:
    // Stack stores pairs: {price, span}
    stack<pair<int, int>> st;

    StockSpanner()
    {
        // constructor runs once, stack starts empty
    }

    int next(int price)
    {
        int span = 1; // at least today counts

        // merge spans of all previous prices <= current price
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second; // reuse previous span
            st.pop();
        }

        // push current price and its span
        st.push({price, span});

        return span;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


👉 Monotonic Stack
👉 Online Algorithm
👉 Span Compression / Previous Greater Element

*/
