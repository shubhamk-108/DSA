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
#include<unordered_set>
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

        // Check each number from 0 to n
        for (int x = 0; x <= n; x++)
        {
            bool found = false;

            // Search x in the array
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == x)
                {
                    found = true;
                    break;
                }
            }

            // If x is not found, it's the missing number
            if (!found)
                return x;
        }

        return -1; // will never be reached
    }
};




//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O(n²)
Outer loop runs n+1 times
Inner loop runs n times

🧠 Space Complexity
O(1)
*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*

The missing number must be in range [0, n]
For each number x in this range:
Scan the entire array
If x is not found → that’s the answer


*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*




*/


//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________


/*

Linear Search
Exhaustive Checking


*/

