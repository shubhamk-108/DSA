/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.



Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> res;

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            if (nums[left] + nums[right] < target)
                left++;
            else if (nums[left] + nums[right] > target)
                right--;
            else
            {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 7, 11, 15};
    vector<int> res = sol.twoSum(v, 9);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n)
Each element is visited at most once by left or right.
No nested loops.

💾 Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The array is already sorted (given by problem).
Use two pointers:
left starts at the beginning.
right starts at the end.
Compute the sum:
nums[left] + nums[right]
Compare the sum with the target:
If sum < target → move left forward to increase sum.
If sum > target → move right backward to decrease sum.
If sum == target → we found the answer (problem guarantees one solution)
Return the 1-indexed positions.
This works because the array is sorted — so the pointer movements always move you closer to the target.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> res;

        int left = 0;           // Pointer at start of array
        int right = n - 1;      // Pointer at end of array

        // Continue until pointers meet
        while (left < right)
        {
            int sum = nums[left] + nums[right]; // Current pair sum

            if (sum < target)
                left++;         // Need a larger sum → move left rightwards
            else if (sum > target)
                right--;        // Need a smaller sum → move right leftwards
            else
            {
                // Found the exact target sum
                // Convert to 1-indexed output as required by problem
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;    // Only one solution exists, so return
            }
        }

        return res; // Should never reach here because one solution is guaranteed
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*



Pattern: Two Pointers on Sorted Array

This is a classic two-pointer pattern used when:
The input array is sorted.
You need to find pairs/triplets that satisfy a sum or condition.\
You want O(n) performance istead of O(n²).
Problems using same pattern:
LC 167 — Two Sum II
LC 15 — 3Sum
LC 16 — 3Sum Closest
LC 125 — Valid Palindrome
LC 344 — Reverse String
*/
