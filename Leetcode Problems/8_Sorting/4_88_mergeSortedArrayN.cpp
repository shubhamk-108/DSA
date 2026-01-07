/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m;
        int j = 0;

        while (i < m + n && j < n)
        {
            nums1[i++] = nums2[j++];
        }

        sort(nums1.begin(), nums1.end());
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};

    // The first 3 elements are valid, the remaining 3 are placeholders.
    // So m must be 3, not 6.
    sol.merge(v1, 3, v2, 3);

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

Time Complexity
O((m + n) log(m + n))

Sorting the combined array dominates the complexity.

📦 Space Complexity
O(1)

Sorting is done in-place.
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*
Start copying elements of nums2 into nums1 starting at index m.
After all elements are copied, sort nums1 completely.



*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m;  // start position to insert nums2 into nums1
        int j = 0;  // pointer for nums2

        // Copy nums2 elements into nums1 after the first m valid elements
        while (i < m + n && j < n)
        {
            nums1[i++] = nums2[j++];
        }

        // Sort the full nums1 array now that all elements are included
        sort(nums1.begin(), nums1.end());
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

No meaningful algorithmic pattern—just:
Array Manipulatio
Brute Force Merge


*/
