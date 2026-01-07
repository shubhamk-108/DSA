/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);

        int left = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 3, 4, 5}; // 60,40,30,24
    vector<int> res = sol.productExceptSelf(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Type                 | Complexity | Explanation                                                                               |
| -------------------- | ---------- | ----------------------------------------------------------------------------------------- |
| **Time Complexity**  | **O(n)**   | Two single passes through the array (left → right and right → left).                      |
| **Space Complexity** | **O(1)**   | No extra arrays — only output vector `res` is used (output doesn’t count as extra space). |



*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Compute prefix products (product of all elements to the left of i).
Then compute suffix products (product of all elements to the right of i).
Multiply both to get the final answer — but do it in-place using a single result array (res), saving extra space.

Dont use two different vectors to store prefix mul and suffix mul.
Whatever is prefix mul , store it in res vector. Then we need suffix mul, but we can generate suffixmul and multiply to the res
and store in res itself. SO no need to use sepetare vector to store suffixMul.

Don't use two separate vectors for prefix and suffix products. Store the prefix product directly in res as you compute it.
Then generate the suffix product on the fly (iterate right-to-left) and multiply it into res at each step. This removes the need for
a separate suffixMul array.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);

        // Step 1: Build prefix products directly into res
        // res[i] will hold product of all elements to the left of i
        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = prefix;     // product of all elements before index i
            prefix *= nums[i];   // update prefix for next iteration
        }

        // Step 2: Multiply res[i] with suffix products (right to left)
        // No extra array needed — use a running suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= suffix;    // multiply with product of elements after index i
            suffix *= nums[i];   // update suffix for next iteration
        }

        return res;
    }
};


*/
