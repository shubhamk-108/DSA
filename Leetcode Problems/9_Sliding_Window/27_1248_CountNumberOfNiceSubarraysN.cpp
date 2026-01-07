/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
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
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j] % 2;
                if (sum == k)
                    count++;
                if (sum > k)
                    break;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 2, 5, 8, 5, 7, 9, 4, 4, 3};
    cout << sol.numberOfSubarrays(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// why convert to parity bit nums[i] = nums[i] % 2 , array of 0 and 1
//___________________________________________________________________________________________________________________________________________

/*

If we convert this nums arrays to 0 and 1, 0 for even and odd for 1 then this question is count the subarray of ones having sum
equal to k. And then this question is exactly same as letcode 560. Count subarray sum equal to k.

*/

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________


/*
time : 
O(n²)

Space Complexity
O(1)


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Use two nested loops:
Outer loop picks starting index i
Inner loop extends subarray from i to j
Maintain sum = number of odd numbers in the subarray nums[i..j]
Each time:
Convert current element to parity nums[j] % 2
Add to sum
If sum == k → we found a valid subarray, increase count
If sum > k → break early (no need to extend further)
Return the final count
This brute force checks all subarrays starting from each index.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;

        // Try every possible starting index i
        for (int i = 0; i < n; i++)
        {
            int sum = 0;  // counts how many odd numbers in current subarray

            // Extend the subarray from i → j
            for (int j = i; j < n; j++)
            {
                // Convert number to parity: even=0, odd=1
                sum += nums[j] % 2;

                // If exactly k odd numbers found, this is a valid subarray
                if (sum == k)
                    count++;

                // If odd count becomes greater than k, no need to continue this subarray
                if (sum > k)
                    break;
            }
        }

        return count;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

“Enumerate All Subarrays” Pattern


*/
