/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();

        if (points.empty())
            return 0;
        int count = 0;

        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        vector<bool> isBursted(n, false);

        for (int i = 0; i < n; i++)
        {
            if (isBursted[i])
                continue;

            int endOfBaloon = points[i][1];

            for (int j = 0; j < n; j++)
            {
                int start = points[j][0];
                int end = points[j][1];

                if (!isBursted[j])
                {
                    if ((endOfBaloon >= start && endOfBaloon <= end))
                    {
                        isBursted[j] = true;
                    }
                }
            }
            count++;
            isBursted[i] = true;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << sol.findMinArrowShots(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Why sort?
//___________________________________________________________________________________________________________________________________________
/*
Because sorting  accorinding to the end coordinate, because shooting arrow to the end allow us to cover as much baloon as we can.
Sorting accorinding to the end coordinate matters because without that we wont get correct order of the baloons to check overlaps.
Ex here 
[[10,16],[2,8],[1,6],[7,12]]
expected o/p is 2 but we are getting 3 because we have not sorted so we take one more arrow.
for 10,16, does end 16 lies in any of this. No. So it takes one arrow. But if we have sorted then end 12 comes earlier and 12 lies
in between 10,16 so both will take one arrow.

*/


//___________________________________________________________________________________________________________________________________________
// Question
// why we are checking does end lies in other baloon's start and end. why we are not checking insted does start lies in other
// baloon's start and end
//___________________________________________________________________________________________________________________________________________

/*

What are we actually checking?

This line:

points[j][0] <= arrow && arrow <= points[j][1]


means:

“Does the arrow position lie inside this balloon?”

Because a balloon bursts only if the arrow passes through it.

Key fact (this decides everything)

👉 An arrow is a single POINT on the x-axis
👉 A balloon is an INTERVAL

So the correct logical question is:

❓ Does this POINT lie inside this INTERVAL?

That’s exactly:

start ≤ arrow ≤ end

Why do we choose end as the arrow position?

Because of the greedy insight:

Shooting the arrow as far right as possible gives maximum chance to hit future balloons.

So we pick:

arrow = some balloon's end


Example:

(1,6), (2,4)


If we shoot at 4:

[1-----------6]
     [2----4]
          ↑ arrow


This arrow bursts both balloons.

Now your core question 👇
❓ Why check
arrow ∈ [start, end]

❓ Why NOT check
start ∈ [otherStart, otherEnd]

Because that checks the WRONG thing

Let’s see with a diagram.

Balloons
A: (1,6)
B: (2,4)

Arrow at 4

Correct check:

Does arrow = 4 lie inside A?  YES
Does arrow = 4 lie inside B?  YES


So both burst ✔️

❌ Wrong idea: “Does start lie inside other balloon?”

Check:

Does start of A (1) lie in B (2,4)?  NO


But A still bursts, because the arrow is at 4, not at 1.

⚠️ The balloon’s start point is irrelevant once the arrow is chosen.

Another example (this really nails it)
Balloon A: (1,10)
Balloon B: (3,4)
Arrow at 4


Diagram:

[1--------------------10]
      [3----4]
           ↑ arrow


Arrow hits both

But:

start of A = 1
1 is NOT in (3,4)


❌ Checking starts would say “no overlap”
✅ But the arrow clearly bursts both balloons

Fundamental rule (memorize this)

Intersection of intervals checks interval–interval overlap
Arrow problem checks point–interval containment

*/




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Sorting: O(n log n)
Nested loops: O(n²)
Total: O(n²) → brute force
.
Space Complexity
isBursted array: O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort balloons by their ending point
This ensures when you shoot an arrow, it’s placed at the earliest possible end.
Maintain a isBursted[] array to track which balloons are already burst.
Iterate through balloons:
If a balloon is already burst → skip it.
Otherwise:
Shoot an arrow at this balloon’s end
Traverse all balloons and burst every balloon whose range contains this arrow
Increase arrow count
Return total arrows used.
This guarantees correctness because:
An arrow shot at a balloon’s end is the safest position to burst as many balloons as possible.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        int n = points.size();

        // Sort balloons by their ending coordinate
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        vector<bool> isBursted(n, false);
        int count = 0;

        // Try shooting arrows
        for (int i = 0; i < n; i++)
        {
            // If this balloon is already burst, skip
            if (isBursted[i])
                continue;

            // Shoot arrow at the end of current balloon
            int arrowPos = points[i][1];

            // Burst all balloons that overlap with this arrow
            for (int j = 0; j < n; j++)
            {
                if (!isBursted[j])
                {
                    int start = points[j][0];
                    int end = points[j][1];

                    if (arrowPos >= start && arrowPos <= end)
                    {
                        isBursted[j] = true;
                    }
                }
            }

            count++; // one arrow used
        }

        return count;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Pattern: Greedy (Brute-force version)
Greedy choice: Always shoot arrow at the earliest ending balloon


*/
