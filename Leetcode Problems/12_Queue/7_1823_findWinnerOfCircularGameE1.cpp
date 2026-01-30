/*
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.



Example 1:

Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
Example 2:

Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
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
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);

        while (q.size() != 1)
        {
            int j = 0;
            while (!q.empty() && j < k - 1)
            {
                int x = q.front();
                q.pop();
                q.push(x);
                j++;
            }
            q.pop();
        }
        return q.front();
    }
};

int main()
{
    Solution sol;
    int n = 5;
    int k = 2;
    cout << sol.findTheWinner(n, k);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop runs (n − 1) times (one player removed each round).
Inner loop runs (k − 1) operations each round.

Time Complexity:
O(n×k)
This is fine given the constraints.

🧠 4. Space Complexity
Queue stores up to n elements.
Space Complexity:
O(n)
	
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

This problem is a classic Josephus elimination game.
Idea: simulate the game using a queue
Put players 1 to n into a queue
Repeat until only one player is left:
Move the first k-1 players from the front of the queue to the back
(this simulates counting).
Remove the k-th player (the one at the front after rotation).
The remaining element in the queue is the winner.
The queue naturally models a circular arrangement.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        // Queue to simulate circular game
        queue<int> q;

        // Push players 1 to n into the queue
        for (int i = 1; i <= n; i++)
            q.push(i);

        // Continue until only one player remains
        while (q.size() != 1)
        {
            int j = 0;

            // Move first (k - 1) players to the back
            while (!q.empty() && j < k - 1)
            {
                int x = q.front(); // take front player
                q.pop();           // remove from front
                q.push(x);         // put at the back
                j++;
            }

            // Remove the k-th player
            q.pop();
        }

        // The last remaining player is the winner
        return q.front();
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Simulation + Queue (Circular Rotation Pattern)
More specifically:
Josephus Problem
Circular Queue / Round-Robin Elimination


*/
