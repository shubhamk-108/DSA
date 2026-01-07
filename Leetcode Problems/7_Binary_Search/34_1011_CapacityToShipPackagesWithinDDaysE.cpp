/*
A conveyor belt has packages that must be shipped from one port to another within currDays currDays.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within currDays currDays.

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], currDays = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 currDays like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], currDays = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 currDays like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

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
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());

        int sum = 0;
        for (auto x : weights)
            sum += x;

        int high = sum;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int currWeightSum = 0;
            int currDays = 1;

            for (int i = 0; i < n; i++)
            {
                if (currWeightSum + weights[i] > mid)
                {
                    currDays++;
                    currWeightSum = 0;
                }
                currWeightSum += weights[i];
            }

            if (currDays <= days)
                high = mid;
            else if (currDays > days)
                low = mid + 1;
        }
        return high;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 2, 2, 4, 1, 4};
    cout << sol.shipWithinDays(v, 3);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// IMP observation. Relationship is inverse
//___________________________________________________________________________________________________________________________________________
/*

Relationship is inverse:

CAPACITY ↑ → DAYS ↓
CAPACITY ↓ → DAYS ↑

✔ mid represents the ship capacity.
✔ We want the minimum capacity such that:
currDays <= days

Case 1: currDays > days
We are using too many days.
Why? Capacity is too small.
Fix: Increase capacity → low = mid + 1.

Case 2: currDays <= days
This capacity works.
But maybe a smaller capacity also works.
Try smaller capacity → high = mid.

Stop when:
low == high → minimum valid capacity

*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity:
O(N * log(sum(weights) - max(weights)))
Why?
Binary search range reduces log(sum)
For each mid, we simulate once → O(N)

Space Complexity:
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We want to ship all packages within days.
Each day we load packages in order, without reordering.

The ship has some capacity.
We need to find the minimum capacity such that we can finish shipping in ≤ days.

Key Observations

Minimum possible capacity = max element in weights
(because you must at least fit the heaviest package)

Maximum possible capacity = sum of all weights
(capacity enough to take all in 1 day)

Between these two, we can binary search for the smallest capacity.

How do we check if a capacity works?

Simulate:

Start with currDays = 1

Add package weights one by one

When exceeding capacity → start new day, increase currDays

If currDays <= days, then the capacity is valid.
Otherwise, it is too small.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();

        // Minimum possible capacity = heaviest package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity = sum of all packages
        int sum = 0;
        for (auto x : weights)
            sum += x;
        int high = sum;

        // Binary search between low and high capacity
        while (low < high)
        {
            int mid = low + (high - low) / 2; // Candidate capacity

            int currWeightSum = 0; // Load for current day
            int currDays = 1;      // Start with day 1

            // Simulate shipping packages with current capacity mid
            for (int i = 0; i < n; i++)
            {
                // If adding next package exceeds capacity,
                // we need an extra day
                if (currWeightSum + weights[i] > mid)
                {
                    currDays++;
                    currWeightSum = 0;
                }
                currWeightSum += weights[i];
            }

            // If we can ship within allowed days,
            // try smaller capacity

            if (currDays <= days)
           
                high = mid;
            
            else // else if (currDays > days)
            
                low = mid + 1;
        }

        // low == high is the minimum valid capacity
        return high;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer
Also known as:
“Search on monotonic function”


*/
