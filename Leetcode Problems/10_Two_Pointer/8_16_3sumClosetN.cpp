/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum;
        int difference = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    int a = nums[i]+nums[j]+nums[k] ;
                    if(abs(target - a) < difference)
                    {
                        difference = abs(target - a);
                        sum = a;
                    }
                }
                
            }
            
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {-1, 2, 1, -4};
    cout << sol.threeSumClosest(v, 1);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity: O(n³)
You use three nested loops, each going up to n.
Space Complexity: O(1)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Iterate through every possible triplet using three nested loops.
Compute the sum of each triplet.
Compare how close this sum is to the target using absolute difference.
Keep the triplet with the smallest difference.
Return the sum of that best triplet.
This guarantees correctness because it checks all combinations.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum;                         // will store the best (closest) sum
        int difference = INT_MAX;        // store minimum difference found so far

        // Try all combinations of three numbers
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // sum of current triplet
                    int a = nums[i] + nums[j] + nums[k];

                    // check if this sum is closer to target
                    if (abs(target - a) < difference)
                    {
                        difference = abs(target - a); // update minimum difference
                        sum = a;                      // update closest sum
                    }
                }
            }
        }

        // return the sum closest to target
        return sum;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force Enumeration Pattern
Also known as "Generate all combinations"
Tries every possible set of 3 numbers.

*/
