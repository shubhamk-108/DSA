/*
You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.



Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3

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


class RecentCounter
{
    int i = 0;
    vector<int> arr;

public:
    RecentCounter() {}

    int ping(int t)
    {
        arr.push_back(t);

        int start = t - 3000;
        while (i < arr.size() && arr[i] < start)
            i++;

        return arr.size() - i;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Per ping() call:
Amortized O(1)
Overall:
Each timestamp is added once and removed (skipped) once → O(n) total
✔ This is optimal.

💾 Space Complexity
O(n) — storing all timestamps
(You can technically delete old ones, but it doesn’t improve asymptotic space.)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Key observations from the problem:
ping(t) is always called with strictly increasing t
We need to count how many timestamps fall in the range
[t − 3000, t]
Strategy:
Store every incoming t in a list (arr)
Maintain a pointer i that always points to the first valid timestamp
When a new t arrives:
Add it to the list
Move i forward until arr[i] >= t - 3000
The number of valid pings is:
total pings so far − invalid (old) pings
This works efficiently because:
t is increasing
i only moves forward (never backward)

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class RecentCounter {
    int i = 0;              // Pointer to the first valid ping
    vector<int> arr;        // Stores timestamps of all pings

public:
    RecentCounter() {}

    int ping(int t) {
        // Add the current ping timestamp
        arr.push_back(t);

        // Calculate the lower bound of the valid time window
        int start = t - 3000;

        // Move pointer i until arr[i] is within the valid range
        while (i < arr.size() && arr[i] < start)
            i++;

        // Number of valid pings in the last 3000 ms
        return arr.size() - i;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

sliding window


*/
