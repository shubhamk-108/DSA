/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
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
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSubarrayCount = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> freq;

            for (int j = i; j < n; j++)
            {
                freq.insert(nums[j]);
                if (freq.size() == k)
                    maxSubarrayCount++;
                if (freq.size() > k)
                    break;
            }
        }
        return maxSubarrayCount;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 1, 2, 3};
    cout << sol.subarraysWithKDistinct(v, 2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²)
Outer loop runs n times.
Inner loop may run up to n times → O(n²).
Set insertion is O(1) average.
Space Complexity: O(k)
The set freq stores at most k+1 elements before breaking.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Loop over all starting points i.
For each i, grow subarray to the right with j.
Keep a set of distinct elements in the current subarray.
If set size == K → count it.
If set size > K → stop expanding (break).


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSubarrayCount = 0;

        // Start every subarray from index i
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> freq;  // stores distinct numbers in current subarray

            // Extend subarray to the right
            for (int j = i; j < n; j++)
            {
                freq.insert(nums[j]);   // include nums[j] into the set

                if (freq.size() == k)
                    maxSubarrayCount++;  // valid subarray with exactly k distinct

                if (freq.size() > k)
                    break; // no need to extend further (it will only increase distinct count)
            }
        }

        return maxSubarrayCount;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Brute Force Enumeration of Subarrays
Try all possible (i, j) pairs.
Use a set to track distinct elements.
Pattern name: “Brute Force + Distinct Counting”

*/
