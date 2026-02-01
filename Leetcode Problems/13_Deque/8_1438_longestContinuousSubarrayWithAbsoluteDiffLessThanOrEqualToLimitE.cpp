
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
#include<set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


//efficient 
// this Q can also be solved using min max heap priiority queue and you should solve it using that once you learn heap ds.
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        int maxLen = 0;

        int left = 0;
        int right = 0;

        multiset<int> window;

        while (right < n)
        {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > limit)
            {
                window.erase(window.find(nums[left]));
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right ++;
        }

        return maxLen;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> v = {10, 1, 2, 4, 7, 2};
//     cout << sol.longestSubarray(v, 5);
//     return 0;
// }

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time:
Each element:
Insert → O(log n)
Possible delete → O(log n)
Total: O(n log n)

Space:
O(n)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

✅ 1. What the problem wants
You must find the longest window (subarray) where:
max(window) – min(window) ≤ limit
This means
At any time, inside the sliding window, you must know:
The minimum element
The maximum element
And you need to update these efficiently as the window grows and shrinks.

In anysubarray if the diff betn max and min is less equal to limit then all the elements will surely give diff less than limit.

❌ 2. Why normal sliding window (without a data structure) fails
If you store just:
minSoFar
maxSoFar
Then when the window shrinks (left moves forward),
the old min/max might be removed from the window, but you don’t know the new min/max.
Recalculating min/max takes O(n) each time → too slow.

⭐ 3. Why multiset is used
Because:
✔ Multiset keeps all numbers sorted automatically
*window.begin() → smallest element
*window.rbegin() → largest element
Both are O(1).
✔ Supports insertion in O(log n)
✔ Supports deletion of ONE specific occurrence in O(log n)
(using erase(window.find(x)))
✔ After insertion/deletion → multiset is still sorted
So you always know the min and max in the window.

🧠 4. Sliding Window + Multiset Approach
This is the full logic:
Step 1: Expand window (move right pointer)
Every time you bring in a new element:
window.insert(nums[right])

Now the window includes nums[left…right].

Step 2: Check validity
while (max - min > limit):
    shrink from left
Where:
max = *window.rbegin()
min = *window.begin()

If the window is invalid:

Shrink it:
window.erase(window.find(nums[left]))
left++

We remove exactly the element leaving the window, not all occurrences.

Step 3: Track maximum length

If window is valid:

maxLen = max(maxLen, right - left + 1)

🧩 5. Why delete only ONE occurrence?

Because the window is:

nums[left], nums[left+1], ..., nums[right]

When you move left to the right, only one element leaves the window.

If nums[left] = 4 and you delete all 4's, the window would lose elements that are still inside it.
That would be completely wrong.

Multiset stores duplicates separately.

Example:
window = {2, 2, 2, 5}
left = 0 → nums[left] = 2

Window after deleting ONE 2:
{2, 2, 5}
Correct.
If you delete ALL 2's → incorrect.


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

        int maxLen = 0;

        int left = 0;
        int right = 0;

        // multiset keeps elements of the current window sorted
        multiset<int> window;

        while (right < n)
        {
            // insert new element into the window (sorted automatically)
            window.insert(nums[right]);

            // while window becomes invalid (difference > limit),
            // shrink it from the left
            while (*window.rbegin() - *window.begin() > limit)
            {
                // erase ONE occurrence of nums[left]
                // because only that element is actually leaving the window
                window.erase(window.find(nums[left]));

                // move left pointer ahead
                left++;
            }

            // current window [left, right] is valid
            // update maximum length
            maxLen = max(maxLen, right - left + 1);

            // expand window by moving right pointer
            right++;
        }

        return maxLen;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sliding Window + Balanced BST (Multiset)

or

Two-pointer + Ordered Data Structure

This is used in problems where the window must maintain min and max values dynamically.


*/