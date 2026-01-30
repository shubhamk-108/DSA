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
    vector<int> arr;

public:
    RecentCounter() {}

    int ping(int t)
    {
        arr.push_back(t);

        int count = 0;
        int start = t - 3000;

        // Check all previous pings
        for (int time : arr)
        {
            if (time >= start && time <= t)
                count++;
        }

        return count;
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Each ping() → O(n)
Total calls (n) → O(n²)
Space Complexity

O(n) — storing all timestamps
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Maintain a list (vector) to store all ping timestamps.
For every new ping(t):
Add t to the list.
Compute the start of the valid window: t - 3000.
Traverse all stored timestamps.
Count how many timestamps lie in the range [t − 3000, t].
Return this count.
This approach checks every previous ping every time — no optimization.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class RecentCounter {
    vector<int> arr;   // Stores timestamps of all pings

public:
    RecentCounter() {}

    int ping(int t) {
        // Store the current ping timestamp
        arr.push_back(t);

        int start = t - 3000;  // Start of the valid time window
        int count = 0;

        // Traverse all previous timestamps
        for (int time : arr) {
            // Check if the timestamp is within [t-3000, t]
            if (time >= start && time <= t)
                count++;
        }

        // Return the number of valid pings
        return count;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
