/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.



Example 1:

Diagram:

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

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
    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();

        sort(position.begin(), position.end());

        int low = 1;
        int high = position[n - 1] - position[0];

        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int lastBallPlacedAt = 0;
            int j = 1;
            int totalBallsPlacedCount = 1;

            while (j < n)
            {
                if (position[j] - position[lastBallPlacedAt] >= mid)
                {
                    totalBallsPlacedCount++;
                    lastBallPlacedAt = j;
                }
                j++;
            }

            if (totalBallsPlacedCount >= m)
            {
                res = mid;
                low = mid + 1;
            }
            else if (totalBallsPlacedCount < m)
                high = mid - 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 7}; // array can be unsorted.
    cout << sol.maxDistance(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Aspect    | Complexity                                                                                            |
| --------- | ----------------------------------------------------------------------------------------------------- |
| **Time**  | O(n log(d)) → n for greedy check, log(d) for binary search, where `d = max(position) - min(position)` |
| **Space** | O(1) → only variables used; sorting is in-place                                                       |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Sort the ball positions
You need positions in increasing order so that greedy placement works.
Binary search on answer (minimum distance / magnetic force)
low = 1 (minimum possible distance)
high = position[n-1] - position[0] (maximum possible distance)
Feasibility check for a candidate distance mid
Place the first ball at position[0].
For each next position, place the ball only if it is ≥ mid away from the last placed ball.
Count how many balls you can place.
Binary search logic:
If you can place at least m balls, the distance is feasible → try larger distances (low = mid + 1).
Otherwise, distance is too large → try smaller distances (high = mid - 1).
Return the largest feasible distance, stored in res.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();

        // Step 1: Sort the ball positions
        sort(position.begin(), position.end());

        // Step 2: Binary search boundaries
        int low = 1;                      // Minimum possible distance
        int high = position[n - 1] - position[0];  // Maximum possible distance
        int res = -1;                      // To store the answer

        while (low <= high)
        {
            int mid = low + (high - low) / 2;  // Candidate minimum distance

            int lastBallPlacedAt = 0;          // Index of last placed ball
            int totalBallsPlacedCount = 1;     // First ball is placed at position[0]
            int j = 1;                         

            // Step 3: Greedy placement of balls
            while (j < n)
            {
                if (position[j] - position[lastBallPlacedAt] >= mid)
                {
                    totalBallsPlacedCount++;   // Place the ball
                    lastBallPlacedAt = j;      // Update last placed ball index
                }
                j++;
            }

            // Step 4: Binary search update
            if (totalBallsPlacedCount >= m)
            {
                res = mid;      // Distance feasible, store answer
                low = mid + 1;  // Try larger distance
            }
            else
            {
                high = mid - 1; // Distance too large, try smaller
            }
        }

        return res; // Largest feasible distance
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Binary Search on Answer (Parametric Search)
You don’t binary search the array itself, you binary search the answer space (minimum distance).
Feasibility function (greedy placement) is monotonic:

*/
