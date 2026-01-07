/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

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
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 1, 3, 4, 2};
    // cout << sol.findDuplicate(v);
    cout << 8 % 5;
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n)
Space: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Treat the array as a linked list:

Each index points to the next index using nums[i].

Since numbers are from 1…n and size is n+1, a cycle must exist.

The duplicate number is the entry point of the cycle.

Phase-1:
Tortoise moves 1 step, hare moves 2 steps until they meet inside cycle.

Phase-2:
Reset slow to start. Both move 1 step.
The point they meet again = duplicate number.
*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: find intersection point inside cycle
        do
        {
            slow = nums[slow];           // move 1 step
            fast = nums[nums[fast]];     // move 2 steps
        } while (slow != fast);

        // Phase 2: find entry of the cycle
        slow = nums[0];                  // reset slow to start
        while (slow != fast)
        {
            slow = nums[slow];           // both move 1 step
            fast = nums[fast];
        }

        return slow;                     // intersection = duplicate
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




Floyd’s Cycle Detection (Tortoise & Hare)

*/
