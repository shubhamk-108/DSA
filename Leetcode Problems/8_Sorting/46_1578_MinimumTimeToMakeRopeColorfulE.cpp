/*
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.


Example 1:

Diagram:

Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.


Example 2:

Diagram:

Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.

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
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();

        vector<pair<char, int>> freq;

        int i = 0;
        int res = 0;

        while (i < n)
        {

            int groupSum = neededTime[i];
            int groupMax = neededTime[i];
            int j = i;

            while (j + 1 < n && colors[j] == colors[j + 1])
            {
                j++;

                groupSum += neededTime[j];
                groupMax = max(groupMax, neededTime[j]);
            }

            res += groupSum - groupMax;

            i = j+1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {7, 2, 9, 4, 1, 10, 6, 3, 8, 5, 2, 9, 1};
    // vector<int> v = {1, 2, 3, 4, 5};
    // string colors = "abaac";
    string colors = "taabbbbbdddde";
    cout << sol.minCost(colors, v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity ⏱️
Each character is processed once
Both pointers only move forward
✅ Time:
O(n)

4️⃣ Space Complexity 💾
✅ Space:
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The problem says:
For each group of consecutive balloons with the same color, remove balloons until only one remains, minimizing total removal time.

Key insight:
For a group of the same color:
You must remove group_size − 1 balloons
To minimize cost, keep the balloon with the maximum neededTime
Cost for the group =
(sum of neededTime in the group) − (maximum neededTime in the group)

Steps:
Traverse the string using two pointers to identify groups of consecutive same colors.
For each group:
Compute the sum of neededTime
Track the maximum neededTime
Add (sum − max) to the answer.
Move to the next group.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();

        int i = 0;      // pointer to traverse the string
        int res = 0;    // total minimum removal cost

        // Traverse the string group by group
        while (i < n)
        {
            // Initialize sum and max for the current group
            int groupSum = neededTime[i];
            int groupMax = neededTime[i];
            int j = i;

            // Expand the group while consecutive colors are same
            while (j + 1 < n && colors[j] == colors[j + 1])
            {
                j++;
                groupSum += neededTime[j];          // accumulate cost
                groupMax = max(groupMax, neededTime[j]); // track max
            }

            // Remove all balloons except the one with max time
            res += groupSum - groupMax;

            // Move to the next group
            i = j + 1;
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy + Two Pointers
Greedy: Keep the balloon with maximum neededTime in each group
Two pointers: Process consecutive groups efficiently in one pass
This pattern is common in:
String grouping problems
Interval / block processing
Problems where local optimal choice leads to global optimal result


*/
