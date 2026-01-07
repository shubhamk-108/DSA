/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. 
Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.
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

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;        
    }
};
int main()
{
    Solution sol;
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << sol.containsDuplicate(v);
    return 0;
}


//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity: O(n²)
Space Complexity
No extra data structures are used.
Space Complexity: O(1)

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


Compare every element with all previous elements in the array.
If you find a pair of equal elements → return true (duplicate exists).
If the entire array is traversed without finding duplicates → return false.
This approach does not use extra space; it just checks all pairs.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Check each element with all previous elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // Duplicate found
                if (nums[i] == nums[j])
                    return true;
            }
        }

        // No duplicates found
        return false;
    }
};



*/
