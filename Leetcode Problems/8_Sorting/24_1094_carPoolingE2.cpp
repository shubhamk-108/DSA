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

        vector<int> events(1001,0);

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
            currentPassenger += x;
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
Processing trips: O(n)
Sweeping fixed array (0–1000): O(1000)
✅ Total Time:
O(n)

Space Complexity

Fixed-size array of length 1001
✅ Space:
O(1)   (constant space)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

Since pickup and drop locations are bounded (0–1000), use a fixed-size array.
Treat each trip as two events:
Add passengers at the pickup location.
Remove passengers at the drop-off location.
Store only the net passenger change at each location.
Sweep from location 0 to 1000, maintaining a running passenger count.
If at any point the count exceeds capacity, return false.
Otherwise, all trips can be completed safely.


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

        // Difference array where:
        // index -> location
        // value -> net passenger change at that location
        vector<int> events(1001, 0);

        // Create pickup (+) and drop-off (-) events
        for (int i = 0; i < n; i++)
        {
            int passenger = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            // Passengers enter at 'from'
            events[from] += passenger;

            // Passengers leave at 'to'
            events[to] -= passenger;
        }

        int currentPassenger = 0;

        // Sweep through all locations in order
        for (int change : events)
        {
            currentPassenger += change;

            // If capacity is exceeded at any point
            if (currentPassenger > capacity)
                return false;
        }

        // All trips completed within capacity
        return true;
    }
};



*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

Pattern Used

🔥 Sweep Line / Prefix Sum / Difference Array
This pattern is used when:
Events start and end at specific points.
You need to track a running total over a timeline.
Related problems:
LC 253 – Meeting Rooms II
LC 2406 – Divide Intervals Into Groups
LC 1109 – Corporate Flight Bookings


*/

