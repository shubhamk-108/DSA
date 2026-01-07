/*
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.


Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
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
    int countKDifference(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i] - nums[j]) == k)
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 2, 1};
    cout << sol.countKDifference(v, 1);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n²)
Two nested loops → all pairs checked → n * (n-1) / 2.
Space Complexity: O(1)
Only a few integer variables used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


You are using a simple brute-force technique where:
You iterate over all possible pairs (i, j) such that i < j.
For each pair, you check whether
|nums[i] - nums[j]| == k.
If yes, increment the count.
Return the total count.
This checks every pair exactly once, ensuring correctness for small input sizes.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();

        // Loop over each element
        for (int i = 0; i < n; i++)
        {
            // Check only forward pairs to avoid duplicates
            for (int j = i + 1; j < n; j++)
            {
                // If absolute difference equals k, count it
                if (abs(nums[i] - nums[j]) == k)
                    count++;
            }
        }

        return count; // Return total valid pairs
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*
This is the simplest pattern for pair-related problems:
Check every pair
Apply a condition
Count matches


*/
