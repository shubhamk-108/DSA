/*

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

        int lowestDiff = 1;
        int maxDiff = position[n - 1] - position[0];

        // Try all possible distances from largest to smallest
        for (int diff = maxDiff; diff >= lowestDiff; diff--)
        {
            int lastBallPlacedAt = 0; // index of last placed ball
            int totalBallsPlaced = 1; // first ball always placed at index 0

            // Try to place remaining balls
            for (int i = 1; i < n; i++)
            {
                if (position[i] - position[lastBallPlacedAt] >= diff)
                {
                    totalBallsPlaced++;
                    lastBallPlacedAt = i;
                }
            }

            // If we successfully placed all m balls with at least diff distance
            if (totalBallsPlaced >= m)
                return diff;
        }

        return -1; // Should never reach here
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

n = number of positions
D = position[n-1] - position[0] (maximum possible distance)
Your brute-force loop runs:

for diff = D → 1   → D iterations
    check feasibility → O(n)

🔸 Total Time = O(D × n)
space :O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort the positions.
Maximum possible minimum distance = position[n-1] - position[0]
For each distance d from max → 1:
Try to greedily place balls:
First ball at index 0
Place next ball whenever distance difference ≥ d
If we can place m balls, return d.


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

        sort(position.begin(), position.end());

        int lowestDiff = 1;
        int maxDiff = position[n - 1] - position[0];

        // Try all possible distances from largest to smallest
        for (int diff = maxDiff; diff >= lowestDiff; diff--)
        {
            int lastBallPlacedAt = 0;  // index of last placed ball
            int totalBallsPlaced = 1;  // first ball always placed at index 0

            // Try to place remaining balls
            for (int i = 1; i < n; i++)
            {
                if (position[i] - position[lastBallPlacedAt] >= diff)
                {
                    totalBallsPlaced++;
                    lastBallPlacedAt = i;
                }
            }

            // If we successfully placed all m balls with at least diff distance
            if (totalBallsPlaced >= m)
                return diff;
        }

        return -1; // Should never reach here
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

binary search brute     


*/
