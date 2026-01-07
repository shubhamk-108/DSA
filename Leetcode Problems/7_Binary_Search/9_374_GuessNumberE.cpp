/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.


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

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int n)
{
    return;
}
class Solution
{
public:
    int guessNumber(int n)
    {
        int low = 1;
        int high = n;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int res = guess(mid); 

            if (res == 1)
                low = mid + 1; 
            else if (res == -1)
                high = mid - 1;
            else
                return mid; 
        }
        return -1; 
    }
};

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

O(log n)
Binary search cuts the range in half each time.

🧠 Space Complexity

O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use binary search on the range [1, n]:
If guess(mid) == 1, the target is higher → move low up
If guess(mid) == -1, the target is lower → move high down
If guess(mid) == 0, mid is the secret number
The search always converges to the exact target.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int res = guess(mid);   // call API ONLY ONCE

            if (res == 1)
                low = mid + 1;      // guess too low
            else if (res == -1)
                high = mid - 1;     // guess too high
            else
                return mid;         // correct guess
        }

        return -1; // not needed, but safe
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Binary Search on Answer
*/
