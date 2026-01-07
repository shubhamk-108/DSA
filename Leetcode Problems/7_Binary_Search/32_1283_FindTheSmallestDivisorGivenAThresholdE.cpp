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

        int low = 1;
        int high = maxEle;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int i = 0; i < n; i++)
            {
                sum += (nums[i] + mid - 1) / mid;
            }

            if (sum <= threshold)
                high = mid;
            else
                low = mid + 1;
        }
        return high;
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

O(n · log(max(nums)))
For each mid we compute the sum in O(n)
We binary search in the range [1 … max(nums)] → about log₂(max(nums)) steps

Space Complexity
O(1)

Only a few integer variables → constant space.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


We need to find the smallest divisor such that:
∑ i=0 to n−1 [nums[i] / divisor ] <= threshold
Key insights:
Divisor affects the sum in a monotonic way
Bigger divisor → each term becomes smaller → total sum decreases.
Smaller divisor → sum increases.
Because of this monotonic property, we can apply Binary Search on the divisor.
Our search space for divisor is:
min = 1
max = max_element(nums)
(because divisor larger than the max element will always make every term become 1)
For each candidate divisor mid:
Compute the sum using ceil(nums[i] / mid).
If the sum is within threshold, it is valid, but we try to find a smaller divisor → move left.
Otherwise, it’s invalid → move right.
At the end, low == high, and that is the smallest valid divisor.

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

        // Largest possible divisor we ever need to test
        int maxEle = *max_element(nums.begin(), nums.end());

        // Search space for divisor: [1, maxEle]
        int low = 1;
        int high = maxEle;

        while (low < high)
        {
            // Mid candidate divisor
            int mid = low + (high - low) / 2;

            int sum = 0;

            // Compute sum of ceilings: ceil(nums[i] / mid)
            for (int i = 0; i < n; i++)
            {
                // Ceil division trick: (a + b - 1) / b
                sum += (nums[i] + mid - 1) / mid;
            }

            // If the sum is within threshold, it's valid
            // Try to minimize divisor (search left)
            if (sum <= threshold)
                high = mid;

            // Otherwise, divisor is too small (sum too large)
            //when we want lesser sum, we need to increase the divisor becasuse for ex 6/1 = 6 but 6/2 = 3. 
            else (sum > threshold)
                low = mid + 1;
        }

        // low == high holds the smallest valid divisor
        return high;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer (also called Search Space Reduction)
We are not binary-searching an array.
We are binary-searching the solution space (possible divisors).


*/
