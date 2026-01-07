/*
There are n flights that are labeled from 1 to n.

You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.



Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
Example 2:

Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]
Explanation:
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]
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

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int>res(n+1, 0);

        for (auto x : bookings)
        {
            int start = x[0];
            int end = x[1];
            int flights = x[2];

            for (int i = start; i <= end; i++)
            {
                res[i] += flights;
            }
        }
        res.erase(res.begin());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}};

    vector<int> res = sol.corpFlightBookings(arr, 5);

    for (auto x : res)
        cout << x << " ";

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

Let:

n = number of flights . this is start and end of every vector. Ex.  {1, 2, 10}, from 1 to 2 and precisely it is end - start + 1.
m = number of bookings. It is vec of vec size.


O(n×m)

Space Complexity

vector<int> res(n + 1)
O(n+1) from this n.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

What you did    
Created an array res to store total seats for each flight
For each booking:
Took the range [start, end]
Added the number of seats to every flight in that range
Returned the final seat count per flight
🔹 In short
You simulated the problem exactly as described, by manually updating each flight affected by every booking.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        // res[i] will store total seats booked for flight i
        // Using size n+1 so we can directly use 1-based indexing
        vector<int> res(n + 1, 0);

        // Iterate over each booking
        for (auto x : bookings)
        {
            int start = x[0];    // starting flight number
            int end = x[1];      // ending flight number
            int flights = x[2];  // seats booked

            // Add 'flights' seats to every flight in range [start, end]
            // This simulates each booking directly
            for (int i = start; i <= end; i++)
            {
                res[i] += flights;
            }
        }

        // Remove index 0 to convert from 1-based indexing
        res.erase(res.begin());

        // Return result for flights 1 to n
        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute-force range update

Direct simulation


*/
