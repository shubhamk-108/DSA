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
        sort(boxTypes.begin(), boxTypes.end(), [] (const vector<int> &a, const vector<int> &b) {return a[1] > b[1];});

        int truckCapacity = truckSize;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if(boxTypes[i][0] <= truckCapacity  )
            {
                res += boxTypes[i][0] *  boxTypes[i][1];
                truckCapacity -=  boxTypes[i][0];
            }  
            else
            {
                res += truckCapacity * boxTypes[i][1];
                return res;
            }
        }
        return res;
        

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{5, 10}, {2, 5}, {4, 7}, {3,9}};
    cout << sol.maximumUnits(v, 10);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Sorting box types: O(N log N)
One pass through box types: O(N)
➡️ Overall Time: O(N log N)

📦 Space Complexity
➡️ Auxiliary Space: O(1) (ignoring sort stack)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Idea:
Each box type has
boxTypes[i][0] → number of boxes
boxTypes[i][1] → units per box
Since we can take partial boxes, to maximize total units:
Always take boxes with maximum units per box first.
Sort all box types in descending order of units per box.
Iterate through the sorted box types:
If the truck can take all boxes of the current type, take them.
Otherwise, take only as many boxes as fit and stop (truck becomes full).
Accumulate total units during the process.
This greedy choice always leads to the optimal result

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
        // Number of different box types
        int n = boxTypes.size();

        // Sort box types by units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] > b[1];
             });

        // Remaining capacity of the truck
        int truckCapacity = truckSize;

        // Stores the maximum total units loaded
        int res = 0;

        // Iterate over each box type
        for (int i = 0; i < n; i++)
        {
            // If all boxes of this type fit in the truck
            if (boxTypes[i][0] <= truckCapacity)
            {
                res += boxTypes[i][0] * boxTypes[i][1];
                truckCapacity -= boxTypes[i][0];
            }
            else
            {
                // Take only the boxes that fit and stop
                res += truckCapacity * boxTypes[i][1];
                return res;
            }
        }

        // Truck not full but no more boxes left
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Greedy Algorithm (Value-Based Sorting)
More specifically:
Greedy Choice Property:
Always take the box type with the highest units per box first.
Sorting + Greedy Selectio
Similar to Fractional Knapsack pattern.

*/
