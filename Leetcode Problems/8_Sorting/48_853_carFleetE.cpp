/*
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.



Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.
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
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++)
        {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int> a, const pair<int, int> b)
             { return a.first < b.first; });

        vector<double> time(n);

        for (int i = 0; i < n; i++)
        {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        int res = 0;

        int i = n - 1;
        while (i > 0)
        {
            if (time[i-1] <= time[i])
                time[i-1] = time[i];
            else
                res++;

            i--;
        }

        return res + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> p = {10, 8, 0, 5, 3};
    vector<int> s = {2, 4, 1, 1, 3};
    cout << sol.carFleet(12, p, s);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Why Right to Left traversal and not Left to right
//___________________________________________________________________________________________________________________________________________

/*

LC problem says A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.
That is a car can not overtake another car. If car catches car ahead to it then it becomes the fleet and this fleet will be
driven by the speed of the slowest car.

And here is the catch:
The car ahead might later slow down because it catches another car.

The correct realization (this is the key)

Even though each car has a pre-given speed,
its effective speed may later reduce if it catches another car ahead.
Therefore, we must process the cars that are further ahead first.
That’s it. That’s the whole reason.
Why this settles L → R vs R → L once and for all
When you go Left → Right (back to front)
You look at a car ahead
You assume its speed/time is final

❌ But that car might later slow down because it catches someone else
So your decision is based on non-final information
That’s why L → R is unsafe
When you go Right → Left (front to back)
The front-most car:
has no one ahead
will never slow down
its time is final
Once its fleet is finalized:
cars behind can safely decide whether they can catch it
So R → L guarantees:
When I compare, the car ahead will never change anymore.
Important subtle point you nailed
“We have pre-calculated speed, but speed can slow down”
This is exactly correct in the context of the problem:
Input speed[i] = individual capability
Fleet speed = minimum speed among merged cars
So effective speed is dynamic, not fixed
That’s the trap.
One-line invariant (final form)
A car’s fate must be decided only after the fate of every car ahead of it is finalized.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Sorting: O(n log n)
Traversal: O(n)
Total: O(n log n)

💾 Space Complexity
cars array → O(n)
time array → O(n)
Total: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Each car has an individual time to reach the target.
A car can only be affected by cars in front of it, never by cars behind.
So we must decide fleets starting from the front-most car.
We:
Pair each car’s position with its speed
Sort cars by position (left → right)
Compute time to reach target for each car
Traverse right → left:
If a car behind can reach the target earlier or at the same time as the car ahead, it will catch it → same fleet
Otherwise, it forms a new fleet

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        // Store (position, speed) for each car
        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; i++)
        {
            cars[i] = {position[i], speed[i]};
        }

        // Sort cars by position from left to right
        // (start of road -> target)
        sort(cars.begin(), cars.end(),
             [](const pair<int, int> a, const pair<int, int> b) {
                 return a.first < b.first;
             });

        // time[i] = time taken by car i (or its fleet) to reach target
        vector<double> time(n);

        // Compute individual time to reach target
        for (int i = 0; i < n; i++)
        {
            time[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        int res = 0;

        // Traverse from right to left (front to back)
        int i = n - 1;
        while (i > 0)
        {
            // If the car behind can catch the fleet ahead
            if (time[i - 1] <= time[i])
                // Merge into the fleet ahead
                time[i - 1] = time[i];
            else
                // Otherwise, it forms a new fleet
                res++;

            i--;
        }

        // Number of fleets = number of breaks + 1
        return res + 1;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Greedy + Sorting     
(also described as Monotonic Processing from One Direction)
Why it’s Greedy:
At each step, you make a local optimal decision:
“Can this car catch the fleet ahead or not?”
Once decided, that decision never changes.


*/
