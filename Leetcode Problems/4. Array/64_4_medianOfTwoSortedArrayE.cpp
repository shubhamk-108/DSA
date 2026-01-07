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

        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;
        double median;
        while (low <= high)
        {

            int cut_1 = low + (high - low) / 2;
            int cut_2 = (n1 + n2 + 1) / 2 - cut_1;

            int left_1 = cut_1 == 0 ? INT_MIN : nums1[cut_1 - 1];
            int left_2 = cut_2 == 0 ? INT_MIN : nums2[cut_2 - 1];

            int right_1 = cut_1 == n1 ? INT_MAX : nums1[cut_1];
            int right_2 = cut_2 == n2 ? INT_MAX : nums2[cut_2];

            if (left_1 <= right_2 && left_2 <= right_1)
            {
                if ((n1 + n2) % 2 == 0)
                    median = ((double)max(left_1, left_2) + (double)min(right_1, right_2)) / 2.0;
                else
                    median = max(left_1, left_2);

                return median;
            }

            else if (left_1 > right_2)
                high = cut_1 - 1;
            else // if (left_2 > right_1)
                low = cut_1 + 1;
        }
        return 0.0;
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
Time Complexity: O(log(min(n1,n2)))
Binary search on smaller array (size = min(n1,n2))
Space Complexity: O(1)

*/

//___________________________________________________________________________________________________________________________________________
// Approach
//___________________________________________________________________________________________________________________________________________

/*

Always binary search on the smaller array to minimize complexity.
Partition both arrays such that:
Left partition contains exactly (n1+n2+1)/2 elements.
Right partition contains the remaining elements.
Ensure all elements in left partition ≤ all elements in right partition:
left_1 <= right_2 && left_2 <= right_1
Median:
If total length even → median = (max(left_1, left_2) + min(right_1, right_2))/2.0
If total length odd → median = max(left_1, left_2)
Why +1 in (n1+n2+1)/2?
Guarantees left partition has the extra element for odd-length total arrays.


*/

//___________________________________________________________________________________________________________________________________________
// Code
//___________________________________________________________________________________________________________________________________________

/*


int n1 = nums1.size(), n2 = nums2.size();

// We always run binary search on the smaller array.
// This keeps the search space minimum and avoids tricky edge cases.
// If nums1 is bigger, we simply swap the arrays.
if (n2 < n1)
    return findMedianSortedArrays(nums2, nums1);

// Now nums1 is guaranteed to be the smaller array.
// We will explore all possible partitions of nums1 from 0 to n1.
int low = 0, high = n1;
double median;

while (low <= high)
{
    // partition in nums1 decides how many elements from nums1 go to left side.
    // This is the mid of our binary search range.
    int cut_1 = low + (high - low) / 2;

    // partition in nums2 must fill the remaining elements so that
    // left half contains exactly half (or half+1) of the combined array.
    int cut_2 = (n1 + n2 + 1) / 2 - cut_1;

    // ----- Identify boundary elements around partitions -----
    // For left side of nums1:
    // If cut_1 == 0 → no elements on left, so use INT_MIN as "imaginary -∞"
    int left_1 = (cut_1 == 0) ? INT_MIN : nums1[cut_1 - 1];

    // For right side of nums1:
    // If cut_1 == n1 → no elements on right, so use INT_MAX as "imaginary +∞"
    int right_1 = (cut_1 == n1) ? INT_MAX : nums1[cut_1];

    // For left side of nums2:
    int left_2 = (cut_2 == 0) ? INT_MIN : nums2[cut_2 - 1];

    // For right side of nums2:
    int right_2 = (cut_2 == n2) ? INT_MAX : nums2[cut_2];

    // ----- Check if the partition is valid -----
    // Valid means:
    //   All left-side elements ≤ all right-side elements.
    // Which simplifies to:
    //   left_1 <= right_2   AND   left_2 <= right_1
    if (left_1 <= right_2 && left_2 <= right_1)
    {
        // We found the perfect partition.

        // If total length is even:
        if ((n1 + n2) % 2 == 0)
        {
            // Median = average of:
            //   max of left side (biggest left element)
            //   min of right side (smallest right element)
            median = (max(left_1, left_2) + min(right_1, right_2)) / 2.0;
        }
        else
        {
            // If total length is odd:
            // Median is simply the largest element on the left side.
            median = max(left_1, left_2);
        }

        return median;
    }
    // ----- Adjust binary search range -----
    else if (left_1 > right_2)
    {
        // This means we took too many elements from nums1,
        // i.e., left_1 is too big and violates ordering.
        // Move partition left.
        high = cut_1 - 1;
    }
    else
    {
        // This means left_2 > right_1: we need more elements from nums1.
        // Move partition right.
        low = cut_1 + 1;
    }
}

// Code should never reach here for valid sorted arrays.
return 0.0;


*/

//___________________________________________________________________________________________________________________________________________
// Pattern used
//___________________________________________________________________________________________________________________________________________

/*

Binary Search on Answer / Partitioning
Not a “simple array” problem — requires binary search on index and handling edge cases.


*/
