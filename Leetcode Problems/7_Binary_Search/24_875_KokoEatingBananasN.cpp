/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
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
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int maxx = *max_element(piles.begin(), piles.end());

        for (int i = 1; i <= maxx; i++)
        {
            long long hours = 0;
            for (int j = 0; j < piles.size(); j++)
            {
                hours += (piles[j] + i - 1) / i;
            }
            if (hours <= h)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 6, 7, 11};
    cout << sol.minEatingSpeed(v, 8);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity
Worst-case:
O(max(piles) * n)
Where:
max(piles) can be up to 10⁹


💾 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Koko can eat bananas at any speed k from 1 to max(piles) bananas per hour.
For each possible eating speed k, calculate how many hours it would take:
hours += ceil(pile / k)
If the total hours ≤ h, then k is a valid eating speed.
The first valid k is the minimum speed Koko needs.
Return that value.
This approach checks all possible speeds one by one.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxx = *max_element(piles.begin(), piles.end());

        // Try every possible speed from 1 to max pile value
        for (int k = 1; k <= maxx; k++)
        {
            long long hours = 0;

            // Calculate hours needed if Koko eats at speed k
            for (int pile : piles)
            {
                // ceil(pile/k) = (pile + k - 1) / k
                hours += (pile + k - 1) / k;
            }

            // If she can finish within h hours → this is the minimum valid speed
            if (hours <= h)
                return k;
        }

        return -1; // theoretically never reached
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

bruteforce for binary search pattern.


*/
