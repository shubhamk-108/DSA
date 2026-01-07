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
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < n - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                nums[n - 1] = 0;
                n--;
            }
            else
                i++;
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

Time Complexity: O(n²)

Space Complexity
Only variables i, j, and n are used.
Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Use a while loop to traverse the array.
Whenever a zero is found at nums[i]:
Shift all elements to the left starting from i.
Put a zero at the end of the array.
Decrease the effective array size (n--).
Do not increment i because the new element at index i could also be zero.
If the element is non-zero → increment i.
This ensures all zeros are moved to the end while preserving the order of non-zero elements.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] == 0) {
                // Shift all elements after i to the left
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                // Put zero at the end
                nums[n - 1] = 0;
                n--; // reduce effective array size
                // Do NOT increment i; new element at i might be zero
            } else {
                i++; // move to next element if current is non-zero
            }
        }
    }
};



*/
