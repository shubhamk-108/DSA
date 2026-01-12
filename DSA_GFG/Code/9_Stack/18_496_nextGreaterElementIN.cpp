/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        // Iterate over each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];  // current element
            int nextGreater = -1;  // default answer if none found

            // Find position of x in nums2
            int j = 0;
            while (j < nums2.size() && nums2[j] != x) 
                j++;

            // Now look to the right of position j
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > x) {
                    nextGreater = nums2[k];  // first greater element found
                    break;
                }
            }

            ans.push_back(nextGreater);  // store answer
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    vector<int> v1 = {4, 1, 2};
    vector<int> v2 = {1, 3, 4, 2};
    vector<int> res = sol.nextGreaterElement(v1, v2);
    for (auto &x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Outer loop → O(m) for each element in nums1
Inner search → in worst case O(n) to find element and then O(n) to check right → total O(m * n)
So Time Complexity: O(m × n)
Not efficient if nums2 is large

4️⃣ Space Complexity
O(m) for the result array

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*




*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        // Iterate over each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];  // current element
            int nextGreater = -1;  // default answer if none found

            // Find position of x in nums2
            int j = 0;
            while (j < nums2.size() && nums2[j] != x) 
                j++;

            // Now look to the right of position j
            for (int k = j + 1; k < nums2.size(); k++) {
                if (nums2[k] > x) {
                    nextGreater = nums2[k];  // first greater element found
                    break;
                }
            }

            ans.push_back(nextGreater);  // store answer
        }

        return ans;
    }
};



*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Brute Force / Linear Scan


*/
