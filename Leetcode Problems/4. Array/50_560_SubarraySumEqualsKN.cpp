/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<unordered_set>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum+=nums[j];
                if(sum == k)
                    count++;
            }
            
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {3, 2, 1, 1, 4, 5};
    int k = 5;
    cout << sol.subarraySum(v, k);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Fix a starting index i.
Expand the subarray to the right with j.
Maintain a running sum of elements from i to j
Each time sum == k, increment the count.
This method directly checks all contiguous subarrays.
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

O(n²) — two nested loops.
Each subarray sum is computed incrementally.

Space Complexity
O(1) — constant extra space.


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        // Fix the starting index of the subarray
        for (int i = 0; i < n; i++)
        {
            int sum = 0; // stores cumulative sum of subarray starting at index i

            // Extend the subarray to include elements from i to j
            for (int j = i; j < n; j++)
            {
                sum += nums[j]; // add current element to running sum

                // If current subarray sum equals k, increment count
                if (sum == k)
                    count++;
            }
        }

        // Return total count of subarrays whose sum equals k
        return count;
    }
};


*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

🧩 Pattern Used
Brute-force + incremental prefix accumulation (foundation for prefix-sum optimization).


*/

