/*
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
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
//naive 2
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {

        int n = nums.size();
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> sett;
            for (int j = i; j < n; j++)
            {
                sett.insert(nums[j]);
                if (sett.size() == totalUnique)
                    res++;
            }
        }

        return res;
    }
};

// int main()
// {
//     Solution sol;
//     vector<int> v = {1, 3, 1, 2, 2};
//     cout << sol.countCompleteSubarrays(v);
// }

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time: O(n²)
Because you check all subarrays.

Space: O(n)
Because of the temporary sett.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

For every start index i,
You expand j,
Insert each element into a unordered_set to track unique elements,
And whenever the number of unique elements equals totalUnique, you increment res.
This is exactly how a correct brute-force solution should behave.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {

        int n = nums.size();
        int res = 0;

        // Find how many unique numbers exist in the entire array
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();   // this many unique numbers must exist in a "complete" subarray

        // Fix starting index i
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> sett;   // will store unique elements inside current subarray

            // Expand the subarray from i to j
            for (int j = i; j < n; j++)
            {
                sett.insert(nums[j]);  // insert element into current subarray set

                // If this subarray contains all unique numbers of the whole array
                if (sett.size() == totalUnique)
                    res++;             // then this subarray is "complete"
            }
        }

        return res;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

bruteforce checking every combination


*/