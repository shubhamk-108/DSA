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

        vector<int> prefixMul(n);
        vector<int> suffixMul(n);

        int left = 1;
        for (int i = 0; i < n; i++)
        {
            prefixMul[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            suffixMul[i] = right;
            right *= nums[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            res[i] = prefixMul[i] * suffixMul[i];
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

Time Complexity: 
O(n)
There are three separate passes over the array (prefix, suffix, and final multiplication), each taking linear time.​

Space Complexity: 
O(n) extra
Two additional arrays (prefixMul and suffixMul), each of size n
n. If the output array is not counted as extra, still 
O(n) from the prefix and suffix arrays


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Prefix Product Array (prefixMul)
prefixMul[i] stores the product of all elements before index i.
Start with left = 1 (since before the first element, there’s nothing).
Update prefixMul[i] = left, then multiply left *= nums[i].
Suffix Product Array (suffixMul)
suffixMul[i] stores the product of all elements after index i.
Start with right = 1 (since after the last element, there’s nothing).
Update suffixMul[i] = right, then multiply right *= nums[i].
Combine Both
For each index i, the product except self is
res[i] = prefixMul[i] * suffixMul[i].

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

        // prefixMul[i] = product of all elements to the left of i (exclusive)
        vector<int> prefixMul(n);
        // suffixMul[i] = product of all elements to the right of i (exclusive)
        vector<int> suffixMul(n);

        int left = 1;
        // Build prefixMul array
        for (int i = 0; i < n; i++)
        {
            prefixMul[i] = left; // Store the product so far (left of i)
            left *= nums[i];     // Update cumulative product for next position
        }

        int right = 1;
        // Build suffixMul array
        for (int i = n - 1; i >= 0; i--)
        {
            suffixMul[i] = right; // Store the product so far (right of i)
            right *= nums[i];     // Update cumulative product for next position
        }
        
        // Multiply left and right products for each index
        for (int i = 0; i < n; i++)
        {
            res[i] = prefixMul[i] * suffixMul[i];
        }

        return res;
    }
};



*/
