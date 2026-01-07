/*
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
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
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        vector<vector<int>> sorted;
        vector<bool> isUsed(n, false);

        for (int i = 0; i < n; i++)
        {
            long long difference = LLONG_MAX;
            int idx = -1;
            for (int j = 0; j < n; j++)
            {
                if (!isUsed[j] && costs[j][0] - costs[j][1] < difference)
                {
                    difference = costs[j][0] - costs[j][1];
                    idx = j;
                }
            }
            sorted.push_back(costs[idx]);
            isUsed[idx] = true;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if(i<n/2)
                res+=sorted[i][0];
            else
                res+=sorted[i][1];
        }

        return res;
        

    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    cout << sol.twoCitySchedCost(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Manual selection sort: O(N²)
Cost summation: O(N)
✅ Overall: O(N²)
Space Complexity
sorted array → O(N)
isUsed array → O(N)
✅ Overall: O(N) extra space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Goal:
Send exactly N people to City A and N people to City B with minimum total cost
(where total people = 2N).
Key observation (greedy idea):
For each person, only the difference matters:
difference = costA − costB
Smaller difference → stronger preference for City A
Larger difference → stronger preference for City B

Steps in your approach:
Manually sort all people by (costA − costB) in increasing order
(using a selection-sort–style brute approach).
Send:
First N people → City A
Remaining N people → City B
Add up the corresponding costs.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        // Total people = 2N
        int n = costs.size();

        // Will store people sorted by (costA - costB)
        vector<vector<int>> sorted;

        // Marks whether a person is already selected in sorting
        vector<bool> isUsed(n, false);

        // Manual selection sort based on (costA - costB)
        for (int i = 0; i < n; i++)
        {
            long long difference = LLONG_MAX;
            int idx = -1;

            // Find unused person with minimum (costA - costB)
            for (int j = 0; j < n; j++)
            {
                if (!isUsed[j] && costs[j][0] - costs[j][1] < difference)
                {
                    difference = costs[j][0] - costs[j][1];
                    idx = j;
                }
            }

            // Place that person next in sorted order
            sorted.push_back(costs[idx]);
            isUsed[idx] = true;
        }

        int res = 0;

        // First n/2 people → City A
        // Remaining n/2 people → City B
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
                res += sorted[i][0]; // cost to City A
            else
                res += sorted[i][1]; // cost to City B
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Main Pattern
✅ Greedy
Supporting Technique
✅ Selection Sort (brute sorting)

*/
