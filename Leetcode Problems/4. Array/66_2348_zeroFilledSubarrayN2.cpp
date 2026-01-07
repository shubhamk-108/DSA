
/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.

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
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; i++)
        {

            // expand subarray from i
            for (int j = i; j < n; j++)
            {

                if (nums[j] != 0)
                    break;
                else if (nums[i] == 0)
                    count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 0, 0, 2, 0, 0, 4};
    cout << sol.zeroFilledSubarray(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Type      | Complexity                                            |
| --------- | ----------------------------------------------------- |
| **Time**  | **O(n²)** — worst case when entire array is all zeros |
| **Space** | **O(1)** — no extra memory used                       |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


You fix a starting index i and then expand the subarray to the right (j = i...n-1).
If you ever hit a non-zero, you immediately break.
For every j where nums[j] == 0, you count it as one valid zero-filled subarray starting at i.
This effectively counts:
[0]
[0,0]
[0,0,0]
… starting from each zero.
This brute-force correctly enumerates all zero-only subarrays.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

long long zeroFilledSubarray(vector<int> &nums) {
    long long n = nums.size();
    long long count = 0;

    // Choose each index i as starting point
    for (int i = 0; i < n; i++) {

        // Expand the subarray starting from i
        for (int j = i; j < n; j++) {

            // If any non-zero appears, no more zero-subarrays possible from i
            if (nums[j] != 0)
                break;

            // nums[j] == 0, so this forms a valid zero-filled subarray [i..j]
            count++;
        }
    }

    return count;
}



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute. Try every combination


*/
