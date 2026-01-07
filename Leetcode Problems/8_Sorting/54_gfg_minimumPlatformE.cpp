/*
url: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform.

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
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0;
        int j = 0;

        int maxOccupiedPlatform = 0;
        int platforms = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
            maxOccupiedPlatform = max(maxOccupiedPlatform, platforms);
        }

        return maxOccupiedPlatform;
    }
};

int main()
{
    Solution sol;
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
    cout << sol.minPlatform(arrival, departure);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Sorting arr → O(N log N)
Sorting dep → O(N log N)
Two-pointer sweep → O(N)
Overall: O(N log N)

📦 Space Complexity
No extra data structures are used
Sorting done in-place (ignoring recursion stack)
Auxiliary Space: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Each train has an arrival and departure time.
The goal is to find maximum number of trains at the station at any time, i.e., minimum platforms needed.
Observation: Platforms are only needed when trains overlap in time.
To track overlapping efficiently:
Sort arrival[] in ascending order
Sort departure[] in ascending order
Use two pointers (i for arrival, j for departure):
If arr[i] <= dep[j] → a train has arrived before the earliest departure → need a new platform (platforms++)
Else → a train has departed → free a platform (platforms--)
Track the maximum platforms during the sweep.
This method is often called the Sweep Line Algorithm or Two Pointer Event Counting.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        // Sort arrival and departure times independently
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0; // pointer for arrival times
        int j = 0; // pointer for departure times

        int maxOccupiedPlatform = 0; // stores answer
        int platforms = 0;           // currently occupied platforms

        // Sweep through all events
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j]) // next event is arrival
            {
                platforms++; // need a new platform
                i++;
            }
            else // next event is departure
            {
                platforms--; // free a platform
                j++;
            }

            // update max platforms needed at any time
            maxOccupiedPlatform = max(maxOccupiedPlatform, platforms);
        }

        return maxOccupiedPlatform;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Sorting + Two Pointers
Sweep Line / Event Counting
Conceptually:
Convert “interval overlap” into events
Track running count
Answer = maximum count at any time
Same pattern appears in:
LC 253 — Meeting Rooms II
LC 1094 — Car Pooling
LC 732 — My Calendar III

*/
