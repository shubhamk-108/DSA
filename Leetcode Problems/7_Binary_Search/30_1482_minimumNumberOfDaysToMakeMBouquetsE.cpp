/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.


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
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        
        if (1LL * m * k > n)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int count = 0;
            int bouquetCount = 0;

            for (int i = 0; i < n; i++)
            {
                if (mid >= bloomDay[i])
                {
                    count++;
                    if (k == count)
                    {
                        bouquetCount++;
                        count = 0;
                    }
                }
                else
                    count = 0;
            }
            if (bouquetCount >= m)
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {7, 7, 7, 7, 12, 7, 7};
    cout << sol.minDays(v, 2, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Imp observaion
//___________________________________________________________________________________________________________________________________________
/*

is it right that flower will take at least min_element number of days to bloom and we can only take that flower once it has bloomed. 
So flower is only valid once it has blommed. And in brute we start from the min_element and see how many flowers has blommed in that 
min_element number of days and we go this to the max_element number of days.
*/


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Binary search over range of days → approximately log(maxDay - minDay)
For each mid, we scan the array once → O(n)
Total: O(n · log(maxDay))

Space Complexity
Only variables used → O(1) extra space
Input array not modified
Total: O(1)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Problem Summary
You need to make m bouquets, each requiring k adjacent flowers.
A flower blooms on a specific day given in bloomDay[i].
Question: What is the minimum day on which it is possible to make m bouquets?

Key Insight
If you pick a day x:
All flowers with bloomDay[i] ≤ x are usable.
Now check: can we form m bouquets from these usable flowers, respecting adjacency?

Observations
If you can make m bouquets on day x,
then you can also make them on any day > x.
If you cannot make m bouquets on day x,
you will also not be able to make them on any day < x.

👉 This gives monotonic search space → perfect for Binary Search on Answer
Steps
Search between min(bloomDay) and max(bloomDay).
For each mid = possible day:
Count how many bouquets we can make.
If we can make ≥ m → try earlier day → high = mid
Else → try later day → low = mid + 1



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();

        // there are m bouquets and each bouquet has k flowers. To total number of flowers bouquet will have are m * n.
        //  And we have n flowers available in our basket. So if total flowers required are greater than total flowers available
        //  then return -1.
        // If total flowers needed (m * k) exceed flowers available → impossible.
        if (1LL * m * k > n)
            return -1;

        // Range of possible answers = min bloom day to max bloom day
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        // Binary search on the number of days
        while (low < high) {
            int mid = low + (high - low) / 2;  // mid = candidate number of days

            int count = 0;         // count adjacent bloomable flowers
            int bouquetCount = 0;  // number of bouquets formed

            // Check how many bouquets we can make by day 'mid'
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    count++;               // one more usable flower
                    if (count == k) {      // enough for one bouquet
                        bouquetCount++;
                        count = 0;         // reset adjacency counter
                    }
                } else {
                    count = 0;             // break adjacency
                }
            }

            // If we can make enough bouquets, try earlier days
            if (bouquetCount >= m)
                high = mid;
            else
                low = mid + 1;  // need more days
        }

        return low;  // low == high (minimum days)
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Binary Search on Answer (Parametric Search)
A very common pattern where:
You are not searching inside the array,
but searching a range of possib le results.
It also includes:

🤝 Greedy Check Function
To verify if a given number of days is enough.

*/
