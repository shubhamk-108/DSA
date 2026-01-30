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

        int target = tickets[k];
        int seconds = 0;

        for (int i = 0; i < n; i++)
        {
            if (i <= k)
            {

                if (tickets[i] < target)
                    seconds += tickets[i];
                else
                    seconds += target;
            }
            else
            {
                if (tickets[i] < target)
                    seconds += tickets[i];
                else
                    seconds += target -1;
            }
        }
        return seconds;
    }
};

/*

// more cleaner code 

for (int i = 0; i < n; i++)
{
    if (i <= k)
        seconds += min(tickets[i], target);
    else
        seconds += min(tickets[i], target - 1);
}

*/

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 2, 5, 8, 6};
    cout << sol.timeRequiredToBuy(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n)
Single pass through the arra
No simulation

🧠 Space Complexity
O(1)
Only variables, no extra structures
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

“Instead of simulating each second, I count how many times each person will buy a ticket before person k finishes. This gives an O(n) 
solution.”

Key Observation

Person k needs tickets[k] tickets, so the process will last exactly tickets[k] rounds.
Instead of simulating each second:
Count how many tickets each person can buy before person k finishes.
Logic Breakdown
People before or at k (i ≤ k)
They get a chance in every round, including the last one.
Contribution:
min(tickets[i],tickets[k])

People after k (i > k)
They do NOT get a chance in the last round.
Contribution:
min(tickets[i],tickets[k]−1)


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
        int n = tickets.size();      // Total number of people in the queue

        int target = tickets[k];     // Number of tickets person k needs
        int seconds = 0;             // Total time required

        // Traverse each person once
        for (int i = 0; i < n; i++)
        {
            // People before or at index k
            if (i <= k)
            {
                // They get a chance in all 'target' rounds
                // So they can buy at most min(tickets[i], target) tickets
                if (tickets[i] < target)
                    seconds += tickets[i];
                else
                    seconds += target;
            }
            // People after index k
            else
            {
                // They do NOT get a chance in the last round
                // So they can buy at most min(tickets[i], target - 1) tickets
                if (tickets[i] < target)
                    seconds += tickets[i];
                else
                    seconds += target - 1;
            }
        }

        return seconds;   // Total seconds needed for person k to finish
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Greedy counting
Observation-based math
Queue simulation optimization



*/
