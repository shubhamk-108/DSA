/*
Given a sorted array arr[] and an integer k, find the position(0-based indexing) at which k is present in the array using binary search. If k doesn't exist in arr[] return -1.

Note: If multiple occurrences are there, please return the smallest index.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.
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
    int binarysearch(vector<int> &nums, int target)
    {
        // code here
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = -1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;

            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

// time : O(logn)
// space : O(1)