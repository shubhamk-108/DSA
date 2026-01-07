/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
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
    void moveZeroes(vector<int> &nums)
    {
        int writePtr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[writePtr]);
                writePtr++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 1, 0, 3, 12};
    sol.moveZeroes(v);
    for (auto x : v)
        cout << x << " ";

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n) — traverse the array once.
O(1) — in-place, no extra array used.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Use a write pointer (writePtr) to track the next position for a non-zero element.
Traverse the array once:
If the current element nums[i] is non-zero, swap it with nums[writePtr].
Increment writePtr.
After the traversal, all non-zero elements are at the front (order preserved), and zeros are moved to the end.
This is a single-pass, in-place algorithm.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int writePtr = 0; // Next position to place a non-zero element

        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            // If current element is non-zero, swap it with the element at writePtr
            if (nums[i] != 0)
            {
                swap(nums[i], nums[writePtr]);
                writePtr++; // Move writePtr to the next position
            }
        }
        // All zeros are automatically moved to the end
    }
};



*/
