/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
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
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();

        int maxEle = *max_element(nums.begin(), nums.end());

        int lowestDiv = INT_MAX;

        for (int div = 1; div <= maxEle; div++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += (nums[j] + div - 1) / div;
            }
            if (sum <= threshold)
                lowestDiv = min(lowestDiv, div);
        }
        return lowestDiv;
    }
};
int main()
{
    Solution sol;
    vector<int> v = {1, 2, 5, 9};
    cout << sol.smallestDivisor(v, 6);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
time:
O(n × max(nums))

Space Complexity
O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
The goal is to find the smallest divisor such that:
∑ i=0 to n−1 [nums[i] / divisor ] <= threshold
Brute force means:
Try every possible divisor from 1 to max(nums).
For each divisor div, compute the sum using ceiling division:
If the total sum is ≤ threshold, this divisor is valid.
Track the smallest valid divisor and return it at the end.
This guarantees correctness because you test every possible divisor.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*



class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();

        // The maximum divisor we ever need to check is the largest number in nums
        int maxEle = *max_element(nums.begin(), nums.end());

        // Initialize with a very large value
        int lowestDiv = INT_MAX;

        // Try all divisors from 1 to maxEle
        for (int div = 1; div <= maxEle; div++)
        {
            int sum = 0;

            // Compute the sum of ceil(nums[j] / div)
            for (int j = 0; j < n; j++)
            {
                // Efficient ceil division formula
                sum += (nums[j] + div - 1) / div;
            }

            // If this divisor keeps the sum <= threshold,
            // update the smallest valid divisor
            if (sum <= threshold)
                lowestDiv = min(lowestDiv, div);
        }

        // Return the smallest valid divisor
        return lowestDiv;
    }
};

*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*


Linear Search on Answer

*/
