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
    vector<pair<int, int>> events;

    MyCalendarThree() {}

    int book(int startTime, int endTime)
    {
        events.push_back({startTime, endTime});
        int ans = 0;

        // pick a time point
        for (auto &t : events)
        {
            int startOfEvent = t.first; // use event start as a time instant
            int active = 0;

            // count how many events cover this time
            for (auto &otherEvents : events)
            {
                if (startOfEvent >= otherEvents.first && startOfEvent < otherEvents.second)
                {
                    active++;
                }
            }

            ans = max(ans, active);
        }

        return ans;
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

Outer loop: O(n) → iterates through all events

Inner loop: O(n) → counts overlaps for each event

Total: O(n²), where n = number of events booked

Space Complexity

Storing all events: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Store all events: Every new booking is stored in a vector.

Check overlaps at specific points: For each event, pick its start time as a representative time point.

Count active events at that time: Check all other events to see if they cover that time instant.

Keep the max: Track the maximum number of overlapping events at any checked time point.

⚠️ Problem with this code: This approach does not always work correctly because it only checks overlaps at the start times of events. Overlaps can happen in the middle of other intervals, which this code misses. That’s why LC732 gives unexpected outputs if you try this.

The correct brute-force approach would be to check every start and end time of all intervals (or any other critical time points), not just start times of events.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class MyCalendarThree
{
public:
    vector<pair<int, int>> events; // Stores all the booked intervals

    MyCalendarThree() {} // Constructor

    int book(int startTime, int endTime)
    {
        // Step 1: Add the new event to the list
        events.push_back({startTime, endTime});
        int ans = 0;

        // Step 2: Pick a "time point" from all events to check overlaps
        for (auto &t : events)
        {
            int startOfEvent = t.first; // Use the start of each event as a representative time instant
            int active = 0;

            // Step 3: Count how many events are active at this time point
            for (auto &otherEvents : events)
            {
                // If this event covers the time instant 'startOfEvent', increment active count
                if (startOfEvent >= otherEvents.first && startOfEvent < otherEvents.second)
                {
                    active++;
                }
            }

            // Step 4: Keep track of the maximum number of simultaneous events
            ans = max(ans, active);
        }

        return ans; // Return the maximum overlap so far
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


This problem is typically solved using the “Sweep Line / Line Sweep” pattern:

Treat each interval as two events: start (+1) and end (-1)

Sort all time points

Sweep through time, keeping track of active events

Maximum active events at any point = answer

*/
