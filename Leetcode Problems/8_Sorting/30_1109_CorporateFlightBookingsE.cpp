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
        vector<int> res(n, 0);

        for (auto x : bookings)
        {
            int start = x[0];
            int end = x[1];
            int flights = x[2];

            res[start - 1] += flights;

            if (end - 1 + 1 < n)
                res[end - 1 + 1] -= flights;
        }

        for (int i = 1; i < n; i++)
        {
            res[i] += res[i - 1];
        }

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
// Simple difference array approach exaplantion
//___________________________________________________________________________________________________________________________________________
/*

we are marking or adding number_of_flights only to the start. And then our intuition is that we will keep adding that 
number_of_flights from start to all the way to the end.
But wait we have given end as well and we dont want number_of_flights to be added after that end.
Ex:{2,5,25} Here we will add number_of_flights 25 to the 2 position/value. And we have to add this 25 to the very end.
But to complete in the O(n+m )and not O(n*m) we are just marrking the start with += number_of_flights.
And then we run another loop and we just add what we have to the current block what we had in the  previous block.
But after 5 here we do not want 25. That is why one position immediate next to end or 5 here we add - number_of_flights that is -25.
So when after end that is 5 when we will try adding 25 then this -25 will also get added and that will nullify both -25 and + 25 
and that way we will get number_of_flights 25 only from position 2 to 5 here.

Important: why we did start - 1. Because this is 0 indexed base. If we want to access 4 then accoring to 0 index  based 4th's
position will be in 4-1 th house or block. Thus we did res[start - 1] += flights;

Similarly why we did end - 1:
becuase end's posiiton is end - 1 for 0th index and then one from one position ahead we want to add minus number_of_flights 25 to nullify
sp we add 1 to it and it became end - 1 + 1 which is end.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
n = number of flights
This comes from the input n in the function corpFlightBookings(vector<vector<int>> &bookings, int n).
Your result array res has size n.
m = number of bookings
This is the number of rows in bookings, i.e., bookings.size().
Total time complexity:
O(m+n)

Space Complexity
res array → size n → O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Difference Array Concept:
For a range update problem (add flights to flights start to end), instead of updating every index in the range, we use a difference array:
Add flights at start-1 (0-indexed start).
Subtract flights at end (0-indexed position after last flight).
After all bookings are applied, compute prefix sum of the array to get the actual seats booked for each flight.
Why efficient:
Instead of looping over all flights in each booking (O(n*m)), we only do two updates per booking + one prefix sum (O(n + m)).


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
        vector<int> res(n, 0); // Initialize result vector for n flights

        // Apply difference array updates for each booking
        for (auto x : bookings)
        {
            int start = x[0];   // Start flight (1-indexed)
            int end = x[1];     // End flight (1-indexed)
            int flights = x[2]; // Seats booked

            res[start - 1] += flights; // Add flights at start (convert to 0-indexed)
            if (end < n)               // Ensure end index is within bounds
                res[end] -= flights;   // Subtract flights after end
        }

        // Build prefix sum to get total seats for each flight
        for (int i = 1; i < n; i++)
        {
            res[i] += res[i - 1];
        }

        return res; // Final array contains total seats booked per flight
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Difference Array / Range Update with Prefix Sum
Often used when we need to apply increment/decrement to ranges efficiently.
Examples: LC1109, LC370 (Range Addition), Interval booking problems.

*/
