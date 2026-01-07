/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you
may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
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
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n2 > n1)
            return intersection(nums2, nums1);

        unordered_set<int> us(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto x : nums2)
        {
            if (us.count(x))
            {
                res.push_back(x);
                us.erase(x);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    vector<int> res = sol.intersection(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*
Building set: O(min(n1, n2))
Lookup for other array: O(max(n1, n2))
Total: O(n + m)

Space:
O(min(n1, n2))

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Make nums1 the smaller array → improves speed.
Insert all elements of nums1 into an unordered_set.
Scan nums2, check membership in O(1).
If found, add to result and erase to avoid duplicates.

putting the larger array into the set and iterating over the smaller one

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
Hahhing



*/
