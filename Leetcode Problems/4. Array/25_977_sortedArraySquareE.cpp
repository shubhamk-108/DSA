/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.



Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
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
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        int right = n - 1;
        int i = n - 1;
        while (i >= 0)
        {
            if (abs(nums[left]) >= abs(nums[right]))
            {
                res[i] = (nums[left] * nums[left]);
                i--;
                left++;
            }
            else
            {
                res[i] = (nums[right] * nums[right]);
                right--;
                i--;
            }
        }

        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {-7,-3,2,3,11};
    vector<int> res = sol.sortedSquares(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
(O(n)) time
O(1) space to store res.


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


The input array nums is already sorted in non-decreasing order.
Squaring numbers can change order because negative values (like -4) become large positives.
You use two pointers:
left → start of the array
right → end of the array
Compare the absolute values at both ends:
The larger absolute value’s square goes at the end (res[i]).
Move the corresponding pointer inward.
Decrement i each time, filling res from back to front.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

// Efficient O(n) solution for LeetCode 977: Squares of a Sorted Array
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);      // Result vector to store sorted squares
        int left = 0;            // Pointer to the start of the array
        int right = n - 1;       // Pointer to the end of the array
        int i = n - 1;           // Position to fill from the end in result

        // Since the input array is sorted, the largest square will come from
        // either the leftmost (most negative) or rightmost (most positive) element.
        while (i >= 0)
        {
            // Compare absolute values of elements at both ends
            if (abs(nums[left]) >= abs(nums[right]))
            {
                // If left absolute value is larger, square it and place at res[i]
                res[i] = nums[left] * nums[left];
                left++; // Move left pointer inward
            }
            else
            {
                // Otherwise, square the right element and place it
                res[i] = nums[right] * nums[right];
                right--; // Move right pointer inward
            }

            // Move to the next position from the end
            i--;
        }

        // The result vector now contains squares in non-decreasing order
        return res;
    }
};



*/
