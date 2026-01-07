

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
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

// Chatgpt says this code is wrong. Please check before understanding it.
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (nums[left] == 0)
            {
                swap(nums[0], nums[left]);
                if (nums[left] == 0)
                    left++;
            }
            else if (nums[left] == 2)
            {
                swap(nums[left], nums[right]);
                if (nums[left] != 2)
                {
                    left++;
                    right--;
                }
            }
            else
                left++;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sol.sortColors(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*




*/
