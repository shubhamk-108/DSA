/*
You are given a 0-indexed integer array nums. In one operation, you can:

Choose two different indices i and j such that 0 <= i, j < nums.length.
Choose a non-negative integer k such that the kth bit (0-indexed) in the binary representation of nums[i] and nums[j] is 1.
Subtract 2k from nums[i] and nums[j].
A subarray is beautiful if it is possible to make all of its elements equal to 0 after applying the above operation any number of times (including zero).

Return the number of beautiful subarrays in the array nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Note: Subarrays where all elements are initially 0 are considered beautiful, as no operation is needed.



Example 1:

Input: nums = [4,3,1,2,4]
Output: 2
Explanation: There are 2 beautiful subarrays in nums: [4,3,1,2,4] and [4,3,1,2,4].
- We can make all elements in the subarray [3,1,2] equal to 0 in the following way:
  - Choose [3, 1, 2] and k = 1. Subtract 21 from both numbers. The subarray becomes [1, 1, 0].
  - Choose [1, 1, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 0, 0].
- We can make all elements in the subarray [4,3,1,2,4] equal to 0 in the following way:
  - Choose [4, 3, 1, 2, 4] and k = 2. Subtract 22 from both numbers. The subarray becomes [0, 3, 1, 2, 0].
  - Choose [0, 3, 1, 2, 0] and k = 0. Subtract 20 from both numbers. The subarray becomes [0, 2, 0, 2, 0].
  - Choose [0, 2, 0, 2, 0] and k = 1. Subtract 21 from both numbers. The subarray becomes [0, 0, 0, 0, 0].
Example 2:

Input: nums = [1,10,4]
Output: 0
Explanation: There are no beautiful subarrays in nums.

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
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int xorOfSubarray = 0;
            for (int j = i; j < n; j++)
            {
                xorOfSubarray ^= nums[j];
                if (xorOfSubarray == 0)
                    count++;
            }
            
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {4, 3, 1, 2, 4};
    cout << sol.beautifulSubarrays(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²)

Outer loop runs n times

Inner loop runs up to n times

Total subarrays = n(n+1)/2 → O(n²)

Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We fix a start index i and expand the subarray toward the right (j = i..n-1) while maintaining a running XOR.
For every subarray nums[i..j], we compute:
xor ^= nums[j]

If at any point the XOR becomes 0, then the subarray nums[i..j] is beautiful and we increment the count.
This checks all possible subarrays and counts the ones whose XOR is 0.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

using namespace std;

class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        // Fix the start index of subarray
        for (int i = 0; i < n; i++)
        {
            int xorOfSubarray = 0;  // running XOR for subarray starting at i

            // Expand the subarray to the right
            for (int j = i; j < n; j++)
            {
                xorOfSubarray ^= nums[j];  // update XOR with current element

                // If XOR becomes 0, this subarray is beautiful
                if (xorOfSubarray == 0)
                    count++;
            }
        }

        return count;  // total number of beautiful subarrays
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Pattern: Subarray enumeration + Running XOR
Classic brute-force technique
Fix start index → expand end index
Maintain running XOR without recomputing from scratch

*/
