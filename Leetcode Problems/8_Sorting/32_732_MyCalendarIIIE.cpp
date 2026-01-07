/*
A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

MyCalendarThree() Initializes the object.
int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.


Example 1:

Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]

Explanation
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1
myCalendarThree.book(50, 60); // return 1
myCalendarThree.book(10, 40); // return 2
myCalendarThree.book(5, 15); // return 3
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class MyCalendarThree
{
public:
    map<int, int> events;

    MyCalendarThree()
    {
    }

    int book(int startTime, int endTime)
    {

        events[startTime] += 1;
        events[endTime] -= 1;

        int res = 0;
        int curr = 0;
        for (auto x : events)
        {
            curr += x.second;
            res = max(res, curr);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time : O(n^2):

when the input is like this 1 + 2 + 4 + 6 ---2n then time becomes O(n^2)

Why the total time is O(n²) (vey precise)

The key point you’re missing is:
The O(n) scan happens INSIDE book() — and book() is called n times.
Break it down by call
Let n = total number of book() calls.
On the 1st call
map size ≈ 2
scan cost = O(1)
On the 2nd call
map size ≈ 4
scan cost = O(2)
On the 3rd call
map size ≈ 6
scan cost = O(3)
...
On the nth call
map size ≈ 2n
scan cost = O(n)
Add them all together
Total scan work:
O(1 + 2 + 3 + ... + n)
This sum is:
n(n + 1) / 2 = O(n²)

4️⃣ Space Complexity
events map stores at most 2n entries
Space = O(n

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


After each booking, return the maximum number of overlapping meetings at any time so far.
Instead of storing full intervals, we track changes in meeting count over time.
Key idea
When a meeting starts, active meetings +1
When a meeting ends, active meetings −1
If we sort these time points and compute a prefix sum, the maximum prefix sum gives the answer
We use an ordered map so times stay sorted automatically.

*/

//___________________________________________________________________________________________________________________________________________
// code explanation
//___________________________________________________________________________________________________________________________________________

/*

We’ll use overlap diagrams + prefix sum thinking, because that’s the heart of LC 732.

Problem Reminder (plain English)

Each time you call:

book(start, end)


You must:

Add this interval

Return the maximum number of meetings happening at the same time so far

Core Idea (before code)

Instead of tracking intervals directly, we track changes:

At start → meetings increase by +1

At end → meetings decrease by −1

Then:

Sort times

Walk left → right

Keep a running count

The highest count = answer

Visual Example (step by step)

Let’s simulate these bookings:

book(10, 20)
book(50, 60)
book(10, 40)

After book(10,20)
Timeline
Time:   10 --------- 20
Meetings:      1

Events map
10 → +1
20 → -1

Prefix sum walk

| Time | Change | Active |
| ---- | ------ | ------ |
| 10   | +1     | 1      |
| 20   | -1     | 0      |


After book(50,60)
Timeline
10 ---- 20      50 ---- 60
   1                1

Events map
10 → +1
20 → -1
50 → +1
60 → -1

Prefix sum walk

| Time | Change | Active |
| ---- | ------ | ------ |
| 10   | +1     | 1      |
| 20   | -1     | 0      |
| 50   | +1     | 1      |
| 60   | -1     | 0      |


max = 1

After book(10,40)
Timeline (important one)
10 -------- 20
10 ------------------- 40


Between 10 and 20, two meetings overlap.

Events map
10 → +2   (two starts)
20 → -1
40 → -1
50 → +1
60 → -1

Prefix sum walk (this is key)

| Time | Change | Active  |
| ---- | ------ | ------- |
| 10   | +2     | 2 ← max |
| 20   | -1     | 1       |
| 40   | -1     | 0       |
| 50   | +1     | 1       |
| 60   | -1     | 0       |



max = 2
this is why answer becomes 2


Line-by-line meaning
map<int,int> events;

Stores time → change in meeting count
Sorted automatically by time.

events[startTime] += 1;

At this time, one meeting starts.

events[endTime] -= 1;

At this time, one meeting ends.

This models:

[start, end)


(end is NOT included)

Prefix sum loop
curr += x.second;


This means:

“Apply all meeting starts/ends at this time.”

res = max(res, curr);


This means:

“Track the maximum number of simultaneous meetings.”

Why this works (mental picture)

Imagine walking along the timeline:

Each +1 = someone enters a room

Each -1 = someone leaves a room

curr = people in the room right now

res = most people ever in the room

That’s it.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class MyCalendarThree
{
public:
    // Map to store time → change in active meetings
    // startTime → +1
    // endTime   → -1
    map<int, int> events;
    
    MyCalendarThree()
    {
        // Constructor is called once when object is created
        // No initialization needed here
    }

    int book(int startTime, int endTime)
    {
        // Mark start of meeting
        events[startTime] += 1;

        // Mark end of meeting
        events[endTime] -= 1;

        int res = 0;   // maximum overlapping meetings
        int curr = 0;  // current active meetings

        // Traverse events in time order (map is sorted)
        for (auto x : events)
        {
            curr += x.second;      // apply change at this time
            res = max(res, curr);  // update maximum overlap
        }

        return res;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

This problem uses:
✅ Sweep Line Algorithm
✅ Difference Array
✅ Prefix Sum
✅ Design + Ordered Map
Same family as:
LC 1109 – Corporate Flight Bookings
Car Pooling
LC 253 – Meeting Rooms II


*/
