/*
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.



Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.

Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
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
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        // sort by position (start -> target)
        sort(cars.begin(), cars.end());

        vector<bool> used(n, false);
        int fleets = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (used[i])
                continue;

            fleets++;
            double ti = (double)(target - cars[i].first) / cars[i].second;

            // check all cars behind i
            for (int j = i - 1; j >= 0; j--)
            {
                if (used[j])
                    continue;

                double tj = (double)(target - cars[j].first) / cars[j].second;

                // if car j can catch car i (or its fleet)
                if (tj <= ti)
                {
                    used[j] = true; // merge into same fleet
                }
            }
        }

        return fleets;
    }
};

int main()
{
    Solution sol;
    vector<int> p = {10, 8, 0, 5, 3};
    vector<int> s = {2, 4, 1, 1, 3};
    cout << sol.carFleet(12, p, s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n²)

Why?
Outer loop runs up to n times
Inner loop, in the worst case, runs up to n times for each outer loop
Even though used[] skips merging, the comparisons still happen
Worst case example:
No car can catch any other
→ every (i, j) pair is checked
So
(n-1) + (n-2) + ... + 1 = O(n²)

💾 Space Complexity: O(n)
cars vector → O(n)
used array → O(n)
Total: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
First, sort cars by position so the road order is clear.
Start from the front-most car (closest to target).
That car must form a fleet, because nobody is ahead of it.
Now check all cars behind it:
If a car behind can reach the target earlier or at the same time, it will eventually catch this car (or fleet).
If it catches, mark it as part of the same fleet.
Move to the next unprocessed car in front order and repeat.
Count how many times you had to start a new fleet.
This approach directly follows the definition of a car fleet, but it checks many unnecessary comparisons.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        // Pair each car's position with its speed
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        // Sort cars by position (start -> target)
        sort(cars.begin(), cars.end());

        // used[i] = true means car i is already part of some fleet
        vector<bool> used(n, false);

        int fleets = 0;

        // Process cars from front to back (right -> left on the road)
        for (int i = n - 1; i >= 0; i--) {

            // If this car is already merged into a fleet, skip it
            if (used[i]) continue;

            // This car starts a new fleet
            fleets++;

            // Time for this fleet leader to reach the target
            double ti = (double)(target - cars[i].first) / cars[i].second;

            // Check all cars behind it
            for (int j = i - 1; j >= 0; j--) {
                if (used[j]) continue;

                // Time for car j to reach the target
                double tj = (double)(target - cars[j].first) / cars[j].second;

                // If car j can catch this fleet before the target
                if (tj <= ti) {
                    used[j] = true; // merge into this fleet
                }
            }
        }

        return fleets;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern Name: 
Brute Force Simulation
More specifically:
Pairwise comparison
Direct simulation of problem statement

*/
