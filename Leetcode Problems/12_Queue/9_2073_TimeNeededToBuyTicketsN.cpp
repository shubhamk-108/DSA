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

// This code is not interview friendly
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        queue<int> q;
        int seconds = 0;

        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (flag == k)
                q.push(-1);
            q.push(tickets[i]);
            flag++;
        }

        bool kthCustomer = false;

        while (true)
        {
            if (q.front() == -1)
            {
                kthCustomer = true;
                q.pop();
                q.push(-1);
                continue;
            }

            int x = q.front();
            if (x == 1)
            {
                seconds++;
                if (kthCustomer)
                    return seconds;
                else
                    q.pop();
            }
            else
            {
                seconds++;
                if (kthCustomer)
                {
                    int x = q.front();
                    x--;
                    q.pop();
                    q.push(x);
                    kthCustomer = false;
                }
                else
                {
                    int x = q.front();
                    x--;
                    q.pop();
                    q.push(x);
                }
            }
        }
        return seconds;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 2};
    cout << sol.timeRequiredToBuy(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

if correct , please give me approach of code, comment my code, then say time and space and then tell which pattern is used to solve problem.

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




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
