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
        long firstL = nums[0];
        long secondL = LONG_MIN;
        long thirdL = LONG_MIN;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > firstL)
            {
                thirdL = secondL;
                secondL = firstL;
                firstL = nums[i];
            }            
            else if (nums[i] > secondL && nums[i] != firstL)
            {
                thirdL = secondL;
                secondL = nums[i];
            }
            else if(nums[i] > thirdL && nums[i] != secondL && nums[i] != firstL)
            {
                thirdL = nums[i];
            }
        }

        return thirdL == LONG_MIN ? firstL : thirdL ;
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

(O(n) time, O(1) space)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

We need the third distinct maximum number in the array.
If it doesn’t exist (i.e., fewer than 3 distinct numbers), we return the maximum instead.
We can find it efficiently in one pass (no sorting) by maintaining three variables:
firstL → largest number
secondL → second largest distinct number
thirdL → third largest distinct number
We iterate once through nums, updating these three when we find a new unique number that’s larger than one of them.
We use long and LONG_MIN sentinels to safely handle cases where array elements include INT_MIN.

Initialize:
firstL = nums[0]
secondL = thirdL = LONG_MIN
For each element:
Skip duplicates (implicitly handled by != checks).
If the number is greater than firstL, shift all down:
→ thirdL = secondL, secondL = firstL, firstL = nums[i]
Else if greater than secondL (but distinct from firstL):
→ thirdL = secondL, secondL = nums[i]
Else if greater than thirdL (but distinct from both):
→ thirdL = nums[i]
After the loop:
If thirdL was never updated (still LONG_MIN), return firstL.
Otherwise, return thirdL.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


// Efficient O(n) solution for LeetCode 414: Third Maximum Number
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // Use long to handle edge cases where nums contain INT_MIN
        long firstL = nums[0];
        long secondL = LONG_MIN;
        long thirdL = LONG_MIN;
        
        for (int i = 1; i < nums.size(); i++)
        {
            // Skip if it's a duplicate of any current max
            if (nums[i] == firstL || nums[i] == secondL || nums[i] == thirdL)
                continue;

            // Case 1: New largest number
            if (nums[i] > firstL)
            {
                thirdL = secondL;
                secondL = firstL;
                firstL = nums[i];
            }
            // Case 2: New second largest number
            else if (nums[i] > secondL)
            {
                thirdL = secondL;
                secondL = nums[i];
            }
            // Case 3: New third largest number
            else if (nums[i] > thirdL)
            {
                thirdL = nums[i];
            }
        }

        // If third largest doesn't exist, return the maximum
        return (thirdL == LONG_MIN) ? firstL : thirdL;
    }
};



*/
