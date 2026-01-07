/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
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
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        int distinctCount = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                distinctCount++;
            }
            if (distinctCount == 3)
            {
                return nums[i];
            }
        }

        return nums[0];
    }
};
int main()
{
    Solution sol;
    vector<int> v = {5,2,9,1,1,2,2,2,2};
    cout << sol.thirdMax(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity:
Sorting → O(n log n)
One linear scan → O(n)
Overall: O(n log n)

Space Complexity:
Sorting is in-place → O(1) extra spac
(unless counting temporary stack for quicksort, which is typically ignored)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Sort the array in descending order.
Iterate through it and count distinct elements.
When the third distinct number is found, return it.
If there are fewer than 3 distinct numbers, return the first element (largest).

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>()); // sort descending

        int distinctCount = 1; // nums[0] is the first distinct maximum

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                distinctCount++;
            }
            if (distinctCount == 3)
            {
                return nums[i]; // found 3rd distinct max
            }
        }

        // fewer than 3 distinct numbers → return largest
        return nums[0];
    }
};


*/
