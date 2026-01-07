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

        int actualSum = (n * (n + 1)) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        return actualSum - sum;
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

Time Complexity
O(n) → single pass through the array

🧠 Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Numbers are from 0 to n
Exactly one number is missing
Sum of 0..n = n*(n+1)/2
Subtract the sum of array elements → missing number


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
        int n = nums.size();

        // Expected sum of numbers from 0 to n
        int actualSum = (n * (n + 1)) / 2;

        // Sum of elements present in the array
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        // Missing number
        return actualSum - sum;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Mathematical / Arithmetic Sum Pattern
Also considered:
Formula-based optimization

*/
