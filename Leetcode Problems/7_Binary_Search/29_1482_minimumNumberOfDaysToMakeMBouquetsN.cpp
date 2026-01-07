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

        int minEle = *min_element(bloomDay.begin(), bloomDay.end());
        int maxEle = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minEle; day <= maxEle; day++)
        {
            int count = 0;
            int currBouquetCount = 0;
            for (int i = 0; i < n; i++)
            {
                if (bloomDay[i] <= day)
                    count++;
                else
                    count = 0;

                if (count == k)
                {
                    currBouquetCount++;
                    count = 0;
                }
            }
            if (currBouquetCount >= m)
                return day;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 10, 3, 10, 2};
    cout << sol.minDays(v, 3, 1);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity:

Outer loop: days from minEle → maxEle → O(maxEle - minEle)
Inner loop: iterate over n flowers → O(n)
Total:
O( n ⋅(maxEle−minEle))

Space Complexity:
Only a few variables (count, currBouquetCount, minEle, maxEle)
No extra arrays → O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Problem Summary:
You have n flowers, each blooms on a day given in bloomDay[i].
You need m bouquets, each requiring k adjacent flowers.
Question: Find the minimum day when it’s possible to make all m bouquets.
Brute-force Approach:
Start from the earliest possible day (min(bloomDay)) up to the latest bloom day (max(bloomDay)).
For each day:
Consider all flowers that have bloomed (bloomDay[i] <= day).
Count adjacent bloomed flowers to form bouquets.
Every time you reach k adjacent bloomed flowers, increment bouquet count and reset the adjacency counter.
If bouquet count ≥ m, return the current day.
If no day satisfies the requirement, return -1.
This is exactly what your code implements.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Impossible case: not enough flowers to form m bouquets
        if (1LL * m * k > n)
            return -1;

        // Determine search range for days
        int minEle = *min_element(bloomDay.begin(), bloomDay.end());
        int maxEle = *max_element(bloomDay.begin(), bloomDay.end());

        // Brute force: try each day from earliest bloom to latest
        for (int day = minEle; day <= maxEle; day++) {
            int count = 0;              // Count of adjacent bloomed flowers
            int currBouquetCount = 0;   // Number of bouquets formed

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= day)
                    count++;             // Flower has bloomed, add to adjacency count
                else
                    count = 0;          // Flower not bloomed, adjacency broken

                if (count == k) {       // Enough for one bouquet
                    currBouquetCount++;
                    count = 0;          // Reset adjacency for next bouquet
                }
            }

            // If we can make required bouquets, return current day
            if (currBouquetCount >= m)
                return day;
        }

        // If no day works, return -1
        return -1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-force / Simulation pattern:
Iterates over all possible days and simulates bouquet formation for each day.


*/
