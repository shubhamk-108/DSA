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

        
        vector<int>roadMaking(1001,0);

        for (int i = 0; i < n; i++)
        {
            int passenger = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            for (int trip = from ; trip < to; trip++)
            {
                roadMaking[trip] += passenger;
                if(roadMaking[trip] > capacity)
                    return false;
            }     
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
Complexity
Time: O(n * L)
n = number of trips
L = average length of trip (to - from)
In worst case, L can be 1000 → O(n * 1000).
Space: O(1001) = O(1)
Fixed-size array to track passengers at each location.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Create an array roadMaking of size 1001 to simulate all locations (since 0 <= location <= 1000).
For each trip [passengers, from, to]:
Loop over each location from from to to-1 (passengers are in the car during this interval).
Add passengers to roadMaking[t].
If roadMaking[t] > capacity, return false immediately.
If no location exceeds capacity after processing all trips, return true.
This effectively simulates the entire timeline of passenger counts.

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

        // Create a vector to track number of passengers at each location
        vector<int> roadMaking(1001,0);

        // Process each trip
        for (int i = 0; i < n; i++)
        {
            int passenger = trips[i][0]; // number of passengers in the trip
            int from = trips[i][1];      // pickup location
            int to = trips[i][2];        // drop-off location

            // Update passenger count for all locations in the trip
            for (int trip = from ; trip < to; trip++)
            {
                roadMaking[trip] += passenger; // add passengers
                if(roadMaking[trip] > capacity) // check capacity immediately
                    return false;
            }     
        }

        return true; // all locations checked, capacity not exceeded
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Complexity

Time: O(n²) — nested loops over n trips.
Space: O(1) — only a few integer variables, no extra data structures.

*/


