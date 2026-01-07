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
        
        unordered_set <int> us;
        for (int i = 0; i < nums.size(); i++)
        {
            if(us.find(nums[i]) != us.end())
                return true;
            else
                us.insert(nums[i]);
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

Average case: O(n)
Each insertion and lookup in an unordered_set is O(1) on average.
Worst case: O(n²) (rare — due to hash collisions)

Space Complexity
O(n):
In the worst case, all elements are unique, so the set stores all n numbers.

*/


//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________


/*


We use an unordered_set to efficiently check if an element has already appeared in the array.
Since unordered_set allows average O(1) insertion and lookup, this gives us an optimal linear-time solution.
Steps:
Create an empty unordered_set us.
Traverse each element nums[i] in the array:
If it already exists in the set → duplicate found → return true.
Otherwise, insert it into the set.
If traversal completes without finding duplicates → return false.

*/


//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________


/*

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> us;  // stores unique elements seen so far

        for (int i = 0; i < nums.size(); i++) {

            // If current element already in set → duplicate found
            if (us.find(nums[i]) != us.end())
                return true;

            // Otherwise, insert current element into the set
            us.insert(nums[i]);
        }

        // No duplicates found after checking all elements
        return false;
    }
};



*/


