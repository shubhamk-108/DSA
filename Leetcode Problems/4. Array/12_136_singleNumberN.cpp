/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
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
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            bool flag = false;
            for (int j = 0; j < nums.size(); j++)
            {
                if ( i != j && nums[i] == nums[j])
                {
                    flag = true;
                }
            }
            if(flag == false)
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {2,2,1};
    cout << sol.singleNumber(v);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Metric    | Complexity                      |
| --------- | ------------------------------- |
| **Time**  | O(n²) — two nested loops        |
| **Space** | O(1) — no extra data structures |


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Iterate over each element nums[i].
For each nums[i], check all other elements nums[j] to see if it appears again (i != j).
If no duplicate is found (flag == false), return nums[i].
If somehow all elements have duplicates (theoretically impossible in this problem), return -1.
This works because you check every element against every other element, ensuring the single number is found.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;

        // Check each element
        for (int i = 0; i < nums.size(); i++)
        {
            bool flag = false; // Assume nums[i] is unique

            // Compare with every other element
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && nums[i] == nums[j])
                {
                    flag = true; // Found a duplicate
                    break;      // No need to check further
                }
            }

            // If no duplicate was found, return the element
            if (!flag)
                return nums[i];
        }

        return -1; // Just for safety; problem guarantees a single number
    }
};



*/
