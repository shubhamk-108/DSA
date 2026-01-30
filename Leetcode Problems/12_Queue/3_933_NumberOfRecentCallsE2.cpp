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
public:
    queue<int> q;

    RecentCounter()
    {
    }

    int ping(int t)
    {
        int start = t - 3000;
        q.push(t);

        if (t <= 3000)
        {
            return q.size();
        }
        else
        {
            while (!q.empty() && q.front() < start)
                q.pop();
            return q.size();
        }
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Each ping: Amortized O(1)
Total: O(n)
(Each timestamp is pushed once and popped once)
✔ Optimal.

💾 Space Complexity
O(n) in the worst case

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Observations:
ping(t) is called with strictly increasing timestamps
We only care about pings in the range [t − 3000, t]
Any timestamp older than t − 3000 will never be needed again
Strategy:
Use a queue to store only relevant timestamps
For every ping(t):
Push t into the queue
Remove timestamps from the front that are < t − 3000
The queue size is the number of valid ping
Because timestamps arrive in order, the queue naturally stays sorted.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class RecentCounter {
public:
    queue<int> q;  // Stores timestamps within the valid time window

    RecentCounter() {}

    int ping(int t) {
        int start = t - 3000;

        // Add the current ping
        q.push(t);

        // Remove outdated pings
        while (!q.empty() && q.front() < start)
            q.pop();

        // Remaining elements are within [t-3000, t]
        return q.size();
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


👉 Sliding Window (Queue-based)
Why?
The window expands when a new ping arrives
It shrinks from the front when pings become outdated
Queue maintains order automatically
This is a textbook sliding window on time-based data

*/
