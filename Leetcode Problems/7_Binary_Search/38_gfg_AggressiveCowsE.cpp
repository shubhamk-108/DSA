/*
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows in this case is 3, which is the largest among all possible ways.


You are given:

An array stalls[] → each element is a unique position of a stall on a straight line.

An integer k → number of cows.

You must place k cows in these stalls so that:

👉 The minimum pairwise distance between any two cows is as large as possible.
🔵 What does “maximum of minimum distance” mean?

If you place cows in some stalls, there will be distances between every pair of adjacent cows.

Example: cows placed at positions
[1, 4, 8] → distances = [4-1 = 3, 8-4 = 4]

Minimum distance = 3
(We care about the smallest distance between any two cows.)

Your goal is to place cows so that this minimum distance is as large as possible.

🔵 Example Explanation
Input:
stalls = [1, 2, 4, 8, 9]
k = 3

Step 1: Sort stalls

(Already sorted)

Step 2: Try placing cows to maximize min distance

Let’s test possible minimum distances:

🟢 Try minimum distance = 1

Possible? Yes.
You can place cows anywhere.

🟢 Try minimum distance = 2

Place first cow → at position 1
Place second cow → at position 4 (4 - 1 = 3 ≥ 2)
Place third cow → at position 8 (8 - 4 = 4 ≥ 2)
✔ Successfully placed all 3 cows.

So 2 is possible.

🟢 Try minimum distance = 3

Place first cow → at 1
Place second cow → at 4 (4 - 1 = 3 ≥ 3)
Place third cow → at 8 (8 - 4 = 4 ≥ 3)
✔ Possible.

🔴 Try minimum distance = 4

Place first cow → 1
Place second → 4 (4 - 1 = 3 < 4 ❌ → can't place here)
Try next stall → 8 (8 - 1 = 7 ≥ 4 ✔)
Place third → 9 (9 - 8 = 1 < 4 ❌ cannot place)

Only 2 cows can be placed.

So 4 is NOT possible.

🔵 So the largest minimum distance that works = 3

This is the answer.


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
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();

        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int lastCowPlacedAt = 0;
            int j = 1;
            int cowsPlacedCount = 1;

            while (j < n)
            {
                if (stalls[j] - stalls[lastCowPlacedAt] >= mid)
                {
                    cowsPlacedCount++;
                    lastCowPlacedAt = j;
                }
                j++;
            }

            if (cowsPlacedCount >= k)
            {
                res = mid;
                low = mid + 1;
            }
            else if (cowsPlacedCount < k)
                high = mid - 1;
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {1, 2, 4, 8, 9};
    // vector<int> v = {10, 1, 2, 7, 5};
    cout << sol.aggressiveCows(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n log n)
Breakdown:
Sorting stalls: O(n log n)
Binary search range ≈ log(stalls[n-1] - stalls[0])
Each check is O(n)
Total: O(n log n)

Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Sort the stall positions
The cows must be placed in increasing position order.

Binary search on the answer (minimum distance)

low = 1

high = max possible distance = stalls[n-1] - stalls[0]

For each mid (distance candidate), check feasibility:

Place the first cow at stalls[0]

Try placing the next cow only in a stall where
stalls[j] - stalls[lastCowPlacedAt] >= mid

Count how many cows you can place.

If cowsPlaced ≥ k, the distance mid is feasible →
try for a bigger minimum distance → low = mid + 1.

Otherwise, reduce distance → high = mid - 1.

The largest feasible distance is stored in res.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();

        // Step 1: Sort stall positions
        sort(stalls.begin(), stalls.end());

        // Binary search on the answer (min possible distance)
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int res = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;  // Candidate distance

            int lastCowPlacedAt = 0;           // First cow at index 0
            int j = 1;                         // Try placing from next stall
            int cowsPlacedCount = 1;           // Already placed first cow

            // Try placing cows greedily
            while (j < n)
            {
                if (stalls[j] - stalls[lastCowPlacedAt] >= mid)
                {
                    cowsPlacedCount++;         // Place cow
                    lastCowPlacedAt = j;       // Update last placed position
                }
                j++;
            }

            // If we can place k cows, mid is a feasible distance. So try increasing distance
            if (cowsPlacedCount >= k)
            {
                res = mid;        // Store best answer so far
                low = mid + 1;    // Try for a larger distance
            }
            else
            {
                // the distance was too much that we coudnt place all the cows at distance so decrease the distance
                high = mid - 1;   // Try a smaller distance
            }
        }
        return res;   // Largest feasible distance
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: 🟦 Binary Search on Answer (Parametric Search)
Also known as:
Search on monotonic function
Feasibility binary search
Binary search + greedy check
This is a classic example of:
We are not binary searching an array, but searching the answer space or range.


*/
