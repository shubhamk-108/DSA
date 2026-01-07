/*
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.



Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91

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
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int res = 0;
        vector<bool> isTaken(n, false);

        int remainingTruckCapacity = truckSize;

        for (int i = 0; i < n; i++)
        {
            int boxWithMaxUnitsIdx = -1;
            for (int j = 0; j < n; j++)
            {
                if ((!isTaken[j] && boxWithMaxUnitsIdx == -1) ||  (!isTaken[j] && boxTypes[j][1] >= boxTypes[boxWithMaxUnitsIdx][1]))
                    boxWithMaxUnitsIdx = j;
            }
            if (boxTypes[boxWithMaxUnitsIdx][0] <= remainingTruckCapacity)
            {
                res += boxTypes[boxWithMaxUnitsIdx][0] * boxTypes[boxWithMaxUnitsIdx][1];
                remainingTruckCapacity -= boxTypes[boxWithMaxUnitsIdx][0];
                isTaken[boxWithMaxUnitsIdx] = true;
            }
            else
            {
                res += remainingTruckCapacity * boxTypes[boxWithMaxUnitsIdx][1];
                return res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << sol.maximumUnits(v, 10);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop runs up to N times
Inner loop scans all N box types each time
➡️ Total Time: O(N²)

📦 Space Complexity
isTaken array of size N
➡️ Space: O(N)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We want to maximize total units.
Greedy choice: always pick the box type with the maximum units per box that is not yet taken.
Since this is a brute-force approach:
Instead of sorting, we repeatedly scan all box types to find the best remaining one.
For the chosen box type:
If all its boxes fit in the remaining truck capacity, take them all.
Otherwise, take only what fits and stop.
Repeat until:
Truck is full, or
All box types are used.
This simulates the greedy strategy manually.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        int res = 0;
        vector<bool> isTaken(n, false);

        int remainingTruckCapacity = truckSize;

        for (int i = 0; i < n; i++)
        {
            int boxWithMaxUnitsIdx = -1;
            for (int j = 0; j < n; j++)
            {
                if ((!isTaken[j] && boxWithMaxUnitsIdx == -1) ||  (!isTaken[j] && boxTypes[j][1] >= boxTypes[boxWithMaxUnitsIdx][1]))
                    boxWithMaxUnitsIdx = j;
            }
            if (boxTypes[boxWithMaxUnitsIdx][0] <= remainingTruckCapacity)
            {
                res += boxTypes[boxWithMaxUnitsIdx][0] * boxTypes[boxWithMaxUnitsIdx][1];
                remainingTruckCapacity -= boxTypes[boxWithMaxUnitsIdx][0];
                isTaken[boxWithMaxUnitsIdx] = true;
            }
            else
            {
                res += remainingTruckCapacity * boxTypes[boxWithMaxUnitsIdx][1];
                return res;
            }
        }
        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy + Selection-Based Brute Force
More specifically:
Greedy strategy: always take the box type with maximum units per box
Manual selection instead of sorting
Equivalent to Selection Sort + Greedy
Conceptually similar to Fractional Knapsack


*/
