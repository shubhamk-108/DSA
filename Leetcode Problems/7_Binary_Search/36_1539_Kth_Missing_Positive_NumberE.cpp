/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
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
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int expectedValueAtMid = mid + 1;
            int missingTillMid = arr[mid] - expectedValueAtMid;

            if (missingTillMid >= k)
                high = mid - 1;
            else if (missingTillMid < k)
                low = mid + 1;
        }
        return low + k;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 4, 7, 11};
    cout << sol.findKthPositive(v, 5);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Explanation
//___________________________________________________________________________________________________________________________________________
/*

🔥 PART 1 — Understanding the formula: missingUntilMid = arr[mid] − (mid + 1)

If no numbers were missing:

index: 0 1 2 3 ...
value: 1 2 3 4 ...


So expected value at index mid is:

expected = mid + 1


But actual value is arr[mid].

The difference:

arr[mid] - (mid + 1)


tells how many numbers have been skipped (missing) from 1 up to arr[mid].

Example:
arr = [2, 3, 5, 6]

At index 2 (value 5):

expected = 2+1 = 3
missing = 5 − 3 = 2 missing numbers (1 and something else?)
→ Actually: missing are {1,4}

Correct.

So the formula works.

🔥 PART 2 — What are we searching for?

We want the first index where:

missingUntilMid >= k


Why?

If missingUntilMid < k → we haven’t seen enough missing numbers yet → go Right

If missingUntilMid >= k → we passed the k-th missing number → go Left

Finally, low will stop at the position where k missing numbers would occur.

🔥 PART 3 — What does low represent at the end?

After the binary search ends:

✔ low = number of elements in arr that are ≤ the final answer.

This is the key intuition.

Example:

arr = [2, 3, 4, 7, 11]
missing = {1, 5, 6, 8, 9, 10, 12, ...}

Suppose we want the 5-th missing number → answer = 9.

How many elements in arr are ≤ 9?

{2,3,4,7} → 4 elements.

binary search will end with:

low = 4


So low counts how many existing numbers are smaller than the missing value.

That’s why we add:

low (existing numbers before answer) +
k   (total missing numbers to skip)


This gives:

answer = low + k


Example:

low = 4
k = 5
answer = 4 + 5 = 9


Correct.

🔥 PART 4 — Why exactly low + k works? (THE DEEP INTUITION)

Let’s rewrite the problem in mathematical terms:

We want the smallest x such that:

missing numbers before x = k


Missing numbers before x =

(x - 1) - (count of elements in arr <= x)


Let:

count of elements in arr <= x = low


Plug this into the formula:

missing = (x - 1) - low


Set this equal to k:

(x - 1) - low = k


Solve for x:

x - 1 = k + low
x = k + low + 1


But in our binary search, num is always 1-based shifted, so the final simplification becomes:

answer = low + k


And that is exactly what we return.

🔥 PART 5 — Step-by-step Example

Let arr = [2,3,4,7,11], k = 5
Missing = {1,5,6,8,9,…}

We want the 5th → 9.

Binary search finds that low = 4.

So:

low + k = 4 + 5 = 9


Which matches the correct answer.
*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(log n)
Binary search

Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If no numbers were missing,
            // arr[mid] should have been equal to mid + 1.
            int expectedValue = mid + 1;

            // How many numbers are missing until index mid?
            // Example:
            // arr = [2,3,4] → at mid=0: missing = 2 - 1 = 1 (missing {1})
            int missingUntilMid = arr[mid] - expectedValue;

            // If missing numbers before mid are already >= k,
            // then the kth missing number is on the LEFT side.
            if (missingUntilMid >= k)
            {
                high = mid - 1;
            }
            else
            {
                // Otherwise, kth missing is to the RIGHT side.
                low = mid + 1;
            }
        }

        // After binary search:
        // 'low' tells how many numbers are NOT missing before the answer.
        // Add k to get the actual missing number.
        return low + k;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer Space


*/
