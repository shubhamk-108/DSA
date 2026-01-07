/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array
Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
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
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int count = 0;

        for (int len = 1; len <= n; len++)
        {
            for (int start = 0; start + len <= n; start++)
            {
                int sum = 0;
                for (int k = 0; k < len; k++)
                {
                    sum += nums[start + k];
                }
                if (sum == goal)
                    count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(v, goal);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time:

Outer loop: n
Middle loop: n
Inner loop: n
Total: O(n³)
Space:
Only a few variables → O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop over every possible subarray length from 1 to n.
For each length, slide a window by varying the start index from 0 to n - len.
For each window, compute the sum by iterating k from 0 to len-1.
If the sum equals the goal, increase the count.
Return the total count after checking all subarrays.
This brute force tries every single subarray and checks its sum.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

for (int len = 1; len <= n; len++) 
    // Correct: generates all possible subarray lengths (1 to n)

for (int start = 0; start + len <= n; start++)
    // Correct sliding window of fixed length "len"

for (int k = 0; k < len; k++)
    sum += nums[start + k];
    // Correct element access for each window

if (sum == goal)
    count++;
    // Correct condition check



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force Subarray Enumeration
(Generate all subarrays by length & starting index)


*/
