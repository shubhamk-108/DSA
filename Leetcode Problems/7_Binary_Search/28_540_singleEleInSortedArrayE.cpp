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
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int low = 1;
        int high = n - 2;

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||( mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << sol.singleNonDuplicate(v);
    return 0;
}

/*

//___________________________________________________________________________________________________________________________________________
// Observation
//___________________________________________________________________________________________________________________________________________


Pairs always start at an even index:

Example:
[1,1,2,2,3,4,4]

Indices:

0 1 2 3 4 5 6
1 1 2 2 3 4 4


Pairs:

1 at (0,1)

2 at (2,3)

4 at (5,6)

👉 Before the single element, pairs follow this rule:
nums[i] == nums[i+1] when i is even.

👉 After the single element, the pattern breaks:
Indices shift, so pairs start at odd indexes.


*/
//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric    | Complexity | Reason                                   |
| --------- | ---------- | ---------------------------------------- |
| **Time**  | `O(log n)` | Binary search halves the range each step |
| **Space** | `O(1)`     | Only constant extra variables            |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The array has these properties:
Every element appears exactly twice
One element appears only once
The array is sorted
This means:
🔹 Before the single element
Pairs start at even indices:
0,1 | 2,3 | 4,5 | ...
🔹 After the single element
Pairs shift and start at odd indices:
1,2 | 3,4 | 5,6 | ...
This change in parity pattern helps us binary-search for the break point.
Steps:
Handle edges
If the single element is at index 0 or index n-1.
Use binary search on indices 1 … n-2
For a position mid:
If nums[mid] is not equal to left or right → this is the unique element.
Otherwise:
If mid is odd and equals left → pairs are correct → go right
If mid is even and equals right → pairs are correct → go right
Else → go left
Binary search guarantees O(log n).

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        // Edge case: only one element
        if (n == 1)
            return nums[0];

        // Edge case: unique element is at the beginning
        if (nums[0] != nums[1])
            return nums[0];

        // Edge case: unique element is at the end
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // If nums[mid] is different from both neighbors, this is the answer
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // Case 1: mid is odd and matches its left → pairs are correct → move right
            // Case 2: mid is even and matches its right → pairs are correct → move right
            else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                     (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
                low = mid + 1;

            // Otherwise, mismatch happened earlier → move left
            else
                high = mid - 1;
        }

        return -1; // Should never reach here in valid input
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Binary Search on Index Parity

*/
