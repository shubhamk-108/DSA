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
    int solve_findWinnerIdx(int n, int k)
    {
        if (n == 1)
            return 0;

        int idx = solve_findWinnerIdx(n - 1, k);
        idx = (idx + k) % n;
        return idx;
    }

    int findTheWinner(int n, int k)
    {
        int res_idx = solve_findWinnerIdx(n, k);

        return res_idx + 1;
    }
};



main()
{
    Solution sol;
    int n = 5;
    int k = 2;
    cout << sol.findTheWinner(n, k);

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Intuition/explanation 
//___________________________________________________________________________________________________________________________________________

/*

Intuition/explanation is writtein in dsa book 1 , page no 21. Please See. Beautiful explanation available on youtube channel
// shashcode. Url: https://www.youtube.com/watch?v=2dN4ktn6D1k
// please see explanation in notebook.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity

One recursive call for each value of n from n → 1.

✅ Time Complexity
O(n)
	​
Space Complexity

Recursion depth = n
Each recursive call uses stack space
❌ Space Complexity
(due to recursion stack) O(n)
(due to recursion stack)

⚠️ Important:
This is not O(1) space because recursion uses the call stack.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


This problem is a classic Josephus Problem.
Core idea
Solve the problem for n − 1 players first.
When one player is removed, the winner’s position shifts by k.
Because players are in a circle, we use modulo % n.
Steps
Base case:
If only 1 player is left, they are the winner → index 0.
Recursive step:
Get the winner index for n − 1 players.
Adjust it for n players using:
(previous_index + k) % n
Convert 0-based index → 1-based label at the end.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    // Returns the winner's index (0-based) for n players
    int solve_findWinnerIdx(int n, int k)
    {
        // Base case: only one player
        if (n == 1)
            return 0;

        // Get winner index for n-1 players
        int idx = solve_findWinnerIdx(n - 1, k);

        // Adjust index after adding the nth player
        // +k -> shift because every k-th player is removed
        // %n -> circular wrap-around
        idx = (idx + k) % n;

        return idx;
    }

    int findTheWinner(int n, int k)
    {
        // Get 0-based index of winner
        int res_idx = solve_findWinnerIdx(n, k);

        // Convert to 1-based numbering
        return res_idx + 1;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Josephus Problem Pattern
More specifically:
Mathematical recurrence
Divide and conquer thinking
Circular index shifting
Modular arithmetic


*/
