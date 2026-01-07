/*
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
        int maxPlatforms = 0;

        // For each arrival time, count how many trains are present
        for (int i = 0; i < n; i++)
        {
            int currPlatforms = 0;
            int time = arr[i];

            for (int j = 0; j < n; j++)
            {
                // GFG rule: arrival at same time as departure needs new platform
                if (arr[j] <= time && dep[j] >= time)
                {
                    currPlatforms++;
                }
            }

            maxPlatforms = max(maxPlatforms, currPlatforms);
        }

        return maxPlatforms;
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

⏱️ Time Complexity
Outer loop: O(N)
Inner loop: O(N)
Total brute force: O(N²)
Sorting step: O(N log N) (dominated by O(N²))
➡️ Overall Time: O(N²)

📦 Space Complexity

➡️ Auxiliary Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



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
        int maxPlatforms = 0;

        // For each arrival time, count how many trains are present
        for (int i = 0; i < n; i++)
        {
            int currPlatforms = 0;
            int time = arr[i];

            for (int j = 0; j < n; j++)
            {
                // GFG rule: arrival at same time as departure needs new platform
                if (arr[j] <= time && dep[j] >= time)
                {
                    currPlatforms++;
                }
            }

            maxPlatforms = max(maxPlatforms, currPlatforms);
        }

        return maxPlatforms;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern Name:
Brute Force Interval Overlap Counting
(Naive version of Sweep Line)
Conceptually:
This is an interval overlap problem
You directly check intersection of intervals
The optimal solution is derived from this using:
Sorting
Two pointers
Sweep Line / Event Counting


*/
