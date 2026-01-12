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



class StockSpanner {
    vector<int> prices;   // store all previous prices

public:
    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);

        int span = 1;
        int i = prices.size() - 2;  // start from previous day

        while (i >= 0 && prices[i] <= price) {
            span++;
            i--;
        }

        return span;
    }
};





//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Worst case: O(n) per next()
Total over N calls:
1 + 2 + 3 + ... + n = O(n²)

6️⃣ Space Complexity
🧠 O(n)
Stores all prices
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*
We maintain a list of all prices seen so far.
When a new price arrives, we scan backward from the previous day.
We count how many consecutive prices are less than or equal to the current price.
As soon as a higher price is found, we stop.
This directly follows the problem statement.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


prices.push_back(price);   // store today's price

int span = 1;              // today counts
int i = prices.size() - 2;

while (i >= 0 && prices[i] <= price) {
    span++;
    i--;
}


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*




*/

