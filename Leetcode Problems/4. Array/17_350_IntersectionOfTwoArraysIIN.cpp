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
        vector<bool> isUsed(n2, false);

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {

                if (!isUsed[j] && nums1[i] == nums2[j])
                {
                    res.push_back(nums1[i]);
                    isUsed[j] = true;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {4, 9, 5};
    vector<int> v2 = {9, 4, 9, 8, 4};
    vector<int> res = sol.intersect(v1, v2);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
Outer loop: O(n1)
Inner loop: O(n2)
Total: O(n1 × n2)

Space Complexity
Boolean array isUsed: O(n2)
Output array res: O(min(n1, n2))
Extra space: O(n2)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*


Use a nested loop: outer loop over nums1, inner loop over nums2.
Keep a boolean array isUsed to track which elements in nums2 have already been matched.
For each nums1[i], find the first unused matching element in nums2.
Add it to the result and mark it used, then break inner loop to avoid counting duplicates multiple times.

*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> res;
        vector<bool> isUsed(n2, false); // track used elements in nums2

        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                // If this nums2 element is not used and matches nums1[i]
                if (!isUsed[j] && nums1[i] == nums2[j])
                {
                    res.push_back(nums1[i]); // add to result
                    isUsed[j] = true;        // mark as used
                    break;                   // stop to avoid duplicate matching
                }
            }
        }

        return res;
    }
};


*/
