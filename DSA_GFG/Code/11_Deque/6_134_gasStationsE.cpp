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
#include<numeric>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int totalFuel = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if(totalFuel < totalCost)
            return -1;

        int ans = 0;
        int fuel = 0;

        for (int i = 0; i < n; i++)
        {
            fuel+=gas[i];
            fuel -= cost[i];
            
            if(fuel < 0)
            {
                ans = i+1;
                fuel = 0;
            }
        }
        return ans;
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
Time Complexity
O(n)
Two linear passes (accumulate + loop)

💾 Space Complexity
O(1)
Only constant extra variables
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Feasibility check
Calculate total gas and total cost.
If total gas < total cost, completing the circuit is impossible → return -1.
Greedy traversal
Traverse all stations once.
Maintain:
fuel: fuel available from the current candidate starting station.
ans: current candidate starting index.
At each station
Add gas and subtract cost.
If fuel becomes negative, current start cannot work.
Set the next station (i + 1) as the new candidate start.
Reset fuel to 0.
Return result
Since total gas ≥ total cost, the final candidate start is guaranteed to work.


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

        // Step 1: Check if the journey is possible at all
        int totalFuel = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalFuel < totalCost)
            return -1;

        int ans = 0;   // candidate starting station
        int fuel = 0;  // fuel from current candidate start

        // Step 2: Greedy single pass
        for (int i = 0; i < n; i++)
        {
            fuel += gas[i];     // gain gas at station i
            fuel -= cost[i];    // spend gas to reach next station

            // If fuel is negative, we cannot continue from 'ans'
            if (fuel < 0)
            {
                ans = i + 1; // next station becomes new candidate
                fuel = 0;    // reset fuel
            }
        }

        // Step 3: Return the valid starting station
        return ans;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy Algorithm
More specifically:
Greedy reset strategy
Prefix sum / net gain reasoning


*/
