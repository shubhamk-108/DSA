/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
#include<numeric>

using namespace std;


class Solution
{
public:
    bool canShip(vector<int> &weights, int days, int cap)
    {
        int d = 1, current = 0;
        for (int w : weights)
        {
            if (current + w > cap)
            {
                d++;
                current = 0;
            }
            current += w;
        }
        return d <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);

        for (int cap = minCap; cap <= maxCap; cap++)
        {
            if (canShip(weights, days, cap))
            {
                return cap;
            }
        }
        return -1; // should never reach
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sol.shipWithinDays(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(N * (sum(weights) - max(weights)))
Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Minimum possible capacity
The ship must at least carry the heaviest package.
→ minCap = max(weights)
Maximum possible capacity
In the worst case, the ship carries all weights in one day.
→ maxCap = sum(weights)
Try every capacity from minCap to maxCap
For each capacity cap, simulate shipping day by day using a helper function canShip().
Add weights until you exceed cap; when exceeded, start a new day.
If the number of days used ≤ days, then this capacity works.
The first valid capacity is the brute-force answer.
This works because capacities are checked in increasing order, so the first valid one is the minimum valid capacity.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Helper function to check whether a given capacity 'cap'
    // allows shipping all packages within 'days' days.
    bool canShip(vector<int> &weights, int days, int cap)
    {
        int d = 1;         // start with day 1
        int current = 0;   // current load on the ship for the day

        for (int w : weights)
        {
            // If adding this package exceeds capacity,
            // we need an extra day
            if (current + w > cap)
            {
                d++;          // use a new day
                current = 0;  // reset ship load for new day
            }
            current += w;     // load the current package
        }

        // If total days used is <= allowed days, capacity is valid
        return d <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        // Minimum capacity = max single weight
        int minCap = *max_element(weights.begin(), weights.end());

        // Maximum capacity = total weight
        int maxCap = accumulate(weights.begin(), weights.end(), 0);

        // Brute force: try every possible capacity in range
        for (int cap = minCap; cap <= maxCap; cap++)
        {
            // If the current capacity works, return it
            if (canShip(weights, days, cap))
            {
                return cap;
            }
        }

        return -1;  // (Should never happen)
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force + Simulation Pattern

*/
