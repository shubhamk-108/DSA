/*
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
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
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        int n = nums.size();

        int i = 0;
        int j = n - 1;

        while (i < j)
        {
            if (nums[i] % 2 == 1)
            {
                swap(nums[i], nums[j]);
                j--;
                if (nums[i] % 2 == 0)
                    i++;
                continue;
            }
            i++;
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {3, 1, 2, 4};
    vector<int> res = sol.sortArrayByParity(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Each element is processed at most once
➡️ O(n)

🧠 Space Complexity
In-place swapping
➡️ O(1) extra space
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use two pointers:
i at the start (looking for odd numbers)
j at the end (looking for even numbers to swap)
While i < j:
If nums[i] is odd, swap it with nums[j]
Decrease j
Recheck nums[i] because a new value came in
If nums[i] is even, move i forward
Continue until pointers cross.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();

        int i = 0;       // left pointer
        int j = n - 1;   // right pointer

        while (i < j)
        {
            // If current element is odd, move it to the right side
            if (nums[i] % 2 == 1)
            {
                swap(nums[i], nums[j]);
                j--;  // right side is fixed now

                // After swap, check if new nums[i] is even
                if (nums[i] % 2 == 0)
                    i++;
                continue;
            }

            // nums[i] is even → correct place
            i++;
        }
        return nums;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two Pointers / Partitioning Pattern
Similar to:
Partition array
Dutch National Flag (simpler version)
Even–Odd segregation


*/
