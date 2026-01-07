/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1
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
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int  i = 0; i < nums.size(); i++)
        {
            res ^= nums[i] ;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2,2,1};
    cout << sol.singleNumber(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Aspect	Details
Approach	XOR all numbers, duplicates cancel
Time Complexity	O(n)
Space Complexity	O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use the XOR operator (^) to cancel out duplicate numbers.
Properties of XOR that make this work:
x ^ x = 0 → duplicates cancel each other
x ^ 0 = x → single number remain
XOR is commutative and associative, so order doesn’t matter
Steps:
Initialize res = 0.
Traverse the array and XOR each element with res.
After processing all elements, duplicates cancel out, leaving the single number in res.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0; // Initialize XOR accumulator

        // Traverse all numbers and XOR them
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i]; // XOR duplicates cancel out
        }

        // res now contains the single number
        return res;
    }
};


*/
