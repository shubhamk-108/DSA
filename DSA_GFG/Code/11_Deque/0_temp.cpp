/*

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
        int total = 0;   // overall gas - cost
        int tank = 0;    // fuel from current start
        int start = 0;   // candidate start station

        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];

            total += diff;
            tank += diff;

            // If we can't reach next station
            if (tank < 0)
            {
                start = i + 1; // next station becomes new start
                tank = 0;      // reset fuel
            }
        }

        // If total gas is enough, start is valid
        return total >= 0 ? start : -1;
    }
};
