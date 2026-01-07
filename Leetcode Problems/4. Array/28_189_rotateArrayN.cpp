/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
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
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        for (int j = 0; j < k; j++)
        {
            int last = nums[n - 1];
            for (int i = n - 1; i > 0; i--)
            {
                nums[i] = nums[i - 1];
            }
            nums[0] = last;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {7, 12, 9, 3, 1,8 , 5, 13};
    sol.rotate(v, 21);
    for (auto x : v)
        cout << x << " ";
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


The goal is to rotate the array to the right by k steps.
In the brute-force method, we rotate the array one step at a time, and we repeat this process k times.
Each single rotation involves:
Saving the last element.
Shifting every other element one position to the right.
Placing the saved last element at the first index.
This ensures that after k full rotations, every element has moved k steps to the right.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


// Brute Force Solution for LeetCode 189: Rotate Array
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();

        // Handle cases where k >= n
        k = k % n;

        // Perform k single-step rotations
        for (int j = 0; j < k; j++)
        {
            // Store the last element before shifting
            int last = nums[n - 1];

            // Shift all elements one step to the right
            for (int i = n - 1; i > 0; i--)
            {
                nums[i] = nums[i - 1];
            }

            // Place the previously last element at the front
            nums[0] = last;
        }
    }
};


*/
