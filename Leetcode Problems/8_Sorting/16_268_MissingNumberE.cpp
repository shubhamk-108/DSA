/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

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
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {3, 0, 1};
    cout << sol.missingNumber(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

O(n log n)
Sorting takes O(n log n)
Loop takes O(n)

🧠 Space Complexity
O(1) extra space
(Ignoring sorting’s internal stack usage, as per interview/LC convention)
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

The array contains n distinct numbers in the range [0, n]
First, sort the array
After sorting, every number should ideally match its index:
At index 0 → value should be 0
At index 1 → value should be 1
…
The first index i where nums[i] != i is the missing number
If all indices match (0 to n-1), then the missing number is n


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // Size of the array
        int n = nums.size();

        // Sort the array so numbers are in increasing order
        sort(nums.begin(), nums.end());

        // Check each index to see if value matches the index
        for (int i = 0; i < n; i++)
        {
            // If mismatch found, index is the missing number
            if (nums[i] != i)
                return i;
        }

        // If all values from 0 to n-1 are present,
        // then the missing number is n
        return n;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Sorting + Index Mapping Pattern
Also commonly described as:
"Sort and Compare with Expected Sequence"
Or "Mismatch Detection after Sorting"


*/
