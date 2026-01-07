// I got error in below code (corrected code is at the end)
// Because
// for (auto x : nums) {
//             arr_sum += x;

//             x = -x;
//         }
// This is changing temporary vector and not the original vector so
// use & here. auto & x : nums.

// And second is
// int maxEnding = nums[0];

//         for (auto x : nums) {
//             maxEnding = max(maxEnding + x, x);

//             res = max(maxEnding, res);
//         }
// here 0th element is already covered so we can not use auto loop
// we have to use regular for loop.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

// wrong code

class Solution
{
public:
    int normalMaxSum(vector<int> nums, int n)
    {
        int res = nums[0];

        int maxEnding = nums[0];

        for (auto x : nums)
        {
            maxEnding = max(maxEnding + x, x);

            res = max(maxEnding, res);
        }

        return res;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();

        int max_normal = normalMaxSum(nums, n);

        if (max_normal < 0)
            return max_normal;

        int arr_sum = 0;

        for (auto x : nums)
        {
            arr_sum += x;

            x = -x;
        }

        int max_circular = arr_sum + normalMaxSum(nums, n);

        return max(max_circular, max_normal);
    }
};

// corrected code:

class Solution
{
public:
    int normalMaxSum(vector<int> &nums, int n)
    {
        int res = nums[0];

        int maxEnding = nums[0];

        for (int i = 1; i < n; i++)
        {
            maxEnding = max(maxEnding + nums[i], nums[i]);

            res = max(maxEnding, res);
        }

        return res;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();

        int max_normal = normalMaxSum(nums, n);

        if (max_normal < 0)
            return max_normal;

        int arr_sum = 0;

        for (auto &x : nums)
        {
            arr_sum += x;

            x = -x;
        }

        int max_circular = arr_sum + normalMaxSum(nums, n);

        return max(max_circular, max_normal);
    }
};