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
        unordered_map<int, int> um;

        for (int i = 0; i < n1; i++)
        {
            um[nums1[i]]++;
        }

        for (int i = 0; i < n2; i++)
        {
            if (um.find(nums2[i]) != um.end())
            {
                res.push_back(nums2[i]);
                um[nums2[i]]--;
                if (um[nums2[i]] == 0)
                    um.erase(nums2[i]);
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
Building map: O(n1)
Iterating nums2: O(n2)
Map operations (find, erase): O(1) average
Total: O(n1 + n2)

🔹 Space Complexity
Frequency map: O(min(n1, n2)) in practice
Result vector: O(min(n1, n2))
Total extra space: O(min(n1, n2))


*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*



Build a frequency map (unordered_map) of elements in nums1:
Keys: elements of nums1
Values: count of each element
Iterate through nums2:
If the element exists in the map (um.find(nums2[i]) != um.end()):
Add it to the result res.
Decrement its count in the map.
If the count becomes 0, erase it from the map (optional, avoids unnecessary keys).
Return the resulting vector res.
Key idea: This method handles duplicates correctly, since each element is added as many times as it appears in both arrays.


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
        unordered_map<int, int> um; // frequency map for nums1

        // Count occurrences of each element in nums1
        for (int i = 0; i < n1; i++)
        {
            um[nums1[i]]++;
        }

        // Check each element in nums2
        for (int i = 0; i < n2; i++)
        {
            if (um.find(nums2[i]) != um.end())
            {
                res.push_back(nums2[i]);   // add to result
                um[nums2[i]]--;            // decrement count
                if (um[nums2[i]] == 0)     // remove key if count reaches 0
                    um.erase(nums2[i]);
            }
        }

        return res; // return intersection
    }
};



*/
