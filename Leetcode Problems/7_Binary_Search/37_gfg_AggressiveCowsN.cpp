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

        int lowestDiff = 1;
        int maxDiff = stalls[n - 1] - stalls[0];
        int res = -1;

        for (int diff = maxDiff; diff >= lowestDiff; diff--)
        {
            int lastCowPlacedAt = 0;
            int totalCowsPlaced = 1;

            for (int i = 1; i < n; i++)
            {
                if (stalls[i] - stalls[lastCowPlacedAt] >= diff)
                {
                    totalCowsPlaced++;
                    lastCowPlacedAt = i;
                }
            }
            if (totalCowsPlaced >= k)
                return diff;
        }
        return -1;
    }
};
int main()
{
    //  for (int diff = lowestDiff; diff <= maxDiff; diff++)
    Solution sol;
    vector<int> v = {10, 1, 2, 7, 5};
    cout << sol.aggressiveCows(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Outer loop: maxDiff = stalls[n-1] - stalls[0] → can be large
Inner loop: O(n)
Total: O(n × maxDiff) → very slow for large inputs

✅ Space Complexity
O(1) (ignoring sorting)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort the stalls in increasing order.
This makes it easy to check distances between cows.
Try all possible minimum distances from largest to smallest:
max possible distance = stalls[n-1] - stalls[0]
min possible distance = 1
Check feasibility for a given distance diff:
Place the first cow at stalls[0].
Try placing the next cow only if the distance to the last placed cow ≥ diff.
Count how many cows you can place.
If you can place k cows, diff is possible.
Return the largest diff for which placement is possible.
This is your brute-force idea: try all candidate distances, check greedily if placement is possible.


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

        sort(stalls.begin(), stalls.end());

        int lowestDiff = 1;
        int maxDiff = stalls[n - 1] - stalls[0];

        // Try every possible distance from max to min
        for (int diff = maxDiff; diff >= lowestDiff; diff--)
        {
            int lastCowPlacedAt = 0;   // index of last cow placed
            int totalCowsPlaced = 1;   // first cow placed at stalls[0]

            for (int i = 1; i < n; i++)
            {
                if (stalls[i] - stalls[lastCowPlacedAt] >= diff)  // FIXED
                {
                    totalCowsPlaced++;
                    lastCowPlacedAt = i;
                }
            }

            if (totalCowsPlaced >= k)
                return diff;   // largest feasible distance
        }

        return -1;   // not possible (theoretically shouldn't happen)
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


bruteforce for binary search

*/
