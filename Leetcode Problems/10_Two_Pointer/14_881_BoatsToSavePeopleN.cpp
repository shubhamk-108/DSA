/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
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
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();

        vector<bool> visited(n, false);
        int boats = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;

            int bestPairIdx = -1;

            for (int j = 0; j < n; j++)
            {
                if (visited[j])
                    continue;
                if (i == j)
                    continue;
                if (people[i] + people[j] <= limit)
                {
                    if (bestPairIdx == -1 || people[j] > people[bestPairIdx])
                        bestPairIdx = j;
                }
            }
            if (bestPairIdx != -1)
                visited[bestPairIdx] = true;
            boats++;
        }
        return boats;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {3, 2, 2, 1};
    cout << sol.numRescueBoats(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop → n
Inner loop → n
Total → O(n²)
Space Complexity
visited[] array → O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
We try to assign people to boats one by one.
For each person i:
If already visited → skip.
Otherwise try to find a second unvisited person j such that:
people[i] + people[j] <= limit
among all valid j, choose the heaviest possible (maximize pairing)
If found → pair them, mark both visited.
If not found → i alone uses one boat.
Continue until all people are visited.
This is an O(n²) brute-force search.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();

        // Track who is already assigned to a boat
        vector<bool> visited(n, false);
        int boats = 0;

        for (int i = 0; i < n; i++)
        {
            // skip if already used
            if (visited[i]) 
                continue;

            // take person i alone first
            visited[i] = true;

            int bestPairIdx = -1;

            // try pairing with someone else
            for (int j = 0; j < n; j++)
            {
                if (visited[j]) continue;
                if (i == j) continue;

                // valid pair?
                if (people[i] + people[j] <= limit)
                {
                    // choose the heaviest partner that still fits
                    if (bestPairIdx == -1 || people[j] > people[bestPairIdx])
                        bestPairIdx = j;
                }
            }

            // If a partner was found, mark as visited
            if (bestPairIdx != -1)
                visited[bestPairIdx] = true;

            // One boat used
            boats++;
        }

        return boats;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



This is Brute Force + Greedy Pair Search.
*/
