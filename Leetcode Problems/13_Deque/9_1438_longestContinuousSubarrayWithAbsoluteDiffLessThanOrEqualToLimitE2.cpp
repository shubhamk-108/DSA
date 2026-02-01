/*
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.



Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2
Explanation: All subarrays are:
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4.
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
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
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        deque<int> maxDq, minDq;
        int left = 0, right = 0;
        int len = 0;

        for (int right = 0; right < n; right++)
        {
            while (!maxDq.empty() && nums[maxDq.back()] < nums[right])
                maxDq.pop_back();

            maxDq.push_back(right);

            while (!minDq.empty() && nums[minDq.back()] > nums[right])
                minDq.pop_back();

            minDq.push_back(right);

            while (nums[maxDq.front()] - nums[minDq.front()] > limit)
            {
                if (left == maxDq.front())
                    maxDq.pop_front();
                if (minDq.front() == left)
                    minDq.pop_front();
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {8, 2, 4, 7};
    cout << sol.longestSubarray(v, 4);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Intuition and explanation
//___________________________________________________________________________________________________________________________________________


/*

I’ll structure this into intuition → rules → why deque → shrinking logic → common confusions → final mental model.

🔒 LC1438 — COMPLETE SUMMARY (from zero to mastery)
Problem in one line
Find the longest contiguous subarray such that
max(subarray) − min(subarray) ≤ limit
1️⃣ Core difficulty (why this problem exists)
If the array had:
only increasing numbers, or
only non-negative numbers
then simple sliding window would work.
But here:
values jump up and down
negative numbers exist
max and min change dynamically
👉 The entire difficulty is:
How do we know the current max and min of a sliding window efficiently?

2️⃣ Three possible solution levels
🟥 Brute force
Try all subarrays
Recompute min and max every time
⏱ O(n²) → too slow

🟨 Sliding window + multiset (your solution)
Maintain window
multiset gives min and max
⏱ O(n log n) → accepted, but not optimal

🟩 Sliding window + monotonic deque (optimal)
Maintain only what matters (min & max)
No extra ordering
⏱ O(n) → best possible

3️⃣ Key insight (this unlocks everything)
We do NOT need all elements sorted.
We only need:
the current maximum
the current minimum
So we maintain two monotonic deques.

4️⃣ What the deques actually represent
🔼 maxDQ (monotonic decreasing)
Stores indices
Values decrease from front → back
front() = index of maximum element in window
🔽 minDQ (monotonic increasing)
Stores indices
Values increase from front → back
front() = index of minimum element in window
💡 These deques store candidates, not all elements.

5️⃣ Why we pop from the back when adding a new element
For maxDQ
If a bigger value comes in:
smaller values behind it can never become max
they are useless → remove them
For minDQ
If a smaller value comes in:
larger values behind it can never become min
remove them
👉 This is greedy elimination.

6️⃣ Sliding window mechanics (very important)
We use:
left → start of windowright → end of window
At each step:
Expand window (right)
Update deques
Check validity
Shrink if invalid
Update answer

7️⃣ The MOST important rule (do not forget this)
This is a CONTIGUOUS subarray problem.
That means:
You are ONLY allowed to remove elements from the left
You are NOT allowed to remove min or max directly
You are NOT allowed to “delete arbitrary elements”
This rule answers half of your doubts.

8️⃣ Why shrinking only checks the FRONT of deques
When left moves forward:
Exactly one element leaves the window → nums[left]

Now the crucial invariants:

🔑 Invariant 1
Deque indices are always in increasing index order.
So:
If left exists in a deque
It must be at the front
It can NEVER be in the middle or back.

🔑 Invariant 2
Only the front affects the condition:
nums[maxDQ.front()] - nums[minDQ.front()]
Anything behind the front:
is not the current max or min
does not affect validity
So when shrinking:
if (maxDQ.front() == left) pop
if (minDQ.front() == left) pop
left++
That’s not a guess — it’s guaranteed.

9️⃣ Your big question:
“Is min always the problem? Can we just remove it?”

❌ NO, and here’s why:
Sometimes the max is the problem
Sometimes the min is the problem
Sometimes removing one still doesn’t fix it
More importantly:
You are NOT allowed to remove min or max arbitrarily.
You can ONLY move left.
So the correct strategy is:
Don’t decide who is guilty. Let the window decide.
When left moves:
if min leaves → good
if max leaves → good
if neither leaves → keep shrinking
Eventually the window becomes valid.

🔟 Why this guarantees correctness
Because:
Each step removes one element
Each element can only leave once
Either the min or max will eventually leave
Difference decreases monotonically
No wrong deletions. No missed cases.

11️⃣ Final mental model (THIS IS THE GOLD)
Please read this slowly:
The violation is caused by (max − min),
but the FIX is controlled only by the LEFT boundary.
We do not ask:
“Which value should I delete?”
We ask:
“What element is leaving the window next?”
That is the essence of sliding window + monotonic deque.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time:
O(n)
Why?
Each index is:
pushed once
popped once
Both deques together do at most 2n operations

🧠 Space Complexity
O(n) (worst case)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We want the longest contiguous subarray where:
max(subarray) − min(subarray) ≤ limit
Key challenges
Max and min keep changing as the window moves
We must update them efficiently
Core idea
Use a sliding window with two monotonic deques:
maxDq → keeps track of maximum values
minDq → keeps track of minimum values
Each deque stores indices, not values.

🧠 Intuition
Expand the window from the right
Maintain:
maxDq.front() → index of maximum element in window
minDq.front() → index of minimum element in window
If the condition breaks, shrink from the left
Track the maximum valid window size
We want the longest contiguous subarray where:
max(subarray) − min(subarray) ≤ limit
Key challenges
Max and min keep changing as the window moves
We must update them efficiently
Core idea
Use a sliding window with two monotonic deques:
maxDq → keeps track of maximum values
minDq → keeps track of minimum values
Each deque stores indices, not values.

🧠 Intuition
Expand the window from the right
Maintain:
maxDq.front() → index of maximum element in window
minDq.front() → index of minimum element in window
If the condition breaks, shrink from the left
Track the maximum valid window size

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        // Deques to store indices
        deque<int> maxDq, minDq;

        int left = 0;
        int len = 0;

        // Right pointer expands the window
        for (int right = 0; right < n; right++)
        {
            // Maintain maxDq in decreasing order
            // Remove all elements smaller than current
            while (!maxDq.empty() && nums[maxDq.back()] < nums[right])
                maxDq.pop_back();
            maxDq.push_back(right);

            // Maintain minDq in increasing order
            // Remove all elements larger than current
            while (!minDq.empty() && nums[minDq.back()] > nums[right])
                minDq.pop_back();
            minDq.push_back(right);

            // Shrink window if condition breaks
            while (nums[maxDq.front()] - nums[minDq.front()] > limit)
            {
                // If the outgoing element is max, remove it
                if (maxDq.front() == left)
                    maxDq.pop_front();

                // If the outgoing element is min, remove it
                if (minDq.front() == left)
                    minDq.pop_front();

                left++;  // move window forward
            }

            // Update maximum valid length
            len = max(len, right - left + 1);
        }

        return len;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


This problem uses three major patterns:

✅ 1. Sliding Window (Two Pointers)
Window expands with right
Shrinks with left
Used for contiguous subarray problems
✅ 2. Monotonic Deque
Efficient min/max tracking in a window
Eliminates unnecessary elements greedily
✅ 3. Greedy Optimization
Remove elements that can never become min/max again

*/
