// Our Task: The cost of a stock on each day is given in an array. Find the maximum profit that you can make by buying and 
// selling on those days. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

// Examples:

// Input: arr[] = {100, 180, 260, 310, 40, 535, 695}
// Output: 865
// Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210
//                        Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655
//                        Maximum Profit  = 210 + 655 = 865
// Input: arr[] = {4, 2, 2, 2, 4}
// Output: 2
// Explanation: Buy the stock on day 1 and sell it on day 4 => 4 – 2 = 2
//                        Maximum Profit  = 2

#include <iostream>
#include<cmath>
using namespace std;


int maxProfit(int arr[], int start, int end)
{
    if(end <= start)
        return 0;
    
    int profit = 0;

    for (int i = start; i< end; i++)
    {
        for(int j = i+1; j<=end; j++)
        {
            if(arr[j] > arr[i])
            {
                int current_profit = arr[j] - arr[i] + maxProfit(arr, start, i-1) + maxProfit(arr, j+1, end) ;

                profit = max(profit, current_profit);
            }

        }
    }
    return profit;
}

int main()
{
    int arr[] =  {4, 3, 3, 8, 12,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n-1;

    cout<<maxProfit(arr,start,end);

    return 0;
}

// Time Complexity: O(n2), Trying to buy every stock and exploring all possibilities.
// Auxiliary Space: O(1)

// about  maxProfit(arr, start, i-1)
// If we remove it, still output is not changing 
// maxProfit(price, start, i - 1) is not strictly necessary in this code because:
// The loop structure already explores all possible buy/sell pairs.
// It doesn't affect the final result.
// But it’s kept in some versions to explicitly show the idea of handling disjoint subarrays — more for conceptual completeness than need.


// ------------------------------------------------------------------------------------

// Logic 

/*

int maxProfit(int arr[], int start, int end)
{
    // regular i= 1; i<n peksha we have use start and end. That is may be we have used recursion here that is why
    if(end <= start)
        return 0;
    
    int profit = 0;

    // i is started from 1 and i<end. Here we are not considering last element as i becasue next element madhun previous element 
    // karayacha aahe ani i ha preious element mhanun act karel. J ha next element mhanun act karel. For example j ha last element 
    // la point karat asel aani i ha second last element la point karat asel ani tevha loop end hoil. 
    for (int i = start; i< end; i++)
    {
        // jithe pn i point karatoy tithun pudhache sagle indices hya j mjanun kam karatil
        for(int j = i+1; j<=end; j++)
        {
            // jr next element larger asel tr to aapan previous element madhun minus karu shakato mhanje profit ha positive kiwa
            // max milel.
            if(arr[j] > arr[i])
            {
                //  maxProfit(arr, j+1, end) ha call i jithe aahe tithun pudhachya elements sathi call karatoy.
                // mhanje same problem arr[j] > arr[i] aapan parat solve karat aahot pn hya veles aapan
                // array modify karun dilela aahe. Ki yachya pathimagcha profit kadhalela aahe aata tu ithun pudhacha profit calculate kr
                // so to parat arr[j] > arr[i] hi condition check karun profit update karel
                int current_profit = arr[j] - arr[i] + maxProfit(arr, start, i-1) + maxProfit(arr, j+1, end) ;

                profit = max(profit, current_profit);
            }

        }
    }
    return profit;
}

*/