/*

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
    bool canAttend(vector<vector<int>> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int lastMeetEnd = arr[i][1];
            int lastMeetStart = arr[i][0];

            for (int j = i+1; j < n; j++)
            {
                int currMeetEnd = arr[j][1];
                int currMeetStart = arr[j][0];

                if (currMeetStart < lastMeetEnd && currMeetEnd > lastMeetStart)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{2, 4}, {9, 12}, {6, 10}};
    cout << sol.canAttend(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Explanation  if (arr[j][0] < arr[i][1] && arr[j][1] > arr[i][0])
//___________________________________________________________________________________________________________________________________________

/*

The key misunderstanding (very common)

You’re thinking:

“If arr[j][0] < arr[i][1] is true, then meeting j starts before meeting i ends.
So obviously meeting j’s end must be greater than meeting i’s start — why check it again?”

This feels intuitive, but it’s not always true.
Why ONE condition is NOT enough
Let’s name the meetings clearly:

Meeting i: [si, ei]
Meeting j: [sj, ej]

Condition you questioned
sj < ei

This only tells us:
“Meeting j starts before meeting i ends”
It does NOT tell us when meeting j ends.

Counterexample (this breaks your logic)
Meeting i: [5, 6]
Meeting j: [1, 4]

Now check your condition:
sj < ei
1  < 6   ✅ true
According to your logic, this means overlap.
But in reality:
[1, 4]   [5, 6]
They do not overlap.
Why?
Meeting j ends at 4
Meeting i starts at 5
They are completely disjoint
👉 This is exactly why checking only start < end is insufficient.
Why the SECOND condition is necessary
The full condition is:

sj < ei  &&  ej > si

Let’s interpret each part:
1️⃣ sj < ei

Meeting j starts before meeting i ends
→ ensures j is not completely after i

2️⃣ ej > si

Meeting j ends after meeting i starts
→ ensures j is not completely before i
Only when both are true do the intervals overlap.

Visual intuition (this helps a lot)
❌ No overlap (fails second condition)
[j----]
        [i----]

sj < ei ✅
ej > si ❌

❌ No overlap (fails first condition)
[i----]
        [j----]

sj < ei ❌
ej > si ✅

✅ Overlap
[i------]
      [j------]

sj < ei ✅
ej > si ✅
Why BOTH directions matter
Overlap means:
Each meeting must extend into the time window of the other
That’s a two-sided condition, not one-sided.
*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity

O(n^2)
	​

💾 Space Complexity
Only constant extra variables used
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Two meetings conflict if and only if their time intervals overlap.
So, check every pair of meetings and see whether any overlap exists.
Steps:
Iterate through each meeting i.
Compare it with every subsequent meeting j (j > i) to avoid duplicate checks.
For each pair, apply the standard overlap condition
If start_j < end_i and
end_j > start_i
→ meetings overlap → return false.
If no overlapping pair is found, return true.
This guarantees correctness by exhaustively checking all pairs


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*
class Solution
{
public:
    bool canAttend(vector<vector<int>> &arr)
    {
        int n = arr.size();

        // Iterate through each meeting
        for (int i = 0; i < n; i++)
        {
            int lastMeetStart = arr[i][0];
            int lastMeetEnd   = arr[i][1];

            // Compare with every meeting after it
            for (int j = i + 1; j < n; j++)
            {
                int currMeetStart = arr[j][0];
                int currMeetEnd   = arr[j][1];

                // Overlap condition:
                // One meeting starts before the other ends
                // AND ends after the other starts
                if (currMeetStart < lastMeetEnd &&
                    currMeetEnd > lastMeetStart)
                {
                    return false;
                }
            }
        }

        // No overlapping meetings found
        return true;
    }
};




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


brute

*/
