/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ptr1 = 0;
        int ptr2 = 0;

        int firstElementOfMedian = -1;
        int secondElementOfMedian = -1;

        int count = 0;

        while (count <= (n1 + n2) / 2)
        {
            firstElementOfMedian = secondElementOfMedian;

            if ((ptr2 >= n2 && ptr1 < n1) || (ptr1 < n1 && nums1[ptr1] <= nums2[ptr2]))
            {
                secondElementOfMedian = nums1[ptr1];
                ptr1++;
            }
            else //  ((ptr2 < n2 && nums2[ptr2] <= nums1[ptr1]) || (ptr2 < n2 && ptr1 >= n1))
            {
                secondElementOfMedian = nums2[ptr2];
                ptr2++;
            }
            count++;
        }

        if ((n1 + n2) % 2 == 0)
            return (firstElementOfMedian + secondElementOfMedian) / 2.0;
        else
            return secondElementOfMedian;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {1, 2};
    vector<int> v2 = {3, 4};
    cout << sol.findMedianSortedArrays(v1, v2);
    return 0;
}

//___________________________________________________________________________________________________________________________________________
// Timespace
//___________________________________________________________________________________________________________________________________________

/*

| Complexity | Value        | Reason                             |
| ---------- | ------------ | ---------------------------------- |
| **Time**   | `O(n1 + n2)` | You simulate merge until mid index |
| **Space**  | `O(1)`       | No extra storage used              |

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Since both arrays are sorted, we don’t need to merge them fully.
Just simulate the merge process up to the middle index of the combined sorted array.
Let:
secondElementOfMedian = current element in the merge
firstElementOfMedian = previous element in the merge
(needed for even total length)
We stop merging once we reach index (n1 + n2) / 2.
Then:
If total length is odd → median is secondElementOfMedian
If even → median is (firstElementOfMedian + secondElementOfMedian) / 2


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Pointers for both arrays
        int ptr1 = 0;
        int ptr2 = 0;

        // To store the last two picked elements
        int firstElementOfMedian = -1;
        int secondElementOfMedian = -1;

        int count = 0;
        int total = n1 + n2;

        // We only need to simulate merge until we reach the middle
        while (count <= total / 2)
        {
            // Shift previous element
            firstElementOfMedian = secondElementOfMedian;

            // Choose from nums1 if:
            // 1) nums1 has remaining elements AND
            // 2) either nums2 is exhausted OR nums1 element is smaller
            //ptr2 >= n2 ptr 2 is greater than equal to n2 means there are no elements remain in the n2. ALl elements of n2 are exhausted
            // so we can ditectly use nums[n1] providing n1 is not exhausted.
            if ((ptr2 >= n2 && ptr1 < n1) || (ptr1 < n1 && nums1[ptr1] <= nums2[ptr2]))
            {
                secondElementOfMedian = nums1[ptr1];
                ptr1++;
            }
            else
            {
                // Otherwise choose from nums2
                secondElementOfMedian = nums2[ptr2];
                ptr2++;
            }

            count++;
        }

        // Even length → average of middle two
        if (total % 2 == 0)
            return (firstElementOfMedian + secondElementOfMedian) / 2.0;

        // Odd length → middle element
        return secondElementOfMedian;
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two Pointer Technique (Merge Process)
This is the same core idea used in merge step of Merge Sort, but you stop early.


*/
