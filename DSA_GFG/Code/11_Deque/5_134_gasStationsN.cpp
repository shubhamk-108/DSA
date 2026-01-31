/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.



Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int fuel = 0;

        int i = 0;
        while (i < n)
        {
            fuel = 0;
            int j = i;
            while (j < n + i)
            {
                fuel += gas[j % n];
                if (fuel >= cost[j % n])
                    fuel -= cost[j % n];
                else
                    break;

                j++;
            }
            if (j  == n + i)
                return i;

            i++;
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
3️⃣ Time & Space Complexity
⏱️ Time Complexity
Outer loop runs n times
Inner loop can run up to n times
Worst case: O(n²)

💾 Space Complexity
Only variables used
O(1) extra space

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We try every gas station as a starting point.
For each station i
Start with fuel = 0
Move to the next n stations in a circular manner
At each station:
Add the gas available
Check if we have enough fuel to go to the next station
If not, this start point fails → stop early
If we successfully travel n stations, then station i is a valid answer
If no station allows a full circular tour, return -1.
This guarantees correctness because we explicitly simulate the journey from every possible start.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int fuel = 0;

        // Try each station as a starting point
        int i = 0;
        while (i < n)
        {
            fuel = 0;          // Reset fuel for new start
            int j = i;         // Current station index

            // Try to travel n stations starting from i
            while (j < n + i)
            {
                // Gain gas at current station
                fuel += gas[j % n];

                // Check if we can go to the next station
                if (fuel >= cost[j % n])
                    fuel -= cost[j % n];   // Spend fuel
                else
                    break;                 // Cannot continue from this start

                j++;
            }

            // If we completed a full circle
            if (j == n + i)
                return i;

            i++; // Try next starting station
        }

        // No valid starting station found
        return -1;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Simulation / Brute Force
More specifically:
Circular Array Simulation


*/
