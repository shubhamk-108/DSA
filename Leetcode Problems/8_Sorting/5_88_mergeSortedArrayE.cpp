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
        int i = m - 1;
        int j = n - 1;
        int writePtr = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
                nums1[writePtr--] = nums1[i--];
            else
                nums1[writePtr--] = nums2[j--];
        }

        while (j >= 0)
            nums1[writePtr--] = nums2[j--];
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
O(m + n)
We scan each array at most once.

📦 Space Complexity
O(1)
In-place merge using only constant extra variabl
*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Steps
Set three pointers:
i = m - 1 → last valid element in nums1
j = n - 1 → last element in nums2
k = m + n - 1 → last index of nums1 (write pointer)
Compare elements from the end:
If nums1[i] > nums2[j] → place nums1[i] at nums1[k]
Else → place nums2[j] at nums1[k]
Move the appropriate pointers leftward
If any elements remain in nums2, copy them into nums1.
Remaining nums1 elements are already in correct position → no need to copy.


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
        int i = m - 1;     // last valid element in nums1
        int j = n - 1;     // last element in nums2
        int k = m + n - 1; // last position in nums1 (full array)

        // Merge from the end to avoid overwriting nums1                                                                                                                                              
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has elements left, copy them
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Two Pointers (from the end)

Also known as the Reverse Two-Pointer Technique or
In-place Merging Using Three Pointers.


*/
