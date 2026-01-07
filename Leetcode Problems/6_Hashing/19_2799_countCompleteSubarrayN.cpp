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

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {

        int n = nums.size();
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();

        for (int start = 0; start < n; start++)
        {
            for (int end = start; end < n; end++)
            {
                unordered_set<int> subarray;
                for (int between = start; between <= end; between++)
                {
                    subarray.insert(nums[between]);
                }
                if (subarray.size() == totalUnique)
                    res++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 3, 1, 2, 2};
    cout << sol.countCompleteSubarrays(v);
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Time Complexity → O(n³)
Breakdown:
Outer two loops generate all subarrays → O(n²)
For each subarray you insert up to n elements into a set → O(n)
Total = O(n² × n) = O(n³)
This is acceptable for brute-force understanding but too slow for constraints.

💾 Space Complexity → O(n)
The subarray set can store at most n elements
The full-array set also stores at most n elements
So total auxiliary space = O(n)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



First, count how many unique elements exist in the entire array.
This tells us what every “complete subarray” must contain.
Then you generate every possible subarray using two loops:
start = starting index
end = ending index
For each subarray (start → end):
Insert all its elements into a set
Count how many unique elements it ha
If the subarray's unique count equals the total array unique count → it is a complete subarray → increase result.
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

        // Count unique elements in the full array
        unordered_set<int> st(nums.begin(), nums.end());
        int totalUnique = st.size();

        // Try every subarray
        for (int start = 0; start < n; start++)
        {
            for (int end = start; end < n; end++)
            {
                // Set to track uniques in current subarray
                unordered_set<int> subarray;

                // Insert all elements between start and end
                for (int between = start; between <= end; between++)
                {
                    subarray.insert(nums[between]);
                }

                // If unique count matches -> complete subarray
                if (subarray.size() == totalUnique)
                    res++;
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

Pattern: Brute Force + Unique Counting (Set-Based)
Specifically:
Generate all subarrays (classic brute-force)
Count unique elements using a set

*/
