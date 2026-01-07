/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2)
        {
            if(nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else    
                j++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1,2,1,3,1};
    vector<int> v2 = {3,1,3,4,1};
    vector<int> res = sol.intersect(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Sorting: O(n1 log n1 + n2 log n2)
Two-pointer scan: O(n1 + n2)
Total: O(n1 log n1 + n2 log n2)

🔹 Space Complexity
O(1) extra (ignoring output vector res)
Sorting is in-place if allowed.

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Sort both arrays (nums1 and nums2).
Use two pointers (i for nums1, j for nums2).
Move pointers according to the values:
If nums1[i] == nums2[j]: push element to res, move both pointers.
If nums1[i] < nums2[j]: move i to catch up.
If nums1[i] > nums2[j]: move j to catch up.
Stop when either pointer reaches the end.
Key idea: Sorting + two pointers ensures all duplicates are counted correctly and efficiently.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;

        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0; // two pointers

        // Iterate through both arrays
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) { // match found
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++; // move i to catch up
            } else {
                j++; // move j to catch up
            }
        }

        return res; // intersection result
    }
};



*/
