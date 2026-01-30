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
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        int start = 0;
        while (arr.size() != 1)
        {
            int indexToBeDeleted = (start + k - 1)%arr.size();
            arr.erase(arr.begin() + indexToBeDeleted);
            start = indexToBeDeleted;
        }
        return arr[0];
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
erase() on vector → O(n)
Happens n - 1 times
👉 Total: O(n²)

Space Complexity
Vector storing players → O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Put all players 1 … n into a list.
Keep a pointer start indicating where counting begins.
For each round:
Move k - 1 steps ahead circularly using modulo.
Eliminate that player.
Continue counting from the next position.
Repeat until only one player remains.
Return the last remaining player.
This is a direct simulation of the problem statement.
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
        vector<int> arr;

        // Initialize players from 1 to n
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        int start = 0; // Starting index for counting

        // Continue until one player remains
        while (arr.size() != 1)
        {
            // Calculate index to remove (circularly)
            int indexToBeDeleted = (start + k - 1) % arr.size();

            // Remove the selected player
            arr.erase(arr.begin() + indexToBeDeleted);

            // Next round starts from this index
            start = indexToBeDeleted;
        }

        // Return the winner
        return arr[0];
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
Circular Simulation / Josephus Problem



*/
