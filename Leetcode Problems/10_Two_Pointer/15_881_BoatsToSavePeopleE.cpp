/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
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
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();

        sort(people.begin(), people.end());

        int boats = 0;

        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
            {
                left++;
                right--;
                boats += 1;
            }
            else
            {
                right--;
                boats += 1;
            }
        }
        return boats;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {3, 2, 2, 1};
    cout << sol.numRescueBoats(v, 3);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
O(n log n)
Sorting → O(n log n)
Two-pointer scan → O(n)
Total = O(n log n).

📦 Space Complexity
O(1) (ignoring sorting space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Sort the people by weight.
This allows pairing the lightest with the heaviest.
Use two pointers:
left → lightest person
right → heaviest person
Try to pair them:
If people[left] + people[right] <= limit,
they both fit into one boat → move both pointers.
Else, the heaviest person must go alone → move right.
Every iteration uses exactly 1 boat.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        // Number of people
        int n = people.size();

        // Sort weights to pair smallest with largest
        sort(people.begin(), people.end());

        int boats = 0;

        // Two pointers
        int left = 0;         // smallest
        int right = n - 1;    // largest

        while (left <= right)
        {
            // If the lightest and heaviest can share a boat
            if (people[left] + people[right] <= limit)
            {
                left++;      // use the lightest person
                right--;     // use the heaviest person
            }
            else
            {
                // Heaviest person cannot be paired -> goes alone
                right--;
            }

            // One boat used in each loop
            boats++;
        }

        return boats;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy + Two Pointers
Greedy: Always try to fit the heaviest person with the lightest possible.
Two pointers: One at start, one at end.


*/
