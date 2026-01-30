/*
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.



Example 1:

Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
Example 2:

Input: tickets = [5,1,1,1], k = 0

Output: 8

Explanation:

The queue starts as [5,1,1,1], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.
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

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int seconds = 0;

        while (true)
        {
            for (int i = 0; i < n; i++)
            {
                if (tickets[i] == 0)
                    continue;

                tickets[i]--;
                seconds++;
                if (tickets[i] == 0 && i == k)
                    return seconds;
            }
        }
        return seconds;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 2,5,8,6};
    cout << sol.timeRequiredToBuy(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity Summary (Your Brute-Force Code)
General Time Complexity
O(n × tickets[k])​
Why?
The simulation runs for tickets[k] rounds
In each round, you scan all n people

Worst-Case Time Complexity
O( ∑ tickets[i])​

In the worst case, person k has the maximum tickets
Every ticket bought by every person is processed once

Space Complexity
O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Idea
We simulate the process exactly as described in the problem.
People stand in a queue from index 0 to n-1
Each second:
The current person buys one ticket (if they still need tickets)
If their tickets become 0, they leave the queue
We keep simulating until person k buys their last ticket
Key points of the approach:
Loop over the array repeatedly (circular queue behavior)
Skip people whose tickets are already 0
Decrease tickets one by one
Count each second
Stop immediately when person k finishes
This is direct simulation, no optimization.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();   // Number of people in the queue
        int seconds = 0;          // Time counter

        // Keep simulating the queue until person k finishes
        while (true)
        {
            // One full round of the queue
            for (int i = 0; i < n; i++)
            {
                // If this person has no tickets left, skip them
                if (tickets[i] == 0)
                    continue;

                // Person i buys one ticket
                tickets[i]--;
                seconds++;

                // If person k just bought their last ticket, stop
                if (i == k && tickets[i] == 0)
                    return seconds;
            }
        }
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute-force simulation

*/
