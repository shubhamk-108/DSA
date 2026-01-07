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

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
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
Outer loop runs n times
Inner loop can also run up to n times
👉 Worst-case time complexity:
O(n²)


🧠 Space Complexity
Uses only constant extra variables
In-place swapping
👉 Space complexity:

O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Traverse the array from left to right using index i.
For each position i, search from index i to the end (j = i … n-1) for the first even number.
When an even number is found:
Swap it with nums[i]
Stop searching further for this i (using break)
Repeat until all possible even numbers are moved to the front.
Odd numbers automatically shift toward the right.

Why this works:
After each iteration i, the subarray nums[0..i] contains only even numbers (as long as evens are available).


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

        // Fix the position i where we want an even number
        for (int i = 0; i < n; i++)
        {
            // Search for an even number from i to the end
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    // Place the even number at position i
                    swap(nums[j], nums[i]);
                    break; // move to the next position i
                }
            }
        }
        return nums;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force / Selection-Based Partitioning
Similar idea to Selection Sort


*/
