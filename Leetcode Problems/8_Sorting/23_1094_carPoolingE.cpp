/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.



Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true


You are driving a car that can carry at most capacity passengers.

You are given a list of trips.
Each trip is described as:

[numPassengers, from, to]

Meaning:
numPassengers get in at loation from

They get out at location to
from < to
📌 The car only moves in one direction (increasing location).

🎯 Goal

Return true if you can complete all trips without the number of passengers in the car ever exceeding capacity.
Otherwise, return false.

📦 Example
Input
trips = [[2,1,5],[3,3,7]]
capacity = 4

Visual timeline
Location:   1   2   3   4   5   6   7
Passengers:
            +2      +3
                    -2      -3

What happens?
At location 1: +2 passengers (car = 2)
At location 3: +3 passengers (car = 5 ❌)
Capacity = 4 → exceeded → return false

Another Example (Valid)
trips = [[2,1,5],[3,5,7]]
capacity = 4

Timeline:
At 1: +2
At 5: -2 and +3 (net +1)
Max passengers = 3 → OK
✅ Return true
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();

        map<int, int> events;

        for (int i = 0; i < n; i++)
        {
            int from = trips[i][1];
            int to = trips[i][2];
            int passenger = trips[i][0];

            events[from] += passenger;
            events[to] -= passenger;
        }

        int currentPassenger = 0;
        for (auto x : events)
        {
            currentPassenger += x.second;
            if (currentPassenger > capacity)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{2, 1, 5}, {3, 3, 7}};
    cout << sol.carPooling(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Building events: O(n)
Iterating over map: O(n)
Map insertion cost: O(log n) per event
✅ Total Time:
O(n log n)

Space Complexity
Map stores up to 2n events
✅ Space:
O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Treat each trip as two events
Passengers enter the car at from
Passengers leave the car at to
Store these passenger changes in a map:
+passengers at from
-passengers at to
Since map is ordered by key, iterate through locations in increasing order.
Maintain a running count of current passengers:
Add the passenger change at each location
If at any point passengers exceed capacity, return false
If the entire journey completes without exceeding capacity, return true


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();

        // Map to store passenger change at each location
        // key   -> location
        // value -> net change in passengers at that location
        map<int, int> events;

        // Create events for each trip
        for (int i = 0; i < n; i++)
        {
            int from = trips[i][1];
            int to = trips[i][2];
            int passenger = trips[i][0];

            // Passengers get in at 'from'
            events[from] += passenger;

            // Passengers get out at 'to'
            events[to] -= passenger;
        }

        int currentPassenger = 0;

        // Sweep through locations in increasing order
        for (auto x : events)
        {
            currentPassenger += x.second;

            // If capacity exceeded at any point
            if (currentPassenger > capacity)
                return false;
        }

        // All trips completed safely
        return true;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Sweep Line / Line Sweep
Also known as:
Prefix Sum
Event-based processing
Difference Array
This same pattern appears in:
LC 253 – Meeting Rooms II
LC 2406 – Divide Intervals Into Groups
LC 218 – Skyline Problem

*/
